#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

double alpha; // ��񱱨�
int beta;	  // �G�ױ���

int main(int argc, char** argv) {
	Mat image = imread("E:\\opencv_sample\\images\\lena.jpg");

	//���F���v�T��ϩҥH�إߤ@�Ӥj�p�P��ϬۦP���x�}�A���e��0�C
	// �إߨê�l�Ƥ@�ӷs�x�}�A�s�x�}�B��Ƶ��c�Mimage�@�ˡC
	Mat new_image;
	new_image = Mat::zeros(image.size(), image.type());

	// Initialize values (Basic Linear Transform)
	cout << "�򥻽u���ഫ" << endl;
	cout << "------------" << endl;
	cout << "* ��Jalpha��[1.0 - 3.0]: "; cin >> alpha;
	cout << "* ��J beta��[  0 - 100]: "; cin >> beta;

	// �ഫ���� new_image(i,j) = alpha*image(i,j) + beta
	// �H�U�������� cv::Mat::convertTo(OutputArray, int, alpha, beta)
	//https://blog.csdn.net/iracer/article/details/49204147
	//markers.convertTo(tmp,CV_8U,255,255); 
	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				// �w�ﹳ�����C�Ӧ��W���ഫ
				new_image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * (image.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}

	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	imshow("Original Image", image);
	imshow("New Image", new_image);

	waitKey();
	return 0;
}