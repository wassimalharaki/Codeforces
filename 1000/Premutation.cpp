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

        vi order(n);
        v<vi> perms(n, vi(n - 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                cin >> perms[i][j];
        
        vi count(101);
        for (int i = 0; i < n; i++) {
            count[perms[i][0]]++;
            if (count[perms[i][0]] > 1)
                order[0] = perms[i][0];
        }

        for (int i = 0; i < n; i++)
            if (perms[i][0] != order[0]) {
                order[1] = perms[i][0];
                break;
            }
        
        for (int i = 1; i < n - 1; i++)
            for (int j = 0; j < n; j++)
                if (perms[j][i] != order[i]) {
                    order[i + 1] = perms[j][i];
                    break;
                }

        for (int i = 0; i < n; i++)
            cout << order[i] << " ";
        cout nl;
    }

    return 0;
}