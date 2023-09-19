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

        int max = 0;
        int current = 0;

        vi nums(n);
        
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        current = (nums[0] == 0);

        for (int i = 1; i < n; i++) {
            if (nums[i] == 0)
                current++;
            else {
                if (current > max)
                    max = current;
                current = 0;
            }
        }

        if (current > max)
            max = current;

        cout << max nl;
    }

    return 0;
}