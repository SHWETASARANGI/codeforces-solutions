#include <iostream>
#include <string>

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    bool zero_found = false;

    for (size_t i = 0; i < s.length(); ++i) {
        if (!zero_found && s[i] == '0') {
            zero_found = true; // Skip the first '0'
            continue;
        }
        
        // If all digits were '1's, drop the last digit
        if (!zero_found && i == s.length() - 1) {
            continue;
        }

        cout << s[i];
    }

    cout << "\n";
    return 0;
}