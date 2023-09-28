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
        string start = "a";

        if (s.find(start) == string::npos) {
            cout << "NO" nl;
            continue;
        }

        string c = "b", answ = "YES";
        for (int i = 1; i < s.size(); i++, c[0]++)
            if (s.find(start + c) != string::npos)
                start += c;
            else if (s.find(c + start) != string::npos)
                start = c + start;
            else {
                answ = "NO";
                break;
            }
        cout << answ nl;
    }

    return 0;
}