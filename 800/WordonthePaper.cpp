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
        string s;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++) {
                char c; cin >> c;
                if (c != '.')
                    s += c;
            }
        cout << s nl;      
    }

    return 0;
}