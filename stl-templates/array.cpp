#include <array>
#include <iostream>

using namespace std;

int main() {
    array<int, 5> numbers{5, 2, 4, 1, 3};

    cout << numbers.front() << ' ' << numbers.back() << '\n';
    numbers.fill(0);
    numbers[2] = 7;

    for (int value : numbers) {
        cout << value << ' ';
    }
    cout << '\n';
    return 0;
}

