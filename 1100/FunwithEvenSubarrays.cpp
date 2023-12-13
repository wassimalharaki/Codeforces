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
        
        int ops = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == nums[n - 1])
                continue;
            int k = n - 1 - i;
            int l = max(n - 2 * k, 0ll);
            for (int j = 0; j < k; j++)
                nums[l + j] = nums[n - 1];
            ops++;
            i = l;
        }
        cout << ops nl;
    }

    return 0;
}