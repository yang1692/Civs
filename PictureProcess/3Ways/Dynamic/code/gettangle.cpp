#include"head.h"
/***********************************************************************************************
*������ ��getangle
*������������ ���õ��ǶȾ���
*�������� ��input������ͼ;tangle:�洢���
*��������ֵ ����
*���� ��Kui Yang
*������������ ��2017.12.8
*�����޸����� ��
*�޸��� ��
*�޸�ԭ�� ��
*�汾 ��1.1.0
*��ʷ�汾 ��
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