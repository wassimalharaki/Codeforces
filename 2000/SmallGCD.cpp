#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

int c2(int x) { return x * (x - 1) / 2; }
int c3(int x) { return x * (x - 1) * (x - 2) / 6; }

const int N = 1e5 + 1;
v<v<int>> divisors(N);

void solve() {
    int n; cin >> n;

    v<int> a(n), cnt(N), mult(N), curr(N);
    for (int& x : a)
        cin >> x, cnt[x]++;

    int gt = n, ans = 0;
    for (int i = 1; i < N; i++) {
        if (cnt[i] == 0) continue;
        int y = cnt[i]; gt -= y;
        ans += gt * c2(y) * i + c3(y) * i;
        
        for (int& d : divisors[i]) {
            if (i == d) continue;
            ans += gt * y * curr[d] * d + c2(y) * curr[d] * d;
            for (int& b : divisors[d])
                if (i % b == 0)
                    curr[b] -= curr[d];
        }

        for (int& d : divisors[i])
            curr[d] = mult[d] += y;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < N; i++) {
        sort(divisors[i].rbegin(), divisors[i].rend());
        for (int j = i; j < N; j += i)
            divisors[j].push_back(i);
    }
    int T = 1;
    cin >> T;
    while (T--) solve();
}