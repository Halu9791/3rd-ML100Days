#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2\imgproc.hpp>  //FONT_HERSHEY_SCRIPT_SIMPLEX

using namespace std;
using namespace cv;

int main(void) {
	string text = "Funny text inside the box";
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
	double fontScale = 2;
	int thickness = 3;

	Mat img(300, 900, CV_8UC3, Scalar::all(0));

	int baseline;
	// �]�t���w�奻�ت��j�p
	Size textSize = getTextSize(text, fontFace, fontScale, thickness, &baseline);

	baseline += thickness;

	// center the text
	Point textOrg((img.cols - textSize.width) / 2,
		(img.rows + textSize.height) / 2);

	// draw the box �e�貰�l
	rectangle(img, textOrg + Point(0, baseline),
		textOrg + Point(textSize.width, -textSize.height),
		Scalar(0, 0, 255));
	// ... and the baseline first �b�Ϥ��e��r���u
	line(img, textOrg + Point(0, thickness),
		textOrg + Point(textSize.width, thickness),
		Scalar(0, 0, 255));

	// then put the text itself  �b�Ϥ���W��r
	putText(img, text, textOrg, fontFace, fontScale,
		Scalar::all(255), thickness, 8);

	imshow("getText", img);
	waitKey();


}