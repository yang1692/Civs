#include"head.h"
/***********************************************************************************************
*函数名 ：Fusion
*函数功能描述 ：融合函数
*函数参数 ：src：输入图;des:输出图;weight:权值图；
*函数返回值 ：无
*作者 ：Kui Yang
*函数创建日期 ：2017.12.3
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：1.1.0
*历史版本 ：
***********************************************************************************************/
void Fusion(Mat *src, Mat &des, vector<vector<double>>& weight)
{


	int COL = src[0].cols;
	int ROW = src[0].rows;
	//初始化结果图
	des = Mat(src[0].size(),src[0].type());
	//计算	
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

