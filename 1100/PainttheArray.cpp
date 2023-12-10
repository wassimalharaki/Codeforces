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

        int even = -1, odd = -1;
        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (i & 1)
                odd == -1 ? odd = nums[i] : odd = gcd(odd, nums[i]);
            else
                even == -1 ? even = nums[i] : even = gcd(even, nums[i]);                
        }

        bool can = 1;
        for (int i = 1; i < n; i += 2)
            if (nums[i] % even == 0) {
                can = 0;
                break;
            }
        
        if (can) {
            cout << even nl;
            continue;
        }

        can = 1;
        for (int i = 0; i < n; i += 2) {
            if (nums[i] % odd == 0) {
                can = 0;
                break;
            }
        }

        cout << (can ? odd : 0) nl;
    }

    return 0;
}