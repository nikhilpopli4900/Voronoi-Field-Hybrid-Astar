#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
#include"params.hpp"
#include"bfs.hpp"
#include"draw_bfs.hpp"
#include"edge_cost.hpp"

using namespace cv;
using namespace std;
#include<queue>


Mat calculate_voronoi_values(Mat obs_dist,Mat voronoi_dist){
	Mat outpu = obs_dist.clone();
	for(int i=0;i<obs_dist.rows;i++){
		for(int j=0;j<obs_dist.cols;j++){
			if(obs_dist.at<uchar>(i,j)!=255){
				if(obs_dist.at<uchar>(i,j)>max_obs_dist){
					outpu.at<uchar>(i,j) = 254;
					continue;
				}
				outpu.at<uchar>(i,j) = (int)(255*(1-((1.0*alpha/(1.0*alpha+1.0*obs_dist.at<uchar>(i,j)))*(1.0*voronoi_dist.at<uchar>(i,j)/(1.0*voronoi_dist.at<uchar>(i,j)+1.0*obs_dist.at<uchar>(i,j)))*((1.0*max_obs_dist-1.0*obs_dist.at<uchar>(i,j))/(1.0*max_obs_dist))*((1.0*max_obs_dist-1.0*obs_dist.at<uchar>(i,j))/(1.0*max_obs_dist)))));
			}
		}
	}
	return outpu;
}

int main(int argv,char** argc)
{
//Use this section to get costmap from ROS into input grayscale image
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Mat input=imread(argc[1],0);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	/* Mat input_inverted=input.clone();
	for(i=0;i<input_inverted.rows;i++)
	{
		for(j=0;j<input_inverted.cols;j++)
		{
			if(input.at<uchar>(i,j)==255)
				input.at<uchar>(i,j)=0;
			else
				input.at<uchar>(i,j)=255;
		}
	}*/
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
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
	common = Mat(input.rows,input.cols,CV_8UC1,Scalar(0));
	main_bfs(input_border);
	Mat output_regions(input.rows,input.cols,CV_8UC1,Scalar(0));
	imshow("common",common);
	output_regions=find_obstacle_dist(input);
	find_edge_cost(voronoi_edges);
	namedWindow("Final",WINDOW_NORMAL);  //To show the results 

//Comment these lines if you don't want the intermediate steps to be printed
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	imshow("Input",input);
	imshow("Input with Borders",input_border);
	imshow("Output",output_regions);
	imshow("obstacle_cost_image",cost_image);
	imshow("voronoi_cost_image",voronoi_cost_image);
	imshow("voronoi_edges_image",voronoi_edges);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	createTrackbar("Alpha","Final",&alpha,1000);
	createTrackbar("Max Obsacle Distance","Final",&max_obs_dist,1000);
	
	while(1){
		Mat final = calculate_voronoi_values(cost_image,voronoi_cost_image);
		imshow("Final",final);
		waitKey(10);
	}
	waitKey(0);
	
}


