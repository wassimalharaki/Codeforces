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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    set<int> pos;
    for (int i = 0; i < n; i++)
        if (s[i] == '1') pos.insert(i);

    int answ = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') continue;

        auto it = pos.lower_bound(i);
        if (pos.size() == 0) {
            answ++;
            pos.insert(i);
        }
        else if (it == pos.begin()) {
            if (abs(*it - i) <= k)
                continue;
            answ++;
            pos.insert(i);
        }
        else if (it == pos.end()) {
            --it;
            if (abs(*it - i) <= k)
                continue;
            answ++;
            pos.insert(i);
        }
        else {
            int a = *it, b = *(--it);
            if (abs(a - i) <= k or abs(b - i) <= k)
                continue;
            answ++;
            pos.insert(i);
        }
    }
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