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

    string s; cin >> s;
    int start = (1 << s.size()) - 1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '7')
            start += 1 << s.size() - (i + 1);
    cout << start nl;

    return 0;
}