#include <iostream>
#include <string>

using namespace std;

bool isMagicNumber(const string& s) {
    // Condition 1: Must start with '1'
    if (s[0] != '1') {
        return false;
    }

    // Condition : Check for invalid digits or "444"
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] != '1' && s[i] != '4') {
            return false; // Contains a digit other than 1 or 4
        }
        if (i >= 2 && s[i] == '4' && s[i - 1] == '4' && s[i - 2] == '4') {
            return false; // Found "444"
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (cin >> s) {
        if (isMagicNumber(s)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}