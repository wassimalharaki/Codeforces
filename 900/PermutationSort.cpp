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
        
        int sorted = 1;
        for (int i = 0; i < n - 1; i++)
            if (nums[i] > nums[i + 1]) {
                sorted = 0;
                break;
            }
        
        if (sorted)
            cout << 0 nl;
        else if (nums[0] == 1 || nums[n - 1] == n)
            cout << 1 nl;
        else if (nums[n - 1] == 1 && nums[0] == n)
            cout << 3 nl;
        else
            cout << 2 nl;
    }

    return 0;
}