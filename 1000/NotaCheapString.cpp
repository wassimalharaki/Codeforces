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
        string s; cin >> s;
        int p; cin >> p;
        int n = s.size();

        vi flags(n, 1);
        v<pair<char, int>> positions(n);
        int price = 0;
        for (int i = 0; i < n; i++) {
            positions[i].F = s[i];
            positions[i].S = i;
            price += s[i] - 'a' + 1;
        }
        sort(rall(positions));

        for (int i = 0; i < n; i++) {
            if (price <= p)
                break;
            price -= positions[i].F - 'a' + 1;
            flags[positions[i].S] = 0;
        }
        for (int i = 0; i < n; i++)
            if (flags[i])
                cout << s[i];
        cout nl;
    }

    return 0;
}