#include"head.h"
int  NUM = 0;
/***********************************************************************************************
                                          主函数
***********************************************************************************************/
int main() {
	cout << "请输入图片数：" << endl;
	cin >> NUM;
	Mat *src=new Mat[NUM];
	Mat *graysrc=new Mat[NUM];
	Mat *grad = new Mat[NUM];
	string img;
	int *wtsum;
	Mat rzt;
	
	//读取图片
	cout << "请输入图片路径：" << endl;
	for (int i = 0; i < NUM; i++)
	{
		cin >> img;
		src[i] = imread(img);
		cvtColor(src[i], graysrc[i], CV_BGR2GRAY);
	}
	cout << "处理中" << endl;
	//获取图片大小
	int COL = graysrc[0].cols;
	int ROW = graysrc[0].rows;
	vector<vector<double>> weight(NUM, vector<double>(ROW*COL, 0));

	wtsum = (int*)malloc(sizeof(int)*COL*ROW);
	memset(wtsum, 0, sizeof(int)*COL*ROW);
	

	Mat sum = Mat(ROW, COL, CV_16UC1);
	Mat *Gau=new Mat[NUM];

	//得到梯度图并高斯模糊
	for (int i = 0; i < NUM; i++)
	{
		Lapgrad(graysrc[i], grad[i]);
		Gau[i]=Gaussian_blur(grad[i] ,51, 51);
	}

	//得到权值和矩阵
	getwtsum(Gau,wtsum);

	//得到权值矩阵
	getweight(Gau, wtsum, weight);

	//最终融合
	Fusion(src,  rzt, weight);

	imshow("result", rzt);
	waitKey(5);
	cout << "请输入存储的结果图名字：" << endl;
	cout << "例：123.jpg" << endl;
	cin >> img;
	imwrite(img, rzt);
	imwrite("Arch_result.jpg",rzt);
	imshow("result", rzt);

	free(wtsum);

	delete[]src;
	delete[]graysrc;
	delete[]grad;
	system("pause");
}

