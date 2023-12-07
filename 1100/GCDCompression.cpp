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

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        vpii evens, odds;
        for (int i = 0; i < 2 * n; i++) {
            int a; cin >> a;
            a & 1 ? odds.pb({a, i + 1}) : evens.pb({a, i + 1});
        }
        if (evens.size() & 1)
            evens.pop_back(), odds.pop_back();
        else if (not evens.empty())
            evens.pop_back(), evens.pop_back();
        else
            odds.pop_back(), odds.pop_back();
        
        for (int i = 0; i < evens.size(); i += 2)
            cout << evens[i].S << " " << evens[i + 1].S nl;
        for (int i = 0; i < odds.size(); i += 2)
            cout << odds[i].S << " " << odds[i + 1].S nl;
    }

    return 0;
}