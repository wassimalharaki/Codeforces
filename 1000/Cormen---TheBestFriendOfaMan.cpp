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

    int n, k; cin >> n >> k;

    vi nums(n); cin >> nums[0];
    int answ = 0;
    for (int i = 1; i < n; i++) {
        cin >> nums[i];
        answ += max((int) 0, k - nums[i - 1] - nums[i]);
        nums[i] += max((int) 0, k - nums[i - 1] - nums[i]);
    }

    cout << answ nl;
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";

    return 0;
}