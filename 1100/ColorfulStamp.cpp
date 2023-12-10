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

        if (n == 1) {
            cout << (s == "W" ? "YES" : "NO") nl;
            continue;
        }

        string answ = "YES";
        bool red = 0, blue = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R')
                red = 1;
            else if (s[i] == 'B')
                blue = 1;
            else if (s[i] == 'W' and i and s[i - 1] != 'W') {
                if (not (red and blue)) {
                    answ = "NO";
                    break;
                }
                red = 0, blue = 0;
            }
        }
        if (s[n - 1] != 'W')
            if (not (red and blue))
                answ = "NO";
        cout << answ nl;
    }

    return 0;
}