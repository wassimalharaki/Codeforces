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

        vi nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];
        int count = 0;
        int currnb;
        for (int i = 0; i < n - 1; i++) {
            if ((double) max(nums[i], nums[i + 1]) / min(nums[i], nums[i + 1]) > 2) {
                if (nums[i] > nums[i + 1]) {
                    currnb = nums[i];
                    while ((double) max(currnb, nums[i + 1]) / min(currnb, nums[i + 1]) > 2) {
                        currnb = (currnb + 1) / 2;
                        count++;
                    }
                }
                else {
                    currnb = nums[i];
                    while ((double) max(currnb, nums[i + 1]) / min(currnb, nums[i + 1]) > 2) {
                        currnb = 2 * currnb;
                        count++;
                    }
                }
            }
        }

        cout << count nl;
    }

    return 0;
}