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

    int k; cin >> k;

    vi nums(12);
    for (int i = 0; i < 12; i++)
        cin >> nums[i];
    sort(all(nums), greater<int>());

    int months = 0, height = 0;
    for (int i = 0; i < 12; i++)
        if (height >= k)
            break;
        else
            height += nums[i], months++;
    cout << (height >= k ? months : -1);

    return 0;
}