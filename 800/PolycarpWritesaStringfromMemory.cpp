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

        int count = 0;
        for (int i = 0; i < n; i--) {
            unordered_set<char> letters;
            while (letters.size() != 4 && i < n)
                letters.insert(s[i++]);
            count++;
            if (i >= n && letters.size() == 4) {
                count++;
                break;
            }
            else if (i >= n)
                break;
        }
        cout << count nl;
    }

    return 0;
}