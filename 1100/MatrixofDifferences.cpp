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

        vvi nums(n, vi(n));
        int l = 1, r = n * n;
        for (int i = 0; i < n; i++)
            nums[0][i] = (i & 1 ? r-- : l++);
        bool turn = (n & 1);
        
        int current = n - 1;
        bool one = 0;
        int multone = -1;
        int multzero = 1;
        for (int i = 2 * (n - 1) + 1; i >= 2; i--, one = !one)
            if (one) {
                for (int j = 0; j < i / 2; j++, turn = !turn) {
                    current += multone;
                    int row = current / n;
                    int col = current % n;
                    nums[row][col] = (turn ? r-- : l++);
                }
                multone *= -1;
            }
            else {
                for (int j = 0; j < i / 2; j++, turn = !turn) {
                    current += n * multzero;
                    int row = current / n;
                    int col = current % n;
                    nums[row][col] = (turn ? r-- : l++);
                }
                multzero *= -1;
            }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << nums[i][j] << " "; cout nl;
        }
    }

    return 0;
}