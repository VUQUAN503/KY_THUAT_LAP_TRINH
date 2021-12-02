/*
        KIỂU SỮ LIỆU CẤU TRÚC(STRUCT)
ghi chú

KIỂU DỮ LIỆU NGUYÊN THUỶ(PRIMITED)
+ int, float, double, char, bool, long, ..

+ ĐIỂM(TRONG HÌNH HỌC)
-- TÍNH KHOẢNG CÁCH HAI ĐIỂM TRONG 1 ĐƯỜNG THẲNG
+ ĐƯỢC TẠO THÀNH TỪ HAI THỨ : HOÀNH ĐỘ TUNG ĐỘ
VD A(2, 3);
HOÀNH ĐỘ VÀ TUNG ĐỘ LÀ HAI KIỂU DỮ LIỆU NGUYÊN THUỶ (FLOAT)

=> KIỂU STRUCT NÓ LÀ KIỂU DỮ LIỆU DO MÌNH TỰ ĐẶT TÊN (DIEM, SINHVIEN, MONHOC, ..)
MÀ NÓ KHÔNG CÓ SẴN TRONG NGÔN NGỮ LẬP TRÌNH
MÀ NÓ ĐC TẠO RA TỪ NHIỀU KIỂU LIỆU NGUYÊN THUỶ CÓ SẴN
+ VD SINHVIEN(TRỪU TƯỢNG HOÁ DỮ LIỆU TRONG OOP)
- TENSV, MASO, AGE
- char[], char[], int
MONHOC
TENMH, SOTC, MAMH

CÚ PHÁP KHAI BÁO RA MỘT KIỂU DỮ LIỆU
struct SinhVien{
    // trong đây là trường thuộc tính, thông tin cấu hình lên kiểu dữ liệu đó
    string name;
    string maso;
    int age;
};

MUỐN TRUY ĐẾN TỪNG THÀNH PHẦN HAY LÀ TỪNG THUỘC TÍNH HAY TỪNG ĐƠN VỊ , THÔNG TIN
CẤU TẠO LÊN NÓ BẰNG CÁCH THÔNG QUA .
GIỐNG NHƯ std::string name = "dkdfdk"
name.length

vd SinhVien x;
=> muốn lấy ra tên của thành sinh viên => x.TENSV
*/

#include <iostream>
#include <string>
#include <cmath>

// khai báo kiểu dữ liệu mới
struct Diem{
    float x, y;
};


// viết hàm nhập thông tin cho một điểm trong không gian
/* nhập n
void Nhap(int &n)
{
    cout << "Nhap n: ";
    cin >> n;
}


*/
void Nhap(Diem &A)
{
    // thàng Diem không như kiểu int, float... bình thường mà nó đc cấu hình từ 
    // nhiều kiểu dữ liệu int , float, ...
    // => muốn nhập đc thông tin cho kiểu dữ liệu Diem => mình nhập từng thông tin, thuộc tính trong cái kiểu
    // dữ liệu điểm đó
    std::string name = "mand";
    std::cout << "Nhap hoanh do: ";
    std:: cin >> A.x;
    std::cout << "Nhap tung do: ";
    std:: cin >> A.y;
}

void Xuat(Diem A)
{
    // a(1, 2);
    std::cout << "A(" << A.x << ", " << A.y << ")" << std::endl;
}

// tính khoảng cách hai điểm trong mặt phẳng
float KhoangCachHaiDiem(Diem A, Diem B)
{
    // căn của x1 - x2 bình + y1 - y2 bình
    return sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
}


int main()
{
    Diem A, B;
    // Nhap cho a
    Nhap(A);
    Nhap(B);
    Xuat(A);
    Xuat(B);
    std::cout << "Khoang cach hai diem A, B la: " << KhoangCachHaiDiem(A, B);
    return 0;
}