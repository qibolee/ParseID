//
// Created by QiboLee on 2016/10/8 0008.
//
#include <string>

#ifndef PARSEID_PARSER_H
#define PARSEID_PARSER_H


class Parser {
public:
    Parser(std::string str) :
            id(str), address(""), year(0), month(0), day(0), animal(""), star(""), sex("") {}

    std::string get_address();

    unsigned get_year();

    unsigned get_month();

    unsigned get_day();

    std::string get_animal();

    std::string get_star();

    std::string get_sex();

    bool check();

    void parse();

private:
    const std::string dir = "./data/";
    const std::string provfile = "./data/prvince.txt";

    std::string id;
    std::string address;
    unsigned year = 0;
    unsigned month = 0;
    unsigned day = 0;
    std::string animal;
    std::string star;
    std::string sex;

    bool equal(unsigned, char);
};


#endif //PARSEID_PARSER_H
