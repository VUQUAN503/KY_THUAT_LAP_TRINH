

#include <iostream>
#include <ctime>

/*ĐỆ QUY
+ NÓ GIỐNG NHƯ VÒNG LẶP
+ MỌI BÀI TOÁN SỬ DỤNG ĐỆ QUY ĐỂ LÀM HẦU NHƯ ĐỀU CÓ THẺ LÀM ĐC BẰNG VÒNG LẶP
NHƯNG NÓ THEO CƠ CHẾ LẦN NGƯỢC CHẠY TỪ DƯỚI LÊN
+ MỘT SỐ LOẠI ĐỆ QUY
+ ĐỆ QUY ĐUÔI
+ ĐỆ QUY PHI TUYẾN
+ ĐỆ QUY HỖ TƯƠNG
+ ĐỆ QUY NHỊ PHÂN
+ ĐIỀU KIỆN DỪNG CỦA ĐỆ QUY 
+ CHẠY LẦN NGƯỢC THÔNG QUA GỌI LẠI CHÍNH BẢN THÂN NÓ TRONG HÀM
HÀM IN CÂU HELLO
vd hàm tính giai thừa
int gt = 1;
for(int i = 1; i <= n; ++i)
{
    gt *= i;
}
return gt;
*/

long long GiaiThua(int n)
{
    if(n == 1) return 1;
    return n*GiaiThua(n - 1);
}

// tỉnh tổng các số từ 1 đến n
int Tong(int n)
{
    if(n == 0) return 0;
    return Tong(n - 1) + n;
}


/*
vd n = 5;
5*giaiThua(4);
giaiThua(4) = 4*giaithua(3);
giaiThua(3) = 3 * giaiThua(2);
giaiThua(2) = 2 * giaiThua(1);
giaitThua(1) = 1;
=> 5*4*3*2*1 = 
*/

void xinChao()
{
    std::cout << "hello" << std::endl;
    xinChao();
}

long long GiaiThuaV2(int n)
{
    int gt = 1;
    for(int i = 1; i <= n; ++i)
    {
        gt *= i;
    }
    return gt;
}

int main()
{
    clock_t start = clock();
    for(int i = 0; i <= 100000000; ++i)
    {
        GiaiThua(18);
    }
    clock_t end = clock();
    clock_t start1 = clock();
    for(int i = 0; i <= 100000000; ++i)
    {
        GiaiThuaV2(18);
    }
    clock_t end1 = clock();
    std::cout << (float)(end - start)/CLOCKS_PER_SEC << std::endl;
    std::cout << (float)(end1 - start1)/CLOCKS_PER_SEC;

    return 0;
}