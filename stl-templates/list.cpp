#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> numbers{3, 1, 2, 2};
    numbers.push_front(4);
    numbers.sort();
    numbers.unique();
    numbers.remove(3);

    for (int value : numbers) {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}

