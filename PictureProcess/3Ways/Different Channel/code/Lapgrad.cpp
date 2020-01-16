#include"head.h"
void Lapgrad(Mat &input,Mat &output)
{
	Mat temp ;
	output = Mat(input.size(), input.type());
	int COL = input.cols;
	int ROW = input.rows;
	copyMakeBorder(input, temp, 1, 1, 1, 1, BORDER_REPLICATE);
	for (int x = 1; x < ROW + 1; x++)
	{
		uchar* pinc = temp.ptr<uchar>(x);
		uchar* pinh = temp.ptr<uchar>(x+1);
		uchar* pinl = temp.ptr<uchar>(x-1);
		uchar* pou = output.ptr<uchar>(x-1);
		for (int y = 1; y < COL + 1; y++)
		{
			pou[y-1] =- 0.25 * pinl[y - 1] - 0.25 * pinl[y] - 0.25 * pinl[y + 1]
					  - 0.25 * pinc[y - 1] + 2   * pinc[y] - 0.25 * pinc[y + 1]
					  - 0.25 * pinh[y - 1] - 0.25 * pinh[y] - 0.25 * pinh[y + 1];
		}

	}
	/*Mat kern = (Mat_<char>(3, 3) <<  -1,-1, -1,
									   -1, 8,-1,
									   -1,-1, -1);
	//cout << coe[25][25] << endl;
	//cout << kernel.at<float>(25, 25);
	//Í¼Ïñ×ª»»
	filter2D(temp, temp, -1, kern);*/
	convertScaleAbs(min(abs(input + output), 255),output);
}