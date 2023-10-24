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
        int n; cin >> n;

        vi seta(101), setb(101);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            seta[a] ? setb[a]++ : seta[a]++;
        }

        int mex1 = 100, mex2 = 100;
        for (int i = 0; i < 101; i++) {
            if (seta[i] == 0 and mex1 == 100)
                mex1 = i;
            if (setb[i] == 0 and mex2 == 100)
                mex2 = i;
        }
        cout << mex1 + mex2 nl;
    }

    return 0;
}