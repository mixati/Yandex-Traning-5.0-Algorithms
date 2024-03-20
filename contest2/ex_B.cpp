#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> prices(n);

    for (int i = 0; i < n; ++i)
        cin >> prices[i];

    int ans = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n && j - i <= k; ++j) {
            int tmp = prices[j] - prices[i];
            ans = max(ans,tmp);
        }
    }
    cout << ans;

    return 0;
}
