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

    string s, t; cin >> s >> t;

    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        while (t[j] != s[i] && j < t.size())
            j++;
        if (j++ >= t.size()) {
            cout << i + 1 nl;
            break;
        }
    }

    return 0;
}