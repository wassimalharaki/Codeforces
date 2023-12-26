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

void solve() {
    int n; cin >> n;

    vi nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    vi start_with_one(n), end_with_n(n);
    for (int i = 0; i < n; i++)
        if (i >= nums[i] - 1)
            start_with_one[i - nums[i] + 1]++;
        else
            end_with_n[nums[i] - 1 - i]++;
            
    int answ = 0;
    for (int i = 0; i < n; i++) {
        int swo = start_with_one[i];
        int ewn = end_with_n[i];
        answ += swo * (swo - 1) / 2;
        answ += ewn * (ewn - 1) / 2;
    }
    cout << answ nl;
}

int32_t main() {
    fast;

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}