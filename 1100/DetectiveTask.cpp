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

        if (count(all(s), '?') == n) {
            cout << n nl;
            continue;
        }

        if (count(all(s), '1') == 0) {
            int answ = 0;
            for (int i = 0; i < n; i++) {
                answ++;
                if (s[i] == '0')
                    break;
            }
            cout << answ nl;
            continue;
        }

        if (count(all(s), '0') == 0) {
            int answ = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                    answ = 0;
                answ++;
            }
            cout << answ nl;
            continue;
        }

        int answ = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                answ = 0;
            answ++;
            if (s[i] == '0')
                break;
        }
        cout << answ nl;
    }

    return 0;
}