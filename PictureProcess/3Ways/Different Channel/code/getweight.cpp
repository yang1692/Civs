#include"head.h"
/***********************************************************************************************
*函数名 ：getweight
*函数功能描述 ：得到梯度图的权值矩阵
*函数参数 ：Gau:原图数组的头指针；wtsum：和矩阵；weight返回的权值向量
*函数返回值 ：空
*作者 ：Kui Yang
*函数创建日期 ：2017.12.03
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：1.0.0
*历史版本 ：
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