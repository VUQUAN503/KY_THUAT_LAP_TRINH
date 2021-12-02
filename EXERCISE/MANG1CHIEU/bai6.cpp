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

void NhapMang(float *a, int n, char name)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << name << "["<< i << "] = ";
        std::cin >> a[i];
    }
}

void XuatMang(float *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << " ";
    }
}

void TaoMangC(float *a, int n, float *b, int m, float *c, int &p)
{
    // gán a vào c
    for(int i = 0; i < n; ++i)
    {
        bool check = true;
        for(int j = 0; j < p; ++j)
        {
            if(a[i] == c[j])
            {
                check = false;
                break;
            }
        }
        
        if(check == true)
        {
            c[p] = a[i];
            p++;
        }
    }
    // gán b vào c
    for(int i = 0; i < m; ++i)
    {
        bool check = true;
        for(int j = 0; j < p; ++j)
        {
            if(b[i] == c[j])
            {
                check = false;
                break;
            }
        }
        if(check == true)
        {
            c[p] = b[i];
            p++;
        }
    }
}

int main()
{
    int n;
    int m;
    Nhap(n);
    float *a = new float[n];
    NhapMang(a, n, 'A');
    Nhap(m);
    float *b = new float[m];
    NhapMang(b, m, 'B');
    int p = 0;
    float *c = new float[p];
    TaoMangC(a, n, b, m, c, p);
    XuatMang(c, p);
}