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


int main()
{
	Mat d=imread("Binary1.png",0);
	imshow("a",d);
	
	Mat in(d.rows,d.cols,CV_8UC1,Scalar(0));
	int i,j;
	for(i=0;i<d.rows;i++)
	{
		for(j=0;j<d.cols;j++)
		{
			if(d.at<uchar>(i,j)>30)
				d.at<uchar>(i,j)=255;
			else
				d.at<uchar>(i,j)=0;
		}
	}
	Mat a=d.clone();
	for(i=0;i<a.rows;i++)
	{
		for(j=0;j<a.cols;j++)
		{
			if(d.at<uchar>(i,j)==255)
				d.at<uchar>(i,j)=0;
			else
				d.at<uchar>(i,j)=255;
		}
	}
	for(i=1;i<d.rows-1;i++)
	{
		for(j=1;j<d.cols-1;j++)
		{	
			//cout<<((int)d.at<uchar>(i,j)==0)<<"   "<<endl;
			if((int)d.at<uchar>(i,j)==0)
			{
				//cout<<"yes"<<endl;
				//cout<<(int)d.at<uchar>(i,j)<<"    "<<endl;
	            if((int)d.at<uchar>(i+1,j)==255||(int)d.at<uchar>(i+1,j+1)==255||(int)d.at<uchar>(i-1,j)==255||(int)d.at<uchar>(i,j-1)==255||(int)d.at<uchar>(i,j+1)==255||(int)d.at<uchar>(i-1,j-1)==255||(int)d.at<uchar>(i+1,j-1)==255||(int)d.at<uchar>(i-1,j+1)==255)
				{	//cout<<"jckbkjdck"<<endl;
						in.at<uchar>(i,j)=255;
				}
			}
		}
	}


	Mat output_colored;
	Mat pushed;
	main_bfs(in);
	Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));
	c=draw_main_bfs(a,a);









	 
	imshow("d",a);

	imshow("dwc",c);
	waitKey(000);

	
}


