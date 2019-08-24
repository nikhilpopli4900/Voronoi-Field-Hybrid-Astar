#ifndef EDGE_COST
#define EDGE_COST
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
#include<queue>
#include<math.h>

int isvalid2(Mat input,int i, int j);

Mat find_edge_cost(Mat input)
{	
	Node temp_node=Node(0,0,0,0),current_node=Node(0,0,0,0);
	Mat occupancy_grid=Mat(input.rows,input.cols,CV_8UC1,Scalar(0));
	current_node=main_q2.top();
	int i,j;
	voronoi_cost_image = Mat(input.rows,input.cols,CV_8UC1,Scalar(0));
	i=current_node.x;
	j=current_node.y;
	int l,m;
	while(!main_q2.empty())
	{
			if(!main_q2.empty())	
			{
				current_node=main_q2.top();
				i=current_node.x;j=current_node.y;
				main_q2.pop();
				if(occupancy_grid.at<uchar>(i,j)==255) continue;
				occupancy_grid.at<uchar>(i,j)=255;
				
				if(current_node.cost<255) voronoi_cost_image.at<uchar>(i,j)=(int)current_node.cost;
				else voronoi_cost_image.at<uchar>(i,j) = 254;
			}    
			for(l=i-1;l<=i+1;l++)
			{
				for(m=j-1;m<=j+1;m++)
				{	
					if(isvalid2(input,l,m)&&occupancy_grid.at<uchar>(l,m)==0)
					{
						temp_node=Node(l,m,current_node.color_code,current_node.cost+1.0+0.414*(abs(l-i+m-j+1)%2));
						main_q2.push(temp_node);
					}

				}
			}
			
	}
	return voronoi_cost_image;

}



int isvalid2(Mat input,int x, int y)
{
	if(x<0||y<0||x>input.rows-1||y>input.cols-1){
		
	 	return 0;
	}
	else return 1;
}

#endif