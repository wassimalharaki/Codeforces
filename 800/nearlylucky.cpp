#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string num;
    cin >> num;
    int luckynum = 0;

    loop(i, 0, num.length())
        if (num[i] == '4' || num[i] == '7')
            ++luckynum;
    
    if (luckynum == 4 || luckynum == 7)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}