#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int value : {3, 1, 4, 2}) {
        max_heap.push(value);
        min_heap.push(value);
    }

    cout << "max = " << max_heap.top() << '\n';
    cout << "min = " << min_heap.top() << '\n';
    return 0;
}

