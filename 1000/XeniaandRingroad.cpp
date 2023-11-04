#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int n, m; cin >> n >> m;

    int time = 0, house = 1;
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        a >= house ?
            time += a - house:
            time += n - house + a;
        house = a;
    }
    cout << time nl;

    return 0;
}