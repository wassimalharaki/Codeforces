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

    char c; cin >> c;
    int a; cin >> a;

    int ur, uc;
    ur = 8 - a;
    uc = c - 'a';

    cin >> c >> a;

    int vr, vc;
    vr = 8 - a;
    vc = c - 'a';

    v<string> answ;
    while (ur < vr) {
        if (uc < vc)
            answ.pb("RD"), uc++;
        else if (uc > vc)
            answ.pb("LD"), uc--;
        else
            answ.pb("D");
        ur++;
    }

    while (ur > vr) {
        if (uc < vc)
            answ.pb("RU"), uc++;
        else if (uc > vc)
            answ.pb("LU"), uc--;
        else
            answ.pb("U");
        ur--;
    }

    while (uc != vc) {
        if (uc > vc)
            answ.pb("L"), uc--;
        else
            answ.pb("R"), uc++;
    }

    cout << answ.size() nl;
    for (int i = 0; i < answ.size(); i++)
        cout << answ[i] nl;

    return 0;
}