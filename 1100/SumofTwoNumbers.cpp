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

int sum(int n) {
    string s = to_string(n);
    int tot = 0;
    for (char c : s)
        tot += c - '0';
    return tot;
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;
        string s = to_string(n);
 
        int x = 0, y = 0;
        int alt = 1;
        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - '0';
            x *= 10, y *= 10;
            if (a & 1) {
                if (alt)
                    x += (a + 1) / 2, y += a / 2;
                else
                    y += (a + 1) / 2, x += a / 2;
                alt = !alt;
            }
            else
                x += a / 2, y += a / 2;
        }
        cout << x << " " << y nl;
    }

    return 0;
}