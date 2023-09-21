#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define INF LONG_LONG_MAX
#define F first
#define S second

int32_t main() {
    fast

    string s; cin >> s;
    int lower = 0, upper = 0;
    
    for (int i = 0; i < s.size(); i++)
        if (islower(s[i]))
            lower++;
        else
            upper++;

    if (upper > lower)
        for (int i = 0; i < s.size(); i++)
            s[i] = toupper(s[i]);
    else
        for (int i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);

    cout << s;

    return 0;
}