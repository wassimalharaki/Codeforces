#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
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

vi divisors(int n) {
    vi divs;

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divs.push_back(i);

    for (int i = divs.size() - 1; i >= 0; i--)
        if (n / divs[i] != divs[i])
            divs.push_back(n / divs[i]);

    return divs;
}

void solve() {
    int n; cin >> n;

    vi divs = divisors(n); divs.pop_back();
    string s(n, '-');
    v<v<bool>> cant(n, v<bool>(26));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++)
            if (not cant[i][j]) {
                s[i] = 'a' + j;
                break;
            }
        for (int& x : divs)
            if (i + x < n)
                cant[i + x][s[i] - 'a'] = 1;
    }
    cout << s << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}