#include <iostream>
#include <string>

using namespace std;

int main() {
    string text = "hello STL";
    text += "!";

    cout << text.size() << '\n';
    cout << text.substr(6, 3) << '\n';

    size_t position = text.find("STL");
    if (position != string::npos) {
        text.replace(position, 3, "C++");
    }
    cout << text << '\n';
    return 0;
}

