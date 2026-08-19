#include <iostream>
#include <algorithm>


using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long k, n, w;
    cin >> k >> n >> w;

    long long total_cost = k * w * (w + 1) / 2;
    long long borrow = total_cost - n;

    if (borrow > 0) {
        cout << borrow << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;

}

