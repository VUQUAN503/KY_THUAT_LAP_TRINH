#include <iostream>
#include <string.h>


int StrStr(char *s, char *keyword)
{
    int len = Strlen(s);
    int len_kw = Strlen(keyword);

    /*
    vd s: Hoc Lap Trinh
      kw: Lar
    */
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == keyword[0])
        {
            int temp = i + 1;
            bool check = true;
            //int index = 1;
            for (int j = 1; j < len_kw; ++j)
            {
                if (s[temp++] != keyword[j])
                {
                    check = false; // bị sai
                    //printf("\n %d", j);
                    break;
                }
            }
            if (check == true)
            {
                return i;
                //printf("\n%d", i);
            }
            i += len_kw - 1;
        }
    }
    return -1;
}

int main()
{
    char s1[30], s2[30], s3[30];
    char *a, *b, *c;
    std::cout << "Nhap s1: ";
    gets(s1);
    std::cout << "\nNhap s2: ";
    gets(s2);
    a = s1;
    b = s2;
    c = s3;
    for(int i = 0; i < strlen(s1); ++i)
    {
        s3[i] = s1[i];
    }
    for(int i = 0; i < strlen(s2); ++i)
    {
        s3[strlen(s1) + i] = s2[i];
    }
    std::cout << " s3 = " << s3 << std::endl;
    char x[30];
    std::cout << "Nhap x: ";
    gets(x);
    if(StrStr(s3, x) >= 0)
    {
        std::cout << "vi tri xh dau tien cua x trong s3 la: " << StrStr(s3 ,x) << std::endl;
    }
    else{
        std::cout << "x khong xh trong s3";
    }
    return 0;
}