#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long os, osh, op, n;
    cin >> n;
    op = (n * (n - 1) * (n - 2) * (n - 3) * (n - 4)) / 120;
    osh = (op * (n - 5)) / 6;
    os = (osh * (n - 6)) / 7;
    cout << op+osh+os;
}