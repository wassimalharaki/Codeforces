#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<int> atk(n), def(n);
    v<bool> ok(n, 1);
    for (int& a : atk) cin >> a;
    for (int& a : def) cin >> a;

    set<int> alive;
    for (int i = 0; i < n; i++)
        alive.insert(i);

    v<int> rounds(n), dead;
    for (int i = 0; i < n; i++) {
        int dmg = 0;
        if (i - 1 >= 0)
            dmg += atk[i - 1];
        if (i + 1 < n)
            dmg += atk[i + 1];
        
        if (dmg > def[i]) {
            dead.push_back(i);
            alive.erase(i);
            rounds[0]++;
            ok[i] = 0;
        }
    }


    for (int i = 1; i < n; i++) {
        int curr = 0;
        v<int> kill;

        for (int j = 0; j < dead.size(); j++) {
            auto right_neighbour = alive.lower_bound(dead[j]);
            if (right_neighbour == alive.end() or
                    right_neighbour == alive.begin())
                continue;

            auto left_neighbour = --alive.lower_bound(dead[j]);
            int l = *left_neighbour, r = *right_neighbour;

            {
                int dmg = atk[r];
                if (not ok[l]) dmg = LLONG_MIN;

                if (left_neighbour != alive.begin()) {
                    --left_neighbour;
                    dmg += atk[*left_neighbour];
                }

                if (dmg > def[l]) {
                    ok[l] = 0;
                    kill.push_back(l);
                    curr++;
                }
            }

            {
                int dmg = atk[l];
                if (not ok[r]) dmg = LLONG_MIN;

                if (++right_neighbour != alive.end()) {
                    dmg += atk[*right_neighbour];
                }

                if (dmg > def[r]) {
                    ok[r] = 0;
                    kill.push_back(r);
                    curr++;
                }
            }
        }

        for (int j = 0; j < kill.size(); j++)
            alive.erase(kill[j]);
        dead = kill;
        rounds[i] = curr;
        if (curr == 0) break;
    }

    for (int& x : rounds)
        cout << x << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}