
/*DÙNG KỸ THUẬT CẤP PHÁT CON TRỎ
+ NHẬP MẢNG MỘT CHIỀU SỐ NGUYÊN TỪ TẬP TIN DULIEU.TXT
+ TÍNH TỔNG GIÁ TRỊ TRONG MẢNG ĐÓ*/
#include <iostream>
#include <fstream>



void NhapMang(int *a, int n, std::ifstream &fileIn)
{
    for(int i = 0; i < n; ++i)
    {
        fileIn >> a[i]; // tập tin
        // std::cin >> a[i]  bàn phím
    }
}


int main()
{
    int n = 9;
    int *arr = new int[n];
    std::ifstream fileIn;
    fileIn.open("DILIEU.txt", std::ios_base::in);
    NhapMang(arr, n, fileIn);
    fileIn.close();
    for(int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}