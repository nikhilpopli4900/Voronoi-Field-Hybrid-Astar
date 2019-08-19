#ifndef EDGE_COST
#define EDGE_COST
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
#include<queue>

int isvalid2(Mat a,int i, int j);

Mat draw_main_bfs2(Mat a, Mat outp)
{
	Node1 temp=Node1(0,0,0,0),new_node=Node1(0,0,0,0);
	Mat b=a.clone();	
	new_node=main_q2.front();
	int i,j;
	Mat nearest_obs = outp.clone();
	voronoi_cost_image=Mat(a.rows,a.cols,CV_8UC1,Scalar(0));
	//voronoi_edges=Mat(a.rows,a.cols,CV_8UC1,Scalar(0));
	i=new_node.x;
	j=new_node.y;

	while(!main_q2.empty())
	{
		//cout<<new_node.color_code<<endl;
			
			if(isvalid2(a,i,j+1)&&b.at<uchar>(i,j+1)==0)
			{
				b.at<uchar>(i,j+1)=255;
				temp.x=i;
			    temp.y=j+1;

				temp=Node1(temp.x,temp.y,new_node.color_code,new_node.cost+1);
				if(temp.cost<255) voronoi_cost_image.at<uchar>(temp.x,temp.y)=temp.cost;
				else voronoi_cost_image.at<uchar>(temp.x,temp.y) = 254;
				//cout << (int)voronoi_cost_image.at<uchar>(i,j)<<endl;
				nearest_obs.at<uchar>(temp.x,temp.y)=new_node.color_code*40;
				main_q2.push(temp);

			}
			
			if (isvalid2(a,i+1,j)&&b.at<uchar>(i+1,j)==0)
			{
				b.at<uchar>(i+1,j)=255;
				temp.x=i+1;
			    temp.y=j;
				temp=Node1(temp.x,temp.y,new_node.color_code,new_node.cost+1);
				if(temp.cost<255) voronoi_cost_image.at<uchar>(temp.x,temp.y)=temp.cost;
				else voronoi_cost_image.at<uchar>(temp.x,temp.y) = 254;
				//cout << (int)voronoi_cost_image.at<uchar>(i,j)<<endl;
				nearest_obs.at<uchar>(temp.x,temp.y)=new_node.color_code*40;
				main_q2.push(temp);	
			}
			
			if(isvalid2(a,i,j-1)&&b.at<uchar>(i,j-1)==0)
			{
				b.at<uchar>(i,j-1)=255;
				temp.x=i;
			    temp.y=j-1;
				temp=Node1(temp.x,temp.y,new_node.color_code,new_node.cost+1);
				if(temp.cost<255) voronoi_cost_image.at<uchar>(temp.x,temp.y)=temp.cost;
				else voronoi_cost_image.at<uchar>(temp.x,temp.y) = 254;
				//cout << (int)voronoi_cost_image.at<uchar>(i,j)<<endl;
				
				nearest_obs.at<uchar>(temp.x,temp.y)=new_node.color_code*40;
				main_q2.push(temp);   
			}
			
			 if(isvalid2(a,i-1,j)&&b.at<uchar>(i-1,j)==0)
			  {
				b.at<uchar>(i-1,j)=255;
				temp.x=i-1;
			    temp.y=j;
				temp=Node1(temp.x,temp.y,new_node.color_code,new_node.cost+1);
				if(temp.cost<255) voronoi_cost_image.at<uchar>(temp.x,temp.y)=temp.cost;
				else voronoi_cost_image.at<uchar>(temp.x,temp.y) = 254;
				//cout << (int)voronoi_cost_image.at<uchar>(i,j)<<endl;
				nearest_obs.at<uchar>(temp.x,temp.y)=new_node.color_code*40;
				main_q2.push(temp);
			  }
			
				main_q2.pop();
				if(!main_q2.empty())	
					{
						new_node=main_q2.front();
						i=new_node.x;j=new_node.y;
					}                                 //check
	}
	return nearest_obs;

}



int isvalid2(Mat a,int x, int y)
{
	if(x<0||y<0||x>a.rows-1||y>a.cols-1){
		
	 	return 0;
	}
	else return 1;
}

#endif