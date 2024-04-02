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

/*
aaaabbbb 2
aabb
aabb

aaabbbb 2
aabbbb
a

aaaabbbbb 2
aabbb
aabb


aaabbbbb 2
aabbbbb
a

aaaaabbbbb 2
aaaabbbbb
a

aaaabb 2
a
aaabb

*/

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    v<int> letters(26);
    for (char& c : s)
        letters[c - 'a']++;
    
    v<pair<char, int>> nums;
    for (int i = 0; i < 26; i++)
        if (letters[i])
            nums.push_back({i + 'a', letters[i]});
    sort(all(nums));

    if (nums[0].second < k) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            x += nums[i].second;
            if (x >= k) {
                cout << nums[i].first << nl;
                break;
            }
        }
    }
    else if (nums.size() == 1)
        cout << string((n + k - 1) / k, nums[0].first) << nl;
    else if (nums.size() == 2 and nums[0].second == k)
        cout << nums[0].first << string((nums[1].second + k - 1) / k, nums[1].first) << nl;
    else {
        string ans;
        nums[0].second -= k - 1;
        for (int i = 0; i < nums.size(); i++)
            ans += string(nums[i].second, nums[i].first);
        cout << ans << nl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}