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
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        sort(all(nums));

        int dist = 1;
        for (int i = 1; i < n; i++)
            if (nums[i] != nums[i - 1])
                dist++;

        for (int i = 0; i < dist; i++)
            cout << dist << " ";
        for (int i = dist + 1; i <= n; i++)
            cout << i << " ";
        cout nl;
    }

    return 0;
}