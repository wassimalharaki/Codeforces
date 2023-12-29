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

    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divs.push_back(i);

    for (int i = divs.size() - 1; i >= 0; i--)
        if (n / divs[i] != divs[i])
            divs.push_back(n / divs[i]);

    return divs;
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    
    int diff = y - x;
    vi divs = divisors(diff);
    for (int i = 0; i < divs.size(); i++) {
        int count = diff / divs[i] + 1;
        if (n >= count) {
            vi nums;
            for (int j = x; j <= y; j += divs[i])
                nums.pb(j), n--;
            reverse(all(nums));
            for (int j = x - divs[i]; j > 0 and n; j -= divs[i])
                nums.pb(j), n--;
            reverse(all(nums));
            for (int j = y + divs[i]; n; j += divs[i])
                nums.pb(j), n--;
            
            for (int j = 0; j < nums.size(); j++)
                cout << nums[j] << " ";
            cout nl;
            return;
        }
    }
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}