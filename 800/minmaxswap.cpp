#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vi a(n);
        vi b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];
        
        for (int i = 0; i < n; i++)
            if (a[i] > b[i])
                swap(a[i], b[i]);
        
        cout << *max_element(all(b)) * *max_element(all(a)) nl;
    }

    return 0;
}