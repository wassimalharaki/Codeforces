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
        string a, b; cin >> a >> b;

        int curr = 0;
        vi nums(2);
        int setsofzeroes = 0;
        for (int i = 0; i < n; i++) {
            nums[a[i] - '0'] = 1;
            nums[b[i] - '0'] = 1;

            if (a[i] == b[i] and a[i] == '0')
                setsofzeroes++;

            if (nums[0] and nums[1]) {
                curr += 2, nums[0] = 0, nums[1] = 0;
                if (a[i] != b[i])
                    curr += setsofzeroes;
                else
                    curr += max(setsofzeroes - 1, 0ll);
                setsofzeroes = 0;
            }
        }
        curr += setsofzeroes;
        cout << curr nl;
    }

    return 0;
}