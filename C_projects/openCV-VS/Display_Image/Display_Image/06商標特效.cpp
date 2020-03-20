#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> //image processing
#include <vector>

using namespace std;
using namespace cv;

int main() {
	//���J�ɮ�
	Mat image1 = imread("E:\\opencv_sample\\images\\lena.jpg");
	Mat logo = imread("E:\\opencv_sample\\images\\opencv-logo.png");

	//�sĶ���n�D�ϥΫe������l��
	Mat image = image1, opencvlogo;

	//�Y�p��Ϧ�Size(col, row)
	resize(logo, opencvlogo, Size(80, 64));

	namedWindow("Image 1", WINDOW_AUTOSIZE);

	//�w�q�Ϧ����h���ϰ�(Region Of Interest, ROI)
	Mat imageROI;

	//���w�ӼЦb��Ϫ���m�ARect(x, y, width(col), height(row))
	imageROI = image(Rect(420, 420, 80, 64));

	imshow("Image 1", opencvlogo);

	//�[�J�Ӽ�
	addWeighted(imageROI, 1.0, opencvlogo, 0.3, 0.0, imageROI);

	//��ܵ��G
	namedWindow("with logo");
	imshow("with logo", image);

	waitKey();
	return 0;

}