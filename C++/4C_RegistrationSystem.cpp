#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;

int main() {
    //Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    if (!cin >> n) {
        cerr << "Error reading input." << endl;
        return 1;
    }

    unordered_map<string, int> name_to_id;

    while(n--) {
        string name;
        cin >> name;

        if (name_to_id[name] == 0) {
            name_to_id[name] = 1;
            cout << "OK\n";
        } else  {
            cout << name << name_to_id[name] << "\n";
            name_to_id[name]++;

        }
    }

    return 0;
}



