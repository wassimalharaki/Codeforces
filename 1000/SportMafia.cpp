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

int32_t main() {
    fast;

    int n, k; cin >> n >> k;

    int lo = 0, hi = 1e9 + 1;
    int min = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int tot = (1 + mid) * mid / 2;
        if (tot >= k)
            min = mid, hi = mid - 1;
        else
            lo = mid + 1;
    }

    int candies = (1 + min) * min / 2 - k;
    int extra = n - candies - min;

    lo = 0, hi = 1e9 + 1;
    int y = 0;
    while (lo <= hi) {
        int x = (lo + hi) / 2;
        int tot = (min + 1 + x) * (x - min) / 2 + (x - min);
        if (tot == extra) {
            y = (min + 1 + x) * (x - min) / 2;
            break;
        }
        else if (tot > extra)
            hi = x - 1;
        else
            lo = x + 1;
    }
    cout << candies + y nl;

    return 0;
}