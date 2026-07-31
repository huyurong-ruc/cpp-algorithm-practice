#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> values;
    values.push(10);
    values.push(20);
    values.emplace(30);

    while (!values.empty()) {
        cout << values.front() << ' ';
        values.pop();
    }
    cout << '\n';
    return 0;
}

