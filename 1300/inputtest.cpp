#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF LONG_LONG_MAX
#define nl << '\n'
#define v vector
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define F first
#define S second

using pii = pair<int, int>;
using vi = v<int>;
using vvi = v<vi>;
using vpii = v<pii>;

int random(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "w", stdout);
    srand(time(0));
    int T = 1000;
    cout << T nl;
    while (T--) {
        int l = random(1, 50);
        int r = random(l, 50);
        cout << l << " " << r nl;
    }

    return 0;
}