#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char** argv) {
	//�{���Ұʮɷ|������J
	argv[1] = "E:\\3rd-ML100Days\\C_projects\\openCV-VS\\resource\\dog.jpg";

	Mat image;

	// ��J����
	image = imread(argv[1], IMREAD_COLOR);

	// �ˬdŪ�ɬO�_���\
	if (!image.data) {
		cout << "�L�k�}�ҩΧ䤣�����" << endl;
		return -1;
	}

	// �إ���ܹ��ɵ���
	namedWindow("���", WINDOW_NORMAL);
	namedWindow("�U����", WINDOW_NORMAL);

	imshow("���", image);

	// ���I��
	int i = 600;
	for (int k = 0; k < i; k++) {
		// rand() is the MFC random number generator
		// try qrand() with Qt
		int i = rand() % image.cols;
		int j = rand() % image.rows;
		if (image.channels() == 1) {// gray-level image
			image.at<uchar>(j, i) = 255;
			if (i < (int)image.cols)
				image.at<uchar>(j + 1, i) = 255;
			if (j < (int)image.rows)
				image.at<uchar>(j, i + 1) = 255;
			if ((i < (int)image.cols) && j < (int)image.rows)
				image.at<uchar>(j + 1, i + 1) = 255;
		}
		else if (image.channels() == 3) {// color image
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;
			if (i < (int)image.cols - 1) {
				image.at<cv::Vec3b>(j, i + 1)[0] = 255;
				image.at<cv::Vec3b>(j, i + 1)[1] = 255;
				image.at<cv::Vec3b>(j, i + 1)[2] = 255;
			}
			if (j < (int)image.rows - 1) {
				image.at<cv::Vec3b>(j + 1, i)[0] = 255;
				image.at<cv::Vec3b>(j + 1, i)[1] = 255;
				image.at<cv::Vec3b>(j + 0, i)[2] = 255;
			}
			if ((i < (int)image.cols - 1) && (j < (int)image.rows - 1)) {
				image.at<cv::Vec3b>(j + 1, i + 1)[0] = 255;
				image.at<cv::Vec3b>(j + 1, i + 1)[1] = 255;
				image.at<cv::Vec3b>(j + 0, i + 1)[2] = 255;
			}
		}
	}
	//�b��������ܹ���
	imshow("�U����", image);

	//�������ݫ���
	waitKey(0);
	return 0;
}