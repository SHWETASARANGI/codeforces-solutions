#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, sumTime;
    if (!(cin >> d >> sumTime)) return 0;

    vector<int> minTime(d), maxTime(d);
    int minSum = 0, maxSum = 0;

    for (int i = 0; i < d; ++i) {
        cin >> minTime[i] >> maxTime[i];
        minSum += minTime[i];
        maxSum += maxTime[i];
    }

    // Check feasibility
    if (sumTime < minSum || sumTime > maxSum) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<int> schedule = minTime;
    int remaining = sumTime - minSum;

    for (int i = 0; i < d; ++i) {
        int add = min(maxTime[i] - minTime[i], remaining);
        schedule[i] += add;
        remaining -= add;
    }

    for (int i = 0; i < d; ++i) {
        cout << schedule[i] << (i == d - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}