#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX

int32_t main() {
    fast

    int t;

    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        v<char> row1(n);

        bool same = true;

        for (int i = 0; i < n; i++) {
            cin >> row1[i];
        }

        for (int i = 0; i < n; i++) {
            char a;
            cin >> a;
            if (a != row1[i] && !(row1[i] != 'R' && a != 'R'))
                same = false;
        }  
    
        cout << ((same)? "YES\n" : "NO\n");
    }

    return 0;
}