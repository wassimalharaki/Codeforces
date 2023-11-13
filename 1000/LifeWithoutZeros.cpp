#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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

    string a, b; cin >> a >> b;
    string c = to_string(stoi(a) + stoi(b));
    string filta, filtb, filtc;

    for (int i = 0; i < a.size(); i++)
        if (a[i] != '0')
            filta += a[i];

    for (int i = 0; i < b.size(); i++)
        if (b[i] != '0')
            filtb += b[i];

    for (int i = 0; i < c.size(); i++)
        if (c[i] != '0')
            filtc += c[i];

    cout << (stoi(filta) + stoi(filtb) == stoi(filtc) ? "YES" : "NO") nl;

    return 0;
}