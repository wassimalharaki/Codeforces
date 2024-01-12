#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    int answ = 0;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == '1' and t[i] == '0'
                and s[i + 1] == '0' and t[i + 1] == '1'
                or s[i] == '0' and t[i] == '1'
                and s[i + 1] == '1' and t[i + 1] == '0') {
            answ++;
            swap(s[i], s[i + 1]);
        }
    
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
            answ++;
    cout << answ nl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}