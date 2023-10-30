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

bool valid(v<vi>& nums, int i, int j) {
    return i >= 0 and j >= 0 and i < nums.size() and j < nums[i].size();
}

void fill(v<vi>& nums, int i, int j) {
    vi cnt(2);
    if (valid(nums, i, j + 1))
        cnt[nums[i][j + 1]]++;
    if (valid(nums, i, j - 1))
        cnt[nums[i][j - 1]]++;
    if (valid(nums, i - 1, j))
        cnt[nums[i - 1][j]]++;
    
    if (nums[i][j])
        cnt[0] == 2 ? nums[i + 1][j] = 1 : nums[i + 1][j] = 0;
    else
        cnt[1] == 2 ? nums[i + 1][j] = 0 : nums[i + 1][j] = 1;
}

void fillup(v<vi>& nums) {
    for (int i = 0; i < nums.size() - 1; i++)
        for (int j = 0; j < nums[i].size(); j++)
            fill(nums, i, j);
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n, m; cin >> n >> m;    

        v<vi> matrix(n, vi(m));
        matrix[0][0] = 1;
        int alt = 1;
        for (int i = 1; i < m; i++) {
            if (i & 1)
                alt = !alt;
            matrix[0][i] = alt;
        }
        fillup(matrix);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << matrix[i][j] << " ";
            cout nl;
        }
    }



    return 0;
}