#include"head.h"
/***********************************************************************************************
*函数名 ：getwtsum
*函数功能描述 ：得到梯度图的和矩阵
*函数参数 ：m:梯度图的数组头指针；wtsum矩阵头指针
*函数返回值 ：空
*作者 ：Kui Yang
*函数创建日期 ：2017.12.03
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：1.0.0
*历史版本 ：
***********************************************************************************************/
void getwtsum(Mat *m,int *wtsum)
{
	extern int  NUM;
	int COL = m[0].cols;
	int ROW = m[0].rows;
	//cout << COL << " " << ROW << endl;
	for (int i = 0; i < NUM; i++)
	{
		for (int x = 0; x < ROW; x++)
		{
			uchar* px = m[i].ptr<uchar>(x);
			for (int y = 0; y < COL; y++)
			{
				wtsum[x*COL + y] += px[y];
			}
		}
	}
	

}