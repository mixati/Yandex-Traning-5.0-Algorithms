#include <iostream> 
#include <string>

using namespace std;

int main() {
    string match1, match2;
    int place;
    cin >> match1 >> match2 >> place;

    int A1 = match1[0] - '0';
    int A2 = match2[0] - '0';
    int B1 = match1[2] - '0';
    int B2 = match2[2] - '0';

    if (A1 + A2 > B1 + B2)
        cout << 0;
    else if (A1 + A2 == B1 + B2) {
        if (place == 1) {
            if (A2 > B1)
                cout << 0;
            else
                cout << 1;
        }
        else {
            if (A1 > B2)
                cout << 0;
            else
                cout << 1;
        }
    }
    else if (place == 1) {
        int tmp = B1 + B2 - A1 - A2;
        if (A2 + tmp > B1)
            cout << tmp;
        else
            cout << B1 + B2 - A1 - A2 + 1;
    }
    else {
        if (A1 > B2)
            cout << B1 + B2 - A1 - A2;
        else
            cout << B1 + B2 - A1 - A2 + 1;
    }

    return 0;
}