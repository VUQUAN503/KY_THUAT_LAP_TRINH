#include <iostream>
#include <string.h>

int strLen(char str[30])
{
    int dem = 0;
    // 0123456789101112
    // hoc lap trinh// 13
    //13
    for(int i = 0; str[i] != '\0'; ++i)
    {
        dem++;
    }
    return dem;
}


int main()
{
    // int a[100] = {1, 2, 3, 4, 5};
    // khai báo mảng name có tối đa 30 ký tự
    //                 01234567891011 nhưng ký tự thứ 12 là /0 kết thúc chuỗi
    // char name_1[30] = "vu dinh quan";
    // name_1[7] = '\0';
    // std::cout << name_1;
    // // chuỗi là một mảng ký tự
    // char x = 'a';
    // char maso[20];
    //LƯU Ý KHI NHẬP CHUỖI NẾU KHI NHẬP MỘT CHUỖI MÀ TRƯỚC NÓ TA ĐÃ NHẬP MỘT SỐ NGUYÊN HOẠC SỐ THỰC
    // THÌ MÌNH CẦN PHẢI XÓA BỘ NHỚ ĐỆM
    // std::cout << "Nhap maso: ";
    // gets(maso);
    // char name[30];
    // std::cout << "Nhap name: ";
    // gets(name);
    // std::cout << "age: " << maso << std::endl;
    // std::cout << "name: " << name << std::endl;
    /*
    chữ thường lớn hơn chữ hoa 32 đơn vị
    ký tự số hơn số 48 đơn vị
    '1' lớn hơn 1 48 đơn vị
    */
    // for(int i = 0; i < 258; ++i)
    // {
    //     std::cout << (char)i << " ";
    // }
// MỘT SỐ HÀM THAO TÁC VỚI CHUỖI str
    // char name[30] = "Dinh Khac Tuan";// length
    // char name_1[30];
    // strcpy(name_1, name);
    // strlwr(name);// lower tất cả ký tự thành chữ cái thường
    // strupr(name_1);// tất cả ký tự thành chữ cái hoa
    // strrev(name);
    // std::cout << name << std::endl;
    // std::cout << name_1;
    //                         8
    char name[30] =   "Hoc iap trinh";
    char name_1[30] = "trinh";
    // int result = strcmp(name, name_1);
    // std::cout << result << std::endl;
    std::cout << atoi("1234");
    
    return 0;
}