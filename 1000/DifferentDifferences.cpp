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
        int k, n; cin >> k >> n;
        
        vi answ(k);
        for (int i = 0, diff = 0, curr = 1; i < k; i++, diff++)
            curr += diff, answ[i] = min(curr, n);
        
        for (int i = k - 1, j = 0; i >= 0; i--, j++)
            if (answ[i] == n or (i + 1 < k and answ[i] >= answ[i + 1]))
                answ[i] = n - j;
            else
                break;
        
        for (int i = 0; i < k; i++)
            cout << answ[i] << " ";
        cout nl;
    }

    return 0;
}