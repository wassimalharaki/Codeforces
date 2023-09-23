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

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        for (int i = 0; i < n; i++) {
            int b; cin >> b;
            string s; cin >> s;

            nums[i] += count(s.begin(), s.end(), 'D') % 10;
            nums[i] -= count(s.begin(), s.end(), 'U') % 10;
            if (nums[i] < 0)
                nums[i] += 10;
            nums[i] %= 10;
        }

        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout nl;
    }

    return 0;
}