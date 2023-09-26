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
        int n; cin >> n;

        vi nums(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += abs(nums[i]);
        }

        int steps = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] < 0) {
                steps++;
                while (nums[i] <= 0 && i < n)
                    i++;
            }
        cout << sum << " " << steps nl;
    }

    return 0;
}