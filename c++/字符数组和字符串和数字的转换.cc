#include <iostream>
#include <string>
using namespace std;

// 数字转字符数组
//C语言
void numToCharArray(int num) {
    // 方法1:
    char buf[SIZE]; 
    sprintf(buf, “my data is %d”, num);

    //方法2:
    itoa(123 ,buf ,10 );
}

//数字转string
//c++98
void numToString(int num) {
    ostringstream oss; 
    oss « 15 « ” is int, ” « 3.14f « ” is float.” « endl; 
    cout « oss.str();
}
// c++11
void numToString(int num) {
    string s = to_string(num);
}

// 字符数组转int
void charArrayToNum(char * c) {
    int i  = atoi(c);
}
// 字符串转int c++11
void stringToInt(string s) {
    int i = stoi(s);
}

int main() {

    return 0;
}