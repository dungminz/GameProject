# Flappy couple
 ^^
- Link youtube demo : https://youtu.be/0F_V6cHfGBI

# Introduction

- Họ và tên : Võ Minh Dũng - K68CA1 - UET

- MSSV : 23021499

# Technologies

Project uses:

- Visual Studio Code (VSCode).
- SDL2
- SDL2_image
- SDL2_ttf
- SDL2_mixer

# How to play
-  Controls :

| Control |  Big Bird | Small Bird | 
|---------|-----------|------------|
| UP      |     ↑     |      w     |
| DOWN    |     ↓     |      s     |
| LEFT    |     ←     |      a     |
| RIGHT   |     →     |      d     | 

- Bạn sẽ điều khiển 2 con chim :
    + Chim bé (main bird) : Chết sẽ game over
    + Chim lớn (support bird) : Bảo vệ chim bé

- Ngoài ra còn có : 
    + Diamond : ăn sẽ được +1 điểm và +5 máu
    + Enemy bird : va chạm sẽ bị -15 máu
    + Rocket : va chạm sẽ bị -50 máu

- Game hiện tại có 2 Wave chính, 1 Wave khó và 1 Ưave bonus
- Mỗi Wave sẽ cho ra các đợt quái, càng về sau sẽ càng nhiều
- Di chuyển chim bé sẽ ăn các viên kim cương để tăng điểm và hồi máu cho chim lớn
- Di chuyển để né hoặc phá huỷ enemy bird và rocket (có mất máu) để bảo vệ chim bé
- Khi chim lớn chết sẽ mất khả năng bảo vệ, được hồi sinh khi Wave hiện tại kết thúc

# Guide
- Mới chơi nên chỉ di chuyển 2 hướng lên và xuống, quen dần mới chuyển sang 4 hướng (Hoặc có thể chơi mỗi chim nhỏ cho dễ di chuyển ~)
- Chim lớn nên di chuyển trước chim bé để dễ dàng lao vào bảo vệ khi cần
- Tên lửa có thể di chuyển hướng đến chim bé, hãy cẩn thận!
- Chim quái tuy chỉ có thể di chuyển một hướng nhưng số lượng sẽ tăng dần theo từng Wave
- Ăn thật nhiều kim cương để tăng điểm số, hãy cận thận sơ sẩy là game over ngay
- Qua Wave cuối sẽ có kim cương bonus, hãy cố gắng sống sót và đạt số điểm cao nhất ^^

# Music
- 0 : pause/resume
- 1-9: change music
- Tự đổi nhạc khi qua màn mới

# Các kĩ thuật sử dụng
- VS code, Thư viện SDL2
- Sử dụng nhiều struct, vector, ...
- Random : quái, background, nhạc, ...
- Tạo các đối tượng khác nhau: smallbird, bigbird, ... 
- Các nhân vật đều có spire riêng
- Tạo ra quái có vị trí, chuyển động, tốc độ khác nhau, tự động biến mất khi chạy qua màn hình
- Lồng nhiều back ground trôi
- Dùng các kiến thức toán học để tính toán được góc nghiêng, hướng di chuyển, ...
- Xử lý thời gian, thao tác chuột và bàn phím, âm thanh, hình ảnh, chữ
- Tạo menu và các nút ấn di chuyển giữa các menu 
- Dùng nhiều yếu tố ngẫu nhiên (rand)
- Dùng thời gian thực, có độ chính xác cao

# Điều tâm đắc
- Game tự viết từ đầu, có sử dụng các đoạn code mẫu của cô
- Game viết có bố cục rõ ràng, dễ debug khi cần
- Các hàm dọn dẹp được sử dụng xuyên suốt quá trình chơi, giúp tối ưu bộ nhớ sử dụng
- Game sử dụng đầy đủ các component cơ bản của SDL: SDL_image, SDL_Mixer, SDL_Font
- Game có cấu trúc đầy đủ: menu, chơi lại game, âm thanh, tính điểm
- Nhạc game có thể thay đổi tuỳ ý (nhấn phím 1-9), hoặc tắt/bật (nhấn phím 0);
- Game có sử sụng các thuật toán ngoài chương trình học:
    + Menu : xây dụng menu riêng cho game, có thể lựa chọn nhân vật chơi
    + Game state : xây dựng các state khác nhau và có thể giải phóng bộ nhớ dễ dàng
    + FPS : tính toán FPS, delay game, sprite dựa trên độ trễ làm game chạy mượt mà
    + Background : các ảnh khác nhau có tốc độ riêng biệt, lồng vào nhau tạo thành 1 background có cảm giác chân thực
    + Toạ độ : tự tạo toạ độ cho từng ảnh nhân vật
    + Vector : lưu các thông số dùng chung một lớp, không cần taọ ra từng lớp riêng lẻ
    + Collision : kiểm tra va chạm giữa các nhân vật khác nhau
    + Angle : tính toán góc nghiêng, góc xoay dựa trên vị trí
    + DrawEx : vẽ nhân vật dựa trên angle
    + Rand : các chỉ số ngẫu nhiên trong khoảng xác định (trong khoảng min và max), như số quái, tốc độ, điểm đặt hình sprite
    + Timing : căn thời gian toàn bộ game, như render delay, sprite delay, lượt xuất hiện quái địch

# Hướng phát triển
- Cập nhật tính năng lưu điểm, tạo ra được một danh sách và có thể lưu tên
- Thêm nhiều loại đồ ăn khác nhau
- Thêm đạn cho chim lớn (đã có spire sẵn trong game)
- Thêm chức năng biến hình (bất tử) trong khoảng thời gian cho chim lớn (đã có sẵn spire trong game)
- Mở rộng thêm các Wave
- Hiện tại dùng vector là đủ, có thể cân nhắc dùng linked list sau này

# Source image

- https://bevouliin.com/game-character-flappy-easter-egg-bird-sprite-sheets/
- https://bevouliin.com/game-assets-sky-birds-sprite-sheets/

# Timing

- http://thenumb.at/cpp-course/sdl2/08/08.html#perf

# Mức điểm tự đánh giá 9+/10