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

    int max = -1;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] > max)
            max = nums[i];
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += max - nums[i];
    }

    cout << sum nl;

    return 0;
}