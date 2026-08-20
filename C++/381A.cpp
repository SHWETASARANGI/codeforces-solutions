#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    int left = 0;
    int right = n - 1;
    
    int sereja_score = 0;
    int dima_score = 0;
    bool sereja_turn = true;

    while (left <= right) {
        int chosen_card;
        
        // Pick the larger card from either end
        if (cards[left] > cards[right]) {
            chosen_card = cards[left];
            left++;
        } else {
            chosen_card = cards[right];
            right--;
        }

        // Add to the active player's score
        if (sereja_turn) {
            sereja_score += chosen_card;
        } else {
            dima_score += chosen_card;
        }

        // Switch turns
        sereja_turn = !sereja_turn;
    }

    cout << sereja_score << " " << dima_score << "\n";

    return 0;
}