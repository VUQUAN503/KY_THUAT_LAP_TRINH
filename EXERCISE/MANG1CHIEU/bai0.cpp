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

void NhapMang(float *a, int n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << "A[" << i << "]=";
        std:: cin >> a[i];
    }
}

void XuatMang(float *a, int n, std::ofstream &fileOut)
{
    fileOut<< "\nMANG LA: ";
    for(int i = 0; i < n; ++i)
    {
        fileOut << a[i] << " ";
    }
}

void chen(float *a, int &n, float x, int k)
{
    if(k >= 0 && k <= n)
    {
        for(int i = n - 1; i >= k; --i)
        {
            a[i + 1] = a[i];
        }
        a[k] = x;
        n++;
    }
    else{
        a[n] = x;
        n++;
    }
}


int main()
{
    int n;
    Nhap(n);
    float * a = new float[n];
    NhapMang(a, n);
    std::ofstream fileOut;
    fileOut.open("bai0.txt", std::ios_base::app);
    XuatMang(a, n, fileOut);
    chen(a, n, 10, 0);
    XuatMang(a, n, fileOut);
    fileOut.close();
    delete[] a; // giải phóng con trỏ
    return 0;
}


