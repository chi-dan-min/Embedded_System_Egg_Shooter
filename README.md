# 🎯 Game Bắn Trứng – STM32F429 + TouchGFX

## 📌 Mô tả dự án
Đây là một mini-game bắn trứng được lập trình trên nền tảng **STM32F429 Discovery Kit** kết hợp với **TouchGFX framework**. Người chơi điều khiển hướng súng thông qua joystick (ADC) và bắn trứng về phía lưới. Khi có từ 3 quả trứng cùng màu nằm cạnh nhau, chúng sẽ biến mất. Mục tiêu là ghi điểm càng nhiều càng tốt.

---

## 🛠️ Công nghệ và công cụ sử dụng

- **Vi điều khiển:** STM32F429ZI (ARM Cortex-M4 @ 180MHz)
- **Giao diện đồ họa:** TouchGFX Designer & Framework
- **Ngôn ngữ:** C++
- **Màn hình:** LCD 240x320 tích hợp trên STM32F429 Discovery Kit
- **Ngoại vi sử dụng:**
  - Joystick (kết nối PA0(trục x), PC3(trục y) – đọc qua ADC1)
  - (Tuỳ chọn) Loa ngoài phát âm thanh (DAC hoặc PWM – chưa triển khai)

---

## 📋 Các tính năng đã hoàn thành

- [x] Giao diện menu chọn chế độ chơi
- [x] Điều khiển súng bằng joystick
- [x] Bắn trứng theo hướng súng
- [x] Trứng va chạm và gắn lên lưới hợp lý
- [x] Xóa nhóm trứng cùng màu (>= 3)
- [x] Tính điểm và cập nhật điểm cao
- [x] Xử lý kết thúc game khi trứng chạm đáy
- [x] Giao tiếp giữa các màn hình qua TouchGFX
- [ ] Phát âm thanh khi bắn/xóa trứng *(chưa hoàn thành)*

---

## 📦 Cấu trúc Project (TouchGFX)

```
TouchGFX/
├── gui/
│   ├── include/
│   │   ├── model/        ← Chứa lớp Model và toàn bộ logic game
│   │   ├── presenter/    ← Giao tiếp giữa Model và View
│   │   └── screens/      ← Các màn hình giao diện (View)
│
├── images/               ← Lưu trữ các bitmap hình ảnh (trứng, nền, nút...)
├── simulator/            ← Chạy mô phỏng project trên PC
└── target/               ← Mã và cấu hình build cho phần cứng STM32F429
```


## ✅ Đánh giá tổng thể

Dự án đã hoàn thành đầy đủ các chức năng cốt lõi theo yêu cầu đề ra, bao gồm điều khiển, xử lý logic game, giao diện và điểm số. Tuy còn thiếu tính năng âm thanh và tổ chức mã nguồn chưa tối ưu, nhưng hệ thống hoạt động ổn định, có thể mở rộng trong tương lai.

---

## 🚀 Hướng dẫn chạy project sau khi clone

### 1. **Mở project TouchGFX:**

Vào đường dẫn:

```bash
Embedded_System_Egg_Shooter/EggShooter/TouchGFX/EggShooter.touchgfx
```

→ Mở bằng **TouchGFX Designer** → nhấn **Generate Code**.

---

### 2. **Mở project STM32CubeIDE:**

Mở file:

```bash
Embedded_System_Egg_Shooter/EggShooter/STM32CubeIDE/.project
```

---

### 3. **Cấu hình lại ADC (nếu bị lỗi):**

- Mở file `.ioc` trong CubeMX.
- Tắt chức năng của **ADC IN0** (PA0), sau đó bật lại.
- Nhấn **Project → Generate Code** để cập nhật lại code.

---

### 4. **Build & Run:**

Sau khi code được generate đầy đủ, có thể tiến hành build và flash chương trình xuống board **STM32F429 Discovery** để chạy game.

---

✅ Project sẽ chạy và hiển thị giao diện game bắn trứng như mong đợi.

---

## 📃 Giấy phép

Dự án được thực hiện với mục đích học tập, không sử dụng cho mục đích thương mại.