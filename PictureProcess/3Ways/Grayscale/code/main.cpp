#include"head.h"
int  NUM = 0;
/***********************************************************************************************
                                          ������
***********************************************************************************************/
int main() {
	cout << "������ͼƬ����" << endl;
	cin >> NUM;
	Mat *src=new Mat[NUM];
	Mat *graysrc=new Mat[NUM];
	Mat *grad = new Mat[NUM];
	string img;
	int *wtsum;
	Mat rzt;
	
	//��ȡͼƬ
	cout << "������ͼƬ·����" << endl;
	for (int i = 0; i < NUM; i++)
	{
		cin >> img;
		src[i] = imread(img);
		cvtColor(src[i], graysrc[i], CV_BGR2GRAY);
	}
	cout << "������" << endl;
	//��ȡͼƬ��С
	int COL = graysrc[0].cols;
	int ROW = graysrc[0].rows;
	vector<vector<double>> weight(NUM, vector<double>(ROW*COL, 0));

	wtsum = (int*)malloc(sizeof(int)*COL*ROW);
	memset(wtsum, 0, sizeof(int)*COL*ROW);
	

	Mat sum = Mat(ROW, COL, CV_16UC1);
	Mat *Gau=new Mat[NUM];

	//�õ��ݶ�ͼ����˹ģ��
	for (int i = 0; i < NUM; i++)
	{
		Lapgrad(graysrc[i], grad[i]);
		Gau[i]=Gaussian_blur(grad[i] ,51, 51);
	}

	//�õ�Ȩֵ�;���
	getwtsum(Gau,wtsum);

	//�õ�Ȩֵ����
	getweight(Gau, wtsum, weight);

	//�����ں�
	Fusion(src,  rzt, weight);

	imshow("result", rzt);
	waitKey(5);
	cout << "������洢�Ľ��ͼ���֣�" << endl;
	cout << "����123.jpg" << endl;
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

