#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

void solve() {
    int n; cin >> n;
    string up = "UP";
    string down = "DOWN";
    string imp = "-1";


    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    if (nums[n - 1] == 0)
        cout << up;
    else if (nums[n - 1] == 15)
        cout << down;
    else if (n == 1)
        cout << imp;
    else
        cout << (nums[n - 1] > nums[n - 2] ? up : down);
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;

    while(T--)
        solve();

    return 0;
}