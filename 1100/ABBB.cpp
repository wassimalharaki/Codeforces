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

        int a = 0, b = 0;
        for (int i = n - 1; i >= 0; i--) {
            s[i] == 'A' ? a++ : b++;

            if (a and b == 0)
                a = 0;
            else if (a and b)
                n -= 2, b--, a--;
        }
        cout << n - b / 2 * 2 nl;
    }

    return 0;
}