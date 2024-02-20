#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string s; cin >> s;

    vector<vector<int>> digits(10);
    for (int i = 0; i < s.size(); i++)
        digits[s[i] - '0'].push_back(i);
    
    auto ok = [&](int n) -> bool {
        int prev = -1;
        string t = to_string(n);
        for (char& c : t) {
            int i = c - '0';
            auto it = upper_bound(digits[i].begin(), digits[i].end(), prev);
            if (it == digits[i].end())
                return 0;
            prev = *it;
        }
        return 1;
    };
    
    for (int i = 0; i < 125; i++)
        if (ok(8 * i)) {
            cout << "YES\n" << 8 * i;
            return;
        }
    cout << "NO";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}