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
        int q; cin >> q;

        vi nums(q);
        for (int i = 0; i < q; i++)
            cin >> nums[i];

        int i = 1; cout << 1;
        int last = nums[0], prev = -INF;
        for (; i < q; i++) {
            if (prev == -INF and nums[i] >= last)
                last = nums[i], cout << 1;
            else {
                if (nums[i] <= nums[0] and nums[i] >= prev)
                    prev = nums[i], cout << 1;
                else
                    cout << 0;
            }
        }
        
        cout nl;
    }

    return 0;
}