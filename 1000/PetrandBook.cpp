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

    int n; cin >> n;

    int sum = 0, last;
    vi week(7);
    for (int i = 0; i < 7; i++) {
        cin >> week[i], sum += week[i];
        if (week[i] > 0)
            last = i + 1;
    }
    n %= sum;

    if (n == 0) {
        cout << last;
        return 0;
    }

    for (int i = 0; i < 7; i++) {
        n -= week[i];
        if (n <= 0) {
            cout << i + 1;
            break;
        }
    }

    return 0;
}