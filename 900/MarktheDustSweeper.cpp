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
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        
        int steps = 0;
        queue<int> strg;
        for (int i = 0; i < n - 1; i++)
            if (nums[i] > 0)
                strg.push(i);
            else if (not strg.empty()) {
                steps++;
                nums[i]++, nums[strg.front()]--;
                strg.push(i);
                if (not nums[strg.front()])
                    strg.pop();
            }
        
        for (int i = 0; i < n - 1; i++)
            steps += nums[i];
        cout << steps nl;
    }

    return 0;
}