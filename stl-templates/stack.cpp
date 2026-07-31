#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> values;
    values.push(10);
    values.push(20);
    values.emplace(30);

    while (!values.empty()) {
        cout << values.top() << ' ';
        values.pop();
    }
    cout << '\n';
    return 0;
}

