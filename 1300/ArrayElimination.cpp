#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
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
    int n; cin >> n;

    vi nums(n);
    for (int& a : nums) cin >> a;

    if (count(all(nums), 0ll) == n) {
        for (int i = 0; i < n; i++)
            cout << (i + 1) << " ";
        cout << nl;
        return;
    }

    vi bits(31);
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < n; j++)
            if ((1 << i) & nums[j])
                bits[i]++;
    
    int gcd = 0;
    for (int i = 0; i < 31; i++)
        gcd = std::gcd(gcd, bits[i]);
    vi divs = divisors(gcd);

    for (int i = 0; i < divs.size(); i++)
        cout << divs[i] << " ";
    cout << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}