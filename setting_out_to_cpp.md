# Bắt đầu với C++

myfirst.cpp:  

```cpp
#include <iostream>                         // Khai bao' thu* vien can` dung`
using namespace std;                        // Khai bao, dong nay quan trong, giup viet code ngan' hon

int main() {                                                // Bat dau phan than^ ham`
    cout << "Sang nay an sang voi phan bo, gio con no lam"; // In ra man hinh 1 cau noi dung
    cout << '\n';                                           // In ra man hinh 1 dong` moi
    return 0;                                               // Lenh ket thuc ham main()
}                                                           // Ket thuc phan than^ ham`
``` 

Chương trình `myfirst.cpp` có những thành phần sau:  

* Comment (phần mã nguồn/code không được thực thi), được xác định sau dấu `//`
* Từ khóa để khai báo thư viện `#include`
* Tên thư viện `iostream` nằm trong cặp ngoặc `<`, `>` &rarr; `<iostream>`
    * Thư viện **iostream** cung cấp các câu lệnh hỗ trợ nhập/xuất như `cin`, `cout`
* Phần tiêu đề của hàm `int main()`, trong đó:
    * `int` là kiểu dữ liệu của giá trị mà hàm trả về
    * `main` là tên hàm
    * `()` là danh sách các tham số mà hàm nhận vào, ở đây hàm `main` không có tham số nhận vào
        * Ví dụ: `int main(int argc, char *argv[])`
* Phần thân hàm, được xác định bằng cặp ngoặc nhọn `{` và `}`
* Câu lệnh sử dụng C++ `cout` để hiển thị dữ liệu lên màn hình
* Ký tự tạo ra dòng mới `\n`
* Câu lệnh `return` để kết thúc hàm `main()`

**C++ comment**  

Comment được sử dụng để lập trình viên truyền tải đến cho người đọc một số nội dung hoặc giải thích về chức năng, công dụng của các dòng code. Trình biên dịch (compiler) sẽ bỏ qua các comment này.  
Ngoài cách comment bằng dấu `//`, còn có thể comment theo kiểu C bằng cách sử dụng cặp `/*` và `*/`. Ví dụ `/* Day la mot comment */`  
Với `//` nội dung của comment được xác định từ sau dấu `//` đến cuối dòng. Với trường hợp sử dụng cặp `/*` và `*/` nội dung comment là phần nằm trong cặp `/*` và `*/`. <br> `/* Noi dung */`

**Header Filenames**  

Một số tệp tin (files) như là `iostream` gọi là tệp thư viện (_include files_ hoặc _header files_). Trình biên dịch C++ cần một số tệp thư viện, để hỗ trợ một số chức năng. Trong ngôn ngữ C, tệp thư viện sử dụng đuôi/extension `.h`, ví dụ `math.h` là thư viện cung cấp các hàm tính toán toán học, `stdio.h` là thư viện cung cấp các hàm nhập xuất dữ liệu chuẩn.  

**Namespace**  

Nếu sử dụng thư viện `iostream`, cần phải sử dụng namespace `std` để hỗ trợ. Nếu không có chỉ thị `using namespace std` chúng ta sẽ phải viết dài hơn (với một số câu lệnh). Ví dụ:  
`std::cout << "Xin chao";`  
`std::cin >> bien_so;`  
Vì thế nếu thêm chỉ thị `using namespace std;` ở đầu chương trình, chúng ta không gắn thêm `std::` vào một số keyword (nằm trong std).  

**Xuất/In dữ liệu với `cout`**  

**Ký tự xuống dòng (`\n`)




# Bài tập

1. Viết một chương trình C++ hiển thị ra màn hình `tên`, `năm sinh` và `lớp học`.  
2. Viết một chương trình C++ yêu cầu nhập vào số `km`, đổi chúng sang `m` và in ra màn hình.
