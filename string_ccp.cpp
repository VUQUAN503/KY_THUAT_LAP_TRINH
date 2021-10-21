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

// TRONG MẢNG THÊM, XOÁ, TÌM KIẾM, SẮP XẾP, KỸ THUẬT XỬ LÝ
/*
1 2 3 4 5
TÌM THẰNG 3
+ 
*/

bool TimKiem(int a[], int n, int x)
{
    for(int i = 0; i < n; ++i)
    {
        if(x == a[i])
        {
            return true; // tìm thấy
        }
    }
    return false;// không tìm thấy
}

/*
CHUỖI BẢN CHẤT NÓ LÀ MẢNG MỘT CHIÊUD CÁC KÝ TỰ
+ CHUỖI CHỈ SỐ ĐC DÁNH DẦU TỪ 0 ĐẾN N - 1
+ ĐC HỖ TRỢ NHỮNG HÀM THAO TÁC XỬ LÝ CHUỖI
+ nhập xuất(erease, substr, length,.... )
+ 
*/

int main()
{
    //                  0123456
    // int age;
    // std::cout << "Nhap tuoi: ";
    // std::cin >> age;

    // // fflush(stdin);// xoá bộ nhớ đệm
    // std::string x;
    // std::getline(std::cin, x);
    // std::string name;
    // std::cout << "Nhap name: ";
    // std::getline(std::cin, name);
    // std::cout <<  "AGE: " << age << std::endl;
    // std::cout << "NAME: " << name;

    // std::string name = "hoc lap trinh";
    // for(int i = 0; i < name.length(); ++i)
    // {
    //     std::cout << name[i];
    // }
    // std::cout << std::endl;
    // std::cout << name;
    return 0;
}


// int main()
// {
//     // std::cin.ignore();
//     std::string name = "hoc lap trinh";
//     // // std:: cout << name.length();
//     // std::cout << name[0];
//     // std:: cout << name.compare("Hoc lap trinh");
//     name += " that kho";
//     std::cout << name;
//     // std:: cout << name;
//     // int a = 5, b = 9;
//     // Swap(a, b);
//     // std:: cout << a << std::endl;
//     // std:: cout << b << std::endl;
//     std::string number = "1234";
//     // std::cout << atoi(number.c_str());
//     return 0;
// }