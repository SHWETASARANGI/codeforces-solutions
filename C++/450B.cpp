#include <iostream>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y, n;
    cin >> x >> y >> n;

    const long long MOD = 1000000007;

    // The sequence has a period of 6
    long long f[] = {x - y, x, y, y - x, -x, -y};

    // Calculate fn mod 6
    long long ans = f[n % 6];

    // Handle negative results in C++ modulo arithmetic
    ans = (ans % MOD + MOD) % MOD;

    cout << ans << "\n";

    return 0;
}