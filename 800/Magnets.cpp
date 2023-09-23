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

    int n; cin >> n;
    char prev = '2';
    int groups = 1;

    for (int i = 0; i < n; i++) {
        char a, b; cin >> a >> b;
        if (a == prev)
            groups++;
        prev = b;
    }

    cout << groups;

    return 0;
}