#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers{4, 1, 3, 2, 3};

    sort(numbers.begin(), numbers.end());
    cout << binary_search(numbers.begin(), numbers.end(), 3) << '\n';

    auto first_three = lower_bound(numbers.begin(), numbers.end(), 3);
    auto after_three = upper_bound(numbers.begin(), numbers.end(), 3);
    cout << "count(3) = " << after_three - first_three << '\n';

    reverse(numbers.begin(), numbers.end());
    cout << *min_element(numbers.begin(), numbers.end()) << '\n';
    return 0;
}

