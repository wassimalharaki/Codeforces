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

int32_t main() {
    fast

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vi nums;
        vi check(n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            int a; cin >> a;
            if (not check[a]) {
                check[a] = 1;
                nums.push_back(a);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout nl;
    }

    return 0;
}