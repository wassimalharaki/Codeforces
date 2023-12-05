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
        int a, b, c; cin >> a >> b >> c;

        string answ = "NO";
        int lo = 1, hi = 1e8;
        while (lo <= hi) {
            int A = a, B = b, C = c;
            int mid = (lo + hi) / 2;
            int shots = 6 * mid;
            A -= mid; B -= mid; C -= mid;
            if (A < 0 or B < 0 or C < 0) {
                hi = mid - 1;
                continue;
            }
            int sub = min(shots, A);
            A -= sub;
            shots -= sub;
            sub = min(shots, B);
            B -= sub;
            shots -= sub;
            sub = min(shots, C);
            C -= sub;
            shots -= sub;

            if (A == 0 and B == 0 and C == 0 and shots == 0) {
                answ = "YES";
                break;
            }
            else if (A > 0 or B > 0 or C > 0)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        cout << answ nl;
    }

    return 0;
}