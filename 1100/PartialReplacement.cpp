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
        int n, k; cin >> n >> k;
        string s; cin >> s;

        if (count(all(s), '*') == 1) {
            cout << 1 nl;
            continue;
        }

        vi pos;
        for (int i = 0; i < n; i++)
            if (s[i] == '*')
                pos.pb(i);
        n = pos.size();

        int left = 0, right = n - 1, count = 2;
        int i = 1;
        while (pos[right] - pos[left] > k) {
            if (pos[i] - pos[left] > k)
                left = i - 1, count++;
            i++;
        }
        cout << count nl;
    }

    return 0;
}