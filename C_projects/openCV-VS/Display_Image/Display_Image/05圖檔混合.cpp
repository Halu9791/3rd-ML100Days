#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main(void) {
	double alpha = 1, beta, input;
	Mat src1, src2, dst;

	// ���ϥΪ̿�Jalpha��
	cout << "²���u���ͦX(Linear Blender)" << endl;
	cout << "-----------------" << endl;
	cout << "* ��J 0 �� 1 ��alpha�� : ";
	cin >> input;

	//�T�{alpha�ȩ�0~1����
	if (alpha >= 0 && alpha <= 1) //alpha�b�i�J�ϰ��ܼƫe�n����l��
		alpha = input;

	// Ū����Ӥj�p�P�����ۦP������
	src1 = imread("E:\\opencv_sample\\images\\LinuxLogo.jpg");
	src2 = imread("E:\\opencv_sample\\images\\WindowsLogo.jpg");
	
	if (!src1.data) {
		cout << "Ū��src1���~" << endl; return -1;
	};
	if (!src2.data) {
		cout << "Ū��src1���~" << endl; return -1;
	};

	namedWindow("Linear Blend", 1);

	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);

	imshow("Linear Blend", dst);

	waitKey(0);
	return 0;
}