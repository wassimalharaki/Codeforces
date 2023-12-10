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

    return divs;
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int l, r; cin >> l >> r;
        if (l == r) {
            if (!(r & 1)) {
                if (r == 2)
                    cout << -1 nl;
                else
                    cout << r / 2 << " " << r / 2 nl;
                continue;
            }

            vi divs = divisors(l);

            if (divs.size() == 1)
                cout << -1 nl;
            else
                cout << divs[1] << " " << l - divs[1] nl;
            continue;
        }
        
        if (r & 1) r--;
        if (r == 2)
            cout << -1 nl;
        else
            cout << r / 2 << " " << r / 2 nl;
    }

    return 0;
}