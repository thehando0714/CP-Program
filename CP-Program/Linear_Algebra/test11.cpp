#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::cout << "Check 1: Program Started" << std::endl;
    // 讀取圖片 (請確保圖片在執行檔旁邊)
    cv::Mat img = cv::imread("test.jpg");

    // 檢查圖片是否讀取成功
    if (img.empty()) {
        std::cout << "找不到圖片！請確認 test.jpg 是否在正確路徑。" << std::endl;
        return -1;
    }

    // 建立一個視窗並顯示圖片
    cv::imshow("OpenCV Test Window", img);

    std::cout << "圖片顯示成功！按下任意鍵關閉視窗..." << std::endl;

    // 等待按鍵，否則視窗會閃退
    cv::waitKey(0);

    return 0;
}