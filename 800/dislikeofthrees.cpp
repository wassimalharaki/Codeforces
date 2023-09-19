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

    vi tcs(t);
    int max = -1;

    for (int i = 0; i < t; i++) {
        cin >> tcs[i];
        if (tcs[i] > max)
            max = tcs[i];
    }

    vi table(max);
    int s = 0;

    for (int i = 1; true; i++) {
        if (i % 10 != 3 && i % 3 != 0) {
            table[s++] = i;
            if (s == max)
                break;
        }
    }

    for (int i = 0; i < t; i++) {
        cout << table[tcs[i] - 1] nl;
    }

    return 0;
}