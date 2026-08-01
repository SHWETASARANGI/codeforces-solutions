#include <iostream>
#include <string>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    long long heavy_count = 0;
    long long total_substrings = 0;

    for (int i = 0; i < n; i++) {
        // Check for "heavy" (length 5)
        if (i + 4 < n && s.substr(i, 5) == "heavy") {
            heavy_count++;
            i += 4; 
        }
        // Check for "metal" (length 5)
        else if (i + 4 < n && s.substr(i, 5) == "metal") {
            total_substrings += heavy_count;
            i += 4; 
        }
    }

    cout << total_substrings << "\n";

    return 0;
}