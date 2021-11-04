#include <iostream>
#include <fstream>


void Nhap(int *a, int n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << "Nhap A[" << i << "] = ";
        std::cin >> *(a + i);
    }
}

void Swap(int &a, int &b)
{
    int tg = a;
    a = b;
    b = tg;
}

void SapXep(int *a, int n)
{
    for(int i = 0; i <= n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            //sắp xếp giảm
            if(a[i] < a[j])
            {
                //đổi chỗ
                Swap(a[i], a[j]);
            }
        }
    }
}

// in mảng đã sắp xếp ra màn hình và tập tin sort.txt

void Xuat(int *a, int n)
{
    for(int i = 0; i < n; ++i)
    {
        // std::cout << *(a + i);
        std::cout << a[i] << " ";
    }
}

// in ra tập tin file để ghi ofstream, file để đọc ifstream
void outPutFile(int *a, int n, std::ofstream &fileOut)
{
    for(int i = 0; i < n; ++i)
    {
        // std::cout << *(a + i);
        fileOut << a[i] << " ";
        //std::cout << a[i]   xuất ra màn hình
    }
}

// GHI BỔ SUNG TỔNG CÁC PHẦN TỬ TỪ trong đoạn 5 ĐẾN 10 VÀO TẬP TIN SORT.TXT
// vd 1 3 8 4 9 => 17 ghi 17 vào tập tin
void ghiTongVaoTapTin(int *a, int n, std::ofstream &fileOut)
{
    // tính tổng
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] >= 5 && a[i] <= 10)
        {
            sum += a[i];
        }
    }
    fileOut << sum;
}

float trungBinh(int *a, int n)
{
    int sum = 0;
    int dem = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += a[i];
        dem++;
    }
    return (float)sum/dem;
}

int count(int *a, int n)
{
    int dem = 0;
    int sum = 0;
    // 1 7 3 8 9
    for(int i = n - 1; i >= 0; --i)
    {
        sum += a[i];
        if(sum < trungBinh(a, n))
        {
            dem++;
        }
        else{
            return dem;
        }
    }
    return 0;
}

// cần lấy nhiều nhất bao nhiêu phần tử của mảng arr để tổng giá trị của chúng
// nhỏ hơn giá trị trung bình trong mảng
/*
b1: tính giá trị trung bình của mảng
sum = 0;
b2: 5 4 3 2 1 
tb 3
*/

int main()
{
    int n;
    std::cout << "Nhap n: ";
    std::cin >> n;
    // cấp phát mảng con trỏ
    int *arr = new int[n];
    Nhap(arr, n);
    SapXep(arr, n);
    Xuat(arr, n);
    std::ofstream fileOut;
    fileOut.open("sort.txt", std::ios_base::app);
    // outPutFile(arr, n, fileOut);
    ghiTongVaoTapTin(arr, n, fileOut);
    fileOut.close();
    std::cout << std::endl;
    std::cout << count(arr, n);
    return 0;
}