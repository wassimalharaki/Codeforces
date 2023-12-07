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
        int k, n, m; cin >> k >> n >> m;

        vi a(n), b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        
        int i = 0, j = 0;
        bool can = 1;
        string answ;
        while (i < n or j < m) {
            while (i < n and a[i] == 0)
                i++, k++, answ += "0 ";
            while (j < m and b[j] == 0)
                j++, k++, answ += "0 ";
            
            if (i == n and j == m)
                break;

            if (i == n) {
                if (b[j] > k) {
                    can = 0;
                    break;
                }
                else
                    answ += to_string(b[j++]) + ' ';
            }
            else if (j == m) {
                if (a[i] > k) {
                    can = 0;
                    break;
                }
                else
                    answ += to_string(a[i++]) + ' ';
            }
            else {
                if (a[i] < b[j]) {
                    if (a[i] > k) {
                        can = 0;
                        break;
                    }
                    else
                        answ += to_string(a[i++]) + ' ';
                }
                else {
                    if (b[j] > k) {
                        can = 0;
                        break;
                    }
                    else
                        answ += to_string(b[j++]) + ' ';
                }
            }
        }
        if (not can)
            cout << -1 nl;
        else
            cout << answ nl;
    }

    return 0;
}