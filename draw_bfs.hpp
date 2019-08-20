#ifndef DRAW_BFS
#define DRAW_BFS
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
#include<queue>

int isvalid1(Mat a,int i, int j);

Mat draw_main_bfs(Mat a, Mat outp)
{
	Node1 temp=Node1(0,0,0,0),new_node=Node1(0,0,0,0);
	Mat b=a.clone();	
	new_node=main_q.top();
	int i,j;
	Mat nearest_obs = outp.clone();
	cost_image = outp.clone();
	voronoi_edges=Mat(a.rows,a.cols,CV_8UC1,Scalar(0));
	i=new_node.x;
	j=new_node.y;
	int l,m;
	while(!main_q.empty())
	{
		//cout<<new_node.color_code<<endl;
			for(l=i-1;l<=i+1;l++)
			{
				for(m=j-1;m<=j+1;m++)
				{
					if(isvalid(a,l,m))
					{
						if(b.at<uchar>(l,m)==0)
						{
							b.at<uchar>(l,m)=255;
							temp=Node1(l,m,new_node.color_code,new_node.cost+1.0+0.414*((l-i+m-j+1)%2));
							if(temp.cost<255) cost_image.at<uchar>(temp.x,temp.y)=(int)temp.cost;
							else cost_image.at<uchar>(temp.x,temp.y) = 254;
							nearest_obs.at<uchar>(temp.x,temp.y)=new_node.color_code*40;
							main_q.push(temp);
						}
						else if(nearest_obs.at<uchar>(l,m)!=new_node.color_code*40&&a.at<uchar>(l,m)==0)
						{
							voronoi_edges.at<uchar>(l,m)=255;
							Node1 tem=Node1(l,m,0,0.0);
							main_q2.push(tem);
						}
					}
				}
			}
			/*if(isvalid1(a,i,j+1)&&b.at<uchar>(i,j+1)==0)
			{
				b.at<uchar>(i,j+1)=255;
				temp.x=i;
			    temp.y=j+1;

				temp=Node1(temp.x,temp.y,new_node.color_code,new_node.cost+1);
				if(temp.cost<255) cost_image.at<uchar>(temp.x,temp.y)=temp.cost;
				else cost_image.at<uchar>(temp.x,temp.y) = 254;
				//cout << (int)cost_image.at<uchar>(i,j)<<endl;
				nearest_obs.at<uchar>(temp.x,temp.y)=new_node.color_code*40;
				main_q.push(temp);

			}
			else if(isvalid1(a,i,j+1)&&nearest_obs.at<uchar>(i,j+1)!=new_node.color_code*40&&a.at<uchar>(i,j+1)==0)
			{
				voronoi_edges.at<uchar>(i,j+1)=255;
				Node1 tem=Node1(i,j+1,0,0);
				main_q2.push(tem);
			}
			if (isvalid1(a,i+1,j)&&b.at<uchar>(i+1,j)==0)
			{
				b.at<uchar>(i+1,j)=255;
				temp.x=i+1;
			    temp.y=j;
				temp=Node1(temp.x,temp.y,new_node.color_code,new_node.cost+1);
				if(temp.cost<255) cost_image.at<uchar>(temp.x,temp.y)=temp.cost;
				else cost_image.at<uchar>(temp.x,temp.y) = 254;
				//cout << (int)cost_image.at<uchar>(i,j)<<endl;
				nearest_obs.at<uchar>(temp.x,temp.y)=new_node.color_code*40;
				main_q.push(temp);	
			}
			else if(isvalid1(a,i+1,j)&&nearest_obs.at<uchar>(i+1,j)!=new_node.color_code*40&&a.at<uchar>(i+1,j)==0)
			{
				voronoi_edges.at<uchar>(i+1,j)=255;
				Node1 tem=Node1(i+1,j,0,0);
				main_q2.push(tem);
			
			}
			if(isvalid1(a,i,j-1)&&b.at<uchar>(i,j-1)==0)
			{
				b.at<uchar>(i,j-1)=255;
				temp.x=i;
			    temp.y=j-1;
				temp=Node1(temp.x,temp.y,new_node.color_code,new_node.cost+1);
				if(temp.cost<255) cost_image.at<uchar>(temp.x,temp.y)=temp.cost;
				else cost_image.at<uchar>(temp.x,temp.y) = 254;
				//cout << (int)cost_image.at<uchar>(i,j)<<endl;
				
				nearest_obs.at<uchar>(temp.x,temp.y)=new_node.color_code*40;
				main_q.push(temp);   
			}
			else if(isvalid1(a,i,j-1)&&nearest_obs.at<uchar>(i,j-1)!=new_node.color_code*40&&a.at<uchar>(i,j-1)==0)
			{
				voronoi_edges.at<uchar>(i,j-1)=255;
				Node1 tem=Node1(i,j-1,0,0);
				main_q2.push(tem);
			
			}
			 if(isvalid1(a,i-1,j)&&b.at<uchar>(i-1,j)==0)
			  {
				b.at<uchar>(i-1,j)=255;
				temp.x=i-1;
			    temp.y=j;
				temp=Node1(temp.x,temp.y,new_node.color_code,new_node.cost+1);
				if(temp.cost<255) cost_image.at<uchar>(temp.x,temp.y)=temp.cost;
				else cost_image.at<uchar>(temp.x,temp.y) = 254;
				//cout << (int)cost_image.at<uchar>(i,j)<<endl;
				nearest_obs.at<uchar>(temp.x,temp.y)=new_node.color_code*40;
				main_q.push(temp);
			  }
			else if(isvalid1(a,i-1,j)&&nearest_obs.at<uchar>(i-1,j)!=new_node.color_code*40&&a.at<uchar>(i-1,j)==0)
			{
				voronoi_edges.at<uchar>(i-1,j)=255;
				Node1 tem=Node1(i-1,j,0,0);
				main_q2.push(tem);
			
			}*/
			
				main_q.pop();
				if(!main_q.empty())	
					{
						new_node=main_q.top();
						i=new_node.x;j=new_node.y;
					}                                 //check
	}
	return nearest_obs;

}



int isvalid1(Mat a,int x, int y)
{
	if(x<0||y<0||x>a.rows-1||y>a.cols-1){
		
	 	return 0;
	}
	else return 1;
}

#endif