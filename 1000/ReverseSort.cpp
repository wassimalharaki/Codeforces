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
        int n; cin >> n;
        string s; cin >> s;

        if (is_sorted(all(s))) {
            cout << 0 nl;
            continue;
        }

        int ones = count(all(s), '1');
        int zeroes = count(all(s), '0');

        int count = 0;
        for (int i = 0; i < ones; i++)
            if (s[n - i - 1] == '0')
                count++;
        
        cout << 1 nl << 2 * count << " ";
        for (int i = 0; i < n - ones; i++)
            if (s[i] == '1')
                cout << i + 1 << " ";
        string app;
        for (int i = 0; i < ones; i++)
            if (s[n - i - 1] == '0')
                app = to_string(n - i) + " " + app;
        cout << app nl;
    }

    return 0;
}