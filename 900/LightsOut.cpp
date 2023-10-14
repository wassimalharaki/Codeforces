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

bool is_valid(int i, int j) {
    return (i >= 0 and i < 3 and j >= 0 and j < 3);
}

void neighbours(int i, int j, int a, v<vi>& nums) {
    if (is_valid(i, j))
        nums[i][j] += a;
}

int32_t main() {
    fast;

    v<vi> nums(3, vi(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int a; cin >> a;
            nums[i][j] += a;
            neighbours(i, j + 1, a, nums);
            neighbours(i, j - 1, a, nums);
            neighbours(i + 1, j, a, nums);
            neighbours(i - 1, j, a, nums);
        }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            nums[i][j] & 1 ? cout << 0 : cout << 1;
        cout nl;
    }

    return 0;
}