# QMAX (cải tiến)

Cho một dãy gồm `𝑛` phần tử có giá trị ban đầu bằng `0`.

Cho các phép biến đổi, mỗi phép có dạng `(0, 𝑢, 𝑘)`: tăng  phần tử ở vị trí `𝑢` lên `𝑘` đơn vị.

Cho các câu hỏi, mỗi câu có dạng `(1, 𝑢, 𝑣)`: cho biết phần tử có giá trị lớn nhất thuộc đoạn `[𝑢, 𝑣]`

Input

* `𝑛`: số phần tử của dãy (𝑛 ≤ 50000).
* `𝑚`: số lượng biến đổi và câu hỏi (𝑚 ≤ 10<sup>5</sup>).
    * biến đổi có dạng: `0 𝑥 𝑣𝑎𝑙𝑢𝑒`
    * câu hỏi có dạng: `1 𝑥 𝑦`.

Output

Ghi ra trả lời cho lần lượt từng câu hỏi.

### Output

* Gồm `𝑚` dòng chứa kết quả tương ứng cho từng câu hỏi.

| Input | Output |
|:---|:---|
6 14 <br> 0 5 8 <br> 0 1 2 <br> 0 2 4 <br> 0 5 3 <br> 1 3 5 <br> 0 1 3 <br> 0 3 6 <br> 0 4 7 <br> 0 6 1 <br> 1 1 6 <br> 0 3 7 <br> 0 4 5 <br> 1 3 5 <br> 1 4 6 | 11 <br> 11 <br> 13 <br> 12 <br>  <br>  <br>  <br>  <br>  <br>  <br>  <br>  <br>  <br>  <br>  <br> 

