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

    vpii nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i].F, nums[i].S = i;
    sort(all(nums));

    vpii answ;
    int of = nums[0].F;
    for (int i = 1; i < n; i++) {
        if (nums[i].F % of == 0) {
            of = nums[i].F;
            continue;
        }
        int be = (nums[i].F / of + 1) * of;
        answ.pb(mp(nums[i].S + 1, be - nums[i].F));
        of = be;
    }
    cout << answ.size() nl;
    for (int i = 0; i < answ.size(); i++)
        cout << answ[i].F << " " << answ[i].S nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;

    while(T--)
        solve();

    return 0;
}