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

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int a = count(all(s), '(');
    int b = count(all(s), ')');

    if (a != b) {
        cout << -1 << nl;
        return;
    }

    bool reg = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        s[i] == '(' ? cnt++ : cnt--;
        if (cnt < 0)
            reg = 0;
    }

    bool rev = 1;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        s[i] == ')' ? cnt++ : cnt--;
        if (cnt < 0)
            rev = 0;
    }

    if (reg or rev) {
        cout << 1 << nl;
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
        cout << nl;
        return;
    }

    vi ans(n);
    char c = s[0];
    deque<int> ind;
    for (int i = 0; i < n; i++) {
        if (s[i] == c) {
            ind.push_back(i);
            continue;
        }

        if (not ind.empty()) {
            ans[ind.front()] = 1;
            ind.pop_front();
            ans[i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
        if (not ans[i])
            ans[i] = 2;
    
    cout << 2 << nl;
    for (int& a : ans)
        cout << a << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}