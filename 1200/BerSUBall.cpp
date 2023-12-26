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

    vi boys(n);
    for (int i = 0; i < n; i++)
        cin >> boys[i];
    sort(all(boys));

    int m; cin >> m;

    vi girls(m);
    for (int i = 0; i < m; i++)
        cin >> girls[i];
    sort(all(girls));

    int i = 0, j = 0, answ = 0;
    while (i < n and j < m)
        if (abs(boys[i] - girls[j]) <=  1)
            answ++, i++, j++;
        else if (boys[i] > girls[j])
            j++;
        else
            i++;
    cout << answ nl;
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}