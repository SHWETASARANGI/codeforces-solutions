#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int max_turns = 0;
    int last_child = 1;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;

        // Calculate ceil(a / m) using integer arithmetic
        int turns = (a + m - 1) / m;

        // Update if this child needs equal or more turns
        if (turns >= max_turns) {
            max_turns = turns;
            last_child = i;
        }
    }

    cout << last_child << "\n";

    return 0;
}