#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector
#define all(v) v.begin(), v.end()

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;

    v<int> nums(n);
    for (int& a : nums) cin >> a;

    v<int> left(n), right(n);
    stack<int> mono;
    for (int i = 0; i < n; i++) {
        while (mono.size() and nums[mono.top()] > nums[i])
            mono.pop();
        
        if (mono.empty())
            left[i] += (i + 1) * nums[i];
        else
            left[i] += nums[i] * (i - mono.top()) + left[mono.top()];
        mono.push(i);
    }
    mono = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
        while (mono.size() and nums[mono.top()] > nums[i])
            mono.pop();
        
        if (mono.empty())
            right[i] += (n - i) * nums[i];
        else
            right[i] += nums[i] * (mono.top() - i) + right[mono.top()];
        mono.push(i);
    }

    int mid = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int curr = left[i] + right[i] - nums[i];;
        if (curr > sum) {
            sum = curr;
            mid = i;
        }
    }
    v<int> ans(nums);
    for (int i = mid - 1; i >= 0; i--)
        ans[i] = min(ans[i], ans[i + 1]);
    for (int i = mid + 1; i < n; i++)
        ans[i] = min(ans[i], ans[i - 1]);
    for (int& a : ans)
        cout << a << " ";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}