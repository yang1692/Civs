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
	//用于分解原图的容器
	vector <Mat> *src_channels=new vector <Mat>[NUM];

	Mat **src_RGB=new Mat*[NUM];

	//将原图分为三个通道
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

	//初始化结果图
	Mat result[3] =
	   { Mat(src_RGB[0][0].size(),src_RGB[0][0].type())
		,Mat(src_RGB[0][0].size(),src_RGB[0][0].type())
		,Mat(src_RGB[0][0].size(),src_RGB[0][0].type()) };

	//计算
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

