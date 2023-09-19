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
        int sum = 0;
        string answ;
        for (int i = 9; i > 0; i--) {
            if (i + sum < s) {
                answ += to_string(i);
                sum += i;
            }
            else if (i + sum == s) {
                answ += to_string(i);
                break;
            }
            else {
                answ += to_string(s - sum);
                break;
            }
        }
        for (int i = answ.size() - 1; i >= 0; i--) {
            cout << answ[i];
        }
        cout nl;
    }

    return 0;
}