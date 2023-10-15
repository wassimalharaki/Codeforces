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

        vi zero, two, five, seven;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '0')
                zero.pb(i);
            else if (s[i] == '2')
                two.pb(i);
            else if (s[i] == '5')
                five.pb(i);
            else if (s[i] == '7')
                seven.pb(i);
        
        int answ = 20;
        if (not zero.empty()) {
            if (zero.size() >= 2)
                answ = s.size() - zero[zero.size() - 2] - 2;
                
            if (not five.empty()) {
                auto it = lower_bound(all(five), zero[zero.size() - 1]);
                if (it != five.begin())
                    --it, answ = min(answ, (int) s.size() - *it - 2);
            }
        }

        if (not five.empty()) {
            if (not two.empty()) {
                auto it = lower_bound(all(two), five[five.size() - 1]);
                if (it != two.begin())
                    --it, answ = min(answ, (int) s.size() - *it - 2);
            }

            if (not seven.empty()) {
                auto it = lower_bound(all(seven), five[five.size() - 1]);
                if (it != seven.begin())
                    --it, answ = min(answ, (int) s.size() - *it - 2);
            }
        }

        cout << answ nl;
    }

    return 0;
}