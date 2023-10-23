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

bool comp (pii i, pii j) {
    return i.S < j.S;
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        int sum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a == 1)
                count++;
            sum += a;
        }
        int comp = 2 * count + (n - count);
        
        comp <= sum and n != 1 ? cout << "YES" nl : cout << "NO" nl;
    }

    return 0;
}