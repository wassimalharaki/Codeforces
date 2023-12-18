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

    int T; cin >> T;
    
    while (T--) {
        int n; cin >> n;

        stack<int> nums;
        for (int i = 0; i < n; i++) {
            int a; cin >> a; nums.push(a);
        }
        
        vi find(n + 1, 0);
        int i = n;
        stack<int> batch;
        vi answ;
        while (not nums.empty()) {
            int top = nums.top();
            nums.pop();
            find[top] = 1;
            batch.push(top);
            if (top != i)
                continue;
            while (not batch.empty())
                answ.pb(batch.top()), batch.pop();
            while (i >= 0 and find[i])
                i--;
        }
        for (int i = 0; i < n; i++)
            cout << answ[i] << " ";
        cout nl;
    }

    return 0;
}