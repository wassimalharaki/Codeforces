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
    int n; cin >> n;
    string s; cin >> s;

    vi nums(10);
    for (int i = 1; i < 10; i++)
        cin >> nums[i];
    
    int l = -1, r = n;
    for (int i = 0; i < s.size(); i++) {
        int a = s[i] - '0';
        if (l == -1) {
            if (nums[a] > a)
                l = i;
        }
        else if (r == n and nums[a] < a)
            r = i;
    }

    if (l == -1) {
        cout << s nl;
        return;
    }

    for (int i = l; i < r; i++)
        s[i] = char('0' + nums[s[i] - '0']);
    cout << s nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}