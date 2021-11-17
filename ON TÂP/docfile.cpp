#include <iostream>
#include <fstream>
#include <string>

/*
        ĐỌC DỮ LIỆU TỪ TỆP RA CHƯƠNG TRÌNH
NẰM TRONG THƯ VIỆN FSTREAM => MUỐN DÙNG THÌ KHAI BÁO THƯ VIỆN
+ class ifstream
// khai báo mở, đóng tệp tương tự
+ tham số thứ nhất đường dẫn đến tệp
+ tham số thứ hai chính là đối số: đối số duy nhất in

THAO TÁC ĐỌC(NHẬP) DỮ LIỆU
+ NẾU MÌNH NHẬP CHUỖI BẰNG STD::CIN >> string
=> nó chỉ lấy đc dữ liệu nhập đến trước khoảng trắng vd hoc c++ nếu nhạp bằng cin 
=> chỉ lấy đc hoc => GIẢI PHÁP KHI NHẬP CHUỖI BAO H CŨNG DÙNG STD::GETLINE(cin, name) HOẶC GETS()
=> TƯƠNG TỰ NHƯ VẬY THÌ ĐỌC TỪ FILE NÓ CŨNG CÓ VẤN ĐỀ XẢY RA TƯƠNG TỰ
=> NẾU dùng FileIn >> để nhập xảy ra vấn đề tương tự
=> giải pháp dùng hàm getline(tên file, name)

+ CHÚ Ý NẾU ĐƯỜNG DẪN TỆP KHÔNG TỒN TẠI => CHƯƠNG TRÌNH KHÔNG BÁO LỖI => KHI RUN(CHẠY)
=> LÀ NGẮT CHƯƠNG TRÌNH VÀ BÁO LỖI
*/

int main()
{
    // đọc dữ liệu từ tệp vào mảng
    int *a = new int[5];
    std::ifstream fileIn;
    // mở file để thao tác
    fileIn.open("dulieu.txt", std::ios_base::in);
    // kiểm tra xem file đó có tồn tại hay không
    // nếu tồn tại thì mới thao tác đọc còn không tồn tại => thông báo cho ngườ dùng biết
    // THAO TÁC ĐỌC
    // nếu đọc từ bàn phím => duyệt qua số lượng phần tử muốn nhập và std::cin >> 
    // => đọc từ file vào tương tự ta chỉ cần thay cin thành tên file của mình
    // bằng cách dùng phương thức good
    if(fileIn.good())
    {
        std::cout << "co ton tai file";
        // for(int i = 0; i < 5; ++i)
        // {
        // // std::cin >> a[i] ; nhập từ bàn phím
        //     fileIn >> a[i];
        // }
    }
    else{// nếu file không tồn tại => thông báo
        std::cout << "file do khon ton tai" << std::endl;
    }
    // đóng tệp lại
    fileIn.close();
    // sau khi đọc xong => mảng đã có dữ liệu => mình xuất ra màn hình kiểm tra
    // for(int i = 0; i < 5; ++i)
    // {
    //     std::cout << a[i] << " ";
    // }
    delete[] a;
    // std::ifstream ahihi;// khai báo tên (object);
    // // mở file ra để thao tác
    // std::string subject;
    // ahihi.open("dulieu.txt", std::ios_base::in);
    // // THAO TÁC ĐỌC
    // // std::cin >> subject; nhập từ bàn phím
    // //ahihi >> subject; // nhập từ file;
    // // => nếu dùng ahihi >> để đọc chuỗi => fail chỉ nhận đc dữ liệu trước khoảng trắng đầu tiên
    // // => giải pháp dùng getline() vấn đề tương tự string
    // // std::getline(std::cin, name); đọc từ bàn phím
    // std::getline(ahihi, subject);
    // std::cout << subject << std::endl;
    // // đóng tệp trước khi quá muộn
    // ahihi.close();
    return 0;
}