#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int magnets;
    cin >> magnets;
    vector<string> order;

    loop(i, 0, magnets) {
        string magnet;
        cin >> magnet;
        order.push_back(magnet);
    }
    int groups = 1;
    for (int i = 0; i < order.size() - 1; ++i) {
        if (order[i] != order[i + 1])
            groups++;
    }

    cout << groups;

    return 0;
}