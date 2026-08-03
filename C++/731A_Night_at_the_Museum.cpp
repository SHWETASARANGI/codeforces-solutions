#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    char current = 'a';
    int total_rotations = 0;

    for (char target : s) {
        int diff = abs(target - current);
        // The minimum moves in a circle of length 26
        total_rotations += min(diff, 26 - diff);
        current = target; // Move the pointer to the current printed letter
    }

    cout << total_rotations << "\n";

    return 0;
}