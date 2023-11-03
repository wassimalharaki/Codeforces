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
        int n, k; cin >> n >> k;

        vi nums(n * k);
        for (int i = 0; i < n * k; i++)
            cin >> nums[i];
        
        int sum = 0;
        for (int i = 1; i <= k; i++)
            sum += nums[n * k - i * (n / 2 + 1)];
        cout << sum nl;
    }

    return 0;
}