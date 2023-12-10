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

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int ones = count(all(nums), 1ll);
        int zeroes = count(all(nums), 0ll);

        if (zeroes >= ones) {
            cout << n - ones nl;
            for (int i = 0; i < n - ones; i++)
                cout << 0 << " ";
            cout nl;
        }
        else {
            int sz = (ones & 1 ? n - zeroes - 1 : n - zeroes);
            cout << sz nl;
            for (int i = 0; i < sz; i++)
                cout << 1 << " ";
            cout nl;
        }
    }

    return 0;
}