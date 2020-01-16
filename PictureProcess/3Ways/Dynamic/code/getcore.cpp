#include"head.h"
/***********************************************************************************************
*函数名 ：getCore
*函数功能描述 ：得到core矩阵
*函数参数 ：src：输入图;score:score矩阵；core:core矩阵
*函数返回值 ：无
*作者 ：Kui Yang
*函数创建日期 ：2017.12.8
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：1.1.0
*历史版本 ：
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
			//求（x,y）点的分母sum
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
			//求（x，y）点的core
			for (int i = 0; i < NUM; i++)
			{
				core[i][x*COL + y] = (alph[i]*score[i][x*COL + y]+0.000001) / (sum + epsilon);
			}
		}
	}
}