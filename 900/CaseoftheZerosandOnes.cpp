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

    int n; cin >> n;
    string s; cin >> s;

    int ones = 0, zeroes = 0;
    for (int i = 0; i < n; i++)
        s[i] == '1' ? ones++ : zeroes++;
    cout << n - 2 * min(ones, zeroes) nl;

    return 0;
}