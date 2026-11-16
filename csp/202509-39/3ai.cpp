#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct HuffmanNode {
    int left=-1,right=-1;
    char value;
    bool leaf=false;
};

struct node {
    string key;
    string value;
};

vector<HuffmanNode> huffman;
string tree;
int pos,n;

vector<node> static_table;
deque<node> dynamic_table;
int dynamic_limit,static_size;

int build_huffman_tree() {
    HuffmanNode node;

    int id = huffman.size();
    huffman.push_back(node);

    if (tree[pos] == '1') {
        pos++;
        huffman[id].leaf = true;
        huffman[id].value = tree[pos++];
        return id;
    }

    pos++;

    int left = build_huffman_tree();
    int right = build_huffman_tree();

    huffman[id].left = left;
    huffman[id].right = right;

    return id;
}

int hex_value(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    return ch - 'a' + 10;
}

string decode_huffman_string(const string& token) {
    vector<int> bytes;

    for (int i = 1; i < (int)token.size(); i += 2) {
        int value = hex_value(token[i]) * 16 + hex_value(token[i + 1]);
        bytes.push_back(value);
    }

    int padding = bytes.back();
    bytes.pop_back();

    int total_bits = (int)bytes.size() * 8 - padding;

    string result;
    int current = 0;

    for (int bit = 0; bit < total_bits; bit++) {
        int byte_id = bit / 8;
        int offset = 7 - bit % 8;
        int direction = (bytes[byte_id] >> offset) & 1;

        if (direction == 0) {
            current = huffman[current].left;
        } else {
            current = huffman[current].right;
        }

        if (huffman[current].leaf) {
            result.push_back(huffman[current].value);
            current = 0;
        }
    }
    return result;
}

// 这个函数只能用于指令中直接给出的字符串
string decode_string(const string& token) {
    if (token[0] != 'H') return token;
    if (token.size() >= 2 && token[1] == 'H')  return token.substr(1);
    return decode_huffman_string(token);
}

node get_entry(int i) {
    if (i <= static_size) {
        return static_table[i - 1];
    }
    return dynamic_table[i - static_size - 1];
}

void insert_dynamic_table(const node& entry) {
    dynamic_table.push_front(entry);

    if (dynamic_table.size() > dynamic_limit) {
        dynamic_table.pop_back();
    }
}

int main() {
    cin >> static_size >> dynamic_limit;
    static_table.resize(static_size);
    for (int i = 0; i < static_size; i++) {
        cin >> static_table[i].key >> static_table[i].value;
    }
    cin >> tree;
    build_huffman_tree();
    cin >> n;
    while (n--) {
        int operation, i;
        cin >> operation >> i;
        if (operation == 1) {
            node entry = get_entry(i);
            cout << entry.key << ": " << entry.value << '\n';
            continue;
        }

        node entry;
        string raw_value;
        if (i == 0) {
            string raw_key;
            cin >> raw_key >> raw_value;
            entry.key = decode_string(raw_key);
        } else {
            cin >> raw_value;
            entry.key = get_entry(i).key;
        }
        entry.value = decode_string(raw_value);
        cout << entry.key << ": " << entry.value << '\n';
        if (operation == 2) insert_dynamic_table(entry);
    }

    return 0;
}