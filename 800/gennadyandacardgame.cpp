#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX

int32_t main() {
    fast

    string table; cin >> table;
    v<string> hand(5);
    for (int i = 0; i < 5; i++)
        cin >> hand[i];
    string answ = "NO";
    for (int i = 0; i < 5; i++) {
        if (table[0] == hand[i][0] || table[1] == hand[i][1]) {
            answ = "YES";
            break;
        }
    }

    cout << answ;

    return 0;
}