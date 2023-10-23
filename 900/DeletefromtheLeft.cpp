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

    string s, t; cin >> s >> t;

    if (t.size() > s.size())
        swap(t, s);

    int diff = s.size() - t.size();

    int seq = 0;
    for (int i = t.size() - 1; i >= 0; i--)
        if (t[i] == s[i + diff])
            seq++;
        else
            break;
    cout << s.size() + t.size() - 2 * seq;

    return 0;
}