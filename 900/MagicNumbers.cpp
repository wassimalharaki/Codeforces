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
    string off = "144", of = "14", o = "1";

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); i++)
        if (i + 2 < s.size() && string{s[i], s[i + 1], s[i + 2]} == off)
            a++;
        else if (i + 1 < s.size() && string{s[i], s[i + 1]} == of)
            b++;
        else if (s[i] == o[0])
            c++;
            
    a * 3 + b * 2 + c == s.size()?
        cout << "YES":
        cout << "NO";

    return 0;
}