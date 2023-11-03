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
        int sum = 0;
        for (int i = 0; i < n; i++)
            cin >> nums[i], sum += nums[i];

        if (sum == 0) {
            cout << "NO" nl;
            continue;
        }
        
        cout << "YES" nl;
        sum > 0 ? sort(all(nums), greater<int>()) : sort(all(nums));
        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout nl;
    }

    return 0;
}