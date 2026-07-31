#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> frequency;
    for (char ch : string("banana")) {
        ++frequency[string(1, ch)];
    }

    cout << "a: " << frequency.at("a") << '\n';
    if (frequency.count("z") == 0) {
        cout << "z does not exist\n";
    }
    return 0;
}

