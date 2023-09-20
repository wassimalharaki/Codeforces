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
        int s; cin >> s;
        int answ = 0;
        int sum = 0;
        for (int i = 1; true; i += 2)
            if (sum + i < s) {
                sum += i;
                answ++;
            }
            else {
                answ++;
                break;
            }

        cout << answ nl;
    }

    return 0;
}