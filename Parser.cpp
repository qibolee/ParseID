//
// Created by QiboLee on 2016/10/8 0008.
//

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

#include "Parser.h"

using namespace std;

string Parser::get_address() {
    return address;
}

unsigned Parser::get_year() {
    return year;
}

unsigned Parser::get_month() {
    return month;
}

unsigned Parser::get_day() {
    return day;
}

string Parser::get_animal() {
    return animal;
}

string Parser::get_star() {
    return star;
}

string Parser::get_sex() {
    return sex;
}

bool Parser::check() {
    unsigned wt[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    unsigned sum = 0;
    if (id.size() != 18) {
        return false;
    }
    for (size_t i = 0; i < id.size() - 1; ++i) {
        if (!isdigit(id[i])) {
            return false;
        }
    }
    if (tolower(id.back()) != 'x' && !isdigit(id.back())) {
        return false;
    }
    for (size_t i = 0; i < id.size() - 1; ++i) {
        sum += (id[i] - '0') * wt[i];
    }
    sum %= 11;
    if (!equal(sum, id.back())) {
        return false;
    }
    year = stoi(id.substr(6, 4));
    month = stoi(id.substr(10, 2));
    day = stoi(id.substr(12, 2));
    if (month > 12 || month == 0 || day > 31 || day == 0) {
        year = 0;
        month = 0;
        day = 0;
        return false;
    }
    return true;
}

bool Parser::equal(unsigned u, char c) {
    char verify[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    return c == verify[u];
}

void Parser::parse() {
    if (!check()) {
        throw runtime_error("the id number is error");
    }
    year = stoi(id.substr(6, 4));
    month = stoi(id.substr(10, 2));
    day = stoi(id.substr(12, 2));
    if ((id[16] - '0') % 2 == 0) {
        sex = "女";
    } else {
        sex = "男";
    }
    ifstream inp(provfile);
    string line;
    while (inp >> line) {
        if (line.substr(0, 2) == id.substr(0, 2)) {
            address = line.substr(3);
            break;
        }
    }
    inp.close();
    string path = dir + id.substr(0, 2) + ".txt";
    ifstream ina(path);
    while (ina >> line) {
        if (line.substr(0, 6) == (id.substr(0, 4) + "00")) {
            address += line.substr(7);
        } else if (line.substr(0, 6) == id.substr(0, 6)) {
            address += line.substr(7);
            break;
        }
    }
    ina.close();

    //animal
    vector<string> ani = {"鼠", "牛", "虎", "兔", "龙", "蛇", "马", "羊", "猴", "鸡", "狗", "猪"};
    vector<string> str = {"摩羯", "水瓶", "双鱼", "白羊", "金牛", "双子", "巨蟹", "狮子", "处女", "天秤", "天蝎", "射手"};
    animal = ani[(year - 4) % 12];
    //star
    if ((month == 12 && day > 21) || (month == 1 && day < 21)) {
        star = str[0];
    } else if ((month == 1 && day > 20) || (month == 2 && day < 20)) {
        star = str[1];
    } else if ((month == 2 && day > 19) || (month == 3 && day < 21)) {
        star = str[2];
    } else if ((month == 3 && day > 20) || (month == 4 && day < 21)) {
        star = str[3];
    } else if ((month == 4 && day > 20) || (month == 5 && day < 22)) {
        star = str[4];
    } else if ((month == 5 && day > 21) || (month == 6 && day < 22)) {
        star = str[5];
    } else if ((month == 6 && day > 21) || (month == 7 && day < 23)) {
        star = str[6];
    } else if ((month == 7 && day > 22) || (month == 8 && day < 24)) {
        star = str[7];
    } else if ((month == 8 && day > 23) || (month == 9 && day < 24)) {
        star = str[8];
    } else if ((month == 9 && day > 23) || (month == 10 && day < 24)) {
        star = str[9];
    } else if ((month == 10 && day > 23) || (month == 11 && day < 23)) {
        star = str[10];
    } else if ((month == 11 && day > 22) || (month == 12 && day < 22)) {
        star = str[11];
    }

}



