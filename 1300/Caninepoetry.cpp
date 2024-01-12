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
    int n = s.size();

    if (n == 1) {
        cout << 0 nl;
        return;
    }

    int answ = 0;
    v<bool> flag(n);
    if (s[0] == s[1])
        flag[1] = 1, answ++;
    for (int i = 2; i < n; i++)
        if (s[i] == s[i - 1] and not flag[i - 1])
            answ++, flag[i] = 1;
        else if (s[i] == s[i - 2] and not flag[i - 2])
            answ++, flag[i] = 1;
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}