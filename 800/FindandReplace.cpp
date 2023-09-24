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

        vi letters(26, -1);
        letters[s[0] - 'a'] = 0;
        for (int i = 1; i < n; i++)
            if (letters[s[i] - 'a'] == -1)
                letters[s[i] - 'a'] = not letters[s[i - 1] - 'a'];

        bool can = 1;
        for (int i = 0; i < n - 1; i++)
            if (letters[s[i] - 'a'] == letters[s[i + 1] - 'a']) {
                can = 0;
                break;
            }
        can ? cout << "YES" nl : cout << "NO" nl;
    }

    return 0;
}