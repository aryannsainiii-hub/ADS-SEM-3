#include <iostream>
using namespace std;

struct Player {
    string name;
    int runs;
    int wickets;
};

int main() {
    int n;

    cout << "Enter number of players: ";
    cin >> n;

    Player p[50];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter player " << i + 1 << " name: ";
        cin >> p[i].name;

        cout << "Enter runs: ";
        cin >> p[i].runs;

        cout << "Enter wickets: ";
        cin >> p[i].wickets;
    }

    cout << "scorecard";
    cout << "Name\tRuns\tWickets\n";

    for (int i = 0; i < n; i++) {
        cout << p[i].name << "\t"
             << p[i].runs << "\t"
             << p[i].wickets << endl;
    }

    return 0;
}