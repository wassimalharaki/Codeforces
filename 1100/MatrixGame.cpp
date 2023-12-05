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
        int n, m; cin >> n >> m;

        vvi nums(n, vi(m));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                cin >> nums[i][j];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (nums[i][j] == 1) {
                    for (int k = 0; k < m; k++)
                        if (nums[i][k] == 0)
                            nums[i][k] = 2;
                    for (int k = 0; k < n; k++)
                        if (nums[k][j] == 0)
                            nums[k][j] = 2;
                }
        
        bool turn = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (not nums[i][j]) {
                    for (int k = 0; k < m; k++)
                        nums[i][k] = 1;
                    for (int k = 0; k < n; k++)
                        nums[k][j] = 1;
                    turn = !turn;
                }
        cout << (turn ? "Ashish" : "Vivek") nl;
    }

    return 0;
}