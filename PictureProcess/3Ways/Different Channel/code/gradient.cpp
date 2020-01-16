#include"head.h"
/***********************************************************************************************
*函数名 ：gradient
*函数功能描述 ：求彩图的梯度图
*函数参数 ：src：输入图；，des:输出图；
*函数返回值 ：无
*作者 ：Kui Yang
*函数创建日期 ：2017.12.2
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：1.0.0
*历史版本 ：
***********************************************************************************************/
void gradient(Mat &src, Mat *des)
{
	Mat dstgreen, dstred, dstblue;
	Mat imggreen, imgred, imgblue;
	Mat output;
	vector <Mat> channels;
	split(src, channels);
	imgblue = channels.at(0);
	imggreen = channels.at(1);
	imgred = channels.at(2);
	graygradient(imgblue, dstblue);
	graygradient(imgred, dstred);
	graygradient(imggreen, dstgreen);
	des[0] = dstblue;
	des[1] = dstgreen;
	des[2] = dstred;
	//imwrite("梯度图dange.jpg", output);
}
