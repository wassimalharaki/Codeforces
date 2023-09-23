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
        int n; cin >> n;
        string s; cin >> s;
        vi check(5, 0);

        if (n != 5) {
            cout << "NO" nl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == 'T')
                check[0] = 1;
            else if (s[i] == 'i')
                check[1] = 1;
            else if (s[i] == 'm')
                check[2] = 1;
            else if (s[i] == 'u')
                check[3] = 1;
            else if (s[i] == 'r')
                check[4] = 1;
        }
        
        if (*min_element(all(check)))
            cout << "YES" nl;
        else
            cout << "NO" nl;
    }

    return 0;
}