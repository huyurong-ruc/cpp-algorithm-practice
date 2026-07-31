#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers{3, 1, 4};
    numbers.push_back(2);
    numbers.emplace_back(5);

    sort(numbers.begin(), numbers.end());
    numbers.erase(numbers.begin());

    cout << "size = " << numbers.size() << '\n';
    for (int value : numbers) {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}

