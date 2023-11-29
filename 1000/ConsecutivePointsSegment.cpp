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
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        
        string answ = "YES";
        bool found = 0;
        for (int i = 1; i < n; i++) {
            if (not found) {
                int diff = nums[i] - nums[i - 1];
                if (diff == 1)
                    continue;
                if (diff == 2)
                    nums[i - 1]++;
                else if (diff == 3)
                    nums[i - 1]++, nums[i]--;
                else {
                    answ = "NO";
                    break;
                }
                found = 1;
                continue;
            }

            int diff = nums[i] - nums[i - 1];
            if (diff > 2) {
                answ = "NO";
                break;
            }
            else if (diff == 2)
                nums[i]--;
            else if (diff == 0)
                nums[i]++;
        }
        cout << answ nl;
    }

    return 0;
}