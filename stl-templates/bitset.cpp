#include <bitset>
#include <iostream>

using namespace std;

int main() {
    bitset<8> bits(13);

    cout << bits << '\n';
    cout << "ones = " << bits.count() << '\n';
    bits.set(7);
    bits.reset(0);
    bits.flip(1);
    cout << bits << '\n';
    return 0;
}

