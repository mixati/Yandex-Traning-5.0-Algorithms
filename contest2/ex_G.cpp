#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        int count = 0; // кол-во отрезков
        int max_len = INT_MAX; // максимальная длина данного отрезка
        vector<int> lens; // длины подотрезков
        int len = 0; // длина данного подотрезка
        for (int j = 0; j < n; ++j) {
            int num;
            cin >> num;
            if (num > len && max_len > len) {
                ++len;
                max_len = min(max_len,num);
            }
            else {
                ++count;
                lens.push_back(len);                
                len = 1;
                max_len = num;
            }
        }
        ++count;
        lens.push_back(len);
        cout << count << endl;
        for (int j = 0; j < lens.size(); ++j)
            cout << lens[j] << ' ';
        cout << endl;
    }

    return 0;
}