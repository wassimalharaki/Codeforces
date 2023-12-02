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
    
    vpii nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i].F >> nums[i].S;
    sort(all(nums));

    bool alex = 0;
    int quality = 0;
    for (int i = 0; i < n; i++) {
        if (quality > nums[i].S) {
            alex = 1;
            break;
        }
        quality = max(quality, nums[i].S);
    }
    cout << (alex ? "Happy Alex" : "Poor Alex");
        
    return 0;
}