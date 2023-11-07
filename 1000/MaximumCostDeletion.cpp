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

int deletions(string& s) {
    string t;

    int n = s.size(), j = 0;
    char f = s[j];
    while (j < n and s[j] == f)
        t += s[j], j++;

    if (j == n)
        return 1;
    
    f = s[j];
    while (j < n and s[j] == f)
        j++;
    for (int i = j; i < n; i++)
        t += s[i];
    
    return 1 + deletions(t);
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        cout << (b >= 0 ? n * (a + b):
                          n * a + b * deletions(s)) nl;
    }

    return 0;
}