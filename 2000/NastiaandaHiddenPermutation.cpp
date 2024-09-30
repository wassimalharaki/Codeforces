#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int ask(int t, int x, int i, int j) {
    cout << "? " << t << " " << i + 1
         << " " << j + 1 << " " << x << endl;
    cin >> x;
    assert(x != -1);
    return x;
}

void answer(v<int>& a) {
    cout << "! ";
    for (int& x : a)
        cout << x << " ";
    cout << endl;
}
void solve() {
    int n; cin >> n;

    v<int> ans(n), store;
    int k = -1;
    for (int i = 0; i + 1 < n; i += 2) {
        int x = ask(2, 1, i, i + 1);
        if (x == 1)
            k = i, ans[k] = 1;
        else if (x == 2)
            store.push_back(i + 1);
    }
    if (n & 1)
        for (int i : {n - 2}) {
            int x = ask(2, 1, i, i + 1);
            if (x == 1)
                k = i, ans[k] = 1;
            else if (x == 2)
                store.push_back(i + 1);
        }

    if (k == -1) {
        if (store.size() == 1)
            k = store[0], ans[k] = 1;
        else {
            int a = store[0], b = store[1];
            if (ask(1, 1, b, a) == 1)
                k = a, ans[k] = 1;
            else
                for (int i = 1; i < (int) store.size(); i++)
                    if (ask(1, 1, a, store[i]) == 1) {
                        k = store[i], ans[k] = 1;
                        break;
                    }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == k) continue;
        ans[i] = ask(1, n - 1, k, i);
    }
    answer(ans);
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}