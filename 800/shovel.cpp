#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, r;

    cin >> k >> r;

    for (int i = 1; i < 10; i++)
        if ((k * i) % 10 == r || (k * i) % 10 == 0) {
            cout << i;
            break;
        }

    return 0;
}