#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> lens(n);
    int max_pos = 0;
    for (int i = 0; i < n; ++i) {
        cin >> lens[i];
        if (lens[max_pos] < lens[i])
            max_pos = i;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (max_pos != i)
            sum += lens[i]; 
    }
    if (sum < lens[max_pos])
        cout << lens[max_pos] - sum;
    else
        cout << lens[max_pos] + sum;

    return 0;
}
