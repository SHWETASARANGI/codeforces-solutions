#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Envelope {
    int w, h, id;
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, card_w, card_h;
    if (!(cin >> n >> card_w >> card_h)) return 0;

    vector<Envelope> envs;
    for (int i = 1; i <= n; ++i) {
        int w, h;
        cin >> w >> h;
        // Only keep envelopes strictly larger than the card
        if (w > card_w && h > card_h) {
            envs.push_back({w, h, i});
        }
    }

    if (envs.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    // Sort by width ascending; if widths are equal, height descending
    sort(envs.begin(), envs.end(), [](const Envelope& a, const Envelope& b) {
        if (a.w != b.w) return a.w < b.w;
        return a.h > b.h;
    });

    int k = envs.size();
    vector<int> dp(k, 1);
    vector<int> parent(k, -1);

    int max_len = 0;
    int best_end = 0;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < i; ++j) {
            if (envs[j].w < envs[i].w && envs[j].h < envs[i].h) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            best_end = i;
        }
    }

    // Reconstruct sequence
    vector<int> path;
    for (int curr = best_end; curr != -1; curr = parent[curr]) {
        path.push_back(envs[curr].id);
    }
    reverse(path.begin(), path.end());

    // Output results
    cout << max_len << "\n";
    for (int i = 0; i < (int)path.size(); ++i) {
        cout << path[i] << (i + 1 == (int)path.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}