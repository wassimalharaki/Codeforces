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

    int T; cin >> T;
    
    while (T--) {
        string s, t, origs, origt; cin >> origs >> origt;
        int l = lcm(origs.size(), origt.size());

        while (s.size() != l)
            s += origs;
        while (t.size() != l)
            t += origt;

        cout << (s == t ? s : "-1") nl;
    }

    return 0;
}