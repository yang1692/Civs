#include"head.h"
/***********************************************************************************************
*������ ��Gaussfunc
*������������ ����ά��˹����
*�������� ��xΪ����㵽���ĵ�����ƽ��
*��������ֵ ������ֵ
*���� ��Kui Yang
*������������ ��2017.12.01
*�����޸����� ��
*�޸��� ��
*�޸�ԭ�� ��
*�汾 ��1.0.0
*��ʷ�汾 ��
***********************************************************************************************/
float Gaussfunc(float x)
{
	float res;
	res = exp(-x / (2 * SIGMA2)) / (2 * PI*SIGMA2);
	return res;
}
/***********************************************************************************************
*������ ��Gaussian_blur
*������������ ����˹ģ��
*�������� ��input������ͼ����x:�˲�����ȣ�����Ϊ��������y:�˲����߶ȣ�����Ϊ��������
*��������ֵ �������ͼ��
*���� ��Kui Yang
*������������ ��2017.11.30
*�����޸����� ��
*�޸��� ��
*�޸�ԭ�� ��
*�汾 ��1.0.0
*��ʷ�汾 ��
***********************************************************************************************/
Mat Gaussian_blur(Mat const&input, int x, int y)
{
	//��ʼ����������
	Mat output;
	float **coe = new float*[x];
	for (int i = 0; i < x; i++)
	{
		coe[i] = new float[y];
	}

	//�����������
	int centerx = x / 2;
	int centery = y / 2;
	float sum = 0;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			float distence = pow(i - centerx, 2) + pow(j - centery, 2);
			coe[i][j] = Gaussfunc(distence);
			sum += coe[i][j];
		}
	}
	//cout << coe[25][25] << endl;
	//Ȩֵ�͹�һ
	Mat kernel = Mat::zeros(x, y, CV_32FC1);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			//coe[i][j] /= sum;
			kernel.at<float>(i, j) = coe[i][j];
		}
	}
	//cout << coe[25][25] << endl;
	//cout << kernel.at<float>(25, 25);
	//ͼ��ת��
	filter2D(input, output, -1, kernel);

	return output;
}