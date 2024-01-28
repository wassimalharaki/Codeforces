#include <bits/stdc++.h>

using namespace std;

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

vi fib(1e5 + 2);
const int mod = 1e9 + 7;

void solve() {
    string s; cin >> s;

    if (count(all(s), 'w') or count(all(s), 'm')) {
        cout << 0;
        return;
    }

    int ans = 1, a = 0, b = 0;
    for (char& c : s)
        if (c == 'u') {
            a++;
            ans = (ans * fib[b]) % mod;
            b = 0;
        }
        else if (c == 'n') {
            b++;
            ans = (ans * fib[a]) % mod;
            a = 0;
        }
        else {
            ans = (ans * fib[a]) % mod;
            ans = (ans * fib[b]) % mod;
            a = b = 0;
        }
    ans = (ans * fib[a]) % mod;
    ans = (ans * fib[b]) % mod;
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fib[0] = 1, fib[1] = 1;
    for (int i = 2; i < fib.size(); i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}