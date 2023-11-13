#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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

    int n; cin >> n;
    
    v<v<char>> square(n, v<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> square[i][j];

    char diag = square[0][0], body = square[0][1];
    if (diag == body) {
        cout << "NO";
        return 0;
    }

    string answ = "YES";
    for (int i = 0; i < n and answ == "YES"; i++)
        for (int j = 0; j < n; j++) {
            if (i == j || n - i - 1 == j) {
                if (square[i][j] != diag) {
                    answ = "NO";
                    break;
                }
            }
            else if (square[i][j] != body) {
                answ = "NO";
                break;
            }
        }
    cout << answ;

    return 0;
}