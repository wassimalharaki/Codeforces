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
        int n; cin >> n;
        char c; cin >> c;
        map<char, vi> count;
        for (int i = 0; i < n; i++) {
            char cc; cin >> cc;
            count[cc].pb(i + 1);
        }

        if (c == 'g') {
            cout << 0 nl;
            continue;
        }

        int answ = -1;
        for (int i = 0; i < count[c].size(); i++) {
            auto it = lower_bound(all(count['g']), count[c][i]);
            if (it == count['g'].end())
                answ = max(answ, n - count[c][i] + count['g'][0]);
            else
                answ = max(answ, *it - count[c][i]);
        }
        cout << answ nl;
    }

    return 0;
}