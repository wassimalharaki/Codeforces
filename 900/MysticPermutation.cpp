#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
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

        vi nums(n), answ(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i], answ[i] = i + 1;
        
        if (n == 1) {
            cout << -1 nl;
            continue;
        }

        for (int i = 0; i < n - 1; i++)
            if (answ[i] == nums[i])
                swap(answ[i], answ[i + 1]);

        if (answ[n - 1] == nums[n - 1])
            swap(answ[n - 1], answ[n - 2]);
        
        for (int i = 0; i < n; i++)
            cout << answ[i] << " ";
        cout nl;
    }

    return 0;
}