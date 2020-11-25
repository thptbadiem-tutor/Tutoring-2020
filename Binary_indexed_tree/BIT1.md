# Binary Indexed Tree - Example Problem 1

Cho dãy số a gồm `n` số nguyên dương, với mỗi phần tử `a[i]` đếm số lượng phần tử `a[j]` (với `j < i`) thỏa `a[j] < a[i]` . (Giải thích: với mỗi giá trị `a[i]` trong dãy a đếm số lượng giá trị trong dãy a nhỏ hơn `a[i]` đã xuất hiện trước đó).

## Giới hạn

* n ≤ 10<sup>5</sup>
* 0 < a<sub>i</sub> ≤ 10<sup>6</sup>

## Input

* Dòng đầu tiên chứa một số nguyên `n` duy nhất, là số lượng phần tử của dãy số
* Dòng thứ hai chứa `n` số nguyên dương

## Output

* Gồm n dòng, mỗi dòng chứa một số nguyên

## Dữ liệu mẫu

| Input | Output |
|---|---|
| 10 <br> 5 1 7 15 10 6 8 9 2 3 <br> <br> <br> <br> <br> <br> <br> <br> <br> | 0 <br> 0 <br> 2 <br> 3 <br> 3 <br> 2 <br> 4 <br> 5 <br> 1 <br> 2

Giải thích

* Với giá trị 5 không có giá trị nào nhỏ hơn 5 đã xuất hiện trước đó
* Với giá trị 1 không có giá trị nào nhỏ hơn 1 đã xuất hiện trước đó
* Với giá trị 7 có 2 giá trị (5, 1) thỏa điều kiện
* Với giá trị 15 có 3 giá trị (5, 1, 7) thỏa điều kiện
* Với giá trị 10 có 3 giá trị (5, 1, 7) thỏa điều kiện
* Với giá trị 6 có 2 giá trị (5, 1) thỏa điều kiện
* Với giá trị 8 có 4 giá trị (5, 1, 7, 6) thỏa điều kiện
* Với giá trị 9 có 5 giá trị (5, 1, 7, 6, 8) thỏa điều kiện
* Với giá trị 2 có 1 giá trị (1) thỏa điều kiện
* Với giá trị 3 có 2 giá trị (1, 2) thỏa điều kiện
