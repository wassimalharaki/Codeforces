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

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        vi a(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        sort(all(a));
        sort(all(b));

        for (int i = 0; i < k; i++)
            if (b[n - i - 1] > a[i])
                swap(b[n - i - 1], a[i]);
            else
                break;

        int sum = 0;
        for (int i =0; i < n; i++)
            sum += a[i];

        cout << sum nl;
    }

    return 0;
}