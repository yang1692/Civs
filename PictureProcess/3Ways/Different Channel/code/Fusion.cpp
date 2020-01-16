#include"head.h"
/***********************************************************************************************
*������ ��Fusion
*������������ ���ںϺ���
*�������� ��src������ͼ;des:���ͼ;weight:Ȩֵͼ��
*��������ֵ ����
*���� ��Kui Yang
*������������ ��2017.12.3
*�����޸����� ��
*�޸��� ��
*�޸�ԭ�� ��
*�汾 ��1.1.0
*��ʷ�汾 ��
***********************************************************************************************/
void Fusion(Mat *src, Mat &des, vector<vector<double>>& weight)
{


	int COL = src[0].cols;
	int ROW = src[0].rows;
	//��ʼ�����ͼ
	des = Mat(src[0].size(),src[0].type());
	//����	
	for (int x = 0; x < ROW; x++)
	{
		for (int y = 0; y < COL; y++)
		{

			double sumxy = 0;
			for (int i = 0; i < NUM; i++)
			{
				sumxy += src[i].at<uchar>(x, y) * weight[i][x*COL + y];			
			}
			if (sumxy > 255)des.at<uchar>(x, y) = 255;
			else des.at<uchar>(x,y) = sumxy;
	
		}
	}
}

