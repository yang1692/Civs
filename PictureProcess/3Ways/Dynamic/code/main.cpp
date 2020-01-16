#include"head.h"
int  NUM = 0;
int COL = 0;
int ROW = 0;
/***********************************************************************************************
                                          ������
***********************************************************************************************/
int main() {
	cout << "���������Ϊarchͼ����" << endl;
	cout << "������ͼƬ����:" << endl;
	while (1)
	{
		cin >> NUM;
		if (!(NUM > 0 && NUM < 10))
			cout << "������1-10֮��ĺϷ����֣�" << endl;
		else break;

	}
	Mat *src    = new Mat[NUM];
	Mat *graysrc= new Mat[NUM];
	Mat *grad = new Mat[NUM];
	Mat *tangle = new Mat[NUM];
	Mat *weight = new Mat[NUM];
	Mat *Gau    = new Mat[NUM];

	Mat rzt;

	//��ȡͼƬ
	string img;
	cout << "������ͼƬ·����" << endl;
	for (int i = 0; i < NUM; i++)
	{
		cin >> img;
		src[i] = imread(img);
		if (src[i].empty())
		{
			cout << "ͼƬ����ʧ�ܣ����������룡" << endl;
			i--;
			continue;
		}
		cvtColor(src[i], graysrc[i], CV_BGR2GRAY);
	}
	cout << "�����У���ȴ�~" << endl;
	//��ȡͼƬ��С
	COL = graysrc[0].cols;
	ROW = graysrc[0].rows;

	Mat easyrzt;

	//score����
	vector<vector<double>> score (NUM, vector<double>(ROW*COL, 0));

	//core����
	vector<vector<double>> core  (NUM, vector<double>(ROW*COL, 0));

	//��ʼ��Ȩֵ�;���
	int *wtsum = new int[ROW*COL];
	memset(wtsum, 0, sizeof(int)*ROW*COL);

	//�õ��ݶ�ͼ����˹ģ��
	for (int i = 0; i < NUM; i++)
	{
		tangle[i] = Mat(ROW, COL, CV_64FC1);
		weight[i] = Mat(ROW, COL, CV_64FC1);
		Lapgrad(graysrc[i], grad[i]);
		Gau[i]=Gaussian_blur(grad[i] ,51, 51);
	}

	//�õ�Ȩֵ�;���
	getwtsum(Gau,wtsum);

	//�õ�Ȩֵ����
	getweight(Gau, wtsum, weight);

	//�õ��ݶȽǶȾ���
	getangle(graysrc, tangle);

	//�õ�score����
	getscore(tangle, score);

	//�õ�core����
	getCore(graysrc, score, core);

	//�õ���̬Ȩֵ
	getFinalW(weight, core);
	for (int i = 0; i < NUM; i++)
	{
		GaussianBlur(weight[i], weight[i], Size(31, 31),40,40,4);

	}
	//�õ�����ͼ��
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

