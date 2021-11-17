#include <iostream>
#include <string>


int main()
{
    std::string name = "hoc c++";
    //std::string number = "1234";
    //int b = atoi(number.c_str());// chuyển number từ kiểu object string thành char * để dùng hàm atoi
    //std::cout << b + 10 << std::endl;
    std::cout << "name: ";
    puts(name.c_str());
    printf("name: %s", name.c_str());
    // auto complex
    //std::cout << "name : " << name;
   // std::cout << strupr((char *)name.c_str());
    // viết hoa tất cả ký tự(hoa kém thường 32 đơn vị)
    // for(int i = 0; i < name.length(); ++i)
    // {
    //     // nếu ký tự đó là chữ thường
    //     if(name[i] >= 'a' && name[i] <= 'z')
    //     {
    //         //name[i] = name[i] - 32;
    //         name[i] -= 32;
    //     }
    // }
    // std::cout << name << std::endl;
    // char name1[20] = "HOC C++";
    // std::cout << name << std::endl;
    // for(int i = 0; i < 7; ++i)
    // {
    //     std::cout << name[i];
    // }
    // int a = 10;
    // std::cout << std::endl;
    // std::cout << name.length() << std::endl;
    // std::cout << strlen(name1) << std::endl;
    // kiểu dữ liệu nguyên thuỷ: int, char, float, double, ...
    // MỘT SỐ HÀM THAO TÁC CHUỖI
    // CHUỖI GIỐNG NHƯ MẢNG MỘT CHIỀU
    // CHUỖI KÝ TỰ LÀ MẢNG MỘT CHIỀU CÁC KÝ TỰ(char)
    // CHÚ Ý KÝ TỰ HOA SẼ KÉM THƯỜNG 32 ĐƠN VỊ
    // CHỈ SỐ CỦA NÓ BẮT ĐẦU TỪ 0 ĐỀN N - 1
    // MỘT SỐ HÀM THAO TÁC CHUỖI
    // string nó là một lớp(class) => trong nó sẽ chứa nhưng thuộc tính(instance variable) và phương thức(hàm) hỗ trợ
    // + HÀM LẤY RA ĐỘ DÀI CỦA CHUỖI KÝ TỰ()
    // C++ string là một object => muốn truy xuất đến phương thức xử lý
    // mình lấy tên của object chấm đến tên phương thức(hàm) mình muốn xử lý
    // vd: lấy độ dài của chuỗi name.length()
    // C char[20] name => mảng ký tự thuần (kiểu dữ liệu nguyên thuỷ) => không chấm trực tiếp đc
    // mà gọi hàm đc hỗ trợ sẵn trong thư viện string.h
    // vd: hàm lấy độ dài chuỗi => strlen(name)
    //   MỘT SỐ HÀM HAY DÙNG()
    //                          C++                             C
    // lấy độ dài           name.length()                   strlen(name);
    // viết hoa all     ko hỗ trợ(tự xây dựng)              strupr(name);// upper
    // viết thường      ko hỗ trợ                           strlwr(name);lower
    // cắt chuỗi            name.substr()                    không hỗ trợ
    // hàm so sánh chuỗi    name.compare(name, name1)        strcmp(name, name1)   
    //                      nếu name > name1 => return 1
    //                      nếu name < name1 => return -1;
    //                      nếu name == name1 => return 0;
    // đổi chuỗi thành số   không hỗ trợ                     atoi(a, name, radix);
    // số thành chuỗi                                        itoa(a, name, ); 
    
    // hàm giúp chuyển đổi string về char *  (c_str)                   
    /*
    + NHẬP XUẤT CHUỖI
    + CHÚ Ý KHI NHẬP CHUỖI KHÔNG DÙNG std::cin >> 
    + THAY VÀO ĐÓ MÌNH DÙNG std::getline(std::cin, bien);
    + HIỆN TƯỢNG BỘ NHỚ ĐỆM CHỈ XẢY RA KHI TRƯỚC MÌNH NHẬP MỘT SỐ
    + VÀ SAU ĐÓ NHẬP CHUỖI
    + CÁC HÀM THAO TÁC HAY DÙNG
    */
    // int a;
    // std::cout << "Nhap a: ";
    // std::cin >> a;
    // std::cout << "Nhap string: ";
    // std::string str;
    // std::getline(std::cin, str);
    // std::cout << str;
    return 0;
}