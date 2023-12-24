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

void solve() {
    int n; cin >> n;

    map<string, string> handles;
    v<string> orig;
    for (int i = 0; i < n; i++) {
        string s1, s2; cin >> s1 >> s2;
        if (handles.find(s1) == handles.end())
            orig.pb(s1);
        handles[s1] = s2;
        handles[s2] = "-";
    }

    cout << orig.size() nl;
    for (int i = 0; i < orig.size(); i++) {
        cout << orig[i] << " ";
        while (handles[orig[i]] != "-")
            orig[i] = handles[orig[i]];
        cout << orig[i] nl;
    }
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;

    while (T--)
        solve();

    return 0;
}