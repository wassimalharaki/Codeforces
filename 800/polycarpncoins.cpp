#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>

int32_t main() {
    fast

    int t;

    cin >> t;

    while(t--) {
        int n;

        cin >> n;
        int c1 = n / 3;
        int c2 = n / 3;
        n %= 3;
        if (n == 1)
            c1++;
        if (n == 2)
            c2++;

        cout << c1 << " " << c2 nl;
    }

    return 0;
}