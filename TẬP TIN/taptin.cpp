#include <iostream>
#include <fstream>
#include <string>

//Kiểu sữ liệu cấu trúc struct(có thể làm đc như oop luôn nhưng mình sẽ ko học)

int main()
{

    std::ifstream fileIn;
    fileIn.open("abc.txt", std::ios_base::in);
    std::string subject;
    std::getline(fileIn, subject);// nhập bằng getline là lấy hết một dòng
    // fileIn >> subject;
    // chú ý nếu nhập chuỗi từ tập tin dùng hàm getline() nếu ko dữ liệu chỉ lấy đc 1 từ
    // khi nhập từ bàn phím với chuỗi có vấn đề gì
    // dùng cin >> nhập cho chuỗi có vấn đề gì
    fileIn.close();
    std::cout << subject;
    //   ĐỌC
    // int *arr = new int[5]; // khai báo mảng có 5 phần tử
    // // nhập từ bàn phím -> duyệt mảng và std::cin >> arr[i];
    // std::ifstream fileIn;
    // fileIn.open("abc.txt", std::ios_base::in);
    // //nhập từ file => duyệt mảng => fileIn >> arr[i];
    // for(int i = 0; i < 5; ++i)
    // {
    //     fileIn >> arr[i];
    // }

    // fileIn.close();
    // // đã kết thúc quá trình đọc dữ liệu từ file
    // // xuất ra màn hình và xem thành quả
    // for(int i = 0; i < 5; ++i)
    // {
    //     std::cout << arr[i] << " ";
    // }

    // std::ofstream fileOut;
    // /*
    //     GHI
    // HÀM open có hai tham số
    // + tham số thứ nhất tên tập tin mình muốn mở
    // + nếu 
    // + tham số thứ hai chính là đối số
    // - đối số: out : dùng để ghi mỗi một lần ghi thì dữ liệu gốc của file đó sẽ bị mất
    // đi và ghi dữ liệu mới vào
    // - đối số: app dùng để ghi nhưng dữ liệu gốc sẽ không bị mất đi mà dữ liệu mới đc ghi
    // ngay đằng sau dữ liệu cũ
    // - in: dùng để nhập
    // */
    // fileOut.open("abc.txt", std::ios_base::out);
    // // xử lý ghi ở đoạn này
    // //bình thường xuất ra màn hình
    // // std::cout << ;
    // fileOut << " 1 2 3 4 5";
    // fileOut.close();//đóng file 
}