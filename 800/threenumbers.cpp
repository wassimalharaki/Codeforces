#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> x(4);
    cin >> x[0] >> x[1] >> x[2] >> x[3];

    sort(x.begin(), x.end());

    cout << x[3] - x[2] << " " << x[3] - x[1] << " " << x[3] - x[0];

    return 0;
}