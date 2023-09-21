#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int curr = 0, mincap = 0;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        curr -= a - b;
        mincap = max(mincap, curr);
    }

    cout << mincap;

    return 0;
}