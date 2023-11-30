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

        vi a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] - a[i] == 0)
                continue;
            count++;
            if (b[i] - a[i] <= 0)
                count += 2;
            while (i + 1 < n and b[i] - a[i] == b[i + 1] - a[i + 1])
                i++;
        }
        cout << (count <= 1 ? "YES" : "NO") nl;
    }

    return 0;
}