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
        int n, k; cin >> n >> k;

        vpii nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i].F , nums[i].S = i;
        sort(all(nums));

        int count = 1;
        for (int i = 1; i < n; i++)
            if (nums[i].S != nums[i - 1].S + 1)
                count++;
        cout << (count <= k ? "YES" : "NO") nl;
    }

    return 0;
}