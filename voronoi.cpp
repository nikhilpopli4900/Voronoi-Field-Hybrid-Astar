#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include"params.hpp"
#include"bfs.hpp"
#include"draw_bfs.hpp"
using namespace cv;
using namespace std;
#include<queue>


int main(int argv,char** argc)
{
	
	Mat input=imread(argc[1],0);
	Mat input_border(input.rows,input.cols,CV_8UC1,Scalar(0));
	int i,j;
	
	//To binarise the image
	for(i=0;i<input.rows;i++)
	{
		for(j=0;j<input.cols;j++)
		{
			if(input.at<uchar>(i,j)>30)
				input.at<uchar>(i,j)=255;
			else
				input.at<uchar>(i,j)=0;
		}
	}
	
	//To invert the image(comment this section if it is not required to be inverted i.e. if the obstacles are already black)
//////////////////////////////////////////////////////////////////////////////////////////
	
	Mat input_inverted=input.clone();
	for(i=0;i<input_inverted.rows;i++)
	{
		for(j=0;j<input_inverted.cols;j++)
		{
			if(input.at<uchar>(i,j)==255)
				input.at<uchar>(i,j)=0;
			else
				input.at<uchar>(i,j)=255;
		}
	}
	
///////////////////////////////////////////////////////////////////////////////////////////
	
	// To generate input image which consists of white pixels representing borders of the obstacle objects as input_border the original image
	for(i=1;i<input.rows-1;i++)
	{
		for(j=1;j<input.cols-1;j++)
		{	
			
			if((int)input.at<uchar>(i,j)==0)
			{
				if((int)input.at<uchar>(i+1,j)==255||(int)input.at<uchar>(i+1,j+1)==255||(int)input.at<uchar>(i-1,j)==255||(int)input.at<uchar>(i,j-1)==255||(int)input.at<uchar>(i,j+1)==255||(int)input.at<uchar>(i-1,j-1)==255||(int)input.at<uchar>(i+1,j-1)==255||(int)input.at<uchar>(i-1,j+1)==255)
				{	
					input_border.at<uchar>(i,j)=255;
				}
			}
		}
	}


	Mat output_colored;
	Mat pushed;
	main_bfs(input_border);
	Mat output(input.rows,input.cols,CV_8UC1,Scalar(0));
	output=draw_main_bfs(input,input);
	imshow("Input",input);
	imshow("Input with Borders",input_border);
	imshow("Output",output);
	imshow("cost_image",cost_image);
	waitKey(0);

	
}


