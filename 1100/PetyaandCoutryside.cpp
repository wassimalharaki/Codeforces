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

    int n; cin >> n;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int inc = 0, dec = 0, max = 0;
    for (int i = 0; i < n; i++) {
        inc = 1;

        int j = i;
        while (j + 1 < n and nums[j] <= nums[j + 1])
            inc++, j++;
        
        dec = 0;
        while (j + 1 < n and nums[j] >= nums[j + 1])
            dec++, j++;
        max = std::max(max, inc + dec);
    }
    cout << max nl;

    return 0;
}