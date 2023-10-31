#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
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
        int n; cin >> n;

        int count = 0, perfect = 1;
        int prev; cin >> prev;
        if (prev) count++, perfect = 0;
        for (int i = 1; i < n; i++) {
            int a; cin >> a;
            if (a) {
                perfect = 0;
                if (prev == 0)
                    count++;
            }
            prev = a;
        }
        cout << (perfect ? 0 : count == 1 ? 1 : 2) nl;
    }

    return 0;
}