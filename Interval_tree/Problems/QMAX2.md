# QMAX2

Cho một dãy gồm `𝑛` phần tử có giá trị ban đầu bằng `0`.

Cho các phép biến đổi, mỗi phép có dạng `(0, 𝑢, 𝑣, 𝑘)`: tăng mỗi phần tử từ vị trí `𝑢` đến vị trí `𝑣` lên `𝑘` đơn vị.

Cho các câu hỏi, mỗi câu có dạng `(1, 𝑢, 𝑣)`: cho biết phần tử có giá trị lớn nhất thuộc đoạn `[𝑢, 𝑣]`

### Input

* `𝑛`: số phần tử của dãy (𝑛 ≤ 50000).
* `𝑚`: số lượng biến đổi và câu hỏi (𝑚 ≤ 10<sup>5</sup>).
    * biến đổi có dạng: `0 𝑥 𝑦 𝑣𝑎𝑙𝑢𝑒`
    * câu hỏi có dạng: `1 𝑥 𝑦`.

### Output

* Gồm `𝑚` dòng chứa kết quả tương ứng cho từng câu hỏi.

| Input | Output |
|---|---|
| 6 3 <br> 0 1 3 3 <br> 0 4 6 4 <br> 1 1 6 | 4 <br>  <br>  <br> <br> 

[Link nộp bài](https://codeforces.com/group/FLVn1Sc504/contest/274521/problem/H)  
[Code mẫu](https://github.com/thptbadiem-tutor/Tutoring-2020/blob/master/Interval_tree/QMAX2.cpp)  
