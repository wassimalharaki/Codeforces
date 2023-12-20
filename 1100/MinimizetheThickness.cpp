#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
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
        vi prefix(n + 1);
        for (int i = 0; i < n; i++)
            cin >> nums[i], prefix[i + 1] = nums[i] + prefix[i];
        
        int answ = n;
        for (int i = n - 2; i >= 0; i--) {
            int sum = prefix[i + 1];
            int max = i + 1;
            bool can = 1;
            int curr_sum = 0;
            int curr_length = 0;
            for (int j = i + 1; j < n; j++) {
                if (curr_sum < sum) {
                    curr_sum += nums[j];
                    curr_length++;
                }
                if (curr_sum == sum) {
                    max = std::max(max, curr_length);
                    curr_sum = 0;
                    curr_length = 0;
                }
                else if (curr_sum > sum) {
                    can = 0;
                    break;
                }
            }
            if (curr_sum != 0 and curr_sum != sum)
                can = 0;
            if (not can)
                continue;
            answ = min(answ, max);
        }
        cout << answ nl;
    }

    return 0;
}