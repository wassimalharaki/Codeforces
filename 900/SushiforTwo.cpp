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

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int answ = 1, ones = 0, twos = 0;
    for (int i = 0; i < n;) {
        while (i < n and nums[i] == 1)
            i++, ones++;
        answ = max(answ, 2 * min(ones, twos));
        twos = 0;
        while (i < n and nums[i] == 2)
            i++, twos++;
        answ = max(answ, 2 * min(ones, twos));
        ones = 0;
    }
    cout << answ nl;

    return 0;
}