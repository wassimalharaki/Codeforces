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

    int n; cin >> n;

    int quarter = 0, half = 0;
    string answ = "YES";
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 25)
            quarter++;
        else if (a == 50)
            quarter--, half++;
        else {
            if (half)
                half--, quarter--;
            else
                quarter -= 3;
        }
        if (quarter < 0)
            answ = "NO";
    }
    cout << answ nl;

    return 0;
}