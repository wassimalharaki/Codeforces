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

int32_t main() {
    fast;

    int n, k; cin >> n >> k;
    string s; cin >> s;

    if (k == 0) {
        cout << s;
        return 0;
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    if (s[0] != '1')
        s[0] = '1', k--;
    
    for (int i = 1; i < n and k; i++)
        if (s[i] != '0')
            s[i] = '0', k--;
    cout << s nl;

    return 0;
}