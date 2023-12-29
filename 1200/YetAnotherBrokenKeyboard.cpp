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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vi letters(26);
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        letters[c - 'a'] = 1;
    }

    int answ = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        if (letters[s[i] - 'a']) {
            curr++;
            continue;
        }
        answ += curr * (curr + 1) / 2;
        curr = 0;
    }
    answ += curr * (curr + 1) / 2;
    cout << answ nl;
}

int32_t main() {
    fast;

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}