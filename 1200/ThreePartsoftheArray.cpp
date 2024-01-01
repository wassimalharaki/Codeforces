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

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int a = 0, c = n - 1, suma = 0, sumc = 0, answ = 0;
    while (a <= c)
        if (suma == sumc) {
            answ = suma;
            if (a == c)
                break;
            suma += nums[a++];
            sumc += nums[c--];
        }
        else if (suma > sumc)
            sumc += nums[c--];
        else
            suma += nums[a++];
    cout << (suma == sumc ? suma : answ);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}