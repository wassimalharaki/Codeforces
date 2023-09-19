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

    int n; cin >> n;

    string orig, code; cin >> orig >> code;

    int steps = 0;

    for (int i = 0; i < n; i++) {
        if (orig[i] > code[i]) {
            steps += min(orig[i] - code[i], '9' - orig[i] + 1 + code[i] - '0');
        }
        else if (orig[i] < code[i]) {
            steps += min(code[i] - orig[i], '9' - code[i] + 1 + orig[i] - '0');
        }
    }

    cout << steps nl;
    return 0;
}