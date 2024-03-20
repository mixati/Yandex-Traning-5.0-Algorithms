#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int count = 0; // кол-во нечетных чисел

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] % 2)
            ++count;
    }
    if (count % 2)
        for (int i = 0; i < n-1; ++i)
            cout << '+';
    else {
        bool flag = 1;
        for (int i = 0; i < n-1; ++i) {
            if (flag && nums[i] % 2) {
                flag = false;
                cout << 'x';
            }
            else
                cout << '+';
        }
    }


    return 0;
}