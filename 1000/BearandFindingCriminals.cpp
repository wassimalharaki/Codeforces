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

    int n, a; cin >> n >> a;
    a--;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int count = nums[a];
    for (int i = 1; a + i < n or a - i >= 0; i++)
        if (a + i >= n)
            count += nums[a - i];
        else if (a - i < 0)
            count += nums[a + i];
        else 
            count += 2 * (nums[a - i] & nums[a + i]);
    cout << count nl;

    return 0;
}