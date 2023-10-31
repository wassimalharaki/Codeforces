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
        string s; cin >> s;
        int n = s.size();
        
        if (s[0] == 'a' and s[n - 1] == 'a')
            cout << s[0] << " "
                 << s.substr(1, n - 2)
                 << " " << s[n - 1] nl;
        else if (s[0] == 'b' and s[n - 1] == 'b')
            cout << s[0] << " "
                 << s.substr(1, n - 2)
                 << " " << s[n - 1] nl;
        else if (s[0] == 'b' and s[n - 1] == 'a')
            cout << s[0] << " " << s[1] << " "
                 << s.substr(2, n - 2) nl;
        else
            cout << s.substr(0, n - 2) << " "
                 << s[n - 2] << " " << s[n - 1] nl;
    }

    return 0;
}