# Binary Indexed Tree - Example Problem 8

(Đây là phiên bản có giới hạn nhỏ hơn của bài [BIT9](https://github.com/thptbadiem-tutor/Tutoring-2020/blob/master/Binary_indexed_tree/BIT9.md))

Cho dãy số a gồm `n` số **nguyên**, với mỗi phần tử `a[i]` tìm giá trị `max(a[j])` (với `j < i`) thỏa `a[j] < a[i]` . (Giải thích: với mỗi giá trị `a[i]` trong dãy a tìm giá trị lớn nhất trong số các giá trị nhỏ hơn `a[i]` đã xuất hiện trước đó).

Nếu giá trị cần tìm không tồn tại, in ra chuỗi `No solution`

## Giới hạn

* n ≤ 10<sup>5</sup>
* -10<sup>6</sup> ≤ a<sub>i</sub> ≤ 10<sup>6</sup>

## Input

* Dòng đầu tiên chứa một số nguyên `n` duy nhất, là số lượng phần tử của dãy số
* Dòng thứ hai chứa `n` số nguyên dương

## Output

* Gồm n dòng, mỗi dòng chứa một số nguyên hoặc chuỗi `No solution`

## Dữ liệu mẫu

| Input | Output |
|---|---|
| 10 <br> 5 1 7 15 10 6 8 9 2 3 <br> <br> <br> <br> <br> <br> <br> <br> <br> | No solution <br> No solution <br> 5 <br> 7 <br> 7 <br> 5 <br> 7 <br> 8 <br> 1 <br> 2

Giải thích

* Với giá trị 5 không có giá trị nào nhỏ hơn 5 đã xuất hiện trước đó
* Với giá trị 1 không có giá trị nào nhỏ hơn 1 đã xuất hiện trước đó
* Với giá trị 7 giá trị lớn nhất và nhỏ hơn 7 đã xuất hiện trước đó là 5
* Với giá trị 15 giá trị lớn nhất và nhỏ hơn 15 đã xuất hiện trước đó là 7
* Với giá trị 10 giá trị lớn nhất và nhỏ hơn 10 đã xuất hiện trước đó là 7
* Với giá trị 6 giá trị lớn nhất và nhỏ hơn 6 đã xuất hiện trước đó là 5
* Với giá trị 8 giá trị lớn nhất và nhỏ hơn 8 đã xuất hiện trước đó là 7
* Với giá trị 9 giá trị lớn nhất và nhỏ hơn 9 đã xuất hiện trước đó là 8
* Với giá trị 2 giá trị lớn nhất và nhỏ hơn 2 đã xuất hiện trước đó là 1
* Với giá trị 3 giá trị lớn nhất và nhỏ hơn 3 đã xuất hiện trước đó là 2

<br>

| Input | Output |
|---|---|
| 10 <br> -5 -1 -7 -15 -10 -6 -8 -9 -2 -3 <br> <br> <br> <br> <br> <br> <br> <br> <br> | No solution <br> -5 <br> No solution <br> No solution <br> -15 <br> -7 <br> -10 <br> -10 <br> -5 <br> -5
