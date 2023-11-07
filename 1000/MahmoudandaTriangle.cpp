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
    sort(all(nums));
    
    string answ = "NO";
    for (int i = 0; i < n - 2; i++)
        if (nums[i] + nums[i + 1] > nums[i + 2]
                and nums[i] + nums[i + 2] > nums[i + 1]
                and nums[i + 1] + nums[i + 1] > nums[i]) {
            answ = "YES";
            break;
        }
    cout << answ;

    return 0;
}