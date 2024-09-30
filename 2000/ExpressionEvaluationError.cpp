#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

const int N = 11;

void solve() {
    string s; cin >> s;
    int n; cin >> n;

    v<int> a(N);
    for (int i = 0; i < (int) s.size(); i++)
        a[s.size() - i - 1] = s[i] - '0';

    int x = accumulate(a.begin(), a.end(), 0ll);
    auto f = [&](int i, auto&& f) -> void {
        if (x >= n or not i) return;
        while (a[i] and x < n) {
            a[i]--;
            a[i - 1] += 10;
            x += 9;
            f(i - 1, f);
        }
    };

    for (int i = 1; i < N and x < n; i++)
        f(i - 1, f);

    int k = 0;
    v b(n, v<int>(N));
    for (int i = N - 1; i >= 0; i--)
        while (a[i]--) {
            b[k][i]++;
            k = (k + 1) % n;
        }
    
    for (int i = 0; i < n; i++) {
        string t;
        for (int j = N - 1; j >= 0; j--)
            t += char('0' + b[i][j]);
        cout << stoll(t) << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}