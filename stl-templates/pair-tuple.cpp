#include <iostream>
#include <string>
#include <tuple>
#include <utility>

using namespace std;

int main() {
    pair<string, int> student{"Alice", 90};
    cout << student.first << ' ' << student.second << '\n';

    tuple<int, string, double> record{1, "book", 39.5};
    auto [id, name, price] = record;
    cout << id << ' ' << name << ' ' << price << '\n';
    return 0;
}

