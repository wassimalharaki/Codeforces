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
        string s; cin >> s;

        vi nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        priority_queue<int> pq;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                while (not pq.empty())
                    pq.pop();
                pq.push(nums[i]);
                continue;
            }
            int start = i;
            pq.push(nums[i]);
            while (i + 1 < n and s[i + 1] == '1')
                i++, pq.push(nums[i]);
            for (int j = 0; j < i - start + 1; j++)
                sum += pq.top(), pq.pop();
        }
        cout << sum nl;
    }

    return 0;
}