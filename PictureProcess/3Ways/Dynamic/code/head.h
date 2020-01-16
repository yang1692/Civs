#ifndef H_MYH
#define H_MYH
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include<cmath>
#include <iterator>
#include<vector>

extern int  NUM;
extern int COL;
extern int ROW;

using namespace cv;
using namespace std;

typedef unsigned char byte;
void getwtsum(Mat *m, int *wtsum);
void graygradient(Mat &src, Mat &mag);
void gradient(Mat &src, Mat &des);
void Fusion(Mat *src, Mat &des, Mat * weight);
void getweight(Mat *Gau, int * wtsum, Mat *weight);
Mat Gaussian_blur(Mat const&input, int x, int y);
float Gaussfunc(float x);
void getangle(Mat *input, Mat *tangle);
void Lapgrad(Mat &input, Mat &output);
void getscore(Mat *tangle, vector<vector<double>> &score);
void getCore(Mat *src, vector<vector<double>> &score, vector<vector<double>> &core);
void getFinalW(Mat *weight, vector<vector<double>> core);
#endif