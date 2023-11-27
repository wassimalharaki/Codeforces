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
        string a, b; cin >> a >> b;
        int n = a.size();

        vi forward(n, 1);
        vi backward(n, 1);

        for (int i = 1; i < n; i++)
            if (a[i] != b[i])
                forward[i] = 0;
            else
                forward[i] = forward[i - 1];
        
        for (int i = n - 2; i >= 0; i--)
            if (a[i] != b[i])
                backward[i] = 0;
            else
                backward[i] = backward[i + 1];
        
        string answ = "NO";
        for (int i = 0; i < n - 1; i++)
            if (a[i] == b[i] and a[i] == '0')
                if (a[i + 1] == b[i + 1] and a[i + 1] == '1') {
                    answ = "YES";
                    break;
                }
        
        for (int i = 1; i < n; i++)
            if (a[i] == b[i]) {
                if (a[i] == '1' and forward[i - 1]) {
                    answ = "YES";
                    break;
                }
                else if (a[i] == '0' and backward[i + 1]) {
                    answ = "YES";
                    break;
                }
            }
        cout << answ nl;
    }

    return 0;
}