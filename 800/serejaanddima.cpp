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

    int n; cin >> n;
    vi cards(n);

    for (int i = 0; i < n; i++)
        cin >> cards[i];

    int sereja = 0, dima = 0;

    for (int i = 0, j = n - 1; i <= j;) {
        if (cards[i] > cards[j]) {
            sereja += cards[i];
            i++;
        }
        else {
            sereja += cards[j];
            j--;
        }

        if (i > j)
            break;
        
        if (cards[i] > cards[j]) {
            dima += cards[i];
            i++;
        }
        else {
            dima += cards[j];
            j--;
        }
    }

    cout << sereja << " " << dima;

    return 0;
}