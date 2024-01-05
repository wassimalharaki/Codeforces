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
    string s; cin >> s;
    int n = 10;

    vi one(n), two(n);
    vi free1(n), free2(n);
    one[0] = (s[0] == '1'); free1[0] = (s[0] == '?');
    for (int i = 1; i < n; i++) {
        two[i] = two[i - 1];
        free2[i] = free2[i - 1];
        one[i] = one[i - 1];
        free1[i] = free1[i - 1];
        if (i & 1) {
            if (s[i] == '?')
                free2[i]++;
            else if (s[i] == '1')
                two[i]++;
        }
        else {
            if (s[i] == '?')
                free1[i]++;
            else if (s[i] == '1')
                one[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (one[i] + free1[i] > two[i] + (n - i) / 2) {
            cout << i + 1 nl;
            return;
        }
        else if (two[i] + free2[i] > one[i] + (n - i - 1) / 2) {
            cout << i + 1 nl;
            return;
        }
    }
    cout << 10 nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}