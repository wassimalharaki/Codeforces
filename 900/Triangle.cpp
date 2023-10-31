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

    bool tri = 0, seg = 0;
    int n = 4;
    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(all(nums));

    for (int i = 0; i < n - 2; i++)
        if (nums[i] + nums[i + 1] > nums[i + 2])
            tri = 1;
    
    if (tri) {
        cout << "TRIANGLE" nl;
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (nums[i] + nums[j] == nums[k])
                    seg = 1;
    cout << (seg ? "SEGMENT" : "IMPOSSIBLE") nl;

    return 0;
}