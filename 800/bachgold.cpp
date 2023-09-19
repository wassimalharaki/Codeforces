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

    int n;

    cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 nl;
        for (int i = 0; i < n / 2; i++)
            cout << 2 << " ";
    }
    else {
        cout << n / 2 nl;
        for (int i = 0; i < n / 2 - 1; i++)
            cout << 2 << " ";
        cout << 3;
    }

    return 0;
}