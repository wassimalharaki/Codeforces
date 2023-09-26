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

    int n; cin >> n;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int s1, s2, min = INF;
    for (int i = 0; i < n; i++) {
        int diff = abs(nums[i] - nums[(i + 1) % n]);
        if (diff < min) {
            min = diff;
            s1 = i + 1;
            s2 = (i + 1) % n + 1;
        }
        if (not diff)
            break;
    }
    cout << s1 << " " << s2;

    return 0;
}