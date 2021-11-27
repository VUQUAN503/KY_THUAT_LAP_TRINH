// Nhập số nguyên dương n thỏa mãn 1≤n≤30.
// - Nhập một dãy số a có n số nguyên.
// - Chỉ bằng một lần duyệt dãy số hãy cho biết dãy số a thỏa mãn tính chất nào dưới đây:
// o Dãy số tăng thực sự (a[i]<a[i+1], 0≤i≤n-2).
// o Dãy số tăng dần (a[i]≤a[i+1], 0≤i≤n-2).
// o Dãy số giảm thực sự (a[i]>a[i+1], 0≤i≤n-2).
// o Dãy số giảm dần (a[i]≥a[i+1], 0≤i≤n-2).
// o Dãy số không có trật tự nào.

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
    for(int i = 0; i < n; ++i)
    {
        std::cout << "A[" << i << "]=";
        std:: cin >> a[i];
    }
}

void XuatMang(int *a, int n, std::ofstream &fileOut)
{
    fileOut<< "\nMANG LA: ";
    for(int i = 0; i < n; ++i)
    {
        fileOut << a[i] << " ";
    }
}

void KiemTra(int *a, int n)
{
    bool check1 = true, check2 = true, check3 = true, check4 = true;
    for(int i = 0; i <= n - 2; ++i)
    {
        // kiểm tra mảng tăng thực sự a[i] < a[i + 1]
        if(a[i] >= a[i + 1]) check1 = false;
        // kiểm tra tăng dần a[i] <= a[i + 1]
        if(a[i] > a[i + 1]) check2 = false;
        // kiểm tra giảm dần thực sự a[i] > a[i + 1]
        if(a[i] <= a[i + 1]) check3 = false;
        // kiểm tra giảm dần a[i] >= a[i + 1]
        if(a[i] < a[i + 1]) check4 = false;
    }
    if(check1 == true)
    {
        std::cout << "mang tang thuc su";
    }
    else if(check2 == true)
    {
        std::cout << "mang tang thuc dan";
    }
    else if(check3 == true)
    {
        std::cout << "mang giam thuc su";
    }
    else if(check4 == true)
    {
        std::cout << "mang giam dan";
    }
    else{
        std::cout << "mang khong co trat tu";
    }
}


int main()
{
    int n;
    Nhap(n);
    int *a = new int[n];
    NhapMang(a, n);
    KiemTra(a, n);
    delete[] a;
}

// 1 2 3 4 5
// 4 2 5 3 1