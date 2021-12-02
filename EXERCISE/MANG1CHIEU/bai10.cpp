#include <iostream>

void Nhap(int *a, int &count)
{
    while(true)
    {
        std::cout << "A[" << count << "] = ";
        std::cin >> a[count];
        if(count == 100 || a[count] == -1){
            break;
        }
        count++;
    }
}

void Xuat(int *a, int count)
{
    for(int i = 0; i < count; ++i)
    {
        std::cout << a[i] << " ";
    }
}

void sapXep(int *a, int count)
{
    for(int i = 0; i < count - 1; ++i)
    {
        for(int j = i + 1; j < count; ++j)
        {
            if(a[i] > a[j])
            {
                std::swap(a[i], a[j]);
            }
        }
    }
}

int main()
{
    int n = 0;
    int *a = new int[n];
    Nhap(a, n);
    std::cout << "So pt cua mang la: " << n;
    Xuat(a, n);
    sapXep(a, n);
    Xuat(a, n);
    return 0;
}