#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> values{3, 1, 2, 2};
    values.insert(4);

    if (values.count(2) > 0) {
        cout << "2 exists\n";
    }

    auto iter = values.lower_bound(3);
    if (iter != values.end()) {
        cout << "first value >= 3: " << *iter << '\n';
    }
    return 0;
}

