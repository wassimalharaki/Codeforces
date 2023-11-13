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

    int T; cin >> T;
    
    while (T--) {
        int n, k; cin >> n >> k;

        v<char> paper(n);
        for (int i = 0; i < n; i++)
            cin >> paper[i];
        
        int blacks, current = 0;
        for (int i = 0; i < k; i++)
            if (paper[i] == 'B')
                current++;
        blacks = current;

        for (int i = k; i < n; i++) {
            if (paper[i - k] == 'B')
                current--;
            if (paper[i] == 'B')
                current++;
            blacks = max(current, blacks);
        }
        cout << max(k - blacks, (int) 0) nl;
    }

    return 0;
}