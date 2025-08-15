#include <iostream>
using namespace std;

bool isBinary(string &s) {
    for (int i = 0; i < s.length(); i++) {

        // Check if the character is neither
        // '0' nor '1'
        if (s[i] != '0' && s[i] != '1') {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "01010101010";
    cout << (isBinary(s) ? "true" : "false");
    return 0;
}