#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
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
    string s, t, p; cin >> s >> t >> p;

    int i = 0, j = 0;
    while (i < t.size() and j < s.size())
        if (t[i++] == s[j])
            j++;
    
    if (j != s.size()) {
        cout << "NO" << nl;
        return;
    }

    vi letters_s(26), letters_t(26), letters_p(26);
    for (char& c : t)
        letters_t[c - 'a']++;
    for (char& c : s)
        letters_s[c - 'a']++;
    for (char& c : p)
        letters_p[c - 'a']++;
    
    for (int i = 0; i < 26; i++)
        if (letters_t[i] - letters_s[i] > letters_p[i]) {
            cout << "NO" << nl;
            return;
        }
    cout << "YES" << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}