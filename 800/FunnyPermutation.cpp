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

        if (n == 3) {
            cout << -1 nl;
            continue;
        }
        else if (n == 5) {
            cout << "3 4 5 1 2" nl;
            continue;
        }

        vi nums(n);
        for (int i = 0; i < n; i++)
            nums[i] = n - i;
        if (n & 1)
            swap(nums[n / 2], nums[n / 2 + 1]);
    
        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout nl;
    }

    return 0;
}