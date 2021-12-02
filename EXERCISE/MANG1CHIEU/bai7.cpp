#include <iostream>
#include <fstream>

void Nhap(int &n)
{
    do
    {
        std::cout << "Nhap so phan tu: ";
        std::cin >> n;
    } while (n > 30 || n < 0);
}

void NhapMang(float *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << "A["<< i << "] = ";
        std::cin >> a[i];
    }
}

void XuatMang(float *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void Tachmang(float *a, int n, float *b, int &m, float *c, int &p)
{
    for(int i = 0; i < n; ++i)
    {
        if(a[i] > 0) b[m++] = a[i];
        else if(a[i] < 0) c[p++] = a[i];
    }
}

int main()
{
    int n;
    Nhap(n);
    float *a = new float[n];
    int m = 0, p = 0;
    float *b = new float[m];
    float *c = new float[p];
    NhapMang(a, n);
    Tachmang(a, n, b, m, c, p);
    XuatMang(b, m);
    XuatMang(c, p);
}
