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
    int n, m; cin >> n >> m;
    
    vpii nums(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        string s = to_string(a);
        reverse(all(s));
        nums[i].S = s.size();
        for (int j = 0; j < s.size(); j++)
            if (s[j] == '0')
                nums[i].F++;
            else
                break;
    }
 
    multiset<pii> ok;
    for (pii& p : nums)
        ok.insert(p);
    
    int alt = 1;
    while (1) {
        if (alt) {
            pii p = *(--ok.end());
            ok.erase(--ok.end());
            p.S -= p.F;
            p.F = 0;
            ok.insert(p);
        }
        else {
            if (ok.size() == 1) break;
            pii p = *(--ok.end());
            pii q = *(ok.begin());
            ok.erase(ok.begin());
            ok.erase(--ok.end());
            pii next = {q.F, p.S + q.S};
            ok.insert(next);
        }
        alt = !alt;
    }

    cout << (ok.begin() -> S > m ? "Sasha" : "Anna") << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}