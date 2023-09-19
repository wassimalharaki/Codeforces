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

int32_t main() {
    fast

    string s; cin >> s; int n = s.size();

    int count = 0;

    for (int i = 0; i < n; i++)
        if (s[i] == 'Q')
            for (int j = i + 1; j < n; j++)
                if (s[j] == 'A')
                    for (int k = j + 1; k < n; k++)
                        if (s[k] == 'Q')
                            count++;
    cout << count nl;

    return 0;
}