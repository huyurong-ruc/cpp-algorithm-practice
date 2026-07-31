#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<string> names{"Alice", "Bob"};
    names.insert("Carol");
    names.erase("Bob");

    if (names.find("Alice") != names.end()) {
        cout << "Alice exists\n";
    }
    cout << "size = " << names.size() << '\n';
    return 0;
}
