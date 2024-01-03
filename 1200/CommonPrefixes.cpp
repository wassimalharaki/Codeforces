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
    int n; cin >> n;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    int max = *max_element(all(nums));

    if (max == 0) {
        for (int i = 0; i <= n; i++)
            cout << (i & 1 ? 'a' : 'b') nl;
        return; 
    }
    
    string prev(max, 'a');
    cout << prev nl;
    for (int i = 0; i < n; i++) {
        string curr;
        for (int j = 0; j < prev.size(); j++)
            j < nums[i] ? curr += prev[j] : curr += (prev[j] == 'a' ? 'b' : 'a');
        cout << curr nl;
        prev = curr;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}