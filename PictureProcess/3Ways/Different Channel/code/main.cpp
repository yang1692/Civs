#include"head.h"
int NUM = 0;
int COL = 0;
int ROW = 0;
/***********************************************************************************************
                                          ������
***********************************************************************************************/
int main() {
	while (1)
	{
		cout << "������ͼƬ��:" << endl;
		cin >> NUM;
		if (!(NUM > 0 && NUM < 10))
			cout << "������1-10֮��Ϸ�������" << endl;
		else break;
	}
	//�洢��ͨ����ԭͼ
	Mat *src = new Mat[NUM];
	
	//�洢����ͨ��ԭͼ�ķ�ͼ
	Mat **graysrc = new Mat*[3];

	//�洢����ͨ��ԭͼ��ͼ���ݶ�ͼ
	Mat **grad = new Mat*[3];
	cout << "������ͼƬ·��" << endl;
	for (int i = 0; i < 3; i++)
	{
		graysrc[i] = new Mat[NUM];
		grad[i] = new Mat[NUM];
	}
	
	vector<Mat> *channel=new vector<Mat>[NUM];
	//�洢����ͨ����Ȩֵ��
	int *wtsum[3];

	//�洢�����ͨ��ͼ
	Mat rzt[3];

	Mat result;
	string img;
	for (int i = 0; i < NUM; i++)
	{
		//��ȡͼƬ
		cin >> img;
		src[i] = imread(img);
		if (src[i].empty())
		{
			cout << "ͼ�����ʧ�ܣ�������������·����ͼ���ʽ" << endl;
			i--;
			continue;
		}
		//����ͼƬ
	
		split(src[i], channel[i]);
		for (int RGB=0; RGB < 3; RGB++)
		{
			//��ԭͼ��RGB��ͼ����graysrc��RGB�š���ͼƬ��š���
			graysrc[RGB][i] = channel[i].at(RGB);

			//���ݶ�ͼ������grad��RGB�š���ͼƬ��š���
			Lapgrad(graysrc[RGB][i],grad[RGB][i]);

		}
	}
	cout << "������....." << endl;
	//��ȡͼƬ��С
	int COL = graysrc[0][0].cols;
	int ROW = graysrc[0][0].rows;

	//��ʼ��Ȩֵ�;���
	for (int RGB = 0; RGB < 3; RGB++)
	{
		wtsum[RGB] = (int*)malloc(sizeof(int)*COL*ROW);
		memset(wtsum[RGB], 0, sizeof(int)*COL*ROW);
	}
	vector<vector<double>> weight(NUM, vector<double>(ROW*COL, 0));

	Mat *Gau=new Mat[NUM];

	//�õ�Ȩֵ�;���
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
	cout << "������洢�Ľ��ͼ���֣�" << endl;
	cout << "����123.jpg" << endl;
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

