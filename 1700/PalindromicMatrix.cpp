#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n;
    
    v<v<int>> ans(n, v<int>(n));
    map<int, int> map;
    for (int i = 0; i < n * n; i++) {
        int a; cin >> a;
        map[a]++;
    }
 
    if (n & 1) {
        int odds = 0;
        for (auto& [key, val] : map)
            odds += val & 1;
        
        if (odds != 1) {
            cout << "NO";
            return;
        }
 
        for (auto& [key, val] : map)
            if (val & 1) {
                ans[n / 2][n / 2] = key, val--;
                if (val == 0) map.erase(key);
                break;
            }
 
        auto it = map.begin();
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++) {
                while (it != map.end() and it -> second < 4) it++;
 
                if (it == map.end()) {
                    cout << "NO";
                    return;
                }
 
                auto& [key, val] = *it;
 
                ans[i][j] = ans[n - i - 1][j] = ans[i][n - 1 - j] = ans[n - i - 1][n - j - 1] = key;
                val -= 4;
 
                if (val == 0) {
                    auto old = it;
                    it++;
                    map.erase(old);
                }
            }
        
        it = map.begin();
        for (int i = 0; i < n / 2; i++) {
            int j = n / 2;
            while (it != map.end() and it -> second < 2) it++;
            if (it == map.end()) {
                cout << "NO";
                return;
            }
 
            auto& [key, val] = *it;
            ans[i][j] = ans[n - i - 1][j] = key;
            val -= 2;
 
            if (val == 0) {
                auto old = it;
                it++;
                map.erase(old);
            }
        }
 
        for (int j = 0; j < n / 2; j++) {
            int i = n / 2;
            while (it != map.end() and it -> second < 2) it++;
            if (it == map.end()) {
                cout << "NO";
                return;
            }
 
            auto& [key, val] = *it;
            ans[i][j] = ans[i][n - j - 1] = key;
            val -= 2;
 
            if (val == 0) {
                auto old = it;
                it++;
                map.erase(old);
            }
        }
    }
    else {
        for (auto& [key, val] : map)
            if (val % 4) {
                cout << "NO";
                return;
            }
 
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n / 2; j++) {
                auto& [key, val] = *map.begin();
 
                ans[i][j] = ans[n - i - 1][j] = ans[i][n - 1 - j] = ans[n - i - 1][n - j - 1] = key;
                val -= 4;
 
                if (val == 0) map.erase(map.begin());
            }
    }
 
    cout << "YES" << nl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " \n"[j == n - 1];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}