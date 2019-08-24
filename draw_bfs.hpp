#ifndef DRAW_BFS
#define DRAW_BFS
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
#include<queue>
#include<math.h>

int isvalid1(Mat input_obstacle_map,int i, int j);




Mat find_obstacle_dist(Mat input_obstacle_map)    //Used to find min distance from obstacles for each point and find voronoi boundaries from which voronoi fields are generated
{
	Node temp_node=Node(0,0,0,0),current_node=Node(0,0,0,0);
	Mat occupancy_grid=input_obstacle_map.clone();	
	for(int i=0;i<input_obstacle_map.rows;i++){
		for(int j=0;j<input_obstacle_map.cols;j++){
			if(common.at<uchar>(i,j)==255) occupancy_grid.at<uchar>(i,j) =0;
		}
	}
	current_node=main_q.top();
	int i,j;
	Mat nearest_obs = input_obstacle_map.clone();
	cost_image = input_obstacle_map.clone();
	voronoi_edges=Mat(input_obstacle_map.rows,input_obstacle_map.cols,CV_8UC1,Scalar(0));
	i=current_node.x;
	j=current_node.y;
	int l,m;
	while(!main_q.empty())
	{
			if(!main_q.empty())	
			{
				current_node=main_q.top();
				i=current_node.x;j=current_node.y;
				main_q.pop();
				if(occupancy_grid.at<uchar>(i,j)==255) continue;
				occupancy_grid.at<uchar>(i,j)=255;
				if(current_node.cost<255) cost_image.at<uchar>(i,j)=(int)current_node.cost;
				else cost_image.at<uchar>(i,j) = 254;
				nearest_obs.at<uchar>(i,j)=current_node.color_code*40;
						
			}     
			for(l=i-1;l<=i+1;l++)
			{
				for(m=j-1;m<=j+1;m++)
				{
					if(isvalid(input_obstacle_map,l,m))
					{
						if(occupancy_grid.at<uchar>(l,m)==0)
						{
							temp_node=Node(l,m,current_node.color_code,current_node.cost+1.0+(0.414*((abs(l-i)+abs(m-j)+1)%2)));
							main_q.push(temp_node);
						}
						else if(nearest_obs.at<uchar>(l,m)!=current_node.color_code*40&&input_obstacle_map.at<uchar>(l,m)==0)
						{
							voronoi_edges.at<uchar>(l,m)=255;
							Node tem=Node(l,m,0,0.0);
							main_q2.push(tem);
						}
					}
				}
			}
			
	}
	return nearest_obs;

}



int isvalid1(Mat input_obstacle_map,int x, int y)
{
	if(x<0||y<0||x>input_obstacle_map.rows-1||y>input_obstacle_map.cols-1){
		
	 	return 0;
	}
	else return 1;
}

#endif