#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(v) v.begin(), v.end()
#define nl << '\n'
#define v vector
#define vi vector<int>
#define pii pair<int, int>

int32_t main() {
    fast

    int n, mishka = 0, chris = 0;

    cin >> n;

    while (n--) {
        int m, c;

        cin >> m >> c;

        if (m > c) 
            mishka++;
        else if (c > m)
            chris++;
    }

    if (mishka > chris)
        cout << "Mishka" nl;
    else if (chris > mishka)
        cout << "Chris" nl;
    else
        cout << "Friendship is magic!^^";

    return 0;
}