#include"head.h"
double const epsilon = pow(10, -5);
void getFinalW(Mat *weight, vector<vector<double>> core)
{
	double sum = 0;
	for (int x = 0; x < ROW; x++)
	{
		
		for (int y = 0; y < COL; y++)
		{
			sum = 0;
			for (int i = 0; i < NUM; i++)
			{
				double* pwt = weight[i].ptr<double>(x);
				sum += pwt[y] * core[i][x*COL + y];
			}
			for (int i = 0; i < NUM; i++)
			{
				double* pwt = weight[i].ptr<double>(x);
				pwt[y] = (pwt[y] * core[i][x*COL + y]+0.0000001) / (sum + epsilon);
			}

		}
	}
}