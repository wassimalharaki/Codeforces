#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string guest, host, pile;

    cin >> guest >> host >> pile;

    vector<int> names(26, 0);
    vector<int> p(26, 0);

    for (int i = 0; i < guest.size(); i++)
        names[guest[i] - 'A']++;

    for (int i = 0; i < host.size(); i++)
        names[host[i] - 'A']++;

    for (int i = 0; i < pile.size(); i++)
        p[pile[i] - 'A']++;

    for (int i = 0; i < 26; i++)
        if (names[i] != p[i]) {
            cout << "NO";
            return 0;
        }
    cout << "YES";

    return 0;
}