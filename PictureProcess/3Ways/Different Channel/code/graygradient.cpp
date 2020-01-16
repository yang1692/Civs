#include"head.h"
/***********************************************************************************************
*函数名 ：graygradient
*函数功能描述 ：求灰度图的梯度图
*函数参数 ：src：输入图；mag:输出图
*函数返回值 ：无
*作者 ：Kui Yang
*函数创建日期 ：2017.12.1
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：1.0.0
*历史版本 ：
***********************************************************************************************/
void graygradient(Mat &src, Mat &mag)
{
	Mat temp;
	copyMakeBorder(src, temp, 1, 1, 1, 1, BORDER_REPLICATE);
	const int H = src.rows, W = src.cols*src.channels();
	//梯度值跨0且值域很大，设为整形
	Mat Ix(H, W, CV_32S), Iy(H, W, CV_32S);

	// 求梯度
	for (int x = 1; x < H + 1; x++)
	{
		for (int y = 1; y < W + 1; y++)
		{
			Ix.at<int>(x - 1, y - 1) = abs(coe[0] * temp.at<byte>(x, y + 1) + coe[1] *temp.at<byte>(x + 1, y + 1) + coe[2]*temp.at<byte>(x - 1, y + 1)
										- (coe[0] * temp.at<byte>(x, y - 1) + coe[1] *temp.at<byte>(x + 1, y - 1) + coe[2] *temp.at<byte>(x - 1, y - 1)));
			Iy.at<int>(x - 1, y - 1) = abs(coe[0] * temp.at<byte>(x + 1, y) + coe[1] *temp.at<byte>(x + 1, y + 1) + coe[2] *temp.at<byte>(x + 1, y - 1)
										- (coe[0] * temp.at<byte>(x - 1, y) + coe[1] *temp.at<byte>(x - 1, y + 1) + coe[2] *temp.at<byte>(x - 1, y - 1)));
		}

	}
	convertScaleAbs(min(0.5*Ix + 0.5*Iy, 255), mag); //处理越界
}