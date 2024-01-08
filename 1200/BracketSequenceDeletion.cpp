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
    string s; cin >> s;

    int ops = 0, i = 0, answ = n;
    for (; i < n; i++) {
        char c = s[i];
        int start = i;
        int open = (c == '(' ? 1 : 0);
        if (open) {
            while (++i < n and s[i] != c) {
                s[i] == ')' ? open-- : open++;
                if (open == 0)
                    break;
            }
            if (i < n) {
                ops++;
                answ -= i - start + 1;
            }
        }
        else {
            while (++i < n and s[i] != c);
            if (i < n) {
                ops++;
                answ -= i - start + 1;
            }
        }
    }
    cout << ops << " " << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}