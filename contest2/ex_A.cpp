#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    int k;
    cin >> k;

    int min_x = INT_MAX,
        min_y = INT_MAX,
        max_x = 0,
        max_y = 0;

    for (; k > 0; --k) {
        int x, y;
        cin >> x >> y;
        min_x = min(min_x, x);
        min_y = min(min_y, y);
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }

    cout << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y;

    return 0;
}
