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

int32_t main() {
    fast

    int t;

    cin >> t;

    while (t--) {
        string s;
        int n;

        cin >> n;

        cin >> s;

        vi check(5, 0);

        if (n != 5) {
            cout << "NO" nl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'T')
                check[0] = 1;
            else if (s[i] == 'i')
                check[1] = 1;
            else if (s[i] == 'm')
                check[2] = 1;
            else if (s[i] == 'u')
                check[3] = 1;
            else if (s[i] == 'r')
                check[4] = 1;
        }
        bool f = 1;
        for (int i = 0; i < 5; i++) {
            if (not check[i]) {
                cout << "NO" nl;
                f = 0;
                break;
            }
        }
        if (f)
            cout << "YES" nl;
    }

    return 0;
}