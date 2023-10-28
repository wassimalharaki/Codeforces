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
        int n, q; cin >> n >> q;
        string s; cin >> s;
        vi zeroes(n + 1), ones(n + 1);
        for (int i = 0; i < n; i++)
            zeroes[i + 1] = zeroes[i] + (s[i] == '0'),
            ones[i + 1] = ones[i] + (s[i] == '1');
        while (q--) {
            int l, r; cin >> l >> r;
            l--; r--;
            string answ = "NO";
            if (s[l] == '0') {
                if (zeroes[l] > 0)
                    answ = "YES";
            }
            else if (ones[l] > 0)
                answ = "YES";
            
            if (s[r] == '0') {
                if (zeroes[n] - zeroes[r + 1] > 0)
                    answ = "YES";
            }
            else if (ones[n] - ones[r + 1] > 0)
                answ = "YES";
            cout << answ nl;
        }
    }

    return 0;
}