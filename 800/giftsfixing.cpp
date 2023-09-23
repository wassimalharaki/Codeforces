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
        int n; cin >> n;
        int steps = 0, mina = INF, mino = INF;

        vi apples(n), oranges(n);
        for (int i = 0; i < n; i++) {
            cin >> apples[i];
            if (apples[i] < mina) 
                mina = apples[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> oranges[i];
            if (oranges[i] < mino)
                mino = oranges[i];
        }

        for (int i = 0; i < n; i++)
            if (apples[i] > mina && oranges[i] > mino) {
                int amount = min(apples[i] - mina, oranges[i] - mino);
                steps += amount;
                apples[i] -= amount;
                oranges[i] -= amount;
                steps += apples[i] - mina + oranges[i] - mino;
            }
            else if (apples[i] > mina)
                steps += apples[i] - mina;
            else if (oranges[i] > mino)
                steps += oranges[i] - mino;

        cout << steps nl;
    }

    return 0;
}