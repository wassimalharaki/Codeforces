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

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        string s; cin >> s;
        int n = s.size();

        vi letters(26);
        for (int i = 0; i < n; i++) {
            char c = s[i];
            int seq = 1;
            while (i + 1 < n and s[i] == s[i + 1])
                i++, seq++;
            if (seq & 1)
                letters[c - 'a'] = 1;
        }


        for (int i = 0; i < 26; i++)
            if (letters[i])
                cout << (char) ('a' + i);
        cout nl;
    }

    return 0;
}