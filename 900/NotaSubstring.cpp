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
        string s; cin >> s;
        int n = s.size();

        if (n == 2 and s[0] == '(' and s[1] == ')') {
            cout << "NO" nl;
            continue;
        }

        bool alt = 1;
        for (int i = 0; i < n - 1 and alt; i++)
            if (s[i] == s[i + 1])
                alt = 0;
        
        cout << "YES" nl;
        if (alt) {
            for (int i = 0; i < n; i++)
                cout << '(';
            for (int i = 0; i < n; i++)
                cout << ')';
        }
        else
            for (int i = 0; i < n; i++)
                cout << "()";
        cout nl;
    }

    return 0;
}