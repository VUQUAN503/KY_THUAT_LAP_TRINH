
#include <iostream>
#include <string.h>
#include <iomanip>



int main()
{
    std::string name = "vu dinh quan";
    std::string maso = "2020606122";
    int age = 19;
    std::cout <<"|" <<std::setw(15) << name << "|" <<std::setw(12) << maso << "|" << std::endl;
     std::cout <<"|" <<std::setw(15) << name << "|" <<std::setw(12) << maso << "|" << std::endl;
    // char str[255];
    // Bai_1(str);
    // char s[50];
    // std::cout << "Nhap s: ";
    // gets(s);
    // if(StrStr(str, s) >= 0)
    // {
    //     std::cout << "vi tri xh dau tien cua x trong str la: " << StrStr(str, s);
    // }
    return 0;
}