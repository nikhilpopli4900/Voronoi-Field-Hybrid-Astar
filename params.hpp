#ifndef PARAMS
#define PARAMS
#include<iostream>
using namespace std;
#include<queue>
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
using namespace cv;

struct Node1{
	int x,y;
	int color_code; int cost;

	Node1( int x, int y, int color_code,int cost) : x(x),y(y),color_code(color_code), cost(cost)
	{

	}

};
struct node{
	int x,y;
};
queue <Node1> main_q;
queue <node> myq;
Node1 new_node=Node1(0,0,0,0);
Mat cost_image;


#endif