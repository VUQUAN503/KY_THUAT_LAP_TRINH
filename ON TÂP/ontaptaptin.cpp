#include <iostream>
#include <fstream>

/*
                            TỆP TIN
// NẰM TRONG THƯ VIỆN FSTREAM
tệp tin nó là một class => mỗi thể hiện của nó là một object
=> nó hỗ trợ nhưng thuộc tính và phương thức xử lý thao tác với tệp
bằng cách tên biến (object)  chấm trực tiếp đến phương thức
+ HAI THAO TÁC CHÍNH TRÊN TÊP
-- ĐỌC DỮ LIỆU TỪ TỆP VÀO CHƯƠNG TRÌNH
-- GHI DỮ LIỆU TỪ TỆP VÀO TRƯƠNG TRÌNH

1/ ĐỌC DỮ LIỆU(NẰM TRONG THƯ VIỆN FSTREAM)
// CLASS NÓ LÀ ofstream
=> khi khai báo ra một biến đố tượng để đọc
// khai báo chuỗi string name
ifstream tên biên; // khai báo ra một đối tượng để thao tác đọc dữ liệu
// vì nó là một class
=> nó có những pt hỗ trợ xử lý thao tác với tệp(đọc)
+ phương thức(hàm) mở tệp
tên biến chấm hàm open(hai tham số)
+ open(đường dẫn đến tệp, đối số để ghi)
+ nó có hai loại: đường dẫn tuyệt đối, tương đối
+ đối số để ghi dữ liệu
- out(nếu đối số thứ hai là out thì mỗi lần ghi dữ liệu vào tệp thì dữ liệu cũ có trong tệp
 sẽ bị xoá đi và ghi dữ liệu mới vào)
- app(nếu đối số thứ hai là app(append) thì dữ liệu sẽ đc ghi ngay vào sau dữ liệu cũ)
vd abcxyz ghi thêm ghi => abcxyzghi

 XỬ LÝ GHI DỮ LIỆU
 + ĐỂ GHI DỮ LIỆU VÀO TRONG TỆP
 + KHI MÌNH GHI DỮ LIỆU RA MÀN HÌNH std::cout << 
 + MÌNH MUỐN GHI DỮ LIỆU RA TỆP thay cout thành tên biến (object) để ghi
    vd file << DỮ LIỆU GHI VÀO FILE

-- VÀ SAU KHI GHI DỮ LIỆU HOÀN TẤT
=> NHỚ ĐÓNG TỆP TIN LẠI BẰNG HÀM close() thông qua tên biến(tên tệp, object) chấm trực tiếp tên hàm
+ phương thức(hàm) đóng tệp
tên tệp .close();
// CHÚ Ý: KHI GHI DỮ LIỆU
+ NẾU ĐƯỜNG DẪN TRUYỀN VÀO TRONG THAM SỐ THỨ NHẤT CỦA HÀM OPEN MÀ NÓ KHÔNG TỒN TẠI
=> MÁY TÍNH TỰ TẠO CHO MÌNH TỆP Ở ĐƯỜNG ĐÓ (CHỈ XẢY RA KHI GHI DỮ LIỆU VÀO FILE)
*/

int main()
{
    int *a = new int[5]{3, 1, 6, 4, 3};
    std::ofstream ahihi;// khai báo ra một đối tượng tệp
    // mở tệp
    ahihi.open("dulieu.txt", std::ios_base::app);
    // thao tác ghi
    std::cout << 10;// ghi dữ liệu ra màn hình console
    // ghi mảng a vào trong tệp
    // xuất mảng a ra màn hình
    for(int i = 0; i < 5; ++i)
    {
        std::cout << a[i] << " ";// ghi dữ liệu từ mảng ra màn hình
        ahihi << a[i] << " "; // ghi từng phần tử của mảng vào tệp
    }
    //ahihi << 10;// ghi dữ liệu vào tệp
    // đóng tệp
    ahihi.close();
    delete[] a;// free(a)
    return 0;
}