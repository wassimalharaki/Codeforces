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
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                continue;
            while (i + 1 < n and nums[i + 1] >= 0)
                nums[i] *= -1, nums[i + 1] *= -1, i++;
            if (i + 1 < n)
                nums[i] *= -1, nums[i + 1] *= -1;
        }

        int neg = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] < 0)
                neg++, nums[i] = abs(nums[i]);
        sort(rall(nums));

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += (i < n - neg ? 1 : -1) * nums[i];
        cout << sum nl;
    }
 
    return 0;
}