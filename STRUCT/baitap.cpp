//                  QUẢN LÝ THÔNG TIN ĐIỂM THI CỦA LỚP HỌC
/*
KHAI BÁO MỘT KIỂU DỮ LIỆU SINH VIÊN GỒM NHỮNG THÔNG TIN TÊN, MASO, AGE, DIEM TOAN, LY, HOA
+ NHẬP DANH SÁCH SINH VIÊN TRONG LỚP HỌC(ok)
+ XUẤT DANH SÁCH SINH VIÊN TRONG LỚP VÀ ĐIỂM TRUNG BÌNH CỦA TỪNG SINH VIÊN(ok)
+ TÌM THÔNG TIN CỦA SINH VIÊN CÓ ĐIỂM TRUNG BÌNH CAO NHẤT LỚP(ok)
+ XUẤT DANH SÁCH SINH VIÊN THI LẠI (ĐIỀU KIỆN THI LẠI LÀ SINH VIÊN CÓ ĐIỂM TRUNG BÌNH < 4)(ok)
+ SẮP XẾP DANH SÁCH SINH VIÊN TRONG LỚP THEO ĐIỂM TRUNG BÌNH GIẢM DẦN(ok)
+ SẮP XẾP DANH SÁCH SINH VIÊN THEO THỨ TỰ TANG DAN TEN(ok)
+ KHÔNG CÓ SINH VIÊN NÀO MÃ GIỐNG NHAU

vd 2020, 2021
=> nhập 2020 => bắt nhập lại 
+ nếu chưa có => cho nhập tiếp

NGUYEN VAN AN
TRAN VAN A
*/

#include <iostream>
#include <string>

using namespace std;

// kiểu sinh viên
struct Student{
    string name;
    string rollNo;
    int age;
    float toan, ly, hoa;
};

// nhập thông tin sinh viên
void NhapMotSinhVien(Student &sv)
{
    // => nhập từng trường thông tin một của sv

    cout << "Nhap name: ";
    getline(cin, sv.name);

    cout << "Nhap age: ";
    cin >> sv.age;

    cout << "Nhap toan: ";
    cin >> sv.toan;

    cout << "Nhap ly: ";
    cin >> sv.ly;

    cout << "Nhap hoa: ";
    cin >> sv.hoa;
}

// tính điểm trung bình sv
float DTB(Student sv)
{
    return (float)(sv.ly + sv.toan + sv.hoa)/3;
}

void XuatThonTinMotSinhVien(Student sv)
{
    std::cout << sv.rollNo << "\t\t" << sv.name << "\t\t" << sv.age << "\t\t" << sv.toan << "\t\t" << sv.ly << "\t\t" << sv.hoa << "\t\t" << DTB(sv) << endl;
}

// Nhập thông tin danh sách lớp học int a[100];
void NhapDanhSachLopHoc(Student arr[100], int n)
{
    for(int i = 0; i < n; ++i)
    {
        /*
            nhập biến mã số 
            kiểm tra giá trị đã với tất cả các mã số của sinh viên trong danh sách đang có
            nếu mã số đó trùng với mã số của một thằng sinh viên bất kỳ => nhập lại biến mã số
            còn nếu mã số đó không trùng
            mình set mã số của thằng sinh viên thứ i hiện tại đang cần nhập bằng giá trị mã số vừa kiểm tra
            và nhập tiếp những thông tin còn lại của sinh viên i đó
        */
        // tạo một biến cờ hiệu
        do{
            string maso;
            fflush(stdin);
            cout << "Nhap maso: ";
            getline(cin, maso);
            bool check = true;// khởi tạo ban đầu bằng true có nghĩa là mã số đó chưa trùng
            // kiểm tra mã số vừa nhập xong với tất cả mã số của từng sinh viên trong danh sách đang có
            for(int j = 0; j < i; ++j)
            {
                // so sanh mã sô vừa nhập với từng mã số của sinh viên đang có trong danh sách
                if(arr[j].rollNo.compare(maso) == 0)
                {
                    // hai thằng bằng nhau => mã số trùng 
                    check = false;// => mã số đã bị trùng
                    break;
                }
            }
            if(check == true)
            {
                // nếu check = true có nghĩa mã số đó chưa có trong danh sách
                arr[i].rollNo = maso;
                NhapMotSinhVien(arr[i]);
                break;
            }
        }while (true);
        
        
        // nhập mảng số nguyên
        // std:: cin >> a[i];
        // arr[i] là gì Sinh Viên thứ i trong lớp học
        //NhapMotSinhVien(arr[i]);// nhập thông tin cho sinh viên thứ i
    }
}

// tương tự xuất danh sách sinh viên
void XuatDanhSachLopHoc(Student arr[100], int n)
{
    // std::cout << "MASO\t\tNAME\t\t\tAGE\t\t\tTOAN\t\t\tLY\t\t\tHOA\t\t\tDTB" << endl;
    for(int i = 0; i < n; ++i)
    {
        // xuất mảng số nguyên
        // std:: cout << a[i];
        // arr[i] là gì Sinh Viên thứ i trong lớp học
        XuatThonTinMotSinhVien(arr[i]);// xuất thông tin cho sinh viên thứ i
    }
}

// TÌM THÔNG TIN SINH VIÊN CÓ ĐIỂM TRUNG BÌNH CAO NHẤT LỚP (tìm vị trí của phần tử lớn nhất trong mảng)
int VTMax(int *a, int n)
{
    int max = 0;
    int vt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] > max)
        {
            max = a[i];
            vt = i;
        }
    }
    return vt;
}

int ThongTinSinhVienCoDTBMax(Student arr[], int n)
{
    float max = 0;
    int vt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(DTB(arr[i]) > max)
        {
            max = DTB(arr[i]);
            vt = i;
        }
    }
    return vt;
}


// + XUẤT DANH SÁCH SINH VIÊN THI LẠI (ĐIỀU KIỆN THI LẠI LÀ SINH VIÊN CÓ ĐIỂM TRUNG BÌNH < 4)

void DanhSachSinhVienThiLai(Student arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        if(DTB(arr[i]) < 4)
        {
            XuatThonTinMotSinhVien(arr[i]);
        }
    }
}

// xuất các số chẵn trong mảng 1 chiều
/*
for(int i = 0; i < n; ++i)
{
    if(a[i] % 2 == 0)
    {
        std::cout << a[i];
    }
}
*/

// + SẮP XẾP DANH SÁCH SINH VIÊN TRONG LỚP THEO ĐIỂM TRUNG BÌNH GIẢM DẦN(ok)
// sắp xếp mảng chiều
/*
for(int i = 0; i < n; ++i)
{
    for(int j = i + 1; j < n; ++j)
    {
        if(a[i] < a[j])
        {
            // đổi vị trí của hai phần tử
            HoanDoi(a[i], a[j])
        }
    }
}
// hoán đổi 2 số nguyên
void HoanDoi(int &a, int &b)
{
    int tg = a;
    a = b;
    b = tg;
}
// hoán đổi 2 sinh viên
void HoanDoi(Student &a, Student &b)
{
    Student tg = a;
    a = b;
    b = tg;
}
*/
void HoanDoi(Student &a, Student &b)
{
    Student tg = a;
    a = b;
    b = tg;
}

void SapXepDanhSachSinhVien(Student arr[], int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(DTB(arr[i]) < DTB(arr[j]))
            {
                HoanDoi(arr[i],arr[j]);
            }
        }
    }
}

void SapXepDanhSachSinhVienTangDanTheoTen(Student arr[], int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            // sắp xếp tăng dần theo độ dài của tên
            // điều kiện so sánh theo tiêu chí name thằng nào có tên dài hơn
            if(arr[i].name.length() > arr[j].name.length())
            {
                HoanDoi(arr[i],arr[j]);
            }
        }
    }
}


int main()
{
    int n;
    std::cout << "Nhap so luong sinh vien trong lop: ";
    std::cin >> n;
    // int a[100];//int *a;
    Student arr[100];
    NhapDanhSachLopHoc(arr, n);
    // 
    std::cout << "DANH SACH SINH VIEN TRUOC KHI SAP XEP"  << std::endl;
    XuatDanhSachLopHoc(arr, n);
    // xuất giá trị của phần tử thứ i trong mảng int a[100]
    // xuất thông tin sinh viên điểm cao nhất lớp vd nó ở vị trí thứ vt 
    // int vt = ThongTinSinhVienCoDTBMax(arr, n);
    // XuatThonTinMotSinhVien(arr[vt]);
    //
    // std::cout << "DANH SACH SINH VIEN THI LAI: " << std::endl;
    // DanhSachSinhVienThiLai(arr, n);
    //SapXepDanhSachSinhVien(arr, n);
    //std::cout << "DANH SACH SINH VIEN SAU KHI SAP XEP"  << std::endl;
    //XuatDanhSachLopHoc(arr, n);
    return 0;
}