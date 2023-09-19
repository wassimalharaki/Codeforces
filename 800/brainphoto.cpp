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

int32_t main() {
    fast

    int n, m; cin >> n >> m;

    char c;

    string answ = "#Black&White";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c != 'B' && c != 'W' && c != 'G') {
                answ = "#Color";
            }
        }
    }

    cout << answ;

    return 0;
}