#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 20;

void solve() {
    int n, x; cin >> n >> x;
    string s; cin >> s;

    int ans = 0;
    set<string> have;
    have.insert(s);
    queue<string> q;
    q.push(s);

    while (not q.empty() and (int) have.size() < x) {
        int sz = q.size();
        for (int i = 0; i < sz and (int) have.size() < x; i++) {
            string t = q.front();
            q.pop();
            for (int j = 0; j < (int) t.size() and (int) have.size() < x; j++) {
                string u;
                for (int k = 0; k < (int) t.size(); k++)
                    if (k != j)
                        u += t[k];
                if (not have.count(u)) {
                    have.insert(u);
                    ans += n - u.size();
                    q.push(u);
                }
            }
        }
    }
    cout << ((int) have.size() == x ? ans : -1) << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}