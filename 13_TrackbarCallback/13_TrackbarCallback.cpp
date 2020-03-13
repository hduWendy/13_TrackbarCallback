// 13_TrackbarCallback.cpp : �������̨Ӧ�ó������ڵ�.
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

String window_name = "binaryMat";
void theshold_Mat(int th, void* data)
{
	Mat src = *(Mat*)(data);
	Mat dst;
	//��ֵ��
	threshold(src, dst, th, 255, 0);
	imshow(window_name, dst);
}

int main()
{
	Mat srcMat;
	Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;

	srcMat = imread("C:/Users/lenovo/Desktop/����/1.jpg");
	if (!srcMat.data)
	{
		cout << "ͼ������ʧ��" << endl;
		return 0;
	}
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);

	imshow(window_name, gryMat);
	createTrackbar("threshold",
		window_name,
		&lowTh,
		maxTh,
		theshold_Mat,
		&gryMat);

	//�ȴ��û�����
	waitKey(0);
	return 0;
}
