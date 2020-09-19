# Phụ lục A: HỆ CƠ SỐ

* Số nguyên trong hệ cơ số 8 (bát phân) - Octal Integers
* Số nguyên trong hệ cơ số 16 (thập lục phân) - Hexadecimal Numbers
* Số nhị phân - Binary Numbers
* Hệ nhị phân và hệ 16 - Binary and Hex

Trong cuộc sống thường ngày, chúng ta thường viết số dựa trên các lũy thừa của 10. Ví dụ số `2468`: 2 biểu diễn cho 2 nghìn, 4 biểu diễn cho 4 trăm, 6 biểu diễn cho 6 mươi, và 8 biểu diễn cho 8 đơn vị. 

`2468 = 2x1000 + 4x1000 + 6x10 + 8x1`  

Một ngàn là `10x10x10`, có thể viết thành 10<sup>3</sup>. Sử dụng cách biểu diễn này, chúng ta có thể viết lại số 2468 như sau: 2468 = 2x10<sup>3</sup> + 4x10<sup>2</sup> + 6x10<sup>1</sup> + 8x10<sup>0</sup>.  

C++ cũng cho phép dùng hệ bát phân và hệ thập lục phân để viết số nguyên.

## Hệ cơ số 8 (bát phân)

Số hệ bát phân được biểu diễn theo các lũy thừa của 8, cho nên hệ 8 sử dụng các chữ số từ `0` đến `7` để viết số. C++ sử dụng tiền tố `0` để biểu thị số hệ bát phân. Cho nên 0177 và 03744 là các số hệ bát phân. Có thể sử dụng các lũy thừa của 8 để quy đổi số hệ 10.

| Octal - hệ bát phân | |
|---|---|
| 0177 | = 1x8<sup>2</sup> + 7x8<sup>1</sup> + 7x8<sup>0</sup> <br> = 1x64 + 7x8 + 7x1 <br> = 127 (hệ thập phân)
| 03744 | = 3x8<sup>3</sup> + 7x8<sup>2</sup> + 4x8<sup>1</sup> + 4x8<sup>0</sup> <br> = 3x512 + 2x64 + 4x8 + 4x0 <br> = 2020 (hệ thập phân)

Hệ điều hành nhân UNIX thường dùng hệ bát phân để biểu diễn giá trị, vì vậy C++ và C hỗ trợ hệ biểu diễn hệ bát phân.

## Hệ cơ số 16 (thập lục phân)

Số hệ thập lục phân được biểu diễn theo các lũy thừa của 16, cho nên hệ 16 sử dụng các chữ số từ `0` đến `9` và từ `A` đến `F`. Cho nên số 10 trong hệ cơ số 16 biểu diễn giá trị 16 + 0, hoặc 16. C++ chấp nhận chữ số in hoa và in thường.

| Chữ số hệ 16 | Giá trị hệ 10 | Chữ số hệ 16 | Giá trị hệ 10 |
|:---:|:---:|:---:|:---:|
| `a` hoặc `A` | 10 | `d` hoặc `D` | 13 |
| `b` hoặc `B` | 11 | `e` hoặc `E` | 14 |
| `c` hoặc `C` | 12 | `f` hoặc `F` | 15 |

C++ quy định dùng `0x` hoặc `0X` để biểu diễn số hệ 16. Cho nên `0x2B3` là giá trị hệ 16. Để quy đổi sang giá trị hệ 10 tương ướng, sử dụng các lũy thừa của 16.

| Hexedecimal (Hệ thập lục phân) | |
|---|---|
| 0x2B3 | = 2x16<sup>2</sup> + 11x16<sup>1</sup> + 3x16<sup>0</sup> <br> = 2x256 + 11x16 + 3x1 <br> = 691

Các tài liệu phần cứng thường sử dụng hệ cơ số 16 để biểu diễn các giá trị như `memory location` hoặc `port number`.

## Hệ cơ số 2 (nhị phân)

Khi sử dụng hệ thập phân, bát phân và thập lục phân để biểu diễn số nguyên, máy tính lưu trữ chúng dưới dạng số nhị phân. Biểu diễn nhị phân sử dụng 2 chữ số, 0 và 1. Ví dụ `10011011` là số nhị phân. Tuy nhiên C++ không hỗ trợ công cụ để viết số nhị phân. Số hệ nhị phân biểu diễn dựa trên các lũy thừa của 2.

| Số hệ nhị phân | |
|---|---|
| 10011011 | = 1x2<sup>7</sup> + 0x2<sup>6</sup> + 0x2<sup>5</sup> + 1x2<sup>4</sup> + 1x2<sup>3</sup> + 0x2<sup>2</sup> + 1x2<sup>1</sup> + 1x2<sup>0</sup> <br> = 128 + 0 + 0 + 16 + 8 + 0 + 2 + 1 <br> = 155
| 11000110 | = 1x2<sup>7</sup> + 1x2<sup>6</sup> + 0x2<sup>5</sup> + 0x2<sup>4</sup> + 0x2<sup>3</sup> + 1x2<sup>2</sup> + 1x2<sup>1</sup> + 0x2<sup>0</sup> <br> = 128 + 64 + 0 + 0 + 0 + 4 + 2 + 0 <br> = 198 


## Hệ cơ số 2 và hệ cơ số 16

Người ta thường dùng hệ 16 như là một cách thuận tiện hơn để biểu diễn dữ liệu hệ nhị phân. Vì mỗi chữ số hệ 16 biểu diễn 4-bit trong hệ nhị phân.

| Hệ cơ số 16 | Hệ cơ số 2 | Hệ cơ số 16 | Hệ cơ số 2 |
|---|---|---|---|
| 0 | 0000 | 8 | 1000 |
| 1 | 0001 | 9 | 1001 |
| 2 | 0010 | A | 1010 |
| 3 | 0011 | B | 1011 |
| 4 | 0100 | C | 1100 |
| 5 | 0101 | D | 1101 |
| 6 | 0110 | E | 1110 |
| 6 | 0111 | F | 1111 |

Để quy đổi từ số hệ 16 sang hệ 2, chỉ cần thay đổi mỗi chữ số hệ 16 sang biểu diễn hệ 2 tương ứng. Ví dụ, số hệ 16 `0xA4` tương ứng với số hệ nhị phân `1010 0100`. Tương tự, có thể chuyển đổi từ hệ nhị phân sang hệ 16 dễ hơn bằng cách chuyển đổi từng nhóm 4-bit sang số hệ 16. Ví dụ, số nhị phân `1001 0101` tương ứng với `0x95`.


# Phụ lục B: TỪ KHÓA C++

Từ khóa là các `identifiers` dưới dạng các từ vựng của một ngôn ngữ lập trình. Các từ khóa này không được dùng cho các mục đích khác, như là đặt tên biến. Danh sách bên dưới liệt kê các từ khóa trong C++; không phải tất các từ khóa đều được hỗ trợ (trong phiên bản hiện tại). Từ khóa được **in đậm** cũng là các từ khóa trong chuẩn ANSI C99. 

| Từ khóa | trong C++ | | | |
|---|---|---|---|---|
| asm | **auto** | bool | **break** | **case** |
| catch | **char** | class | **const** | const_cast | 
| **continue** | **default** | delete | **do** | double |
| dynamic_cast | **else** | **enum** | explicit | export |
| **extern** | false | **float** | **for** | friend | 
| **goto** | **if** | **inline** | **int** | **long** |
| mutable | namespace | new | operator | private |
| protected | public | **register** | reinterpret_cast | **return** |
| **short** | **signed** | **sizeof** | **static** | static_cast |
| **struct** | **switch** | template | this | throw |
| true | try | **typedef** | typeid | typename |
| **union** | **unsigned** | using | virtual | **void** |
| **volatile** | wchar_t | **while**

# Phụ lục C: BẢNG KÝ TỰ ASCII

# Phụ lục D: ĐỘ ƯU TIÊN TOÁN TỬ

# Phụ lục E: MỘT SỐ TOÁN TỬ KHÁC

# Phụ lục F: `string` CLASS

# Phụ lục G: THƯ VIỆN `STL`
