# static local variable

Scope:
- Chỉ dùng được trong hàm khai báo.

Lifetime:
- Tồn tại từ lúc chương trình bắt đầu đến lúc kết thúc.

Memory:
- Data/BSS.
- Không nằm trên Stack.
# 📌 Volatile

## Volatile là gì?

`volatile` là từ khóa báo cho compiler rằng:

> **Giá trị của biến có thể thay đổi bất kỳ lúc nào ngoài sự kiểm soát của chương trình.**

=> Compiler **không được phép tối ưu hóa** việc đọc/ghi biến đó.

---

# Tại sao cần volatile?

Thông thường compiler sẽ tối ưu code.

Ví dụ:

```c
while(flag == 0)
{
}
```

Compiler có thể nghĩ:

> "flag không hề bị thay đổi trong chương trình."

Nó sẽ chỉ đọc `flag` một lần rồi giữ giá trị trong thanh ghi (register).

Nếu ISR hoặc phần cứng thay đổi `flag` thì chương trình vẫn không biết.

---

# Ví dụ không dùng volatile

```c
int flag = 0;

while(flag == 0)
{
}
```

ISR

```c
void EXTI_IRQHandler(void)
{
    flag = 1;
}
```

Compiler có thể biến thành

```
Đọc flag một lần

↓

flag = 0

↓

while(1)
{
}
```

=> Chương trình treo.

---

# Dùng volatile

```c
volatile int flag = 0;

while(flag == 0)
{
}
```

Compiler buộc phải

```
Mỗi vòng lặp

↓

Đọc lại flag từ RAM
```

ISR đổi

```
flag = 1
```

↓

Main đọc được ngay.

---

# Khi nào dùng volatile?

## 1. Biến dùng trong Interrupt (ISR)

```c
volatile int button_pressed;
```

ISR

```c
button_pressed = 1;
```

Main

```c
if(button_pressed)
{
    ...
}
```

---

## 2. Thanh ghi phần cứng

Ví dụ

```c
#define GPIOA_IDR (*(volatile uint32_t *)0x48000010)
```

Mỗi lần đọc

```
GPIOA_IDR
```

đều phải đọc từ phần cứng.

---

## 3. Biến dùng giữa nhiều task (RTOS)

Ví dụ

Task A

```c
status = 1;
```

Task B

```c
while(status == 0)
{
}
```

Nếu không có cơ chế đồng bộ phù hợp, `volatile` có thể cần thiết để tránh compiler giữ giá trị cũ. (Trong RTOS thực tế vẫn nên dùng semaphore, mutex hoặc event thay vì chỉ dựa vào `volatile`.)

---

# Volatile KHÔNG làm gì?

❌ Không chống race condition.

❌ Không đồng bộ nhiều thread.

❌ Không thay thế Mutex.

❌ Không thay thế Semaphore.

Nó chỉ ngăn compiler tối ưu hóa việc truy cập biến.

---

# Ghi nhớ

Không có volatile

```
RAM

flag = 1

↓

Compiler

↓

Register

flag = 0
```

Main luôn đọc Register.

---

Có volatile

```
RAM

flag

↑

Main luôn đọc RAM
```

---

# Cách nhớ

volatile

↓

"Biến này có thể thay đổi bất cứ lúc nào."

↓

"Đừng cache."

↓

"Hãy đọc trực tiếp từ RAM."

---

# Ví dụ trong Embedded

✓ GPIO Register

✓ UART Register

✓ ADC Register

✓ Timer Register

✓ Interrupt Flag

✓ DMA Flag

✓ CAN Status

✓ SPI Status

Đây đều là nơi rất hay dùng `volatile`.

---

# Điều mình rút ra

- `volatile` ngăn compiler tối ưu hóa việc đọc/ghi biến.
- Luôn dùng cho biến bị thay đổi bởi ISR hoặc phần cứng.
- Không giải quyết race condition hay đồng bộ đa luồng.
- Trong Embedded, hầu hết các thanh ghi ngoại vi đều được khai báo `volatile`.