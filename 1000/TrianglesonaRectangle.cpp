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
        int w, h; cin >> w >> h;

        int answ = 0;
        for (int i = 0; i < 4; i++) {
            int min = INF, max = -1;
            int k; cin >> k;

            while (k--) {
                int a; cin >> a;
                min = std::min(min, a);
                max = std::max(max, a);
            }

            answ = std::max(answ, (max - min) * (i < 2 ? h : w));
        }
        cout << answ nl;
    }

    return 0;
}