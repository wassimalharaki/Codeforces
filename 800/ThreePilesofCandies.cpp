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

    int t; cin >> t;
    
    while (t--) {
        vi candies(3);
        cin >> candies[0] >> candies[1] >> candies[2];
        sort(all(candies));

        int split = min(candies[2], candies[1] - candies[0]);
        cout << candies[0] + split + (candies[2] - split) / 2 nl;
    }

    return 0;
}