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

        if (s[0] != '9') {
            for (int i = 0; i < n; i++)
                cout << '9' - s[i];
            cout nl;
            continue;
        }

        string p{'1'};
        for (int i = 0; i < s.size() - 1; i++)
            p += '8';
        p += '1';
        reverse(all(p)); reverse(all(s));

        int carry = 0;
        string answ(n, '1');
        for (int i = 0; i < n; i++)
            if (p[i] - carry >= s[i])
                answ[n - i - 1] = char(p[i] - carry - s[i] + '0'), carry = 0;
            else
                answ[n - i - 1] = char(p[i] - carry - s[i] + 10 + '0'), carry = 1;

        cout << answ nl;
    }

    return 0;
}