#include <iostream>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    // Calculate the total number of odd integers up to n
    long long odds_count = (n + 1) / 2;

    if (k <= odds_count) {
        // k-th position is in the odd numbers section
        cout << 2 * k - 1 << "\n";
    } else {
        // k-th position is in the even numbers section
        cout << 2 * (k - odds_count) << "\n";
    }

    return 0;
}