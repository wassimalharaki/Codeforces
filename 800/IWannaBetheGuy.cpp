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
#define F first
#define S second

int32_t main() {
    fast

    int n, p; cin >> n >> p;

    vi lvls(n, 0);

    for (int i = 0; i < p; i++) {
        int l; cin >> l;
        lvls[l - 1] = 1;
    }

    int q; cin >> q;

    for (int i = 0; i < q; i++) {
        int l; cin >> l;
        lvls[l - 1] = 1;
    }

    if (*min_element(all(lvls)))
        cout << "I become the guy.";
    else
        cout << "Oh, my keyboard!";

    return 0;
}