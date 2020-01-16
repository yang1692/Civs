#include"head.h"
/***********************************************************************************************
*������ ��getweight
*������������ ����Ȩֵ����
*�������� ��Gau������ͼ������ָ�룻wtsum:Ȩֵ�ͣ�weight:Ȩֵ����
*��������ֵ ����
*���� ��Kui Yang
*������������ ��2017.12.2
*�����޸����� ��
*�޸��� ��
*�޸�ԭ�� ��
*�汾 ��1.0.0
*��ʷ�汾 ��
***********************************************************************************************/
int const e = pow(10, -5);
void getweight(Mat *Gau, int * wtsum, Mat *weight)
{
	for (int i = 0; i < NUM; i++)
	{
		for (int x = 0; x < ROW; x++)
		{
			uchar* px = Gau[i].ptr<uchar>(x);
			double* pwt = weight[i].ptr<double>(x);
			for (int y = 0; y < COL; y++)
			{
				pwt[y]= (double)px[y] /((double)( wtsum[x*COL + y])+e);
			}
		}
	}
}