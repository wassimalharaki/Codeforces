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
        if (n % 2050) {
            cout << -1 nl;
            continue;
        }

        string s = to_string(n / 2050);
        int answ = 0;
        for (int i = 0; i < s.size(); i++)
            answ += s[i] - '0';
        cout << answ nl;
    }

    return 0;
}