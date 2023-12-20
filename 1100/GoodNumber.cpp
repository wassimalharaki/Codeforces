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

    int n, k; cin >> n >> k;
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        vi digits(10);
        for (int j = 0; j < s.size(); j++)
            digits[s[j] - '0'] = 1;
        if (*min_element(digits.begin(), digits.begin() + k + 1))
            count++;
    }
    cout << count nl;

    return 0;
}