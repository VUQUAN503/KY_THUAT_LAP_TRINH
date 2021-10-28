

#include <iostream>

/*
CON TRỎ
+ NÓ LÀ MỘT BIẾN ĐỊA CHỈ
*/

// lambada

int chanLonNhat(int *a, int n)
{
    int max = -1000000000;
    for(int i = 0; i < n; ++i)
    {
        if(*(a + i) % 2 == 0)
        {
            if(*(a + i) > max)
            {
                max = *(a + i);
            }
        }
    }
    return max;
}

/*
CON TRỎ MẢNG
-- TÌM PHẦN TỬ CHẴN LỚN NHẤT TRONG MẢNG số nguyên
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


/*

+ mảng THÊM, XOÁ , TÌM KIẾM, SẮP XẾP, ...
+ CON TRỎ LÀ MỘT BIẾN ĐỊA CHỈ
+ KHI CON TRỎ NẮM GIỮ ĐỊA CHỈ CỦA BIẾN KHÁC THÌ KHI GIÁ TRỊ CỦA MỘT TRONG HAI THẰNG THAY ĐỔI
+ THÌ ĐỒNG THỜI THẰNG KIA CŨNG BỊ THAY ĐỔI LUÔN
+ MẢNG BÌNH THƯỜNG
- LÀ MỘT DÃY CÁC Ô NHỚ NẰM LIỀN NHAU
- CHỈ SỐ ĐÁNH TỪ 0 DẾN N - 1
int a[100] : máy tính tạo ra 100 ô nhớ liền nhau trên vùng nhớ stack(vùng nhớ do máy tính quản lý)
- NẾU KHAI BÁO 100 P TỬ MÀ CHỈ DÙNG CÓ 5 PHẦN TỬ BẰNG 0
+ KHI NÓI ĐẾN MẢNG CON TRỎ(MẢNG ĐỘNG)
- NHẬP N = 5 => MẢNG CÓ 5 PHẦN TỬ
- DÙNG KỸ THUẬT CẤP PHÁT Ô NHỚ
- int *a = new int[n]; mình cấp phát 5 ô nhớ trong vùng nhớ heap(vùng nhớ do dev quản lý)
- CON TRỎ MẢNG NẮM GIỮ ĐỊA CHỈ CỦA PHẦN TỬ ĐẦU TIÊN TRONG MẢNG MÀ MẢNG LÀ MỘT DÃY CÁC Ô NHỚ
- NẰM LIỀN KỀ NHAU => MUỐN TRUY XUẤT ĐẾN PHẦN TỬ TIẾP THEO BẰNG CON TRỎ
- CHÚ Ý MỌI THAO TÁC SỬ LÝ VỚI MẢNG CON TRỎ GIỐNG Y HỆT MẢNG BÌNH THƯỜNG
- nhớ giải phóng vùng nhớ khi không dùng nữa
- delete []a;

smart pointer(con trỏ thông minh)
*/

int main()
{
    // int a = 10;// RAM SẼ TẠO RA MỘT VÙNG NHỚ(STACK) CHỨA ĐỊA CHỈ CỦA BIẾN A VÀ GIÁ TRỊ CỦA BIẾN ĐÓ
    // int b = a;
    // std::cout << a << std::endl;
    // std::cout << &a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << &b << std::endl;
    // b = 100;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << "gia tri ca bien khi dung con tro" << std::endl;
    // // GÁN ĐỊA CHỈ CỦA BIẾN A SANG CHO CON TRỎ C
    // int *c = &a;// HAI CHÀNG MỘT NÀNG
    // std::cout << a << std:: endl;
    // std::cout << &a << std:: endl;
    // std::cout << *c << std:: endl;
    // std::cout << c << std:: endl;
    // *c = 100;
    // std::cout << a << std:: endl;
    // std::cout << &a << std:: endl;
    // std::cout << *c << std:: endl;
    // std::cout << c << std:: endl;
    // // mảng chia hai loại mảng động và mãng tĩnh
    // // mảng tĩnh int a[100];
    // // mảng động : mình dùng bao nhiêu phần tử thì cấp bằng đấy ô nhớ
    // // mảng nó là một dãy các ô nhớ xếp cạnh nhau trong ram

    int *arr = new int[5];// cấp phát ra mảng động gồm có 5 phần tử
    for(int i = 0; i < 5; ++i)
    {
        // 1 2 3 4 5
        arr[i] = i + 1;// gán gái trị mảng thông thường
        // *(arr + i) = i + 1;// nganh bằng với arr[i]
    }
    // std::cout << Tong(arr, 5);
    // mà nó sẽ chỉ giữ địa chỉ của phần tử đầu tiên
    std::cout << arr << std::endl;
    std::cout << &arr[0] << std::endl;
    std::cout << *arr << std::endl;
    std::cout << arr[0] << std::endl;
    // mảng là những ô nhớ nằm cạnh nhau => địa chỉ hơn kém nhau 1 đơn vị
    // std::cout << (arr + 2) << std::endl;
    // std::cout << &arr[2] << std::endl;
    // std::cout << *(arr + 2) << std::endl;
    // std::cout << arr[2] << std::endl;

    // int a[100] ={1, 2, 3, 4, 5};
    // for(int i = 0; i < 5; ++i)
    // {
    //     std::cout << &a[i] << std::endl;
    // }
    delete [] arr;// giải phóng vùng nhớ
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