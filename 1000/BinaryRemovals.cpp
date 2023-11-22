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
        string s; cin >> s;
        int n = s.size();
        
        if (is_sorted(all(s))) {
            cout << "YES" nl;
            continue;
        }

        bool twozeroes = 0;
        int last;
        for (int i = 1; i < n; i++)
            if (s[i] == s[i - 1] and s[i] == '0')
                twozeroes = 1, last = i - 1;

        if (not twozeroes) {
            cout << "YES" nl;
            continue;
        }

        bool twoones = 0;
        for (int i = 1; i < last; i++)
            if (s[i] == s[i - 1] and s[i] == '1') {
                twoones = 1;
                break;
            }
        cout << (twoones ? "NO" : "YES") nl;
    }

    return 0;
}