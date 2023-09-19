#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int horseshoes[4];
    loop(i, 0, 4)
        cin >> horseshoes[i];
    sort(horseshoes, horseshoes + 4);
    int num = 0;
    loop(i, 0, 3)
        if (horseshoes[i] == horseshoes[i + 1])
            ++num;
    
    cout << num;

    return 0;
}