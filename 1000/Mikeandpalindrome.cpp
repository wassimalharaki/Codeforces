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

    string s; cin >> s;
    int n = s.size();

    int count = 0;
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - i - 1])
            count++;
    cout << (count == 1 ? "YES" : count == 0 and (n & 1) ? "YES" : "NO") nl;

    return 0;
}