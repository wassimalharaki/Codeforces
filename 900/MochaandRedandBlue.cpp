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

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;

        int start = 1;
        if (s[0] == '?') {
            int first = 0;
            for (int i = 0; i < n; i++)
                if (s[i] != '?') {
                    first = i;
                    break;
                }
            start = first + 1;

            if (not first) {
                v<char> color{'R', 'B'};
                for (int i = 0; i < n; i++)
                    cout << color[i & 1];
                cout nl;
                continue;
            }
            for (int i = first - 1; i >= 0; i--)
                s[i + 1] == 'R' ? s[i] = 'B' : s[i] = 'R';
        }
        
        for (int i = start; i < n; i++)
            if (s[i] == '?')
                s[i - 1] == 'R' ? s[i] = 'B' : s[i] = 'R';
        cout << s nl;
    }

    return 0;
}