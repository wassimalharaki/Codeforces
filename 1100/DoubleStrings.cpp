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

        v<pair<string, int>> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i].F, s[i].S = i;
        sort(all(s));

        v<bool> answ(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < s[i].F.size(); j++) {
                string left = s[i].F.substr(0, j);
                string right = s[i].F.substr(j);

                auto it_left = lower_bound(all(s), mp(left, -1ll));
                auto it_right = lower_bound(all(s), mp(right, -1ll));
                if (it_left == s.end() or it_right == s.end())
                    continue;
                if (it_left -> F == left and it_right -> F == right) {
                    answ[s[i].S] = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
            cout << answ[i];
        cout nl;
    }

    return 0;
}