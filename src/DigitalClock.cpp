#include "../include/DigitalClock.h"

// Constructor: Khởi tạo đồng hồ với giờ, phút, giây ban đầu
DigitalClock::DigitalClock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    // Nếu các giá trị khởi tạo vượt quá phạm vi, đặt lại chúng về giá trị hợp lệ
    if (hours < 0 || hours >= 24) hours = 0;
    if (minutes < 0 || minutes >= 60) minutes = 0;
    if (seconds < 0 || seconds >= 60) seconds = 0;
}

// Phương thức cập nhật thời gian từ hệ thống
void DigitalClock::updateTime() {
    // Lấy thời gian hiện tại từ hệ thống
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto localTime = *std::localtime(&time);

    // Cập nhật giờ, phút, giây từ thời gian hệ thống
    hours = localTime.tm_hour;
    minutes = localTime.tm_min;
    seconds = localTime.tm_sec;
}

// Phương thức hiển thị thời gian hiện tại trên console
void DigitalClock::displayTime() const {
    // Sử dụng `setw` và `setfill` để định dạng đầu ra
    std::cout << std::setw(2) << std::setfill('0') << hours << ":"
              << std::setw(2) << std::setfill('0') << minutes << ":"
              << std::setw(2) << std::setfill('0') << seconds << std::endl;
}

// Phương thức chạy đồng hồ, hiển thị thời gian theo thời gian thực
void DigitalClock::run() {
    while (true) {
        // Xóa màn hình
        system("cls");
        
        // Cập nhật thời gian
        updateTime();
        
        // Hiển thị thời gian hiện tại
        displayTime();
        
        // Delay 1 giây
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
