#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int l1, l2;
    string word1, word2;
    cin >> word1 >> word2;
    l1 = word1.size();
    l2 = word2.size();
    if (l1 == l2) {
        for (int i = l1 - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (word1[j] > word1[j + 1]) {
                    swap(word1[j], word1[j + 1]);
                }
                if (word2[j] > word2[j + 1]) {
                    swap(word2[j], word2[j + 1]);
                }
            }
        }
        if (word2 == word1) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
}

