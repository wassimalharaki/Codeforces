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

        vi nums(n); cin >> nums[0];
        bool can = 1;
        for (int i = 1; i < n; i++) {
            int a; cin >> a; //a = |nums[i] - nums[i - 1]|
            // nums[i] = a + nums[i - 1] or nums[i] = nums[i - 1] - a
            int left = a + nums[i - 1];
            int right = nums[i - 1] - a;
            if (left >= 0 and right >= 0 and left != right)
                can = 0;
            nums[i] = max(left, right);
        }
        if (can)
            for (int i = 0; i < n; i++)
                cout << nums[i] << " ";
        else
            cout << -1;
        cout nl;
    }

    return 0;
}