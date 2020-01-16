#include"head.h"
/***********************************************************************************************
*������ ��gradient
*������������ �����ͼ���ݶ�ͼ
*�������� ��src������ͼ����des:���ͼ��
*��������ֵ ����
*���� ��Kui Yang
*������������ ��2017.12.2
*�����޸����� ��
*�޸��� ��
*�޸�ԭ�� ��
*�汾 ��1.0.0
*��ʷ�汾 ��
***********************************************************************************************/
void gradient(Mat &src, Mat &des)
{
	Mat dstgreen, dstred, dstblue;
	Mat imggreen, imgred, imgblue;
	Mat output;
	vector <Mat> channels;
	split(src, channels);
	imgblue = channels.at(0);
	imggreen = channels.at(1);
	imgred = channels.at(2);
	graygradient(imgblue, dstblue);
	graygradient(imgred, dstred);
	graygradient(imggreen, dstgreen);
	channels[0] = dstblue;
	channels[1] = dstgreen;
	channels[2] = dstred;
	merge(channels, output);
	des = output;
	//imwrite("�ݶ�ͼdange.jpg", output);
}