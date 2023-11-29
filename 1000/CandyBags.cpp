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

    int n; cin >> n;

    vvi nums(n, vi(n));
    int num = 1;
    for (int j = 0; j < n; j++)
        if (j & 1)
            for (int i = n - 1; i >= 0; i--)
                nums[i][j] = num++;
        else
            for (int i = 0; i < n; i++)
                nums[i][j] = num++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << nums[i][j] << " ";
        cout nl;
    }


    return 0;
}