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

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        sort(all(nums));

        int rep = 1, curr = 1;
        for (int i = 0; i < n - 1; i++)
            nums[i] == nums[i + 1] ?
                curr++, rep = max(rep, curr):
                curr = 1;

        if (rep == n) {
            cout << 0 nl;
            continue;
        }
        
        int lo = 0, hi = 31, k;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int comp = rep * (1 << mid);
            if (comp < n)
                lo = mid + 1;
            else if (comp > n)
                hi = mid - 1, k = mid;
            else {
                k = mid;
                break;
            }
        }
        cout << k + rep * ((1 << k) - 1) - 2 * rep * (1 << (k - 1)) + n nl;
    }

    return 0;
}