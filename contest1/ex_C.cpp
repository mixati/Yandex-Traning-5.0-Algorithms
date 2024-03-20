#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int count;
        cin >> count;
        if (count % 4 == 1) {
            --count;
            ++ans;
        }
        else if (count % 4 == 2) {
            count -= 2;
            ans += 2;
        }
        else if (count % 4 == 3) {
            count -= 3;
            ans += 2;
        }
        ans += count / 4;
    }
    cout << ans;

    return 0;
}