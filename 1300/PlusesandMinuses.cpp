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
    string s; cin >> s;
    int n = s.size();

    map<int, int> map;
    int curr = 0, min = INF;
    for (int i = 0; i < s.size(); i++) {
        curr += (s[i] == '+' ? 1 : -1);
        min = std::min(min, curr);
        if (map.count(curr) == 0)
            map[curr] = i + 1;
    }
    
    int answ = n;
    for (int i = 0; i < - min; i++)
        answ += map[-(i + 1)];
    cout << answ nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}