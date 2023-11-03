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
        int n, a, b; cin >> n >> a >> b;

        bool possible = 1;
        vi left(n / 2);
        vi taken(n + 1);
        taken[a] = 1;
        left[0] = a;
        for (int i = 1, j = n; i < n / 2; i++, j--) {
            if (j == b)
                j--;
            if (j == a) {
                possible = 0;
                break;
            }
            left[i] = j;
            taken[j] = 1;
        }

        if (not possible) {
            cout << -1 nl;
            continue;
        }

        int max;
        for (int i = 1; i <= n; i++)
            if (not taken[i])
                max = i;

        if (max != b) {
            cout << -1 nl;
            continue;
        }

        for (int i = 0; i < n / 2; i++)
            cout << left[i] << " ";
        for (int i = 1; i <= n; i++)
            if (not taken[i])
                cout << i << " ";
        cout nl;
    }

    return 0;
}