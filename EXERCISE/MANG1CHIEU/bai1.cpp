// . Viết chương trình thực hiện các yêu cầu sau:
// - Nhập số nguyên dương n thỏa mãn 1≤n≤30.
// - Tạo một dãy số a có n số nguyên sao cho a[0]=1, a[1]=1, a[i]=a[i-1]+a[i-2] khi i≥2.
// - Hiển thị dãy số a ra màn hình.
// - Tính và hiển thị ra màn hình tổng tất cả các phần tử dữ liệu củdãy số aa.

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


void taoMang(int *a, int n)
{
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i < n; ++i)
    {
        a[i] = a[i - 1] + a[i - 2]; 
    }
}

void XuatMang(int *a, int n, std::ofstream &fileOut)
{
    fileOut<< "MANG LA: ";
    for(int i = 0; i < n; ++i)
    {
        fileOut << a[i] << " ";
    }
}

void Tong(int *a, int n, std::ofstream &fileOut)
{
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += a[i];
    }
    fileOut << "\nTONG CAC PHAN TU TRONG MANG LA: " << sum;
}

int main()
{
    int n;
    Nhap(n);
    int *a = new int[n];
    taoMang(a, n);
    std::ofstream fileOut;
    fileOut.open("bai1.txt", std::ios_base::app);
    XuatMang(a, n, fileOut);
    Tong(a, n, fileOut);
    fileOut.close();
    delete[] a;
}
