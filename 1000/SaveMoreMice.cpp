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

        vi nums(k);
        for (int i = 0; i < k; i++) 
            cin >> nums[i];
        sort(rall(nums));

        int cat = 0, count = 0;
        for (int i = 0; i < k; i++)
            if (nums[i] > cat)
                count++, cat += n - nums[i];
            else
                break;
        cout << count nl;
    }

    return 0;
}