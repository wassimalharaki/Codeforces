#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int rooms;
    int available = 0;
    cin >> rooms;
    loop(i, 0, rooms) {
        int p, q;
        cin >> p >> q;
        if (q - p >= 2)
            ++available;
    }

    cout << available;

    return 0;
}