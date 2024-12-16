#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

map<array<int, 2>, int> qs;
int ask(int i, int j) {
    if (i > j) swap(i, j);
    if (qs.count({i, j})) return qs[{i, j}];
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int x; cin >> x;
    if (x == -1) exit(0);
    return qs[{i, j}] = x;
}

void ans(int i, int j) {
    if (i > j) swap(i, j);
    cout << "! " << i + 1 << " " << j + 1 << endl;
    cin >> i; if (i == -1) exit(0);
}

void solve() {
    int n; cin >> n;
    qs.clear();

    int j = -1, mx = 1;
    for (int i = 0; i + 1 < n; i++) {
        int x = ask(i, i + 1);
        if (x > mx) {
            mx = x;
            j = i;
        }
    }

    if (j == -1)
        return ans(0, n - 1);
    if (mx >= (n + 1) / 2)
        return ans(j, j + 1);

    v<int> curr;
    for (int i = 0; i < n; i++)
        if (i != j) {
            int x = ask(i, j);
            if (x >= (n + 1) / 2)
                return ans(i, j);
            if (x > mx) {
                curr = {i};
                mx = x;
            }
            else if (x == mx)
                curr.push_back(i);
        }

    while (curr.size() > 2) {
        j = curr[0];
        v<int> nxt;
        for (int i = 1; i < (int) curr.size(); i++) {
            int x = ask(j, curr[i]);
            if (x >= (n + 1) / 2)
                return ans(curr[i], j);
            if (x > mx) {
                nxt = {curr[i]};
                mx = x;
            }
            else if (x == mx)
                nxt.push_back(curr[i]);
        }
        nxt.swap(curr);
    }

    if (curr.size() == 1)
        return ans(j, curr[0]);
    if (curr.size() == 2)
        return ans(curr[0], curr[1]);
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}