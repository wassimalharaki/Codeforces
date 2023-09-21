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
#define F first
#define S second

int32_t main() {
    fast

    int n = 5;
    int answ;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            if (a == 1)
                answ = abs(i - 2) + abs(j - 2);
        }

    cout << answ;

    return 0;
}