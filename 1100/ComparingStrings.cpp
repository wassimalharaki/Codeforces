#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

void solve() {
    string s1, s2; cin >> s1 >> s2;

    if (s1.size() != s2.size()) {
        cout << "NO" nl;
        return;
    }

    v<pair<char, char>> need;
    for (int i = 0; i < s1.size(); i++)
        if (s1[i] != s2[i])
            need.pb(mp(s1[i], s2[i]));
    
    if (need.size() == 0) {
        cout << "YES" nl;
        return;
    }
    
    if (need.size() != 2) {
        cout << "NO" nl;
        return;
    }

    if (need[0].F == need[1].S and need[0].S == need[1].F)
        cout << "YES" nl;
    else
        cout << "NO" nl;
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;

    while(T--)
        solve();

    return 0;
}