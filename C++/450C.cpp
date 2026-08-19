#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, k;
    cin >> n >> m >> k;

    // Impossible if required cuts exceed maximum allowed cuts
    if (k > n + m - 2) {
        cout << -1 << "\n";
        return 0;
    }

    long long ans = 0;

    // Try allocating maximum possible cuts to dimension n
    if (k < n) {
        ans = max(ans, (n / (k + 1)) * m);
    } else {
        ans = max(ans, 1 * (m / (k - n + 2)));
    }

    // Try allocating maximum possible cuts to dimension m
    if (k < m) {
        ans = max(ans, n * (m / (k + 1)));
    } else {
        ans = max(ans, (n / (k - m + 2)) * 1);
    }

    cout << ans << "\n";

    return 0;
}