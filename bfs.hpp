#ifndef BFS
#define BFS
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;


#include<queue>

void bfs(Mat a, Mat b, int i,int j,int count);
int isvalid(Mat a,int i, int j);

void main_bfs(Mat d)
{


int l,m;


Mat a(d.rows,d.cols,CV_8UC1,Scalar(0));	
	for(l=0;l<a.rows;l++)
	{
		for(m=0;m<a.cols;m++)
		{
			if(d.at<uchar>(l,m)<150)
				a.at<uchar>(l,m)=0;
			else
				a.at<uchar>(l,m)=255;
	    }
	}



Mat b=a.clone();
int i,j,k;
node temp;
int count=0;

for(l=0;l<a.rows-1;l++)
{
	for(m=0;m<a.cols-1;m++)
	{	
		
		if(b.at<uchar>(l,m)==255)
		{
		    temp.x=l;
		    temp.y=m;
		    new_node=Node1(temp.x,temp.y,count+1,0);
		    //cout<<count<<endl;
		    //cout<<"aa"<<new_node.color_code<<endl;
		    main_q.push(new_node);
		    myq.push(temp);
		   	b.at<uchar>(l,m)=0;
			bfs(a,b,l,m,count);
			
			count++; 
			
		}
	}
}
cout<<count<<"  dg"<<endl;

}

void bfs(Mat a,Mat b,int i,int j,int count)
{	
	node temp;
	
	//cout<<count<<"inf"<<endl;
	while(!myq.empty())
	{
			
			if(isvalid(a,i,j+1)&&b.at<uchar>(i,j+1)==255)
			{
				b.at<uchar>(i,j+1)=0;
				temp.x=i;
			    temp.y=j+1;
				new_node=Node1(temp.x,temp.y,count+1,0);
				//cout<<"aa"<<new_node.color_code<<endl;
				main_q.push(new_node);
				myq.push(temp);

			}
			if (isvalid(a,i+1,j)&&b.at<uchar>(i+1,j)==255)
			{
				b.at<uchar>(i+1,j)=0;
				temp.x=i+1;
			    temp.y=j;
				new_node=Node1(temp.x,temp.y,count+1,0);
				//cout<<"aa"<<new_node.color_code<<endl;
				main_q.push(new_node);
				myq.push(temp);	
			}
			if(isvalid(a,i,j-1)&&b.at<uchar>(i,j-1)==255)
			{
				b.at<uchar>(i,j-1)=0;
				temp.x=i;
			    temp.y=j-1;
				new_node=Node1(temp.x,temp.y,count+1,0);
				//cout<<"aa"<<new_node.color_code<<endl;
				main_q.push(new_node);
				myq.push(temp);   
			}
			 if(isvalid(a,i-1,j)&&b.at<uchar>(i-1,j)==255)
			  {
				b.at<uchar>(i-1,j)=0;
				temp.x=i-1;
			    temp.y=j;
				new_node=Node1(temp.x,temp.y,count+1,0);
				//cout<<"aa"<<new_node.color_code<<endl;
				main_q.push(new_node);
				myq.push(temp);
			  }
				myq.pop();
				if(!myq.empty())	
					{temp=myq.front();
				i=temp.x;j=temp.y;}                                 //check
	}
}

int isvalid(Mat a,int x, int y)
{
	if(x<0||y<0||x>a.rows-1||y>a.cols-1){
		
	 	return 0;
	}
	else return 1;
}

#endif