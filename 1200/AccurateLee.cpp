#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int zero = 0, one = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            zero++;
        else
            break;
    
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == '1')
            one++;
        else
            break;

    if (zero + one == n)
        cout << s nl;
    else
        cout << string(zero, '0') + '0' + string(one, '1') nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}