#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        
        int count = 0, last;
        for (int i = n - 1; i >= 0 and count < k; i--)
            if (nums[i] == nums[n - 1])
                count++, last = i;
        if (count != k) {
            cout << "NO" nl;
            continue;
        }

        count = 0;
        int first;
        for (int i = 0; i < n and count < k; i++)
            if (nums[i] == nums[0])
                count++, first = i;
        if (count != k) {
            cout << "NO" nl;
            continue;
        }

        cout << (first < last ? "YES" : nums[0] == nums[n - 1] ? "YES" : "NO") nl;
    }

    return 0;
}