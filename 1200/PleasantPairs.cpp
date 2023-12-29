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

vi divisors(int n) {
    vi divs;

    for (int i = 1; i * i < n; i++)
        if (n % i == 0)
            divs.push_back(i);

    return divs;
}

void solve() {
    int n; cin >> n;

    vpii nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i].F, nums[i].S = i + 1;
    sort(all(nums));

    int answ = 0;
    for (int i = 3; i < 2 * n; i++) {
        vi divs = divisors(i);
        for (int j = 0; j < divs.size(); j++) {
            int l = divs[j], r = i / divs[j];
            auto it = lower_bound(all(nums), mp(l, -1ll));
            if (it == nums.end() or it -> F != l)
                continue;
            auto it2 = lower_bound(all(nums), mp(r, -1ll));
            if (it2 == nums.end() or it2 -> F != r)
                continue;
            if (it -> S + it2 -> S == i)
                answ++;
        }
    }
    cout << answ nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}