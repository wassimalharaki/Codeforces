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

    v<pii> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i].F, nums[i].S = i + 1;
    sort(all(nums), greater<pii>());

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += i * nums[i].F + 1;

    cout << sum nl;
    for (int i = 0; i < n; i++)
        cout << nums[i].S << " ";

    return 0;
}