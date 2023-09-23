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
    int mishka = 0, chris = 0;

    while (n--) {
        int m, c; cin >> m >> c;
        if (m > c) 
            mishka++;
        else if (c > m)
            chris++;
    }

    if (mishka > chris)
        cout << "Mishka" nl;
    else if (chris > mishka)
        cout << "Chris" nl;
    else
        cout << "Friendship is magic!^^";

    return 0;
}