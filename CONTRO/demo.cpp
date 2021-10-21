

#include <iostream>

/*
CON TRỎ
+ NÓ LÀ MỘT BIẾN ĐỊA CHỈ
*/

// lambada


/*
CON TRỎ MẢNG

TÍNH TỔNG TẤT CẢ PHẦN TỬ LẺ TRONG MẢNG
*/

int Tong(int *arr, int n)
{
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        if(*(arr + i) % 2 != 0)
        {
            sum += *(arr + i);
        }
    }
    return sum;
}

int main()
{

    // mảng chia hai loại mảng động và mãng tĩnh
    // mảng tĩnh int a[100];
    // mảng động : mình dùng bao nhiêu phần tử thì cấp bằng đấy ô nhớ
    // mảng nó là một dãy các ô nhớ xếp cạnh nhau trong ram

    int *arr = new int[5];// cấp phát ra mảng động gồm có 5 phần tử
    for(int i = 0; i < 5; ++i)
    {
        // 1 2 3 4 5
        // arr[i] = i + 1;// gán gái trị mảng thông thường
        *(arr + i) = i + 1;// nganh bằng với arr[i]
    }
    std::cout << Tong(arr, 5);
    // mà nó sẽ chỉ giữ địa chỉ của phần tử đầu tiên
    // std::cout << arr << std::endl;
    // std::cout << &arr[0] << std::endl;
    // std::cout << *arr << std::endl;
    // std::cout << arr[0] << std::endl;
    // // mảng là những ô nhớ nằm cạnh nhau => địa chỉ hơn kém nhau 1 đơn vị
    // std::cout << (arr + 2) << std::endl;
    // std::cout << &arr[2] << std::endl;
    // std::cout << *(arr + 2) << std::endl;
    // std::cout << arr[2] << std::endl;

    // int a[100] ={1, 2, 3, 4, 5};
    // for(int i = 0; i < 5; ++i)
    // {
    //     std::cout << &a[i] << std::endl;
    // }
    return 0;
}

// int main()
// {
//     int *a; // khai báo một biến con trỏ(địa chỉ)
//     std::cout << a << std::endl;
//     int x = 10;
//     a = &x;
//     std::cout << a << std::endl;
//     std::cout << &x << std::endl;

//     std::cout << *a << std::endl; // lấy ra giá trị của biến con trỏ
//     std::cout << x << std::endl;
//     x = 20; // cho thằng x này nó thay đổi => giá trị của con ônr cũng bị thay đổi
//     std::cout << *a << std::endl; // lấy ra giá trị của biến con trỏ
//     std::cout << x << std::endl;
//     // int x = 5;
//     // std::cout << &x << std::endl;// in ra địa chỉ của biến x
//     // std::cout << x; // in ra giá trị của biến x
//     return 0;
// }