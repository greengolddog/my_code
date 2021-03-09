#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;
ll summ = 0;

void prov(vector<vector<ll>>& arr, vector<vector<ll>>& arr2, ll i, ll j) {
    if (arr2[i][j] == -1) {
        if (arr[i - 1][j] < arr[i][j]) {
            arr2[i][j] = 1;
        }
        if (arr[i + 1][j] < arr[i][j]) {
            arr2[i][j] = 1;
        }
        if (arr[i][j - 1] < arr[i][j]) {
            arr2[i][j] = 1;
        }
        if (arr[i][j + 1] < arr[i][j]) {
            arr2[i][j] = 1;
        }
    }
    if (arr2[i][j] != -1) {
        if (arr2[i - 1][j] == -1) {
            if (arr[i - 1][j] == arr[i][j]) {
                arr2[i - 1][j] = 1;
                prov(arr, arr2, i - 1, j);
            }
        }
        if (arr2[i + 1][j] == -1) {
            if (arr[i + 1][j] == arr[i][j]) {
                arr2[i + 1][j] = 1;
                prov(arr, arr2, i + 1, j);
            }
        }
        if (arr2[i][j - 1] == -1) {
            if (arr[i][j - 1] == arr[i][j]) {
                arr2[i][j - 1] = 1;
                prov(arr, arr2, i, j - 1);
            }
        }
        if (arr2[i][j + 1] == -1) {
            if (arr[i][j + 1] == arr[i][j]) {
                arr2[i][j + 1] = 1;
                prov(arr, arr2, i, j + 1);
            }
        }
    }
}

void prov2(vector<vector<ll>>& arr, vector<vector<ll>>& arr2, ll i, ll j) {
    if (arr2[i][j] == -1) {
        summ++;
    }
    if (arr2[i][j] < 1) {
        if (arr2[i - 1][j] == -1) {
            if (arr[i - 1][j] == arr[i][j]) {
                arr2[i - 1][j] = 0;
                prov2(arr, arr2, i - 1, j);
            }
        }
        if (arr2[i + 1][j] == -1) {
            if (arr[i + 1][j] == arr[i][j]) {
                arr2[i + 1][j] = 0;
                prov2(arr, arr2, i + 1, j);
            }
        }
        if (arr2[i][j - 1] == -1) {
            if (arr[i][j - 1] == arr[i][j]) {
                arr2[i][j - 1] = 0;
                prov2(arr, arr2, i, j - 1);
            }
        }
        if (arr2[i][j + 1] == -1) {
            if (arr[i][j + 1] == arr[i][j]) {
                arr2[i][j + 1] = 0;
                prov2(arr, arr2, i, j + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n + 2, vector<ll>(m + 2, 1000000)), arr2(n + 2, vector<ll>(m + 2, -1));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            prov(arr, arr2, i, j);
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            prov2(arr, arr2, i, j);
        }
    }
    cout << summ;
}
