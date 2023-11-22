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
        int k; cin >> k;
        string s; cin >> s;

        vvi nums(10);
        for (int i = 0; i < k; i++)
            nums[s[i] - '0'].pb(i);

        vi ones{1, 4, 6, 8, 9};
        bool f = 0;
        for (int i = 0; i < ones.size(); i++)
            if (nums[ones[i]].size() > 0) {
                cout << 1 nl << ones[i] nl;
                f = 1;
                break;
            }
        if (f)
            continue;

        //2, 3, 5, 7
        v<string> twos{"22", "25", "27", "32", "33", "35", "52", "55", "57", "72", "75", "77"};
        for (int i = 0; i < twos.size(); i++) {
            int first = twos[i][0] - '0';
            int second = twos[i][1] - '0';
            if (nums[first].empty() or nums[second].empty())
                continue;
            if (nums[first][0] < nums[second][nums[second].size() - 1]) {
                cout << 2 nl << twos[i] nl;
                break;
            }
        }
    }

    return 0;
}