#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
        map<int, int> count;
        for (int i = 0; i < n; i++)
            cin >> nums[i], count[nums[i]]++;
        
        int stop = 0;
        for (auto &p : count)
            if (p.second == 1) {
                stop = 1;
                break;
            }
        if (stop) {
            cout << -1 nl;
            continue;
        }

        vi answ(n);
        iota(all(answ), 1);
        for (int i = 0; i < n - 1; i++) {
            int l = i, r;
            while (i + 1 < n and nums[i] == nums[i + 1])
                i++, r = i;
            rotate(answ.begin() + l, answ.begin() + l + 1, answ.begin() + r + 1);
        }

        for (int i = 0; i < n; i++)
            cout << answ[i] << " ";
        cout nl;
    }

    return 0;
}