#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; ++i)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int size;
    string stones;
    int remove = 0;
    cin >> size >> stones;

    loop(i, 0, size - 1) {
        if (stones[i] == stones[i + 1])
            ++remove;
    }

    cout << remove;
    
    return 0;
}