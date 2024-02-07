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
    string s, t; cin >> s >> t;

    list<pair<int, char>> blocks{{1, s[0]}};
    for (int i = 1; i < n; i++)
        if (s[i] == blocks.back().S)
            blocks.back().F++;
        else
            blocks.pb({1, s[i]});

    auto it = blocks.begin();
    int j = 0;
    while (not blocks.empty()) {
        auto& [val, c] = *it;

        if (val == 0) {
            blocks.erase(it);
            it = blocks.begin();
            continue;
        }
        
        if (c == t[j])
            val--;
        else if (c == 'c' and t[j] == 'a'
               or c == 'a' and t[j] == 'c') {
            cout << "NO" << nl;
            return;
        }
        else if (c == 'b' and t[j] == 'a') {
            cout << "NO" << nl;
            return;
        }
        else if (c == 'c' and t[j] == 'b') {
            cout << "NO" << nl;
            return;
        }
        else if (c == 'a' and t[j] == 'b') {
            if (blocks.size() == 1) {
                cout << "NO" << nl;
                return;
            }
            it++;
            auto it2 = it--;
            while (it2 -> S == c) {
                val += it2 -> F;
                blocks.erase(it2);
                if (blocks.size() == 1) {
                    cout << "NO" << nl;
                    return;
                }
                it++;
                it2 = it--;
            }

            auto& [next_val, next_c] = *it2;
            if (next_c != 'b') {
                cout << "NO" << nl;
                return;
            }
            if (next_val == 0) {
                cout << "NO" << nl;
                return;
            }
            next_val--;
            if (next_val == 0)
                blocks.erase(it2);
        }
        else if (c == 'b' and t[j] == 'c') {
            if (blocks.size() == 1) {
                cout << "NO" << nl;
                return;
            }

            it++;
            auto it2 = it--;
            while (it2 -> S == c) {
                val += it2 -> F;
                blocks.erase(it2);
                if (blocks.size() == 1) {
                    cout << "NO" << nl;
                    return;
                }
                it++;
                it2 = it--;
            }

            auto& [next_val, next_c] = *it2;
            if (next_c != 'c') {
                cout << "NO" << nl;
                return;
            }
            if (next_val == 0) {
                cout << "NO" << nl;
                return;
            }
            next_val--;
            if (next_val == 0)
                blocks.erase(it2);
        }
        j++;
    }
    cout << "YES" << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}