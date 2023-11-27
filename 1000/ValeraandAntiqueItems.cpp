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

    int n, u; cin >> n >> u;

    vi sellers;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        bool can = 0;
        for (int j = 0; j < k; j++) {
            int a; cin >> a;
            if (u > a and not can) {
                can = 1;
                sellers.pb(i + 1);
            }
        }
    }

    cout << sellers.size() nl;
    for (int i = 0; i < sellers.size(); i++)
        cout << sellers[i] << " ";

    return 0;
}