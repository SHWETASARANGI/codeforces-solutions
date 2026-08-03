#include <iostream>

using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;
    // Calculate ceil((n * m) / 2) using integer division
    long long ans = (n * m + 1) / 2;
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}