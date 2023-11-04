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

    int s, n; cin >> s >> n;

    v<pii> dragons(n);
    for (int i = 0; i < n; i++)
        cin >> dragons[i].F >> dragons[i].S;
    sort(all(dragons));

    string answ = "YES";
    for (int i = 0; i < n; i++)
        if (s > dragons[i].F)
            s += dragons[i].S;
        else {
            answ = "NO";
            break;
        }
    cout << answ nl;

    return 0;
}