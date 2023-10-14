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

    vi spf(n + 1);
    for (int i = 2; i <= n; i++)
        spf[i] = i;
    for (int i = 4; i <= n; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i <= n; i++)
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }

    unordered_set<int> pf;
    auto fill_pf = [&](int x) -> void {
        pf.clear();
        while (x != 1) {
            pf.insert(spf[x]);
            x /= spf[x];
        }
    };

    int answ = 0;
    for (int i = 6; i <= n; i++) {
        fill_pf(i);
        if (pf.size() == 2)
            answ++;
    }
    cout << answ;

    return 0;
}