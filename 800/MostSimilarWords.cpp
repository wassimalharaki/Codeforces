#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int t; cin >> t;
    
    while (t--) {
        int n, m; cin >> n >> m;

        v<v<char>> words(n, v<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> words[i][j];

        int min = INF;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int diff = 0;
                for (int k = 0; k < m; k++)
                    diff += abs(words[i][k] - words[j][k]);
                if (diff < min)
                    min = diff;
            }
        cout << min nl;
    }

    return 0;
}