#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> arr2(10000001, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int maximum = arr[0];
    for (int i = 1; i < n; i++) {
        maximum = min(maximum, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr2[arr[i]-maximum]++;
    }
    for (int i = 0; i <= 10000001; i++) {
        for (int j = 0; j < arr2[i]; j++) {
            cout << i + maximum << ' ';
        }
    }
}