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

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        
        v<char> s(n);
        int start = -1, end;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            s[i] = a + '0';
            if (start == -1 && a == 1)
                start = i;
            if (a == 1)
                end = i;
        }
        
        int count = 0;
        for (int i = start; i < end; i++)
            if (s[i] == '0')
                count++;
        cout << count nl;
    }

    return 0;
}