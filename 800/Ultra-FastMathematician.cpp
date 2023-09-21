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

    string s1, s2, s3; cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); i++)
        if (s1[i] == s2[i])
            s3 += '0';
        else
            s3 += '1';

    cout << s3;

    return 0;
}