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

    int t; cin >> t;
    
    while (t--) {
        int n, s, r; cin >> n >> s >> r;

        vi nums(n, 1);
        nums[0] = s - r;
        int sum = (n - 1) + s - r;
        for (int i = 1; i < n; i++) {
            if (sum == s)
                break;
            nums[i] += min(s - sum, nums[0] - 1);
            sum += nums[i] - 1;
        }
        
        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout nl;
    }

    return 0;
}