#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>  
#include <iostream>
#include<cmath>
#include <iterator>
#include<vector>
#include<stdlib.h>
double const PI = 3.14;
double const SIGMA = 15;
double const SIGMA2 = SIGMA*SIGMA;
extern int  NUM ;
extern int  COL;
extern int  ROW;
int const e = pow(10,-5);
int const coe[3] = { 2,1,1 };

using namespace cv;
using namespace std;

typedef unsigned char byte;
void getwtsum(Mat *m, int *wtsum);
void graygradient(Mat &src, Mat &mag);
void gradient(Mat &src, Mat *des);
void Fusion(Mat *src, Mat &des, vector<vector<double>>& weight);
void getweight(Mat *Gau, int * wtsum, vector<vector<double>>& weight);
Mat Gaussian_blur(Mat const&input, int x, int y);
float Gaussfunc(float x);
void transweight(vector<vector<double>>& weight, int const&ROW, int const &COL);
void Lapgrad(Mat &input, Mat &output);
//void matsum(Mat *input, Mat &output);