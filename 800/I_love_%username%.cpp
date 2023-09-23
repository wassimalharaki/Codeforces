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

    int n, p, min, max, amazing = 0;

    cin >> n >> p;
    max = min = p;

    for (int i = 1; i < n; i++) {
        cin >> p;
        if (p > max) {
            amazing++;
            max = p;
        }
        if (p < min) {
            amazing++;
            min = p;
        }
    }

    cout << amazing;

    return 0;
}