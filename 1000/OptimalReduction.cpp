#include <bits/stdc++.h>
 
using namespace std;
 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
 
    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;
        
        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        
        string answ = "YES";
        int left = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[left] > nums[i] and nums[i + 1] > nums[i]) {
                answ = "NO";
                break;
            }
            if (!(nums[i + 1] == nums[i] and nums[left] > nums[i]))
                left = i;
        }
        cout << answ nl;
    }
 
    return 0;
}