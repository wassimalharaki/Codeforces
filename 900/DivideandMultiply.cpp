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
        int n; cin >> n;

        vi nums(n);
        int multiples = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            while (!(nums[i] & 1))
                nums[i] /= 2, multiples++;
        }
        sort(all(nums));
        nums[n - 1] *= pow(2, multiples);

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        cout << sum nl;
    }

    return 0;
}