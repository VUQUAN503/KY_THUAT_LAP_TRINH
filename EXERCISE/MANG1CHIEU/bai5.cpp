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

void XuatMang(int *a, int n)
{
    for (int i = n - 1; i >= 0; --i)
    {
        std::cout << a[i] << " ";
    }
}

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

void SapXep(int *a, int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(a[i] < a[j])
            {
                std::swap(a[i], a[j]);
            }
        }
    }
}



int main()
{
    int n;
    Nhap(n);
    int *a = new int[n]; 
    NhapMang(a, n);
    XuatMang(a, n);
    SapXep(a, n);
    std::cout << "\n";
    for(int i = 0; i < n; ++i)
    {
        std::cout << a[i] << " ";
    }
    return 0;
}

