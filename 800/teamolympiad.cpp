#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>

int32_t main() {
    fast

    int n;
    cin >> n;

    vi nums(n);
    v<vi> subs(3, vi());

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        subs[nums[i] - 1].push_back(i + 1);
    }

    int teams = min(subs[0].size(), min(subs[1].size(), subs[2].size()));

    cout << teams nl;
    for (int i = 0; i < teams; i++) {
        cout << subs[0][i] << " " << subs[1][i] << " " << subs[2][i] nl;
    }
    return 0;
}