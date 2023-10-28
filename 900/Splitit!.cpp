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

bool is_palindrome(string& s, int k) {
    for (int i = 0; i < k; i++)
        if (s[i] != s[s.size() - i - 1])
            return 0;
    return 1;
}

int32_t main() {
    fast;

    int T; cin >> T;
    
    while (T--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        
        if (not (n & 1) and k == n / 2) {
            cout << "NO" nl;
            continue;
        }
        is_palindrome(s, k) ? cout << "YES" nl : cout << "NO" nl;
    }

    return 0;
}