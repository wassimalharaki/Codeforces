#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

void solve() {
    int n, k; cin >> n >> k;
    
    vi a(n), h(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    
    int answ = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = i + 1;
        while (r < n and h[r - 1] % h[r] == 0)
            r++;
        int curr = 0, sum = 0;
        for (int j = l; j < r; j++) {
            sum += a[j];
            curr++;
            while (sum > k) {
                sum -= a[l++];
                curr--;
            }
            answ = max(answ, curr);
        }
        i = r - 1;
    }
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}