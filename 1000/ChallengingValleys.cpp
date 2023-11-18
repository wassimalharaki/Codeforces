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
        int n; cin >> n;

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        
        int count = 0;
        for (int i = 0; i < n;) {
            int l = i, r = i;
            while (i + 1 < n and nums[i] == nums[i + 1])
                i++, r++;
            if (r == l)
                i++;

            if ((l == 0 or nums[l - 1] > nums[l])
                    and (r == n - 1 or nums[r + 1] > nums[r]))
                count++;
        }
        cout << (count == 1 ? "YES" : "NO") nl;
    }

    return 0;
}