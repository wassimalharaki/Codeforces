#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

struct Group {
    int l, r;
    Group(int a, int b) {
        l = a, r = b;
    }
};

void solve() {
    int n, k, x; cin >> n >> k >> x;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(all(nums));

    v<Group> groups; int g = 0;
    groups.pb(Group(nums[0], nums[0]));
    for (int i = 1; i < n; i++) {
        if (nums[i] - groups[g].r <= x) {
            groups[g].r = nums[i];
            continue;
        }
        groups.pb(Group(nums[i], nums[i]));
        g++;
    }
    g++;

    int answ = g;
    vi diff(g - 1);
    for (int i = 0; i < g - 1; i++)
        diff[i] = groups[i + 1].l - groups[i].r;
    sort(all(diff));

    for (int i = 0; i < g - 1 and k; i++) {
        int need = (diff[i] + x - 1) / x - 1;
        if (need <= k)
            k -= need, answ--;
        else
            k = 0;
    }
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}