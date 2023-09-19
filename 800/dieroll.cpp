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

    int y, w;

    cin >> y >> w;

    int dot = 6 - max(y, w) + 1;

    int num = dot;
    int deno = 6;

    int div = gcd(num, deno);

    num /= div;
    deno /= div;

    cout << num << "/" << deno;

    return 0;
}