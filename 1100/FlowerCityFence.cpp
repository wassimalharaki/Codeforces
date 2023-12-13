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

        vi fences;
        int sub = 0;
        for (int i = n - 1; i >= 0 and fences.size() <= n; i--) {
            while (nums[i] - sub > 0 and fences.size() <= n)
                fences.pb(i + 1), sub++;
        }
        cout << (fences == nums ? "YES" : "NO") nl;
    }

    return 0;
}