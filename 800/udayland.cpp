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
#define F first
#define S second

int32_t main() {
    fast

    int n; cin >> n;

    v<v<char>> bus(n, v<char>(5));

    bool found = false;
    for (int i = 0; i < n; i++) {
        cin >> bus[i][0] >> bus[i][1] >> bus[i][2];
        if (not found && bus[i][0] == bus[i][1] && bus[i][0] == 'O') {
            found = true;
            bus[i][0] = bus[i][1] = '+';
        }
        cin >> bus[i][3] >> bus[i][4];
        if (not found && bus[i][3] == bus[i][4] && bus[i][3] == 'O') {
            found = true;
            bus[i][3] = bus[i][4] = '+';
        }
    }

    if (found) {
        cout << "YES" nl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++)
                cout << bus[i][j];
            cout nl;
        }
    }
    else
        cout << "NO" nl;

    

    return 0;
}