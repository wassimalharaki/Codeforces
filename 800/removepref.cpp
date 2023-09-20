#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;

        vi nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];
        
        set<int> s;
        int answ = -1;
        for (int i = n - 1; i >= 0; i--) {
            int size = s.size();
            s.insert(nums[i]);
            if (size == s.size()) {
                answ = i;
                break;
            }
        }

        cout << answ + 1 nl;
    }

    return 0;
}