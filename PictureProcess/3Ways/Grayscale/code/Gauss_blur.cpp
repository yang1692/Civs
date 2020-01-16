#include"head.h"
/***********************************************************************************************
*函数名 ：Gaussfunc
*函数功能描述 ：二维高斯函数
*函数参数 ：x为计算点到中心点距离的平方
*函数返回值 ：函数值
*作者 ：Kui Yang
*函数创建日期 ：2017.12.01
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：1.0.0
*历史版本 ：
***********************************************************************************************/
float Gaussfunc(float x)
{
	float res;
	res = exp(-x / (2 * SIGMA2)) / (2 * PI*SIGMA2);
	return res;
}
/***********************************************************************************************
*函数名 ：Gaussian_blur
*函数功能描述 ：高斯模糊
*函数参数 ：input：输入图；，x:滤波器宽度，必须为正奇数；y:滤波器高度，必须为正奇数；
*函数返回值 ：处理后图像
*作者 ：Kui Yang
*函数创建日期 ：2017.11.30
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：1.0.0
*历史版本 ：
***********************************************************************************************/
Mat Gaussian_blur(Mat const&input, int x, int y)
{
	//初始化参数矩阵
	Mat output;
	float **coe = new float*[x];
	for (int i = 0; i < x; i++)
	{
		coe[i] = new float[y];
	}

	//计算参数矩阵
	int centerx = x / 2;
	int centery = y / 2;
	float sum = 0;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			float distence = pow(i - centerx, 2) + pow(j - centery, 2);
			coe[i][j] = Gaussfunc(distence);
			sum += coe[i][j];
		}
	}
	//cout << coe[25][25] << endl;
	//权值和归一
	Mat kernel = Mat::zeros(x, y, CV_32FC1);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			//coe[i][j] /= sum;
			kernel.at<float>(i, j) = coe[i][j];
		}
	}
	//cout << coe[25][25] << endl;
	//cout << kernel.at<float>(25, 25);
	//图像转换
	filter2D(input, output, -1, kernel);

	return output;
}