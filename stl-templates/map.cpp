#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> scores{{"Alice", 90}, {"Bob", 85}};
    scores["Carol"] = 92;
    scores.insert({"David", 88});

    auto iter = scores.find("Alice");
    if (iter != scores.end()) {
        cout << iter->first << ": " << iter->second << '\n';
    }

    for (const auto& [name, score] : scores) {
        cout << name << ' ' << score << '\n';
    }
    return 0;
}

