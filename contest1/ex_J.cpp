#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
    w - ширина строки
    h - стандартная высота строки
    c - ширина символов
*/

struct Helper_ {
    int w = 0;
    int h = 0;
    int c = 0;
    int pos_x = 0; // положение курсора
    int pos_y = 0;


};

struct ImageInfo_ {
    char layout = ' ';
    int width = 0;
    int height = 0;
    int dx = 0;
    int dy = 0;
};

bool is_symbol(char c) {
    if ((c >= 'a' && c <= 'z') || 
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        c == '.' || c == ',' ||
        c == ':' || c == ';' ||
        c == '!' || c == '?' ||
        c == '-' || c == '\'')
        return true;

    return false;
}

void image_handling(std::string& line, int& p, std::ofstream& out, Helper_& helper, std::vector<std::pair<int,int>>& elem_pos) {
    
    ImageInfo_ image;
    for (;line[p] != ' '; ++p) ;
    
    while (line[p] != ')') {
        // layout
        if (line[p] == 'l') {
            while (line[p] != '=') ++p;
            image.layout = line[++p];
            while (line[p] != ' ' && line[p] != ')')
                ++p;
            
        }
        // width
        else if (line[p] == 'w') {
            while (line[p] != '=') ++p;
            ++p;
            while (line[p] != ' ' && line[p] != ')') {
                image.width = image.width * 10 + (line[p] - '0');
                ++p;
            }
        }
        // height
        else if (line[p] == 'h') {
            while (line[p] != '=') ++p;
            ++p;
            while (line[p] != ' ' && line[p] != ')') {
                image.height = image.height * 10 + (line[p] - '0');
                ++p;
            }
        }
        // dx, dy
        else if (line[p] == 'd')  {
            ++p;
            if (line[p++] == 'x') {
                ++p;
                while (line[p] != ' ' && line[p] != ')') {
                    image.dx = image.dx * 10 + (line[p] - '0');
                    ++p;
                }
            }
            else {
                ++p;
                while (line[p] != ' ' && line[p] != ')') {
                    image.dy = image.dy * 10 + (line[p] - '0');
                    ++p;
                }
            }
        }
        
    }
    
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    std::string line;
    Helper_ helper;
    in >> helper.w >> helper.h >> helper.c;

    std::vector<std::pair<int,int>> elem_pos;

    getline(in,line);
    
    int word_size = 0; // размер слова
    while (getline(in, line)) {
        if (line.empty()) {


            continue;
        }
        for (int i = 0; i < line.size(); ++i) {
            if (is_symbol(line[i])) { // если слово продолжается - увеличиваем размер слова на 1
                ++word_size;
                continue;
            }

            if (line[i] == ' ') { // если слово закончилось - вставляем его 
                if ((word_size+1) * helper.c + helper.pos_x <= helper.w) {
                    helper.pos_x += (word_size+1) * helper.c;
                }
                else {
                    helper.pos_x = word_size * helper.c;
                    helper.pos_y += helper.h;
                }
                word_size = 0;
                continue;
            }

            if (line[i] == '(') {
                image_handling(line, i, out, helper, elem_pos);
            }
            
        }
    }
        
    return 0;
}
