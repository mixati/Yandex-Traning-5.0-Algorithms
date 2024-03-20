#include <iostream>
#include <cmath>
#include <string>


using namespace std;
/*
    n - изначальная прибыль
    k - кол-во учредителей компании
    d - кол-во дней
*/

void fill_str(string& str, unsigned long long len) {
    for (; len; --len)
        str.push_back('0');
}

int recurs(string& ans_, unsigned long long n, unsigned long long k, unsigned long long d) {
    unsigned long long ans = 0;
    
    for (int i = 0; i < 10; ++i) {
        unsigned long long tmp = (n * 10) + i;
        if ((tmp % k) == 0) {
            ans_ = to_string(tmp);
            fill_str(ans_, d-1);
            
            return 0;
        }
    }

    return -1;
}

int main() {
    unsigned long long n, k, d;
    string ans;
    cin >> n >> k >> d;
    ans = to_string(n);
    int res = recurs(ans, n, k, d);
    if (res == -1) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}