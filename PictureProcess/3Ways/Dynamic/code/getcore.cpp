#include"head.h"
/***********************************************************************************************
*������ ��getCore
*������������ ���õ�core����
*�������� ��src������ͼ;score:score����core:core����
*��������ֵ ����
*���� ��Kui Yang
*������������ ��2017.12.8
*�����޸����� ��
*�޸��� ��
*�޸�ԭ�� ��
*�汾 ��1.1.0
*��ʷ�汾 ��
***********************************************************************************************/
double const epsilon = pow(10, -5);
void getCore(Mat *src,vector<vector<double>> &score, vector<vector<double>> &core)
{
	double taumax = 1 * 255;
	double taumin = 0 * 255;
	int *alph=new int[NUM];
	double sum = 0;
	for (int x = 0; x < ROW; x++)
	{
		for (int y = 0; y < COL; y++)
		{
			//��x,y����ķ�ĸsum
			sum = 0;
			for (int i = 0; i < NUM; i++)
			{
				alph[i] = 1;
				if (src[i].at<uchar>(x, y)< taumin|| src[i].at<uchar>(x, y) > taumax)
				{
					alph[i] = 0;
				}
				sum += alph[i]*score[i][x*COL + y];
			}
			//��x��y�����core
			for (int i = 0; i < NUM; i++)
			{
				core[i][x*COL + y] = (alph[i]*score[i][x*COL + y]+0.000001) / (sum + epsilon);
			}
		}
	}
}