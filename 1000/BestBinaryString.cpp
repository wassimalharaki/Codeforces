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

        if (count(all(s), '?') == s.size()) {
            fill(all(s), '1');
            cout << s nl;
            continue;
        }

        if (s.size() == 1) {
            cout << s nl;
            continue;
        }

        if (s[0] == '?')
            s[1] == '?' ? s[0] = '0', s[1] = '0' : s[0] = s[1];

        for (int i = 1; i < s.size(); i++)
            if (s[i] == '?')
                s[i] = s[i - 1];
                
        cout << s nl;
    }

    return 0;
}