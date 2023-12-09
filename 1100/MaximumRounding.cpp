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

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        string s; cin >> s;
        int n = s.size();

        int add = 0, last = INF;
        for (int i = n - 1; i >= 0; i--) {
            if (add) {
                if (s[i] == '9') {
                    s[i] = '0', add = 1, last = i;
                    continue;
                }
                else
                    s[i]++, add = 0;
            }
            
            if (s[i] >= '5')
                s[i] = '0', add = 1, last = i;
        }

        if (s[0] == '0')
            cout << 1;
        for (int i = 0; i < n; i++)
            cout << (i <= last ? s[i] : '0');
        cout nl;
    }

    return 0;
}