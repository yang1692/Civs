#include"head.h"
/***********************************************************************************************
*函数名 ：getangle
*函数功能描述 ：得到角度矩阵
*函数参数 ：input：输入图;tangle:存储结果
*函数返回值 ：无
*作者 ：Kui Yang
*函数创建日期 ：2017.12.8
*函数修改日期 ：
*修改人 ：
*修改原因 ：
*版本 ：1.1.0
*历史版本 ：
***********************************************************************************************/

void getangle(Mat *input, Mat *tangle)
{
	Mat temp;
	
	for (int i = 0; i < NUM; i++)
	{
		copyMakeBorder(input[i], temp, 1, 1, 1, 1, BORDER_REPLICATE);
		for (int x = 1; x < ROW+1; x++)
		{
			uchar* pinl = temp.ptr<uchar>(x - 1);
			uchar* pinc = temp.ptr<uchar>(x);
			uchar* pinh = temp.ptr<uchar>(x + 1);

			double* ptrt = tangle[i].ptr<double>(x - 1);
			for (int y = 1; y < COL+1; y++)
			{
				double detax = abs( -     pinl[y - 1] +     pinl[y + 1]
									- 2 * pinc[y - 1] + 2 * pinc[y + 1]
									-     pinh[y - 1] +     pinh[y + 1]);

				double detay = abs( - pinl[y - 1] - 2 * pinl[y] - pinl[y + 1]
								    + pinh[y - 1] + 2 * pinh[y] + pinh[y + 1])+0.00000001;
				ptrt[y - 1] = atan(detay / detax)*360/3.1415926;
			}

		}

	}

}