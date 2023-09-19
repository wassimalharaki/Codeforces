#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair

int summation(int n) {
    return (1 + n) * n / 2;
}

int32_t main() {
    fast

    int n;

    cin >> n;

    int height = 0;

    int blocksNeeded = 0;

    for (int i = 1; blocksNeeded <= n; i++) {
        blocksNeeded += summation(i);
        height++;
    }

    height--;

    cout << height;

    return 0;
}