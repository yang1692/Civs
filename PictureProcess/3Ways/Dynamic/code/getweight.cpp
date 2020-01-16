#include"head.h"
/***********************************************************************************************
*函数名 ：getweight
*函数功能描述 ：求权值矩阵
*函数参数 ：Gau：输入图的数组指针；wtsum:权值和；weight:权值矩阵；
*函数返回值 ：无
*作者 ：Kui Yang
*函数创建日期 ：2017.12.2
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：1.0.0
*历史版本 ：
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