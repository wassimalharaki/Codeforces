#include <bits/stdc++.h>

using namespace std;

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

#define int long long
#define INF LONG_LONG_MAX
#define nl '\n'
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

unordered_map<char, char> counter{
    {'R', 'P'},
    {'P', 'S'},
    {'S', 'R'}
};

void solve() {
    string s; cin >> s;
    char c;
    int max = -1;
    unordered_map<char, int> count;
    for (int i = 0; i < s.size(); i++)
        count[s[i]]++;
    
    for (auto& [ch, val] : count)
        if (val > max) {
            max = val;
            c = ch;
        }
    cout << string(s.size(), counter[c]) << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}