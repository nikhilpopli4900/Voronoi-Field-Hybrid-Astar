#ifndef BFS
#define BFS
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;

#include<queue>

void bfs(Mat obstacle_map, Mat occupancy_grid, int i,int j,int count);
int isvalid(Mat obstacle_map,int i, int j);

Node temp_node(0,0,0,0);
	
void main_bfs(Mat input_obstacle_map)     //Used to identify individual obstacles and find their edges
{
	int l,m;
	Mat obstacle_map(input_obstacle_map.rows,input_obstacle_map.cols,CV_8UC1,Scalar(0));	
	for(l=0;l<obstacle_map.rows;l++)
	{
		for(m=0;m<obstacle_map.cols;m++)
		{
			if(input_obstacle_map.at<uchar>(l,m)<150)
				obstacle_map.at<uchar>(l,m)=0;
			else
				obstacle_map.at<uchar>(l,m)=255;
		}
	}

	Mat occupancy_grid=obstacle_map.clone();
	int i,j,k;
	node temp;
	int count=0;

	for(l=0;l<obstacle_map.rows-1;l++)
	{
		for(m=0;m<obstacle_map.cols-1;m++)
		{	
			
			if(occupancy_grid.at<uchar>(l,m)==255)
			{
				temp.x=l;
				temp.y=m;
				temp_node=Node(temp.x,temp.y,count+1,0);
				main_q.push(temp_node);
				myq.push(temp);
				occupancy_grid.at<uchar>(l,m)=0;
				bfs(obstacle_map,occupancy_grid,l,m,count);
				count++; 
			}
		}
	}
}

void bfs(Mat obstacle_map,Mat occupancy_grid,int i,int j,int count)   //Used to apply bfs to travers whole of the obstacle edge
{	
	node temp;
	int l,m;
	while(!myq.empty())
	{
		for(l=i-1;l<=i+1;l++)
		{
			for(m=j-1;m<=j+1;m++)
			{
				if(isvalid(obstacle_map,l,m)&&occupancy_grid.at<uchar>(l,m)==255)
				{
					occupancy_grid.at<uchar>(l,m)=0;
					common.at<uchar>(l,m)=255;
					temp.x=l;
					temp.y=m;
					temp_node=Node(l,m,count+1,0.0);
					main_q.push(temp_node);
					myq.push(temp);
				}
			}
		}
		myq.pop();
		if(!myq.empty())	
		{
			temp=myq.front();
			i=temp.x;j=temp.y;
		}                                
	}
}

int isvalid(Mat obstacle_map,int x, int y)
{
	if(x<0||y<0||x>obstacle_map.rows-1||y>obstacle_map.cols-1)
	{
		return 0;
	}
	else return 1;
}

#endif