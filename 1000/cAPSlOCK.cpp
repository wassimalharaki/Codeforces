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

    string s; cin >> s;

    bool allupper = isupper(s[0]), upper = islower(s[0]);
    for (int i = 1; i < s.size(); i++)
        if (islower(s[i])) {
            allupper = 0; upper = 0;
            break;
        }
    
    if (allupper)
        for (int i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);
    else if (upper) {
        s[0] = toupper(s[0]);
        for (int i = 1; i < s.size(); i++)
            s[i] = tolower(s[i]);
    }
    cout << s;
    
    return 0;
}