#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
        string s, t; cin >> s >> t;

        if (t.size() == 1 and t[0] == 'a') {
            cout << 1 nl;
            continue;
        }
        
        if (t.find('a') == string::npos) {
            cout << (1LL << s.size()) nl;
            continue;
        }

        cout << -1 nl;
    }

    return 0;
}