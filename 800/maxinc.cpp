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
#define INF LONG_LONG_MAX

int32_t main() {
    fast

    int n;

    cin >> n;

    vi nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int curr = 1;
    int max = -1;

    for (int i = 0; i < n - 1; i++) {
        if (nums[i] < nums[i + 1]) {
            curr++;
        }
        else {
            if (curr > max)
                max = curr;

            curr = 1;
        }
    }

    if (curr > max)
        max = curr;

    cout << max;

    return 0;
}