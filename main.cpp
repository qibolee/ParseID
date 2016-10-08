#include <iostream>
#include "Parser.h"

using namespace std;

int main(int argc, char *argv[]) {
    string id;
    cout << "请输入身份证号：" << endl;
    while (cin >> id) {
        Parser par(id);
        if (!par.check()) {
            cout << "身份证号不正确！" << endl;
        } else {
            par.parse();
            cout << "查得个人信息为：" << endl;
            cout << "地    址：" << par.get_address() << endl;
            cout << "出生日期：" << par.get_year() << "年" << par.get_month() << "月" << par.get_day() << "日" << endl;
            cout << "性    别：" << par.get_sex() << endl;
            cout << "属    相：" << par.get_animal() << endl;
            cout << "星    座：" << par.get_star() << endl;
        }
        cout << "\n请输入身份证号：" << endl;
    }
    return 0;
} 
