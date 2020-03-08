#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, const char** argv) {
    argv[1] = "E:\\3rd-ML100Days\\C_projects\\openCV\\resource\\dog.jpg";
    //Mat�OopenCV�s�q����ƫ��A�A�N���ǲΪ���ƫ��Aint�Bfloat�BString�CMat�N��Ϲ��A�ӹϹ����O�G���}�C�A�ҥHOpenCV�w�q�B�z�Ϲ����x�}���O(Matrix)
    Mat image;

    //���J����
    image = imread(argv[1], IMREAD_COLOR);

    //�ˬdŪ�ɬO�_���\
    if (!image.data) {
        cout << "�L�k�}�ҩΧ䤣�����" << std::endl;
        return -1;
    }

    //�إ���ܹ��ɵ���
    namedWindow("Display window", WINDOW_NORMAL);

    // CV_WINDOW_FREERATIO �P CV_WINDOW_KEEPRATIO
    // CV_GUI_NORMAL �P CV_GUI_EXPANDED

    // ��������ܹ���
    imshow("Display window", image);

    //�������ݫ���
    waitKey(0);

    return 0;
}