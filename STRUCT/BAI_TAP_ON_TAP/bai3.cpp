#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Student{
    string name;
    int namSinh;
    float gpaI, gpaII;
};

float GPA(Student sv)
{
    return (2 * sv.gpaII + sv.gpaI)/3.0;
}

void NhapSoLuongSinhVien(int &n)
{
    do{
        cout << "Nhap so luong sinh vien trong lop: ";
        cin >> n;
    }while(n < 0);
}

void NhapThongTinSinhVien(Student &sv)
{
    fflush(stdin);
    cout << "Nhap name: ";
    getline(cin, sv.name);
    
    cout << "Nhap nam sinh: ";
    cin >> sv.namSinh;

    cout << "Nhap gpa I: ";
    cin >> sv.gpaI;

    cout << "Nhap gpa II: ";
    cin >> sv.gpaII;
}


void XuatThongTinSinhVien(Student sv)
{
    cout << sv.name << setw(20 - sv.name.length()) << sv.namSinh << setw(20) << sv.gpaI << setw(20) << sv.gpaII << setw(20) << GPA(sv) << endl;
}


void NhapDanhSach(Student *arr, int n)
{
    std::cout << "Nhap danh sach hoc sinh trong lop: \n";
    for(int i = 0; i < n; ++i)
    {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        NhapThongTinSinhVien(arr[i]);
    }
}

void XuatDanhSach(Student *arr, int n)
{
    cout << "    NAME" << setw(20 - 8) << "YOB" << setw(20) << "GPAI" << setw(20) << "GPAII" << setw(20) << "GPA" << endl;
    for(int i = 0; i < n; ++i)
    {
        XuatThongTinSinhVien(arr[i]);
    }
}

// Hiển thị ra màn hình danh sách các học sinh có điểm trung bình cả năm từ 5.0 trở lên theo 
// thứ tự giảm dần của điểm trung bình cả năm(sắp xếp danh sách sinh viên giảm dần theo điểm tb)

void HoanDoi(Student &a, Student &b)
{
    Student tg = a;
    a = b;
    b = tg;
}

void SapXep(Student *arr, int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            // if arr[i] < arr[j] = > hoán đổi hai phần tử
            if(GPA(arr[i]) < GPA(arr[j]))
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void DanhSachSinhVienCoDiemTBLonHonNam(Student * arr, int n)
{
    SapXep(arr, n);
    for(int i = 0; i < n; ++i)
    {
        if(GPA(arr[i]) >= 5)
        {
            XuatThongTinSinhVien(arr[i]);
        }
    }
}

// - Hiển thị ra màn hình danh sách học sinh lưu ban (đtbcn<4.0 hoặc đtbkI<2.0 hoặc 
// dtbkII<2.0).
void DanhSachSinhVienLuaBan(Student *arr, int n)
{
    cout << "\nDANH SACH SINH VIEN LUU BAN: \n";
    for(int i = 0; i < n; ++i)
    {
        if(GPA(arr[i]) < 4 || arr[i].gpaI < 2 || arr[i].gpaII < 2)
        {
            XuatThongTinSinhVien(arr[i]);
        }
    }
}

void TyLeHocLucCuaSinhVienTrongLop(Student *arr, int n)
{
    int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;
    // duyệt qua danh sách lớp đếm số lượng sinh viên giỏi, khá, ...
    for(int i = 0; i < n; ++i)
    {
        // xét học sinh giỏi
        if(GPA(arr[i]) >= 8 && arr[i].gpaI >= 6 && arr[i].gpaII >= 6)
        {
            count_1++;
        }
        // xét học sinh khá
        else if(GPA(arr[i]) >= 6.5 && arr[i].gpaI >= 5 && arr[i].gpaII >= 5)
        {
            count_2++;
        }
        // xét trung bình
        else if(GPA(arr[i]) >= 5 && arr[i].gpaI >= 3 && arr[i].gpaII >= 3)
        {
            count_3++;
        }
        // xét yếu
        else if(GPA(arr[i]) >= 3.5 && arr[i].gpaI >= 2 && arr[i].gpaII >= 2)
        {
            count_4++;
        }
    }
    // xau khi duyệt xong thì có số lượng sinh viên của từng học lực
    cout << "% HOC SINH GIOI: " << (float)count_1/n * 100 << "%\n";
    cout << "% HOC SINH KHA: " << (float)count_2/n * 100 << "%\n";
    cout << "% HOC SINH TRUNG BINH: " << (float)count_3/n * 100 << "%\n";
    cout << "% HOC SINH YEU: " << (float)count_4/n * 100 << "%\n";
    cout << "% HOC SINH KEM: " << 100 - ((float)count_1/n * 100 + (float)count_2/n * 100 + (float)count_3/n * 100 + (float)count_4/n * 100) << "%\n";
}

// Tính tỷ lệ % học sinh giỏi, khá, trung bình, yếu, kém của lớp và hiển thị các kết quả biết:
// Giỏi: đtbcn≥8.0 và không có kỳ nào dưới 6.0.
// Khá: đtbcn≥6.5 và không có kỳ nào dưới 5.0.
// Trung bình: đtbcn≥5.0 và không có kỳ nào dưới 3.0.
// Yếu: đtbcn≥3.5 và không có kỳ nào dưới 2.0.
// Còn lại là kém.


int main()
{
    int n;
    NhapSoLuongSinhVien(n);

    Student * arr = new Student[n];
    NhapDanhSach(arr, n);
    // DanhSachSinhVienCoDiemTBLonHonNam(arr, n);
    TyLeHocLucCuaSinhVienTrongLop(arr, n);
    delete[] arr;

    return 0;
}





/*
. Viết chương trình quản lý điểm của một lớp gồm có những nhiệm vụ sau:
- Nhập số lượng học sinh của lớp.
- Nhập danh sách hồ sơ học sinh, biết mỗi học sinh gồm: họ tên, năm sinh, điểm trung bình 
học kỳ I, điểm trung bình kỳ II, điểm trung bình cả năm (đtbcn=(2*đtbkII+đtbkI)/3).
- Hiển tị ra màn hình danh sách các học sinh có điểm trung bình cả năm từ 5.0 trở lên theo 
thứ tự giảm dần của điểm trung bình cả năm(sắp xếp danh sách sinh viên giảm đân theo điểm tb)
- Hiển thị ra màn hình danh sách học sinh lưu ban (đtbcn<4.0 hoặc đtbkI<2.0 hoặc 
dtbkII<2.0).
- Tính tỷ lệ % học sinh giỏi, khá, trung bình, yếu, kém của lớp và hiển thị các kết quả biết:
Giỏi: đtbcn≥8.0 và không có kỳ nào dưới 6.0.
Khá: đtbcn≥6.5 và không có kỳ nào dưới 5.0.
Trung bình: đtbcn≥5.0 và không có kỳ nào dưới 3.0.
Yếu: đtbcn≥3.5 và không có kỳ nào dưới 2.0.
Còn lại là kém.
*/