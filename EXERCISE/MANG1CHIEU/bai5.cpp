#include <iostream>
#include <fstream>

void Nhap(int &n)
{
    do
    {
        std::cout << "Nhap n: ";
        std::cin >> n;
    } while (n > 20 || n < 0);
}

void NhapMang(int *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << "A[" << i << "]=";
        std::cin >> a[i];
    }
}

void XuatMang(float *a, int n, std::ofstream &fileOut)
{
    fileOut << "\nMANG LA: ";
    for (int i = n - 1; i >= 0; --i)
    {
        fileOut << a[i] << " ";
    }
}

// Nhập số thực x, chèn x vào dãy số a sao cho trật tự của dãy số a không bị thay đổi.
/*
mảng nó có trật tự nào
+ tăng dần
+ giảm dần
=> YÊU CẦU BÀI CHÈN MỘT SỐ THỰC X VÀO MẢNG SAO CHO CHO MẢNG VẪN GIẢM DẦN
VD 5 4 2 1
CHÈN 3
=> 5 4 3 2 1
:  TÌM VỊ TRÍ PHẦN TỬ NHỎ HƠN 3 ĐẦU TIÊN
=> CHÈN TRỰC TIẾP 3 VÀO VỊ TRÍ ĐÓ
*/
void Chen(int *a, int &n, int vtchen, int ptchen)
{
    if (vtchen >= 0 && vtchen <= n)
    {
        for (int i = n - 1; i >= vtchen; --i)
        {
            a[i + 1] = a[i];
        }
        a[vtchen] = ptchen;
        n++;
    }
}

// tìm vị trí nhỏ hơn x đầu tien
void ChenX(int *a, int &n, int x)
{
    // tìm vị trí nhỏ hơn x đầu tiên
    for(int i = 0; i < n; ++i)
    {
        if(a[i] < x)
        {
            Chen(a, n, i, x);
            // khi chèn xong x vào phần tử đầu tiên rồi
            break;
        }
    }
}


// Tạo dãy số c từ hai dãy số a và b sao cho trong dãy số c không tồn tại các phần tử có giá trị 
// bằng nhau.
/*
+ duyệt qua a từng phần của a và b
+ kiểm tra xem phần tử đó đã có trong c hay chưa
+ nếu chưa có thêm vào c nếu có rồi thì thôi
*/
void TaoMangC(int *a, int n, int *b, int m, int *c, int &p)
{
    // gán a vào c
    for(int i = 0; i < n; ++i)
    {
        bool check = true;
        // duyệt hết qua từng phần tử mảng c nếu a[i] bằng một tử bất kỳ trong c => check = false
        // nếu duyệt hết c mà biến check vẫn bằng true có nghĩa là a[i] không có trong c
        // => lúc này thêm a[i] vào trong c
        for(int j = 0; j < p; ++j)
        {
            if(a[i] == c[j])
            {
                check = false; // a[i] đã có trong c
                break;
            }
        }
        // sau khi duyệt xong vòng lặp các phần tử c
        // nếu check vẫn bằng true có nghĩa là a[i] chưa có trong c => thêm a[i] vào trong c
        if(check == true)
        {
            // thêm a[i] vào c
            c[p] = a[i];
            p++;// tăng p lên
        }
    }
    // gán b vào c
    for(int i = 0; i < m; ++i)
    {
        bool check = true;
        // duyệt hết qua từng phần tử mảng c nếu a[i] bằng một tử bất kỳ trong c => check = false
        // nếu duyệt hết c mà biến check vẫn bằng true có nghĩa là a[i] không có trong c
        // => lúc này thêm a[i] vào trong c
        for(int j = 0; j < p; ++j)
        {
            if(b[i] == c[j])
            {
                check = false; // a[i] đã có trong c
                break;
            }
        }
        // sau khi duyệt xong vòng lặp các phần tử c
        // nếu check vẫn bằng true có nghĩa là a[i] chưa có trong c => thêm a[i] vào trong c
        if(check == true)
        {
            // thêm a[i] vào c
            c[p] = b[i];
            p++;// tăng p lên
        }
    }
}

int main()
{
    int n;
    int m;
    int p = 0;
    Nhap(n);
    Nhap(m);
    int *a = new int[n];
    int *b = new int[m];
    int *c = new int[p];// chuẩn làm như này sẽ bị sai vì mảng c chưa biết số lượng phần tử sao cấp phát đc
    // ban đầu khởi tạo p bằng 0 nếu cấp phát thì sẽ cấp phát 0 phần tử
    // nhưng mà làm điều này với c++ lại đúng
    // mọi người có thể tìm hiểu vector mảng co giãn 
    NhapMang(a, n);
    NhapMang(b, n);
    TaoMangC(a, n, b, m, c, p);
    // sau khi gọi hàm này thì p đã thay đổi và p chính là số phần tử mảng c luôn
    for(int i = 0; i < p; ++i)
    {
        std::cout << c[i] << " ";
    }
}

