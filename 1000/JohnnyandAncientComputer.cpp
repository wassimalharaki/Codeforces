#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int a, b; cin >> a >> b;

        if (a == b) {
            cout << 0 nl;
            continue;
        }

        if (a > b) {
            int count = 0;
            while (a > b) {
                if (a & 1) break;
                a /= 2;
                count++;
                if (a == b) break;
            }
            count = count / 3 + (count % 3) / 2 + (count % 3 == 1);
            cout << (a == b ? count : -1) nl;
        }
        else {
            int count = 0;
            while (b > a) {
                a *= 2;
                count++;
                if (a == b) break;
            }
            count = count / 3 + (count % 3) / 2 + (count % 3 == 1);
            cout << (a == b ? count : -1) nl;
        }
    }

    return 0;
}