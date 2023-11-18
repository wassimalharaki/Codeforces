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
        int n; cin >> n;

        vi p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        
        string s; cin >> s;

        int ones = count(all(s), '1');

        vi q(n, INF);
        vi count(n + 1);
        for (int i = 0; i < n; i++)
            if (s[i] == '1' and p[i] > n - ones)
                q[i] = p[i], count[p[i]] = 1;
            else if (s[i] == '0' and p[i] <= n - ones)
                q[i] = p[i], count[p[i]] = 1;

        vi left, right;
        for (int i = 1; i <= n; i++)
            if (not count[i])
                i > n - ones ? right.pb(i) : left.pb(i);
        
        map<int, int> m;
        for (int i = 0; i < left.size(); i++) {
            m[left[i]] = right[i];
            m[right[i]] = left[i];
        }

        for (int i = 0; i < q.size(); i++)
            if (q[i] == INF)
                q[i] = m[p[i]];

        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
        cout nl;
    }

    return 0;
}