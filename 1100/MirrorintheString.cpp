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
        int n; cin >> n;
        string s; cin >> s;

        string a{s[0]};
        string b(a);
        bool stop = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] > s[i - 1])
                break;
            b.pb(s[i]);
            if (s[i] < s[i - 1] and not stop)
                a.pb(s[i]);
            else
                stop = 1;
        }

        string rev = a;
        reverse(all(rev));
        a = a + rev;
        rev = b;
        reverse(all(rev));
        b = b + rev;
        a = min(a, b);

        cout << a nl;
    }

    return 0;
}