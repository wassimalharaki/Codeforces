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
        string s; cin >> s;
        int n = s.size();

        int start, end;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') {
                start = i;
                break;
            }
        for (int i = n - 1; n >= 0; i--)
            if (s[i] == '1') {
                end = i;
                break;
            }
        
        int count = 0;
        for (int i = start; i < end; i++)
            if (s[i] == '0')
                count++;
        cout << count nl;
    }

    return 0;
}