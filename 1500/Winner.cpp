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

    int avl = 0;
    map<string, int> id;
    v<int> nums(1000);
    v<pair<int, int>> logs;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int a; cin >> a;
        if (not id.count(s))
            id[s] = avl++;
        int j = id[s];
        logs.push_back({j, nums[j] += a});
    }

    set<int> winners;
    int max = -INT_MAX;
    for (int i = 0; i < 1000; i++)
        if (nums[i] > max) {
            max = nums[i];
            winners.clear();
            winners.insert(i);
        }
        else if (nums[i] == max)
            winners.insert(i);
    
    for (int i = 0; i < logs.size(); i++) {
        auto& p = logs[i];
        if (p.second < max) continue;
        if (not winners.count(p.first)) continue;
        int j = p.first;
        for (auto& [key, val] : id)
            if (val == j)
                cout << key;
        break;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}