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

v<string> p2(63);

void solve() {
    string s; cin >> s;

    int min = INF;
    for (int i = 0; i < 63; i++) {
        int a = 0;
        for (int j = 0; j < s.size() and a < p2[i].size(); j++)
            if (s[j] == p2[i][a])
                a++;
        int val = s.size() + p2[i].size() - 2 * a;
        min = std::min(min, (int) (s.size() + p2[i].size()) - 2 * a);
    }
    cout << min nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 63; i++)
        p2[i] = to_string(1ll << i);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}