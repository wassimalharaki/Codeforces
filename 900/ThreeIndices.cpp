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
        
        vi left(n, -1), right(n, -1);
        int min = 0;
        for (int i = 1; i < n; i++)
            nums[i] > nums[min] ? left[i] = min : min = i;
        min = n - 1;
        for (int i = n - 2; i >= 0; i--)
            nums[i] > nums[min] ? right[i] = min : min = i;

        int found = 0;
        for (int i = 0; i < n; i++)
            if (left[i] != -1 && right[i] != -1) {
                found = 1;
                cout << "YES" nl << left[i] + 1 << " " << i + 1 << " " << right[i] + 1 nl;
                break;
            }
        
        if (not found)
            cout << "NO" nl;
    }

    return 0;
}