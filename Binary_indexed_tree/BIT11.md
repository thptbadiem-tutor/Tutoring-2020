# Binary Indexed Tree - Example Problem 11

(Đây là phiên bản có giới hạn nhỏ hơn của bài [BIT12](https://github.com/thptbadiem-tutor/Tutoring-2020/blob/master/Binary_indexed_tree/BIT12.md))

Cho dãy số a gồm `n` số **nguyên**, với mỗi phần tử `a[i]` tìm giá trị `min(a[j])` (với `j < i`) thỏa `a[j] > a[i]` . (Giải thích: với mỗi giá trị `a[i]` trong dãy a tìm giá trị nhỏ nhất trong số các giá trị lớn hơn `a[i]` đã xuất hiện trước đó).

Nếu giá trị cần tìm không tồn tại, in ra chuỗi `No solution`

## Giới hạn

* n ≤ 10<sup>5</sup>
* -10<sup>6</sup> ≤ a<sub>i</sub> ≤ 10<sup>6</sup>

## Input

* Dòng đầu tiên chứa một số nguyên `n` duy nhất, là số lượng phần tử của dãy số
* Dòng thứ hai chứa `n` số nguyên

## Output

* Gồm n dòng, mỗi dòng chứa một số nguyên hoặc chuỗi `No solution`

## Dữ liệu mẫu

### Ví dụ 1

| Input | Output |
|---|---|
| 10 <br> 5 1 7 15 10 6 8 9 2 3 <br> <br> <br> <br> <br> <br> <br> <br> <br> | No solution <br> 5 <br> No solution <br> No solution <br> 15 <br> 7 <br> 10 <br> 10 <br> 5 <br> 5

Giải thích

* Với giá trị 5 **không có** giá trị nào lớn hơn 5 đã xuất hiện trước đó
* Với giá trị 1 các giá trị lớn hơn 1 đã xuất hiện trước đó là 5 &rarr; Giá trị nhỏ nhất là 5
* Với giá trị 7 **không có** giá trị nào lớn hơn 7 đã xuất hiện trước đó
* Với giá trị 15 **không có** giá trị nào lớn hơn 15 đã xuất hiện trước đó
* Với giá trị 10 các giá trị lớn hơn 10 đã xuất hiện trước đó là 15 &rarr; Giá trị nhỏ nhất là 15
* Với giá trị 6 các giá trị lớn hơn 6 đã xuất hiện trước đó là 7, 15, 10 &rarr; Giá trị nhỏ nhất là 7
* Với giá trị 8 các giá trị lớn hơn 8 đã xuất hiện trước đó là 15, 10 &rarr; Giá trị nhỏ nhất là 10
* Với giá trị 9 các giá trị lớn hơn 9 đã xuất hiện trước đó là 15, 10 &rarr; Giá trị nhỏ nhất là 10
* Với giá trị 2 các giá trị lớn hơn 2 đã xuất hiện trước đó là 5, 7, 15, 10, 6, 8, 9  &rarr; Giá trị nhỏ nhất là 5
* Với giá trị 3 các giá trị lớn hơn 3 đã xuất hiện trước đó là 5, 7, 15, 10, 6, 8, 9  &rarr; Giá trị nhỏ nhất là 5

### Ví dụ 2

| Input | Output |
|---|---|
| 10 <br> -5 -1 -7 -15 -10 -6 -8 -9 -2 -3 <br> <br> <br> <br> <br> <br> <br> <br> <br> | No solution <br> No solution <br> -5 <br> -7 <br> -7 <br> -5 <br> -7 <br> -8 <br> -1 <br> -2

Giải thích  

* Với giá trị -5 **không có** giá trị nào lớn hơn -5 đã xuất hiện trước đó
* Với giá trị -1 **không có** giá trị nào lớn hơn -1 đã xuất hiện trước đó
* Với giá trị -7 các giá trị lớn hơn -7 đã xuất hiện trước đó là -5, -1 &rarr; Giá trị nhỏ nhất là -5
* Với giá trị -15 các giá trị lớn hơn -15 đã xuất hiện trước đó là -5 -1 -7 &rarr; Giá trị nhỏ nhất là -7
* Với giá trị -10 các giá trị lớn hơn -10 đã xuất hiện trước đó là -5 -1 -7 &rarr; Giá trị nhỏ nhất là -7
* Với giá trị -6 các giá trị lớn hơn -6 đã xuất hiện trước đó là -5 -1 &rarr; Giá trị nhỏ nhất là -5
* Với giá trị -8 các giá trị lớn hơn -8 đã xuất hiện trước đó là -5 -1 -7 -6 &rarr; Giá trị nhỏ nhất là -7
* Với giá trị -9 các giá trị lớn hơn -9 đã xuất hiện trước đó là -5 -1 -7 -6 -8 &rarr; Giá trị nhỏ nhất là -8
* Với giá trị -2 các giá trị lớn hơn -2 đã xuất hiện trước đó là -1 &rarr; Giá trị nhỏ nhất là -1
* Với giá trị -3 các giá trị lớn hơn -3 đã xuất hiện trước đó là -1, -2 &rarr; Giá trị nhỏ nhất là -2
