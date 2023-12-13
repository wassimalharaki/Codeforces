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
        string s; cin >> s;
        int n = s.size();

        bool flag = 0;
        if (s[0] > s[n - 1])
            swap(s[0], s[n - 1]), flag = 1;
        
        vpii nums;
        for (int i = 1; i < n - 1; i++)
            if (s[i] >= s[0] and s[i] <= s[n - 1])
                nums.pb(mp(s[i] - 'a', i + 1));
        sort(all(nums));
        if (flag)
            reverse(all(nums));
        
        cout << s[n - 1] - s[0] << " " << nums.size() + 2 nl;
        cout << 1 << " ";
        for (int i = 0; i < nums.size(); i++)
            cout << nums[i].S << " ";
        cout << n nl;
    }

    return 0;
}