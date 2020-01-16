#include"head.h"
/***********************************************************************************************
*������ ��graygradient
*������������ ����Ҷ�ͼ���ݶ�ͼ
*�������� ��src������ͼ��mag:���ͼ
*��������ֵ ����
*���� ��Kui Yang
*������������ ��2017.12.1
*�����޸����� ��
*�޸��� ��
*�޸�ԭ�� ��
*�汾 ��1.0.0
*��ʷ�汾 ��
***********************************************************************************************/
void graygradient(Mat &src, Mat &mag)
{
	Mat temp;
	copyMakeBorder(src, temp, 1, 1, 1, 1, BORDER_REPLICATE);
	const int H = src.rows, W = src.cols*src.channels();
	//�ݶ�ֵ��0��ֵ��ܴ���Ϊ����
	Mat Ix(H, W, CV_32S), Iy(H, W, CV_32S);

	// ���ݶ�
	for (int x = 1; x < H + 1; x++)
	{
		for (int y = 1; y < W + 1; y++)
		{
			Ix.at<int>(x - 1, y - 1) = abs(coe[0] * temp.at<byte>(x, y + 1) + coe[1] *temp.at<byte>(x + 1, y + 1) + coe[2]*temp.at<byte>(x - 1, y + 1)
										- (coe[0] * temp.at<byte>(x, y - 1) + coe[1] *temp.at<byte>(x + 1, y - 1) + coe[2] *temp.at<byte>(x - 1, y - 1)));
			Iy.at<int>(x - 1, y - 1) = abs(coe[0] * temp.at<byte>(x + 1, y) + coe[1] *temp.at<byte>(x + 1, y + 1) + coe[2] *temp.at<byte>(x + 1, y - 1)
										- (coe[0] * temp.at<byte>(x - 1, y) + coe[1] *temp.at<byte>(x - 1, y + 1) + coe[2] *temp.at<byte>(x - 1, y - 1)));
		}

	}
	convertScaleAbs(min(0.5*Ix + 0.5*Iy, 255), mag); //����Խ��
}