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

vi prep(30);

void solve() {
    int n, k; cin >> n >> k;

    if (k > 28) {
        cout << 0 nl;
        return;
    }

    int a = 0, b = n / prep[k - 1], c = a + b;
    for (int i = 0; i < k - 3; i++)
        a = b, b = c, c = a + b;
    a = 0, b = n / prep[k - 1];

    while (c != n and a <= b)
        if (c < n) {
            a++;
            c += prep[k - 2];
        }
        else {
            b--;
            c -= prep[k - 1];
        }

    int answ = 0;
    while (a <= b) {
        a += prep[k - 1];
        b -= prep[k - 2];
        answ++;
    }
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prep[1] = 1;
    for (int i = 2; i < 30; i++)
        prep[i] = prep[i - 1] + prep[i - 2];

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}