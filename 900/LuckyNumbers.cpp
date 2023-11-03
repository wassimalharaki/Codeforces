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
        int l, r; cin >> l >> r;

        int answ = 0, luck = 0;
        for (int i = l; i <= r; i++) {
            string s = to_string(i);
            char maxc = s[0], minc = s[0];
            for (int j = 0; j < s.size(); j++)
                maxc = max(maxc, s[j]), minc = min(minc, s[j]);
            if (maxc - minc >= luck) {
                luck = maxc - minc;
                answ = i;
            }
            if (luck == 9)
                break;
        }
        cout << answ nl;
    }

    return 0;
}