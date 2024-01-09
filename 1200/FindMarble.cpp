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
    int n, s, t; cin >> n >> s >> t;

    vi nums(n), vis(n);
    for (int i = 0; i < n; i++) 
        cin >> nums[i];

    int answ = 0, curr = s; 
    while (curr != t and not vis[curr - 1]) {
        vis[curr - 1] = 1;
        curr = nums[curr - 1];
        answ++;
    }
    
    cout << (curr == t ? answ : -1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}