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

int fact(int n) {
    if (n < 0)
        return 0;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

int combinations(int n, int r) {
    int res = 1;
    for (int i = 0; i < r; i++) {
       res = res * (n - i);
       res = res / (i + 1);
    }
    return res;
}

int32_t main() {
    fast;

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
        }
        cout << combinations(10 - n, 2) * 6 nl;
    }

    return 0;
}