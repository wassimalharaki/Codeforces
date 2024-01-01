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

    vi neg, pos;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        a >= 0 ? pos.pb(a) : neg.pb(a);
    }
    sort(all(neg)), sort(all(pos));

    if (n == 5) {
        cout << accumulate(all(neg), 1ll, multiplies<int>()) *
                accumulate(all(pos), 1ll, multiplies<int>()) nl;
        return;
    }

    if (pos.size() == 0) {
        cout << accumulate(neg.end() - 5, neg.end(), 1ll, multiplies<int>()) nl;
        return;
    }

    int answ = pos[pos.size() - 1];
    int i = 0, j = pos.size() - 2;
    for (int x = 0; x < 2; x++) {
        if (i + 1 < neg.size() and j - 1 >= 0) {
            int negs = neg[i] * neg[i + 1];
            int poss = pos[j] * pos[j - 1];
            if (negs > poss)
                answ *= negs, i += 2;
            else
                answ *= poss, j -= 2;
        }
        else if (i + 1 < neg.size())
            answ *= neg[i] * neg[i + 1], i += 2;
        else
            answ *= pos[j] * pos[j - 1], j -= 2;
    }
    cout << answ nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}