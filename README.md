TestCreator

Hướng dẫn sử dụng TestCreator

Định dạng test trong đó xyz là tên bài làm:
xyz / test_xx / xyz.in , xyz.out
 
Với mục đích tạo ra format test tương tác tốt với themis và CooJudge, mình tạo TestCreator giúp giải quyết việc này đơn giản hơn và lớn nhất là chạy được trên linux.

Thư mục bao gồm:
- File GenInput.cpp và Solution.cpp để sinh Input và Output cho bài toán.
- File TestFormat.cpp để tùy chỉnh thiết lập mặc định và sinh ra bộ test.

Hướng dẫn sử dụng:
- Tạo thư mục để lưu tất cả các file trên, gọi là abc.
- Trong abc, cài đặt file GenInput.cpp và Solution.cpp.
	File GenInput sinh input ra file input.txt
	File Solution đọc input từ input.txt và sinh output ra file answer.txt
- Compile lại file TestFormat.cpp (khuyên khích thông qua terminal):
	cd đến mục abc -> Compile -> "./TestFormat".
	Chương trình sẽ yêu cầu tên bài và số lượng test muốn tạo theo thứ tự tương ứng mình nhập vào.

Một số lưu ý khi sử dụng:
- Mặc định mình để định dạng test là "xyz.in" và "xyz.out", nếu muốn thay đổi, ta chỉ cần thay (string) inp và (string) out ở đầu file TestFormat thành đuôi khác tương ứng.
- Nếu những folder đã có sẵn mình sẽ chỉ bỏ qua không tác động đến.
- Folder test sẽ sinh ra ở ngay trong folder abc ở trên luôn.
- Nếu bạn không thích việc phải compile lại file TestFormat thì thay đổi biến delRunFile trong TestFormat thành false.

Ví dụ về việc chạy chương trình:

Ở đây mình giả dụ sinh test cho bài toán LIS quen thuộc

Minh họa: https://imgur.com/a/7FzBsrB

