#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<int> numbers;
    numbers.push_back(2);
    numbers.push_front(1);
    numbers.push_back(3);

    cout << numbers.front() << ' ' << numbers.back() << '\n';
    numbers.pop_front();
    numbers.pop_back();
    cout << numbers.front() << '\n';
    return 0;
}

