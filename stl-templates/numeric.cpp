#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers(5);
    iota(numbers.begin(), numbers.end(), 1);

    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    int product = accumulate(numbers.begin(), numbers.end(), 1, multiplies<int>());

    cout << "sum = " << sum << '\n';
    cout << "product = " << product << '\n';
    cout << "gcd(18, 24) = " << gcd(18, 24) << '\n';
    return 0;
}
