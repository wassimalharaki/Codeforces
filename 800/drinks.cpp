#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    double sum = 0;
    loop(i , 0, n) {
        int j;
        cin >> j;
        sum += j;
    }

    cout << sum / n;

    return 0;
}