#include <iostream>
#include <string>

// function template(khuân mẫu hàm, Generric)
// template <typename HocLapTrinh>
// void Swap(HocLapTrinh &a, HocLapTrinh &b)
// {
//     HocLapTrinh tg = a;
//     a = b;
//     b = tg;
// }


int main()
{
    // std::cin.ignore();
    std::string name = "hoc lap trinh";
    // // std:: cout << name.length();
    // std::cout << name[0];
    // std:: cout << name.compare("Hoc lap trinh");
    name += " that kho";
    std::cout << name;
    // std:: cout << name;
    // int a = 5, b = 9;
    // Swap(a, b);
    // std:: cout << a << std::endl;
    // std:: cout << b << std::endl;
    std::string number = "1234";
    // std::cout << atoi(number.c_str());
    return 0;
}