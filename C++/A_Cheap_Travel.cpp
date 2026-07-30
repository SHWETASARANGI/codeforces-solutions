#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    //Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m, a, b;
    if(!(cin >> n >> m >> a >> b)) return 0;

    //Buy single tickets for each ride
    int single_ticket_cost = n * a;

    //Buy as many m-ride tickets as possible and then sigle tickets for the remainder
    int m_ride_tickets_cost= (n / m)*b  + (n % m)*a;

    //Buy m-ride tickets exclusively  which may cover more than n rides
    int m_ride_tickets_only_cost = ((n + m - 1) / m) * b;

    //Output the minimum cost
    int  min_cost = min({single_ticket_cost, m_ride_tickets_cost, m_ride_tickets_only_cost});

    cout << min_cost << "\n";

    return 0;
}


