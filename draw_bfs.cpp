#ifndef BFS
#define BFS
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;


#include<queue>


int isvalid1(Mat a,int i, int j);

Mat draw_main_bfs(Mat a, Mat out)
{
	Node1 temp,new_node;
	Mat b=a.clone();	
	new_node=main_q.front;
	int i,j;
	i=new_node.x;
	j=new_node.y;
	while(!main_q.empty())
	{
			
			if(isvalid1(a,i,j+1)&&b.at<uchar>(i,j+1)==0)
			{
				b.at<uchar>(i,j+1)=255;
				temp.x=i;
			    temp.y=j+1;
				temp=Node1(temp.x,temp.y,new_node.color_code);
				out.at<uchar>(temp.x,temp.y)=new_node.color_code*50;
				main_q.push(temp);

			}
			if (isvalid1(a,i+1,j)&&b.at<uchar>(i+1,j)==0)
			{
				b.at<uchar>(i+1,j)=255;
				temp.x=i+1;
			    temp.y=j;
				temp=Node1(temp.x,temp.y,new_node.color_code);
				out.at<uchar>(temp.x,temp.y)=new_node.color_code*50;
				main_q.push(temp);	
			}
			if(isvalid1(a,i,j-1)&&b.at<uchar>(i,j-1)==0)
			{
				b.at<uchar>(i,j-1)=255;
				temp.x=i;
			    temp.y=j-1;
				temp=Node1(temp.x,temp.y,new_node.color_code);
				out.at<uchar>(temp.x,temp.y)=new_node.color_code*50;
				main_q.push(temp);   
			}
			 if(isvalid1(a,i-1,j)&&b.at<uchar>(i-1,j)==0)
			  {
				b.at<uchar>(i-1,j)=255;
				temp.x=i-1;
			    temp.y=j;
				temp=Node1(temp.x,temp.y,new_node.color_code);
				out.at<uchar>(temp.x,temp.y)=new_node.color_code*50;
				main_q.push(temp);
			  }
				main_q.pop();
				if(!main_q.empty())	
					{new_node=main_q.front();
				i=new_node.x;j=new_node.y;}                                 //check
	}
	return out;

}



int isvalid1(Mat a,int x, int y)
{
	if(x<0||y<0||x>a.rows-1||y>a.cols-1){
		
	 	return 0;
	}
	else return 1;
}

#endif