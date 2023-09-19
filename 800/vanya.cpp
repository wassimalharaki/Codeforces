#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n >> h;
    int width = n;
    loop(i, 0, n) {
        int height;
        cin >> height;
        if (height > h)
            ++width;
    }

    cout << width;

    return 0;
}