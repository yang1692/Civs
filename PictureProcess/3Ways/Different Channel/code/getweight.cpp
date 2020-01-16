#include"head.h"
/***********************************************************************************************
*������ ��getweight
*������������ ���õ��ݶ�ͼ��Ȩֵ����
*�������� ��Gau:ԭͼ�����ͷָ�룻wtsum���;���weight���ص�Ȩֵ����
*��������ֵ ����
*���� ��Kui Yang
*������������ ��2017.12.03
*�����޸����� ��
*�޸��� ��
*�޸�ԭ�� ��
*�汾 ��1.0.0
*��ʷ�汾 ��
***********************************************************************************************/
void getweight(Mat *Gau, int * wtsum, vector<vector<double>> &weight)
{

	int COL = Gau[0].cols;
	int ROW = Gau[0].rows;
	//cout << COL << " " << ROW << endl;
	for (int i = 0; i < NUM; i++)
	{
		for (int x = 0; x < ROW; x++)
		{
			uchar* px = Gau[i].ptr<uchar>(x);
			for (int y = 0; y < COL; y++)
			{
				weight[i][x*COL + y] = (double)px[y] /((double)( wtsum[x*COL + y])+e);
			}
		}
	}
	//cout << weight[0][100*COL+200] << endl;
	//cout << (int)m[2].at<uchar>(100, 200) << endl;
	
}