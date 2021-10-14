#include <iostream>



//Hãy liệt kê các giá trị xuất hiện trong dãy quá một lần (lietke). Lưu ý: 
// mỗi giá trị liệt kê một lần.

/*

sẽ tạo mảng phụ có 6 phần tử cho nó có giá trị 0
0 1 2 3 4 5
1 1 1 1 1 1

0 1 2 3 4 5
2 3 1 4 2 5
2: 2
3: 1
1: 1
4: 1
2: 1
5: 1
*/

void tanSo(int a[], int n)
{
    // khai báo tất cả phần tử bằng 0
    int b[100] = {0};// khai báo mảng phụ có n phần tử bằng 0 đánh dấu 
    for(int i = 0; i < n; ++i)
    {
        if(b[i] == 0)
        {
            b[i] = 1;// đã xét phần tử này 
            int dem = 1;
            for(int j = i + 1; j < n; ++j)
            {
                if(a[i] == a[j])
                {
                    b[j] = 1;// phần tử này xét rồi
                    dem++;
                }
            }
            std::cout << a[i] << " xuat hien : " << dem << " lan" << std::endl;
        }
    }
}

int main()
{
    int a[100] = {2, 2, 2, 2, 2};
    tanSo(a, 5);
    return 0;
}