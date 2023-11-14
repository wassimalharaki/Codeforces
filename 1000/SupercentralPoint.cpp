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

    //up, down, right, left
    v<vi> points(n, vi(4));
    v<tuple<int, int, int>> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> get<0>(x[i]);
        cin >> get<0>(y[i]);
        get<1>(x[i]) = get<0>(y[i]);
        get<1>(y[i]) = get<0>(x[i]);
        get<2>(x[i]) = get<2>(y[i]) = i;
    }
    sort(all(x));
    sort(all(y));

    for (int i = 0; i < n - 1; i++) {
        if (get<0>(x[i]) != get<0>(x[i + 1]))
            continue;
        
        points[get<2>(x[i])][0]++;
        points[get<2>(x[i + 1])][1]++;
    }

    for (int i = 0; i < n - 1; i++) {
        if (get<0>(y[i]) != get<0>(y[i + 1]))
            continue;
        
        points[get<2>(y[i])][2]++;
        points[get<2>(y[i + 1])][3]++;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
        if (*min_element(all(points[i])))
            count++;
    cout << count nl;

    return 0;
}