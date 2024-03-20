#include <iostream>
#include <string>

using namespace std;

int main() {
    string desk[8];

    for (int i = 0; i < 8; ++i) {
        cin >> desk[i];
    }

    int ans = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            
            // ЛАДЬЯ
            if (desk[i][j] == 'R') {
                int vert = i-1;
                int gor = j-1;
                ++ans;
                // идем по вертикали вверх
                for (; vert >= 0 && (desk[vert][j] == '*' || desk[vert][j] == 't') ; --vert ) {
                    if (desk[vert][j] == '*') {
                        desk[vert][j] = 't';
                        ++ans;
                    }
                }
                // идем по вертикали вниз
                for (vert = i+1; vert < 8 && (desk[vert][j] == '*' || desk[vert][j] == 't') ; ++vert) {
                    if (desk[vert][j] == '*') {
                        desk[vert][j] = 't';
                        ++ans;
                    }
                }

                // идем по горизонтали влево
                for (; gor >= 0 && (desk[i][gor] == '*' || desk[i][gor] == 't') ; --gor ) {
                    if (desk[i][gor] == '*') {
                        desk[i][gor] = 't';
                        ++ans;
                    }
                }
                // идем по горизонтали вправо
                for (gor = j+1; gor < 8 && (desk[i][gor] == '*' || desk[i][gor] == 't') ; ++gor ) {
                    if (desk[i][gor] == '*') {
                        desk[i][gor] = 't';
                        ++ans;
                    }
                }
            }

            // СЛОН
            else if (desk[i][j] == 'B') {
                int vert = i-1;
                int gor = j-1;
                ++ans;

                // идет вверх влево
                for (; vert >= 0 && gor >= 0 && (desk[vert][gor] == '*' || desk[vert][gor] == 't') ; --vert, --gor) {
                    if (desk[vert][gor] == '*') {
                        desk[vert][gor] = 't';
                        ++ans;
                    } 
                }

                // идет вверх вправо
                for (vert = i-1, gor = j+1; vert >= 0 && gor < 8 && (desk[vert][gor] == '*' || desk[vert][gor] == 't') ; --vert, ++gor) {
                    if (desk[vert][gor] == '*') {
                        desk[vert][gor] = 't';
                        ++ans;
                    }
                }

                // идет вниз влево
                for (vert = i+1, gor = j-1; vert < 8 && gor >= 0 && (desk[vert][gor] == '*' || desk[vert][gor] == 't') ; ++vert, --gor) {
                    if (desk[vert][gor] == '*') {
                        desk[vert][gor] = 't';
                        ++ans;
                    }
                }

                // идет вниз вправо
                for (vert = i+1, gor = j+1; vert < 8 && gor < 8 && (desk[vert][gor] == '*' || desk[vert][gor] == 't') ; ++vert, ++gor) {
                    if (desk[vert][gor] == '*') {
                        desk[vert][gor] = 't';
                        ++ans;
                    }
                }
            }
        }
    }

    cout << 64 - ans;

    return 0;
}