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
        int n, x; cin >> n >> x;

        vi rank(201);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            rank[a] = 1;
        }

        int answ;
        for (int i = 1; i < 201; i++) {
            if (not rank[i])
                if (x) x--; else break;
            answ = i;
        }
        cout << answ nl;
    }

    return 0;
}