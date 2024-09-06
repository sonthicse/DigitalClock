#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

class DigitalClock {
private:
    // Thuộc tính lưu trữ giờ, phút và giây
    int hours;
    int minutes;
    int seconds;

    // Phương thức cập nhật thời gian từ hệ thống
    void updateTime();

public:
    // Constructor khởi tạo đồng hồ với giá trị giờ, phút, giây ban đầu
    DigitalClock(int h = 0, int m = 0, int s = 0);

    // Phương thức hiển thị thời gian hiện tại trên console
    void displayTime() const;

    // Phương thức chạy đồng hồ, hiển thị thời gian theo thời gian thực
    void run();
};

#include "../src/DigitalClock.cpp"

#endif // DIGITALCLOCK_H
