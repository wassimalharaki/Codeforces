#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl << '\n'
#define pii pair<int, int>
#define v vector
#define vi v<int>
#define vvi v<vi>
#define vpii v<pii>
#define mp make_pair
#define pb push_back
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast;

    int a, b; cin >> a >> b;

    int count = 0;
    while (a > 0 and b > 0 and !(a == 1 and b == 1)) {
        count++;
        if (a > b)
            b += 1, a -= 2;
        else
            a += 1, b -= 2;
    }
    cout << count nl;

    return 0;
}