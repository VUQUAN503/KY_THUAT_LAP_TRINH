#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define QUAN_SAID printf
/*
hàm strlen() => trả về độ dài của chuỗi
vd "Hoc Lap Trinh" => len = 13
chuỗi có đọ dài là 13 thì chỉ số ký tự đc đánh dấu từ 0 -> 12  và ký tự 
thứ 13 là ký tự '\0'(kết thúc chuỗi)
chuỗi đang kiểm tra là s
điều kiện dừng của vòng lặp là khi gặp ký tự '\0'
int dem = 0;
int i = 0;// khởi tạo 
while(s[i] != '\0')
{
    dem++;
    i++;// bước lặp
}
*/
int Strlen(const char *s)
{
    int dem = 0;
    //int i = 0;
    // vd s = "Hoc Lap Trinh";
    while (s[++dem] != '\0')
    {
        //dem++;// 13
        //i++;// 13 => s[13] là '\0' => kết thúc vòng lặp đc dem = 13
    }
    return dem;
}

char *StrCpy(char *dest, const char *src)
{
    int len = Strlen(src);
    for (int i = 0; i < len; ++i)
    {
        *(dest + i) = *(src + i);
    }
    dest[len] = '\0';
    return dest;
}

char *Strdup(char *src)
{
    char *temp = src;
    return temp;
}
char *Strupr(char *s)
{
    int len = Strlen(s);
    for (int i = 0; i < len; ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
    return s;
}

char *StrLwr(char *s)
{
    int len = Strlen(s);
    for (int i = 0; i < len; ++i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
    }
    return s;
}

char *Strrev(char *s)
{
    int len = Strlen(s);
    //char *temp = (char *)malloc(len*(sizeof(char)));
    char temp[20];
    int idx = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        temp[idx++] = s[i];
    }
    temp[idx] = '\0';
    StrCpy(s, temp);
    //free(temp);
    return s;
}

int Strcmp(char *s, char *s1)
{
    int len_s1 = Strlen(s1);
    int len_s = Strlen(s);
    int min = len_s1 < len_s ? len_s1 : len_s;
    for (int i = 0; i < min; ++i)
    {
        if (s[i] < s1[i])
            return -1;
        else if (s[i] > s1[i])
            return 1;
    }
    return 0;
}

char *StrCat(char *s, char *s1)
{
    int len_s = Strlen(s);
    int len_s1 = Strlen(s1);
    int idx = 0;
    for (int i = len_s; i < len_s + len_s1; ++i)
    {
        s[i] = s1[idx++];
    }
    s[len_s + len_s1] = '\0';
    return s;
}

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

long long Atol(char *s)
{
    long long sum = 0;
    int len = Strlen(s);
    // "-1234" => len = 5 => -1234
    int i = 0;
    if (s[0] == '-')
    {
        i = 1;
    }
    for (; i < len; ++i)
    {
        int chuso = s[i] - 48;
        sum += chuso * pow(10, len - 1 - i);
    }
    if (s[0] == '-')
    {
        return -sum;
    }
    return sum;
}

float ATof(char *s)
{
    int index = 0;
    int idx = 0;
    int len = Strlen(s);
    char temp[20];
    for (int i = 0; i < len; ++i)
    {
        if (s[i] != '.')
            temp[idx++] = s[i];
        else
            index = i;
    }
    return (float)Atol(temp) / pow(10, len - index - 1);
}

char *VietHoaKyTuDauTienMoiTu(char *s)
{
    int len = Strlen(s);
    if (s[0] >= 'a' && s[0] <= 'z')
        s[0] -= 32;
    for (int i = 1; i < len; ++i)
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
        {
            if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
                s[i + 1] -= 32;
        }
    }
    return s;
}

/*
Các ký tự đầu tiên mỗi từ thành ký tự hoa
hoc lap trinh => Hoc Lap Trinh



/*
atof
    0123 => index = 2
vd "12.34" => 12.34
(float)1234/10 = 12.34
1234/pow(10, 5 - 2 - 1)
dùng mảng phụ => nhớ dùng hàm atoi để đổi nó thành số
*/

char *Itoa(int number)
{
    char *s = (char *)malloc(sizeof(char));
    int index = 0;
    int temp = number;
    if (temp < 0)
        temp *= -1;
    // - 1234
    while (temp != 0)
    {
        s[index++] = temp % 10 + 48;
        temp /= 10;
    }
    //4321
    if (number < 0)
    {
        s[index++] = '-';
    }
    s[index] = '\0';
    Strrev(s);
    return s;
}

char *ITOA(int value, char *buffet, int radix)
{
    int index = 0;
    int number = value;
    if (value < 0)
        value *= -1;
    while (value != 0)
    {
        if (value % radix == 10)
            buffet[index++] = 'a';
        else if (value % radix == 11)
            buffet[index++] = 'b';
        else if (value % radix == 12)
            buffet[index++] = 'c';
        else if (value % radix == 13)
            buffet[index++] = 'd';
        else if (value % radix == 14)
            buffet[index++] = 'e';
        else if (value % radix == 15)
            buffet[index++] = 'f';
        else
            buffet[index++] = value % radix + 48;
        // quy ước nếu hệ 2 8 16 nếu số âm thì thành dương còn hệ 10 mình xét trường hợp âm
        value /= radix;
    }
    if (number < 0 && radix == 10)
        buffet[index++] = '-';
    // mọi người có thể lên mạng tra xem số âm sang hệ 2 8 16 kiểu gì
    // xong làm như nào
    buffet[index] = '\0';
    Strrev(buffet);
    return buffet;
}
/*
itoa 1234 => "1234"
vd 1 2 3 4
s[3] = 1 + 48
s[2] = 2 + 48
s[1] = 3 + 48
s[0] = 4 + 48
"4321" = "1234" Dảo ngược


*/

/*
atoi 
vd "1234" => 1234
lưu ý ký tự 1 hơn số 1 48 đơn vị
vd '4' - 48 = 4
    '3' - 48 = 3
    '2' - 48 = 2
    '1' - 48 = 1
    1234 = 1*10^3 + 2*10^2 + 3*10^1 + 4*10^0
    = 1000 + 200 + 30 + 4 = 1234
*/

void XoaKYTu(char *s, int vtxoa)
{
    int len = Strlen(s);
    for (register int i = vtxoa + 1; i < len; ++i)
        s[i - 1] = s[i];
    len--;
    s[len] = '\0';
}

char *ChuanHoaChuoi(char *s)
{
    int len = Strlen(s); // 20
    for (register int i = 0; i < len; ++i)
    {
        if (s[i] == ' ' && (s[i - 1] == ' ' || s[i + 1] == ' '))
        {
            XoaKYTu(s, i);
            i--;
        }
    }
    if (s[0] == ' ')
        XoaKYTu(s, 0);
    int len_1 = Strlen(s);
    if (s[len_1 - 1] == ' ')
        s[len_1 - 1] = '\0';
    return s;
}

int SoLuongTu(char *s)
{
    int len = Strlen(s);
    int count = 0;
    for (int i = 0; i < len; ++i)
    {
        //        Hoc          Lap         Trinh
        if (s[i] != ' ')
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (s[j] == ' ')
                {
                    count++;
                    i = j - 1;
                    break;
                }
            }
        }
    }
    if (s[len - 1] == ' ')
        return count;
    return count + 1;
}

int MaxTu(char *s)
{
    int len = Strlen(s);
    int max = INT_MIN;
    int start, end;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] != ' ')
        {
            start = i;
            for (int j = i + 1; j < len; ++j)
            {
                if (s[j] == ' ')
                {
                    end = j;
                    i = j - 1;
                    break;
                }
                else if (s[len - 1] != ' ')
                    end = j + 1;
            }
            if (end - start > max)
                max = end - start;
        }
    }
    return max;
}

/*
tìm từ có đọ dài lớn nhất
   0123
vd Hoc Lap Trinh => Từ Trinh có độ dài là dài nhất
*/

/*
Viết hàm nhận vào một chuỗi s và đếm
xem có bao nhiêu từ trong chuỗi đó.
     Hoc Lap Trinh       => có 3 từ
=> 
*/
/*
Chuẩn hóa chuỗi (xóa khoảng trắng thừa).
vd        Hoc      Lap Trinh        
=> Hoc Lap Trinh
*/
/*
STRSTR(char *s, char *s1) tìm chuỗi s1 trong chuỗi s
nếu có trả về vị trí xuất hiện đầu tiên của chuỗi s1 trong s
nếu chuỗi s1 ko nằm trong s trả về -1
vd Hoc Lap TrLnh
vd  La
=> 4->6

b1: mình duyệt chuối s nếu ký tự nào bằng ký tự đầu tiên của s1
thì
mình sẽ duyệt chuỗi s từ vị trí ký tự vừa bằng ký tự dầu tiên của s1
cho vòng lặp chạy từ vị trí ký tự bằng đến vt + đọ dài s1
so sánh các ký tự trong khoảng đó với từng ký tự của chuỗi s1
chỉ cần một ký tự trong khoảng đó khác với ký tự trong chuỗi s
thì mình sẽ duyệt tiếp chuỗi s với vt tiếp theo
nếu chuỗi s1 trùng hết trong khoảng mình vừa xét
=> thỏa mãn và trả về vị trí của ký tự đầu tiên của s1 trong chuỗi s
LÀM HẾT BÀI 1
*/

/*
HÀM STRCAT(char s, char s1) nối chuỗi s1 vào sau chuỗi s
cho vòng lặp bắt đầu từ len(s) điều kiện lặp < len(s) + len(s1);
*/

/*
hàm STRCMP(char s, char s1)
nếu s < s1 trả về -1
nếu s == s1 trả về 0
nếu s > s1 trả về 1
độ lớn ký tự
vd Hoc
   HOc
   => Hoc lớn hơn
   => quy tắc
*/

/*
Đảo ngược chuỗi
vd: Hoc => coh
b1:cho vòng lặp chạy ngược lại gán s => s1
*/

/*
HÀM CHUYỂN CHUỖI THƯỜNG THÀNH HOA
VD hoc lap trinh => HOC LAP TRINH
CHỮ CÁI HOA VÀ THƯỜNG CÁCH NHAU 32 ĐƠN VỊ(CỤ THỂ THƯỜNG LỚN HƠN HOA)
VD a = 97 => A 65
chạy vòng lặp
nếu ký tự đó >= a và nho bằng z => trừ đi 32
*/
/*
HÀM STRCPY => SAO CHÉP CHUỖI
char *strcpy(char *_dest, const char *src)
vd s = "Hoc Lap Trinh" => s1 = "Hoc Lap Trinh"
cho vòng chạy và gán từng ký tự của s sang cho s1
*/
int main()
{
    char name[] = "      hoc                   lap    trinh!";
    //VietHoaKyTuDauTienMoiTu(name);
    // ChuanHoaChuoi(name);
    // QUAN_SAID("%s", name);
    QUAN_SAID("%d", MaxTu(name));
    //QUAN_SAID("%d", 1);
    // char name[20] = "v";
    // char name1[20] = "Vu Dinh Quan Dir";
    // char keyword[10] = "Dir";
    // int result = StrStr(name1, keyword);
    // printf("%d", result);
    // char StringNumber[20] = "-1234";
    // int result = atoi(StringNumber);
    // printf("%d", result);
    // int number = 250;
    // char StringNumber[20];
    // char StringNumber1[20];
    // StrCpy(StringNumber, ITOA(number, StringNumber, 16));
    // StrCpy(StringNumber1, itoa(number, StringNumber1, 16));
    // printf("%s", StringNumber);
    // printf("\n%s", StringNumber1);
    // char number[20] = "12.3456784";
    // float result = ATof(number);
    // float result1 = atof(number);
    // printf("%f", result);
    // printf("\n%f", result1);
    // int kq = Strcmp(name, name1);
    // printf("%d", kq);
    //Strupr(name);
    // StrLwr(name);
    // Strrev(name);
    // printf("%s", name);
    // int len = Strlen(name);
    // printf("%d", len);
    // char s[20];
    // StrCpy(s, name);
    // char *s;
    // s = Strdup(name);
    // printf("%s", s);
    return 0;
}

/*
vd 250
muốn đổi sang hệ 2
250 % 2 = 0
250 / 2 = 125
125 % 2 = 1
125 / 2 = 74
74 % 2 = 0
74 / 2 = 37
37 % 2 = 1
37 / 2 = 18
18 % 2 = 0
18 / 2 = 9
9 % 2 = 1
9 / 2 = 4
4 % 2 = 0
4 / 2 = 2
2 % 2 = 0
2 / 2 = 1
1 % 2 = 1
1 / 1 = 0
=> 250 đổi sang hệ 2 100101010

đổi sang hệ bát phân
250 % 8 = 2
250 / 8 = 31
31 % 8 = 7
31 / 8 = 3
3 % 8 = 3
3 / 8 = 0
=> 250 đổi sang hệ 8 = 372

đổi 250 sang hệ 10
250 % 10 = 0
250 / 10 = 25
25 % 10 = 5
25 / 10 = 2
2 % 10 = 2
2 / 10 = 0
=> 250 sang hệ 10 đc 250

250 sang hệ 16(10 : A, 11: B, 12:C, 13:D, 14:E, 15:F)
250 % 16 = 10 A
250 / 16 = 15
15 % 16  15 F
15 / 16 = 0
=> 250 sang 16 đc FA
*/