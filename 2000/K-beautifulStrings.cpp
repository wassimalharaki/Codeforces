#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#define v vector

const int N = 26;

bool valid(array<int, N>& cnt, int n, int k) {
    int y = 0;
    for (int& x : cnt) {
        if (x % k)
            return 0;
        y += x;
    }
    return y == n;
}

array<int, N> best(array<int, N> cnt, int n, int k) {
    int x = 0;
    for (int i = 0; i < N; i++) {
        cnt[i] += (k - cnt[i] % k) % k;
        x += cnt[i];
    }
    cnt[0] += max(0, n - x);
    return cnt;
}

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    if (n % k) {
        cout << -1 << nl;
        return;
    }

    array<int, 26> cnt; cnt.fill(0);
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    
    if (valid(cnt, n, k)) {
        cout << s << nl;
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        cnt[s[i] - 'a']--;
        for (int j = s[i] - 'a' + 1; j < N; j++) {
            cnt[j]++;
            auto curr = best(cnt, n, k);
            if (valid(curr, n, k)) {
                for (int l = 0; l < i; l++)
                    cout << s[l], curr[s[l] - 'a']--;
                cout << char('a' + j);
                curr[j]--;
                for (int l = 0; l < N; l++)
                    cout << string(curr[l], char('a' + l));
                cout << nl;
                return;
            }
            cnt[j]--;
        }
    }
    cout << -1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}