#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int a;
    cin >> a;
    vector<int> arr(a, 0);
    vector<int> arr_id(a, 0);
    for (int i = 0; i < a; i++) {
        cin >> arr_id[i];
        cin >> arr[i];
    }
    for (int i = a - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swap(arr_id[j], arr_id[j + 1]);
            }
            if (arr[j] == arr[j + 1]) {
                if (arr_id[j] > arr_id[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swap(arr_id[j], arr_id[j + 1]);
                }
            }
        }
    }
    for (int i = 0; i < a; i++) {
        cout << arr_id[i] << ' ' << arr[i] << endl;
    }
}


