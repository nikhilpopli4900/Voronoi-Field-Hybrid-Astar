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
	int color_code; float cost;

	Node1( int x, int y, int color_code,float cost) : x(x),y(y),color_code(color_code), cost(cost)
	{

	}

};

struct Compare { 
    bool operator()(Node1 const& p1, Node1 const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        p1.cost > p2.cost; 
    	
    } 
};
struct node{
	int x,y;
};
priority_queue<Node1, vector<Node1>, Compare> main_q;
queue <Node1> main_q2;
queue <node> myq;
Node1 new_node=Node1(0,0,0,0);
Mat cost_image;
Mat voronoi_cost_image;
Mat voronoi_edges;
int max_obs_dist = 250;
int alpha = 250;

#endif