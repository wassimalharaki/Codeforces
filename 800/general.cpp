#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int max = 0, min = INT_MAX;
    int iMax = -1, iMin = -1;

    loop(i, 0, n) {
        int h;
        cin >> h;
        if (h > max) {
            max = h;
            iMax = i;
        }
        if (h <= min) {
            min = h;
            iMin = i;
        }
    }
    if (iMax > iMin)
        cout << iMax + n - 2 - iMin;
    else 
        cout << iMax + n - 1 - iMin;
   
    return 0;
}