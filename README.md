"# DAGT" 
##Đề tài:     Quản lý vật tư

##Chức năng: 
+ In danh sách thông tin các vật tư {*}
+ Bổ sung thêm vật tư vào danh sách
+ Tìm kiếm vật tư theo nhiều tiêu chí (tên vật tư, mã vật tư, loại vật tư) 
+ Sắp xếp theo thứ tự tăng dần/giảm dần {*}
+ Chèn vật tư sao cho vẫn được sắp xếp
+ Xóa một vật tư
+ Xóa các vật tư có (số lượng > 100) (thêm)
+ Tính thành tiền (TT) = số lượng * đơn giá * discount (theo quy ước) 
    25% <=> sl > 200
    10% <=> 100 < sl <=200
     0%  <=> sl <= 100
+ In bảng thống kê theo (loại vật tư) gồm: loại vật tư, số lượng, tổng tiền

##Output: 
>> Build: g++ Date.cpp vattu.cpp List.cpp Source.cpp -o run (VS Code)
>> Run: run.exe
