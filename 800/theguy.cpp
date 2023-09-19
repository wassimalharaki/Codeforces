#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

bool find(int arr[], int a, int size);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p, q;
    cin >> n >> p;
    int x[p];

    loop(i, 0, p)
        cin >> x[i];

    cin >> q;
    int y[q];

    loop(i, 0, q)
        cin >> y[i];

    loop(i, 1, n + 1)
        if (!(find(x, i, p) || find(y, i, q))) {
            cout << "Oh, my keyboard!";
            return 0;
        }
    
    cout << "I become the guy.";

    return 0;
}

bool find(int arr[], int a, int size) {
    loop(i, 0, size)
        if (a == arr[i])
            return true;
    return false;
}