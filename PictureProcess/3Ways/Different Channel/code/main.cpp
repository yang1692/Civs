#include"head.h"
int NUM = 0;
int COL = 0;
int ROW = 0;
/***********************************************************************************************
                                          主函数
***********************************************************************************************/
int main() {
	while (1)
	{
		cout << "请输入图片数:" << endl;
		cin >> NUM;
		if (!(NUM > 0 && NUM < 10))
			cout << "请输入1-10之间合法的数字" << endl;
		else break;
	}
	//存储三通道的原图
	Mat *src = new Mat[NUM];
	
	//存储各个通道原图的分图
	Mat **graysrc = new Mat*[3];

	//存储各个通道原图分图的梯度图
	Mat **grad = new Mat*[3];
	cout << "请输入图片路径" << endl;
	for (int i = 0; i < 3; i++)
	{
		graysrc[i] = new Mat[NUM];
		grad[i] = new Mat[NUM];
	}
	
	vector<Mat> *channel=new vector<Mat>[NUM];
	//存储各个通道的权值和
	int *wtsum[3];

	//存储结果的通道图
	Mat rzt[3];

	Mat result;
	string img;
	for (int i = 0; i < NUM; i++)
	{
		//读取图片
		cin >> img;
		src[i] = imread(img);
		if (src[i].empty())
		{
			cout << "图像加载失败，请检查输入的相对路径或图像格式" << endl;
			i--;
			continue;
		}
		//分裂图片
	
		split(src[i], channel[i]);
		for (int RGB=0; RGB < 3; RGB++)
		{
			//将原图的RGB分图存入graysrc【RGB号】【图片序号】，
			graysrc[RGB][i] = channel[i].at(RGB);

			//求梯度图并存入grad【RGB号】【图片序号】中
			Lapgrad(graysrc[RGB][i],grad[RGB][i]);

		}
	}
	cout << "处理中....." << endl;
	//获取图片大小
	int COL = graysrc[0][0].cols;
	int ROW = graysrc[0][0].rows;

	//初始化权值和矩阵
	for (int RGB = 0; RGB < 3; RGB++)
	{
		wtsum[RGB] = (int*)malloc(sizeof(int)*COL*ROW);
		memset(wtsum[RGB], 0, sizeof(int)*COL*ROW);
	}
	vector<vector<double>> weight(NUM, vector<double>(ROW*COL, 0));

	Mat *Gau=new Mat[NUM];

	//得到权值和矩阵
	for (int RGB = 0; RGB < 3; RGB++)
	{
		for (int i = 0; i < NUM; i++)
		{
			Gau[i] = Gaussian_blur(grad[RGB][i], 51 , 51);
		}
		getwtsum(Gau, wtsum[RGB]);
		getweight(Gau, wtsum[RGB], weight);
		Fusion(graysrc[RGB], rzt[RGB], weight);
		channel[0][RGB] = rzt[RGB];
	}

	//transweight(weight,ROW,COL);
	merge(channel[0], result);
	imshow("result", result);
	cout << "请输入存储的结果图名字：" << endl;
	cout << "例：123.jpg" << endl;
	cin >> img;
	imwrite(img, result);


	for (int RGB = 0; RGB < 3; RGB++)
	{
		free(wtsum[RGB]);
	}
	for (int i = 0; i < 3; i++)
	{
		delete[]graysrc[i];
		delete[]grad[i];
	}
	delete[]graysrc;
	delete[]grad;
	delete[]src;
	delete[]Gau;
	system("pause");
}

