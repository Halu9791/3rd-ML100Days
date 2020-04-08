// .h���Y�� �ŧiclass�B�禡
#pragma once

//����h��include
#ifndef IMAGE_PROCESSING_QMAIN_H
#define IMAGE_PROCESSING_QMAIN_H

#include "image.h" // Mat image�����ܼ�

#include <QtWidgets/QMainWindow>
#include "ui_image_processing_qmain.h"
#include "binarization.h"//�G�Ȥ�
#include "smoothing.h"//���Ƥ�
//Qt Graphics View�[�c: QGraphicsScene�BQGraphicsView�BQGraphicsItem
//Scene(����) View(��ܰϰ�) Item(������������)
//https://kheresy.wordpress.com/2011/07/11/qt-graphics-view-framework-%E7%B0%A1%E4%BB%8B/
#include <QGraphicsScene> //QGraphicsScene�OQGraphicsView��������
#include <QGraphicsView>  
#include <qfiledialog.h>
#include <qlabel.h>
#include <qtextbrowser.h>

//OpenCV
#include <opencv2\imgproc\imgproc.hpp> //�e�B�z
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp> //gui
using namespace cv;
using namespace std;

namespace Ui {
	class image_processing_qmainClass;
}

class image_processing_qmain : public QMainWindow  //���M���~��QMainWindow
{
	Q_OBJECT

public:
	explicit image_processing_qmain(QWidget *parent = 0);
	~image_processing_qmain(); //�Ѻc�l
	QDialog *binarization_dialog;
	QDialog *smoothing_dialog;
//�K�[�Ѩ��  ���s����
private slots:
	//���榡on_����W_clicked�R�W��ơAQT�|�q�{������ƩM���s�ʧ@���s��
	//�A�p�G���o�˩R�W���ܴN�h�]�m �H���Ѩ��
	// Basic
	void on_OpenFig_clicked();
	void on_refresh_clicked();
	//binarazation
	void on_Barization_clicked();
	void receiveData(string data); //����string��ƪ���
	//smoothing
	void on_somoothing_clicked();

//
private:
	Ui::image_processing_qmainClass *ui;
	Mat image;
	QLabel *label;
	QLabel *label_2;
	QPushButton *pushButton;
	QPushButton *pushButton_2;
	QPushButton *pushButton_3;
	QTextBrowser *textBrowser;
};
#endif  //IMAGE_PROCESSING_QMAIN_H

/*
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_image_processing_qmain.h"

class image_processing_qmain : public QMainWindow
{
	Q_OBJECT

public:
	image_processing_qmain(QWidget *parent = Q_NULLPTR);

private:
	Ui::image_processing_qmainClass ui;
};
*/
