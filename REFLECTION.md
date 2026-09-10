  
1.Với  insertion sort algorithm, lý do ta sử dụng nó là vì nó có thể xử lý nhanh các dữ liệu vào gần như được sắp xếp sẵn, đồng thời cũng rất ổn định, không có overhead.  
Với selection sort thì nó chỉ cần tìm top 3 đơn giản, sau 3 vòng, ba bid cao nhất nằm ở đầu mảng, nên ta có thể dùng sớm.  
Với interchange sort thì dùng được vì công cụ chỉ xử lý các dữ liệu nhỏ, cấu trúc 2 vòng lặp dễ đếm số lần swaps và so sánh.  
Với bubble sort, vì nó có dừng sớm nên rất phù hợp để kiểm tra đúng sai, và cũng rất ổn đinh.  
Với quick sort, vì nó có khả năng xử lý dữ liệu lớn, chiến lược median of three giảm khả năng rơi vào hỗn loạn.  
2.Khoảng run-time đã thu được sau khi chạy 100k bid là 27ms  
3\. Khi làm thì em đã gặp rất nhiều bug về truyền dữ liệu trong các thuật toán sao cho đúng, và bản thân em đã sử dụng LLM để hỗ trợ tìm lỗi  
4\. 1Tìm lỗi trong code, 2Giải thích cách hoạt động của thuật toán quick sort  
5\. Nó vẫn là O(n^2) ở trường hợp xấu nhất vì median\_of-three chỉ giảm xác suất gặp pivot của trường hợp xấu nhất thôi nó vẫn là O(n²) trong trường hợp xấu nhất.  
