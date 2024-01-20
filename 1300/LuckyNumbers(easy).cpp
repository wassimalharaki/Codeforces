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

void inc(string& s) {
    int n = s.size();
    for (int i = n - 1; i > 0; i--)
        if (s[i - 1] == '4' and s[i] == '7') {
            swap(s[i - 1], s[i]);
            sort(s.begin() + i + 1, s.end());
            return;
        }
    s = string(n / 2 + 1, '4') + string(n / 2 + 1, '7');
}

void solve() {
    string s; cin >> s;
    int n = s.size() + (s.size() & 1);
    string t = string(n / 2, '4') + string(n / 2, '7');
    while (stoll(t) < stoll(s)) inc(t);
    cout << t;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}