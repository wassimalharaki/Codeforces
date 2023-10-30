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

void add(char c, int& player) {
    c = tolower(c);
    if (c == 'q')
        player += 9;
    else if (c == 'r')
        player += 5;
    else if (c == 'n')
        player += 3;
    else if (c == 'b')
        player += 3;
    else if (c == 'p')
        player += 1;
}

int32_t main() {
    fast;

    int white = 0, black = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            char c; cin >> c;
            islower(c) ? add(c, black) : add(c, white);
        }
    white > black ? cout << "White" : white < black ? cout << "Black" : cout << "Draw";

    return 0;
}