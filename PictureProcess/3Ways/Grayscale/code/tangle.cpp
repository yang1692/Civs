#include"head.h"
void gettangle(Mat *input, vector<vector<double>> &tangle)
{

	int COL = input[0].cols;
	int ROW = input[0].rows;
	Mat temp;
	
	for (int i = 0; i < NUM; i++)
	{
		copyMakeBorder(input[i], temp, 1, 1, 1, 1, BORDER_REPLICATE);
		for (int x = 1; x < ROW; x++)
		{
			uchar* pinc = temp.ptr<uchar>(x);
			uchar* pinh = temp.ptr<uchar>(x + 1);
			uchar* pinl = temp.ptr<uchar>(x - 1);
			for (int y = 1; y < COL; y++)
			{
				double detax = abs( -     pinl[y - 1] +     pinl[y + 1]
									- 2 * pinc[y - 1] + 2 * pinl[y + 1]
									-     pinc[y - 1] +     pinl[y + 1]);

				double detay = abs( -pinl[y - 1] - 2 * pinl[y] - pinl[y + 1]
								   + pinh[y - 1] + 2 * pinh[y] + pinh[y + 1]);
				tangle[i][(x - 1)*COL + y] = atan(detay/detax);
				cout << tangle[i][(x - 1)*COL + y-1] << endl;
			}

		}

	}
}