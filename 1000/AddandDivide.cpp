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
#define vii v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int binpow(int a, int b) {
    int res = 1;
    bool aoverflow = 0;
    while (b > 0) {
        if (b & 1) {
            if (aoverflow)
                return 1e9 + 1;
            res = res * a;
        }
        a = a * a;
        if (a > 1e9)
            aoverflow = 1;
        if (res > 1e9)
            return 1e9 + 1;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int a, b; cin >> a >> b;
        
        int lo = 1, hi = 18;
        int answ;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            bool works = 0;
            for (int i = 0; i < mid; i++) {
                int num = binpow(b + i, mid - i);
                if (num > a)
                    works = 1;
            }
            
            if (works)
                answ = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        cout << answ nl;
    }

    return 0;
}