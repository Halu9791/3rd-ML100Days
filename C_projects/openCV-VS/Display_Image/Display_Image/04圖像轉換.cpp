#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <opencv2\imgproc.hpp> //cvtColor
using namespace std;
using namespace cv;
int main(int argc, char* argv) {
	// ����
	const char* imageName = "E:\\3rd-ML100Days\\C_projects\\openCV-VS\\resource\\dog.jpg";
	
	// Ū������
	Mat image = imread(imageName, 1); // 1 = IMREAD_COLOR

	// ���ɱqRGB��Ƕ�
	Mat gray_image;
	cvtColor(image, gray_image, cv::COLOR_RGB2GRAY);

	// ��ܹ��ɵ����j�p
	namedWindow(imageName, WINDOW_AUTOSIZE);
	namedWindow("Gray image", WINDOW_AUTOSIZE);

	// ��ܭ���ϼ�
	imshow(imageName, image);
	
	// ��ܦǶ��ϼ�
	imshow("Gray image", gray_image);
	
	
	waitKey(0);
	return 0;
}
