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

void solve() {
    int n; cin >> n;

    vi odds, evens;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a & 1 ? odds.pb(a) : evens.pb(a);
    }
    sort(all(odds)); sort(all(evens));

    if (n == 1) {
        cout << (evens.size() > 0 ? "Alice" : "Tie") nl;
        return;
    }

    int alice = 0, bob = 0;
    int i = evens.size() - 1, j = odds.size() - 1;
    int alt = 1;
    while (i >= 0 and j >= 0) {
        if (alt) {
            if (evens[i] > odds[j])
                alice += evens[i--];
            else
                j--;
        }
        else {
            if (odds[j] > evens[i])
                bob += odds[j--];
            else
                i--;
        }
        alt = !alt;
    }

    while (i >= 0) {
        if (alt)
            alice += evens[i];
        else
            if (i - 1 >= 0) alice += evens[i - 1];
        i -= 2;
    }

    while (j >= 0) {
        if (not alt)
            bob += odds[j];
        else
            if (j - 1 >= 0) bob += odds[j - 1];
        j -= 2;
    }
    
    cout << (alice > bob ? "Alice" : alice == bob ? "Tie" : "Bob") nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}