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
	//���ڷֽ�ԭͼ������
	vector <Mat> *src_channels=new vector <Mat>[NUM];

	Mat **src_RGB=new Mat*[NUM];

	//��ԭͼ��Ϊ����ͨ��
	for (int i = 0; i < NUM; i++)
	{
		src_RGB[i] = new Mat[3];
		split(src[i], src_channels[i]);
		for (int j = 0; j < 3; j++)
		{
			src_RGB[i][j] = src_channels[i].at(j);
		}
	}

	int COL = src_RGB[0][0].cols;
	int ROW = src_RGB[0][0].rows;

	//��ʼ�����ͼ
	Mat result[3] =
	   { Mat(src_RGB[0][0].size(),src_RGB[0][0].type())
		,Mat(src_RGB[0][0].size(),src_RGB[0][0].type())
		,Mat(src_RGB[0][0].size(),src_RGB[0][0].type()) };

	//����
	for (int RGB = 0; RGB < 3; RGB++)
	{
			
		for (int x = 0; x < ROW; x++)
		{
			for (int y = 0; y < COL; y++)
			{
				double sumxy = 0;
				for (int i = 0; i < NUM; i++)
				{
					sumxy += src_RGB[i][RGB].at<uchar>(x, y) * weight[i][x*COL + y];			
				}

				if (sumxy > 255)result[RGB].at<uchar>(x, y) = 255;
				else result[RGB].at<uchar>(x,y) = sumxy;

			}

		}
	}

	for (int i = 0; i < 3; i++)
	{
		src_channels[0][i] = result[i];
	}

	merge(src_channels[0], des);
	for (int i = 0; i<NUM; i++)
	{
		delete[]src_RGB[i];
	}
	delete[]src_RGB;
}

