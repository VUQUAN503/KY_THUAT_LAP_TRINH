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

//Hiển thị ra màn hình các số chẵn chia hết cho 3 và vị trí của chúng
void XuatMang(int *a, int n, std::ofstream &fileOut)
{
    for(int i = 0; i < n; ++i)
    {
        if(a[i] % 2 == 0 && a[i] % 3 == 0)
        {
            fileOut << a[i] << ": " << i << "\n";
        }
    }
}

void HoanDoi(int &a, int &b)
{
    int tg = a;
    a = b;
    b = tg;
}

void sapXep(int *a, int n)
{
    //b1: chuyển chẵn về đầu dãy
    // 0 1 2 3 4
    // 3 2 5 1 4
    // 2 3 5 1 4   1
    // 2 4 3 5 1
    int vt = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] % 2 == 0)
        {
            // hoán đổi hai phần tử
            HoanDoi(a[i], a[vt]);
            vt++;
        }
    }
    // sắp xếp
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            // sắp xếp chẵn trước
            if(a[i] % 2== 0 && a[j] % 2 == 0)
            {
                if(a[i] < a[j])
                {
                    std::swap(a[i], a[j]);
                }
            }
            // sắp xếp lẻ
            if(a[i] % 2 != 0 && a[j] % 2 != 0)
            {
                if(a[i] < a[j])
                {
                    std::swap(a[i], a[j]);
                }
            }
        }
    }
    // for(int i = 0; i < n - 1; ++i)
    // {
    //     for(int j = i + 1; j < n; ++j)
    //     {
    //         if(a[i] % 2 == 0 && a[j] % 2== 0)
    //         {
    //             if(a[i] < a[j])
    //             {
    //                 std::swap(a[i], a[j]);
    //             }
    //         }
    //         if(a[i] % 2 != 0 && a[j] % 2 == 0)
    //         {
    //             std::swap(a[i], a[j]);
    //         }
    //         if(a[j] % 2 != 0 && a[i] % 2 != 0)
    //         {
    //             if(a[i] < a[j])
    //             {
    //                 std::swap(a[i], a[j]);
    //             }
    //         }
    //     }
    // }
}


int main()
{
    int n;
    Nhap(n);
    int *a = new int[n];
    NhapMang(a, n);
    std::ofstream fileOut;
    fileOut.open("bai3.txt", std::ios_base::app);
    sapXep(a, n);
    XuatMang(a, n, fileOut);
    fileOut.close();
    delete[] a;
}


//Sắp xếp dãy số a sao cho các số chẵn ở đầu dãy số theo thứ tự giảm dần, các số lẻ ở cuối dãy 
//số theo thứ tự giảm dần.
/*
3 2 5 4 7
2 4 3 5 7
4 2 7 5 3
b1: chuyển hết số chẵn vễ đầu dãy
// mình duyệt qua mảng
nếu phần tử đó là số chẵn
vt = 0
hoán đổi a[vt] với phần tử chẵn đó
và tăng vị trí lên 1
để lần lặp tiếp theo nếu có số chẵn thì hoán đổi
tương tự như vậy duyệt đến cuối
b2: sắp xếp chẵn giảm dần
b3: sắp xếp lẻ giảm dần
*/