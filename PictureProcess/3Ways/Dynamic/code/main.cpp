#include"head.h"
int  NUM = 0;
int COL = 0;
int ROW = 0;
/***********************************************************************************************
                                          主函数
***********************************************************************************************/
int main() {
	cout << "本程序参数为arch图参数" << endl;
	cout << "请输入图片数量:" << endl;
	while (1)
	{
		cin >> NUM;
		if (!(NUM > 0 && NUM < 10))
			cout << "请输入1-10之间的合法数字！" << endl;
		else break;

	}
	Mat *src    = new Mat[NUM];
	Mat *graysrc= new Mat[NUM];
	Mat *grad = new Mat[NUM];
	Mat *tangle = new Mat[NUM];
	Mat *weight = new Mat[NUM];
	Mat *Gau    = new Mat[NUM];

	Mat rzt;

	//读取图片
	string img;
	cout << "请输入图片路径：" << endl;
	for (int i = 0; i < NUM; i++)
	{
		cin >> img;
		src[i] = imread(img);
		if (src[i].empty())
		{
			cout << "图片加载失败，请重新输入！" << endl;
			i--;
			continue;
		}
		cvtColor(src[i], graysrc[i], CV_BGR2GRAY);
	}
	cout << "处理中！请等待~" << endl;
	//获取图片大小
	COL = graysrc[0].cols;
	ROW = graysrc[0].rows;

	Mat easyrzt;

	//score矩阵
	vector<vector<double>> score (NUM, vector<double>(ROW*COL, 0));

	//core矩阵
	vector<vector<double>> core  (NUM, vector<double>(ROW*COL, 0));

	//初始化权值和矩阵
	int *wtsum = new int[ROW*COL];
	memset(wtsum, 0, sizeof(int)*ROW*COL);

	//得到梯度图并高斯模糊
	for (int i = 0; i < NUM; i++)
	{
		tangle[i] = Mat(ROW, COL, CV_64FC1);
		weight[i] = Mat(ROW, COL, CV_64FC1);
		Lapgrad(graysrc[i], grad[i]);
		Gau[i]=Gaussian_blur(grad[i] ,51, 51);
	}

	//得到权值和矩阵
	getwtsum(Gau,wtsum);

	//得到权值矩阵
	getweight(Gau, wtsum, weight);

	//得到梯度角度矩阵
	getangle(graysrc, tangle);

	//得到score矩阵
	getscore(tangle, score);

	//得到core矩阵
	getCore(graysrc, score, core);

	//得到动态权值
	getFinalW(weight, core);
	for (int i = 0; i < NUM; i++)
	{
		GaussianBlur(weight[i], weight[i], Size(31, 31),40,40,4);

	}
	//得到最终图像
	Fusion(src,  rzt, weight);

	imshow("result", rzt);
	delete[]src;
	delete[]graysrc;
	delete[]grad;
	delete[]tangle;
	delete[]Gau;
	delete[]wtsum;
	waitKey(0);
}

