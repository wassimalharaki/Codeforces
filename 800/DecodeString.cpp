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

        string answ = "";
        for (int i = n - 1; i >= 0; i--)
            if (s[i] == '0')
                i -= 2, answ += (char) (96 + (s[i] - '0') * 10 + s[i + 1] -'0');
            else
                answ += (char) (96 + s[i] - '0');
        reverse(all(answ));
        cout << answ nl;
    }

    return 0;
}