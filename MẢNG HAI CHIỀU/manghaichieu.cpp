#include <iostream>
#include <cmath>
/*
Tính tổng các số dương trong ma trận các số thực.
*/

int tongDuong(int a[100][100], int dong, int cot)
{
    int sum = 0;
    for(int i = 0; i < dong; ++i)
    {
        for(int j = 0; j < cot; ++j)
        {
            if(a[i][j] > 0)
            {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

//.Tính trung bình cộng các số dương trong ma trận các số nguyên.
float trungBinhCongSoDuong(int a[100][100], int dong, int cot)
{
    float sum = 0;
    int dem = 0;
    for(int i = 0; i < dong; ++i)
    {
        for(int j = 0; j < cot; ++j)
        {
            if(a[i][j] > 0)
            {
                sum += a[i][j];
                dem++;
            }
        }
    }
    return sum/dem;
}

// .Tính trung bình nhân các số dương tỏng ma trận các số thực
float trungBinhNhan(int a[100][100], int dong, int cot)
{
    float tich = 1;
    int dem = 0;
    for(int i = 0; i < dong; ++i)
    {
        for(int j = 0; j < cot; ++j)
        {
            if(a[i][j] > 0)
            {
                tich *= a[i][j];
                dem++;
            }
        }
    }
    return pow(tich, (float)1/dem);
    //  trung bình nhân của a, b, c, d = căn bậc 4 của a * b * c * d;
    // căn bậc hai của 1 = 1 ^ 1/2;
    // căn bậc n của 1 = 1^1/n => căn bậc đếm của tích = tich ^ 1/dem
}

//21.Tính tích các giá trị lẻ trong ma trận các số nguyên.
int tichLe(int a[100][100], int dong, int cot)
{
    int tich = 1;
    for(int i = 0; i < dong; ++i)
    {
        for(int j = 0; j < cot; ++j)
        {
            if(a[i][j] % 2 != 0)
            {
                tich *= a[i][j];
            }
        }
    }
    return tich;
}

//Tính tổng các giá trị trên một dòng của ma trận các số
// ví dụ truyền tham số là 0 tính tổng trên dòng 0, nếu truyền 1 tính tổng trên dòng 1
int tongDong(int a[100][100], int dong, int cot, int vtDongMuonTinh)
{
    // vd tính dòng 1
    int sum = 0;
    for(int i = 0; i < cot; ++i)
    {
        sum += a[vtDongMuonTinh][i];
    }
    return sum;
}

// tính tổng các giá trị trên một cột
int tongCot(int a[100][100], int dong, int cot, int vtCotMuonTinh)
{
    // vd tính dòng 1
    int sum = 0;
    for(int i = 0; i < dong; ++i)
    {
        sum += a[i][vtCotMuonTinh];
    }
    return sum;
}

//Tính tổng các giá trị nằm trên biên của ma trận
/*
giá trị nằm trên biên là những giá trị nào
{{1, 2, 3, 4},
{2, 3, 4, 5}, 
{3, 4, 5, 6}};

dòng 0 ,dòng 2, cột 0, cột 3
*/
int tongGiaTriNamTrenBien(int a[100][100], int dong, int cot)
{
    int sum = 0;
    sum += tongDong(a, dong, cot, 0) + tongDong(a, dong, cot,  dong - 1) + tongCot(a, dong, cot, 0)
    + tongCot(a, dong, cot, cot - 1) - a[0][0] - a[0][cot - 1] - a[dong - 1][cot - 1] - a[dong - 1][0];
}

int main(){
    /*
    MẢNG HAI CHIỀU LÀ MẢNG MỘT CHIỀU NHƯNG CÁC PHẦN TỬ TRONG MẢNG MỘT CHIỀU LÀ MỘT MẢNG MỘT CHIỀU
    KHAI BÁO 
    int arr[100][100] = {{}, {}, {}, {}}
    dựa trên số dòng và số cột
    int a[100] = {1, 2, 3, 4, 5};
    */
    int arr[100][100] = {{1, 2, 3, 4},
                         {2, 3, 4, 5}, 
                         {3, 4, 5, 6}};

    // std::cout << tongDuong(arr, 3, 4) << std::endl;
    // std::cout << tichLe(arr, 3, 4) << std::endl;
    // std::cout << trungBinhCongSoDuong(arr, 3, 4) << std::endl;
    // std::cout << trungBinhNhan(arr, 3, 4) << std::endl;
    std::cout << tongDong(arr, 3, 4, 2) << std::endl;
    // for(int i = 0; i < 3; ++i)
    // {
    //     for(int j = 0; j < 4; ++j)
    //     {
    //         std::cout << arr[i][j] << ", ";
    //     }
    //     std::cout << std::endl;
    // }
    
    return 0;
}




