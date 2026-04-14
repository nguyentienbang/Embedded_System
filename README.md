1/ Biên dịch thư viện tĩnh (.a)
a/Compile object file
    gcc -c hashtable.c
b/ Tạo thư viện
    ar rcs libhash.a hashtable.o
c/Link với main
    gcc main.c -L. -lhash -o main
👉 -L.: tìm thư viện ở folder hiện tại
👉 -lhash: libhash.a
d/Chạy:
   ./main

2/ Thư viện động (.so)
a/Build:
    gcc -fPIC -c hashtable.c
    gcc -shared -o libhash.so hashtable.o
b/Link:
    gcc main.c -L. -lhash -o main
c/Chạy (Linux):
    export LD_LIBRARY_PATH=.
    ./main

3/So sánh thư viện tĩnh vs động
	             Static (.a)	           Dynamic (.so)
Link	         lúc compile	           lúc runtime
Kích thước	       lớn	                   nhỏ
Cập nhật     	phải build lại	         không cần
Tốc độ	        nhanh hơn	             hơi chậm hơn
