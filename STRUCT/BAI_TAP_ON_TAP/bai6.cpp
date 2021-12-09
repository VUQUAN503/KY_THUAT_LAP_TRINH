//  Cho một hóa đơn bán hàng của một của hàng gồm các thông tin: Số hóa đơn, ngày lập, người 
// lập hóa đơn và danh sách n mặt hàng ghi trong hóa đơn, mỗi mặt hàng gồm các thông tin: Mã 
// hàng, tên hàng, đơn giá, số lượng, thành tiền. Viết chương trình thực hiện các yêu cầu:
// - Nhập số liệu cho hóa đơn nói trên từ tập tin.
// - Hiển thị số liệu của hóa đơn ra màn hình với danh sách các mặt hàng có tên được sắp xếp 
// theo thứ tự xuất hiện trong từ điển kèm theo tổng thành tiền của các mặt hàng.
// - Xuất các mặt hàng trong danh sách có đơn giá cao hơn 1 triệu vào trong tệp tin .
// - Nhập vào thông tin của một mặt hàng mới, chèn thông tin mặt hàng này vào đầu danh 
// sách các mặt hàng trong hóa đơn, hiển thị lại hóa đơn vào trong tệp.
// - Xóa các mặt hàng có thành tiền bằng không trong danh sách các mặt hàng của hóa đơn, 
// hiển thị lại hóa đơn.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


using namespace std;


struct MatHang{
    string maHang;
    string tenHang;
    int soLuong;
    float donGia;
};

struct DonHang{
    string soHoaDon;
    int ngayLap;
    string tenNguoiLap;
    int n; // số lượng hàng
    MatHang * arr;
};

void NhapThongTinMatHang(MatHang &x, ifstream &fileIn)
{
    getline(fileIn, x.maHang, '-'); 
    // trước khi đc dữ liệu cho tên thì có 1 byte khoẳng trắng thừa trước tên
    // mình bỏ qua khoảng trắng đó bằng cách dịch con trỏ chỉ vị(file) lên 1 byte
    fileIn.seekg(1, fileIn.cur);
    // hàm seekg có hai tham số
    /*
    tham số thứ nhất chính là số byte muốn dịch
    tham số thứ hai là vị trí của con trỏ file
    */
    getline(fileIn, x.tenHang, '-'); 

    fileIn >> x.soLuong;

    fileIn.seekg(3, fileIn.cur);
    fileIn >> x.donGia;

    fileIn.seekg(3, fileIn.cur);
}

void XuatMatHang(MatHang x)
{
    cout << x.maHang << setw(20 - x.maHang.length()) << x.tenHang << setw(20 - x.tenHang.length()) << x.soLuong << setw(20) << x.donGia << endl;
}

void NhapThongTinDanhSachMatHang(MatHang* arr, int n, ifstream &fileIn)
{
    for(int i = 0; i < n; ++i)
    {
        NhapThongTinMatHang(arr[i], fileIn);
    }
}

void XuatThongTinDanhSachMatHang(MatHang* arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        XuatMatHang(arr[i]);
    }
}


void NhapThongTinDonHang(DonHang &dh, ifstream &fileMatHang, ifstream &fileDonHang)
{
    getline(fileDonHang, dh.soHoaDon, '-');

    fileDonHang >> dh.ngayLap;

    fileDonHang.seekg(3, fileDonHang.cur);
    getline(fileDonHang, dh.tenNguoiLap, '-');

    fileDonHang >> dh.n;

    dh.arr = new MatHang[dh.n];

    NhapThongTinDanhSachMatHang(dh.arr, dh.n, fileMatHang);
}

void XuatDonHang(DonHang x)
{
    cout << "SO HOA DON: " << x.soHoaDon << endl;
    cout << "NGAY LAP: " << x.ngayLap << endl;
    cout << "TEN NGUOI LAP: " << x.tenNguoiLap << endl;
    cout << "MA MAT HANG" << setw(20 - 11) << "TEN HANG" << setw(20 - 8) << "SO LUONG" << setw(20) << "DON GIA" << endl;
    XuatThongTinDanhSachMatHang(x.arr, x.n);
}

int main()
{
    ifstream fileMatHang;
    ifstream fileDonHang;
    fileMatHang.open("danhsachmathang.txt", ios_base::in);
    fileDonHang.open("thongtindonhang.txt", ios_base::in);
    DonHang x;
    NhapThongTinDonHang(x, fileMatHang, fileDonHang);
    XuatDonHang(x);
    fileDonHang.close();
    fileMatHang.close();
    delete[] x.arr;
    return 0;
}
