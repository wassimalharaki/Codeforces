#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
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
    int a, b; cin >> a >> b;
    string s; cin >> s;
    int n = a + b;

    int zero = count(all(s), '0');
    int one = count(all(s), '1');

    for (int i = 0; i < n; i++)
        if (s[i] == '?' and s[n - i - 1] != '?') {
            s[i] = s[n - i - 1];
            s[i] == '1' ? one++ : zero++;
        }
        
    if ((zero ^ a) & 1) {
        if (!(n & 1) or s[n / 2] != '?') {
            cout << -1 nl;
            return;
        }
        zero++, s[n / 2] = '0';
    }

    if ((one ^ b) & 1) {
        if (!(n & 1) or s[n / 2] != '?') {
            cout << -1 nl;
            return;
        }
        one++, s[n / 2] = '1';
    }

    for (int i = 0; i < n / 2; i++)
        if (s[i] == '?') {
            if (zero < a)
                s[i] = s[n - i - 1] = '0', zero += 2;
            else
                s[i] = s[n - i - 1] = '1', one += 2;
        }

    if (zero > a or one > b) {
        cout << -1 nl;
        return;
    }
    
    bool ok = (count(all(s), '?') == 0);
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            ok = 0;
    cout << (ok ? s : "-1") nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}