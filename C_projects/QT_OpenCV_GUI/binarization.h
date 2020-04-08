#pragma once
// �ϥ�OpenCV�����Ϥ��e�B�z

#ifndef  BINARIZATION_H
#define BINARIZATION_H

#include <QtWidgets/QMainWindow>
#include "image_processing_qmain.h"
#include "ui_binarization.h"

#include <qdialog.h>
// �ΨӨϹϤ��٭�
#include "image.h"

#include <map>
#include <qcombobox.h>
#include <qpushbutton.h>
// OpenCV�w
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
namespace Ui {
	class binarizationClass;
}

//�ŧi�G�Ȥ� ��Dialog�l�����\��
class binarization : public QDialog
{
	Q_OBJECT
public:
	explicit binarization(QWidget *parent = 0);
	~binarization();
private:
	Ui::binarizationClass *ui;
	QComboBox *comboBox;
	QLineEdit *lineEdit;
	QLineEdit *lineEdit_2;
	QPushButton *pushButton;
	QPushButton *pushBotton_2;
	QPushButton *pushBotton_3;
	QLabel *label;

private slots:
	void on_lowThresh_clicked();
	void on_highThresh_clicked();
	void on_comboBox_clicked();
	Mat on_enter_clicked();
	void on_restore_clicked();
	void on_send_clicked();
	int receiveData_int(QString);
	int receiveData_bin_type(QString);
signals:
	void sendData(QString);//�ΨӶǻ�QString�ƾ�
	void sendData(string);
	//void sendData(QLabel); //�ΨӶǻ�QImage�ƾ�
};

#endif //BINARIZATION_H
