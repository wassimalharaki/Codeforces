#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];

    loop(i, 0, n) {
        int a;
        cin >> a;
        arr[a - 1] = i + 1;
    }

    loop(i, 0, n)
        cout << arr[i] << " ";
    return 0;
}