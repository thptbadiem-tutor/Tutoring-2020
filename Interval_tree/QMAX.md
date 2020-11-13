# QMAX

Cho một dãy gồm `𝑛` phần tử có giá trị ban đầu bằng `0`.

Cho `𝑚` phép biến đổi, mỗi phép có dạng `(𝑢, 𝑣, 𝑘)`: tăng mỗi phần tử từ vị trí `𝑢` đến vị trí `𝑣` lên 𝑘 đơn vị.

Cho `𝑞` câu hỏi, mỗi câu có dạng `(𝑢, 𝑣)`: cho biết phần tử có giá trị lớn nhất thuộc đoạn `[𝑢, 𝑣]`

### Input

* Dòng 1: `𝑛`, `𝑚`
* `𝑚` dòng tiếp theo, mỗi dòng chứa `𝑢`, `𝑣`, `𝑘` cho biết một phép biến đổi
* Dòng thứ `𝑚+2`: `𝑝`
* `𝑝` dòng tiếp theo, mỗi dòng chứa `𝑢`, `𝑣` cho biết một phép biến đổi
* `𝑛`, `𝑚`, `𝑞` `≤` `50000`
* `𝑘` `>` `0`
* Giá trị của một phần tử luôn không vượt quá 2<sup>31</sup>− 1

### Output

* Gồm `𝑝` dòng chứa kết quả tương ứng cho từng câu hỏi.

| Input | Output |
|:---|:---|
| 6 2 <br> 1 3 2 <br> 4 6 3 <br> 1 <br> 3 4 | 3  <br>  <br>  <br>  <br>  <br> |

[Link nộp bài](https://codeforces.com/group/FLVn1Sc504/contest/274521/problem/G)  
[Code mẫu](https://github.com/thptbadiem-tutor/Tutoring-2020/blob/master/Interval_tree/QMAX.cpp)  
