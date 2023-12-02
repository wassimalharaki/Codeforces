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
        
        int answ = -INF;
        for (int i = 0; i < n;) {
            int min = 0, sum = nums[i], start = i;
            while (i + 1 < n and (nums[i] ^ nums[i + 1]) & 1) {
                answ = max(answ, sum - min);
                min = std::min(sum, min);
                sum += nums[i++ + 1];
            }
            answ = max(answ, sum - min);
            if (i - start == 0)
                i++;
        }
        cout << answ nl;
    }

    return 0;
}