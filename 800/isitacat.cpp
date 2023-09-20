#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        v<char> meow{'m', 'e', 'o', 'w'};
        vi check(4);
        int j = 0;
        string answ = "YES";
        
        for (int i = 0; i < n; i++) {
            char c; cin >> c; c = tolower(c);
            if (j >= 4)
                continue;
            if (c != meow[j]) {
                j++;
                if (j >= 4)
                    continue;
                if (c != meow[j]) {
                    j = 4;
                    continue;
                }
                else
                    check[j] = 1;
            }
            else
                check[j] = 1;
        }
        if (j != 3 || not *min_element(all(check)))
            answ = "NO";
        cout << answ nl;
    }

    return 0;
}