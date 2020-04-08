#pragma once
#ifndef SMOOTHING_H
#define SMOOTHING_H
#include "ui_smoothing.h"
#include <qdialog.h>
// �ΨӨϹϤ��٭�
#include "image.h"
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qslider.h>

#include<string>

// OpenCV�w
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
namespace Ui {
	class smoothingClass;
}

//�ŧi���Ƥ� ��Dialog�����\��
class smoothing : public QDialog
{
	Q_OBJECT
public:
	explicit smoothing(QWidget *parent = 0);
	~smoothing();
private:
	Ui::smoothingClass *ui;
	// GaussianBlur( )   pushButton���Ϋŧi ����emit��X��ƧY�ior XXX->show();�I�s�l����
	QLabel *label;
	QLabel *label_2;
	QLabel *label_3;
	QLabel *label_4;
	QLineEdit *lineEdit;
	QSlider *horizontalSlider;
	QSlider *horizontalSlider_2;
	QSlider *horizontalSlider_3;
	QSpinBox *spinBox;
	QSpinBox *spinBox_2;
	QSpinBox *spinBlox_3;
	// medianBlur( )
	QLabel *label_5;
	QSlider *horizontalSlider_4;
	QSpinBox *spinBox_4;
	// averageBlur( )
	QLabel *label_8;
	QLabel *label_9;
	QLabel *label_10;
	QLabel *label_11;
	QSlider *horizontalSlider_5;
	QSpinBox *spinBox_5;
	QLineEdit *lineEdit_2;
	QLineEdit *lineEdit_3;
	QLineEdit *lineEdit_4;
private slots:
	// �q��
	void on_restore_clicked();
	int receiveData_int(int);
	double receiveData_double(int);
	int receiveData_QString2int(QString);
	string receiveData_Qstring2string(QString);
	// GaussianBlur( )
	void on_gaussian_ksize_clicked();
	void on_sigmaX_clicked();
	void on_sigmaY_clicked();
	void on_borderType_clicked();
	Mat on_gaussianEnter_clicked();
	void on_gaussianSend_clicked();
	// medianBlur( )
	Mat on_medianEnter_clicked();
	void on_medianSend_clicked();
	//averageBlur( )
	Mat on_averageEnter_clicked();
	void on_averageSend_clicked();
signals:
	void sendData(QString);//�ǰelineEdit�������
	void sendData(int);
	void sendData(double);
	void sendData(string);//�ǰe�ѼƳ]�w���G
};
#endif // SMOOTHING_H
