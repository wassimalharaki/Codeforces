#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX

int32_t main() {
    fast

    int n, m; cin >> n >> m;
    int mx = max(n, m);
    int count = 0;

    for (int a = 0; a <= mx; a++)
        for (int b = 0; b <= mx; b++)
            if (a*a + b == n && b*b + a == m)
                count++;

    cout << count nl;

    return 0;
}