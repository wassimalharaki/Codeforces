#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    v<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + (s[i] == '1');
    
    v<int> cnt1(n), cnt2(n), cnt3(n), cnt4(n);
    for (int i = 0; i + 2 < n; i++)
        if (t[i] == '1' and t[i + 2] == '1' and s[i + 1] == '0')
            cnt1[i]++;
    
    v<int> turned_on(n);
    for (int i = 0; i + 2 < n; i++)
        if (s[i] == '0' and s[i + 2] == '0' and t[i + 1] == '0')
            turned_on[i + 1] = 1;
    
    for (int i = 0; i + 2 < n; i++)
        if (turned_on[i] and t[i + 2] == '1' and s[i + 1] == '0')
            cnt2[i - 1]++;
    
    for (int i = 0; i + 2 < n; i++)
        if (t[i] == '1' and turned_on[i + 2] and s[i + 1] == '0')
            cnt3[i]++;
    
    for (int i = 0; i + 2 < n; i++)
        if (turned_on[i] and turned_on[i + 2] and s[i + 1] == '0')
            cnt4[i - 1]++;
    
    v<int> pref_cnt1(n + 1), pref_cnt2(n + 1), pref_cnt3(n + 1), pref_cnt4(n + 1);
    partial_sum(cnt1.begin(), cnt1.end(), pref_cnt1.begin() + 1);
    partial_sum(cnt2.begin(), cnt2.end(), pref_cnt2.begin() + 1);
    partial_sum(cnt3.begin(), cnt3.end(), pref_cnt3.begin() + 1);
    partial_sum(cnt4.begin(), cnt4.end(), pref_cnt4.begin() + 1);

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--, r--;

        int ans = 0;
        ans += pref[r + 1] - pref[l];
        if (r - 1 >= 0)
            ans += max(0ll, pref_cnt1[r - 1] - pref_cnt1[l]);
        if (r - 2 >= 0)
            ans += max(0ll, pref_cnt2[r - 2] - pref_cnt2[l]);
        if (r - 2 >= 0)
            ans += max(0ll, pref_cnt3[r - 2] - pref_cnt3[l]);
        if (r - 4 >= 0)
            ans += max(0ll, pref_cnt4[r - 3] - pref_cnt4[l]);

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