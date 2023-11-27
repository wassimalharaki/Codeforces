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
        int n; cin >> n;
        string s; cin >> s;

        int cnt = count(all(s), '2');
        if (cnt == 1 or cnt == 2) {
            cout << "NO" nl;
            continue;
        }
        cout << "YES" nl;
        v<v<char>> nums(n, v<char>(n, '?'));
        
        for (int i = 0; i < n; i++) {
            bool haswon = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    nums[i][j] = 'X';
                else if (s[i] == '1' or s[j] == '1')
                    nums[i][j] = '=';
                else if (nums[j][i] != '?')
                    nums[i][j] = (nums[j][i] == '+' ? '-' : '+');
                else
                    nums[i][j] = (haswon ? '-' : '+'), haswon = 1;
                
                cout << nums[i][j];
            }
            cout nl;
        }
    }

    return 0;
}