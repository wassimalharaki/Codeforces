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

int ok(int n) {
    string s = to_string(n);
    return n + (*min_element(all(s)) - '0') * (*max_element(all(s)) - '0');
}

void solve() {
    int a, k; cin >> a >> k; k--;

    while (k--) {
        int ai = ok(a);
        if (ai == a)
            break;
        a = ai;
    }
    cout << a nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}