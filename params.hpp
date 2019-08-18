#ifndef PARAMS
#define PARAMS
#include<iostream>
using namespace std;
#include<queue>

struct Node1{
	int x,y;
	int color_code;

	Node1( int x, int y, int color_code) : x(x),y(y),color_code(color_code)
	{

	}

};
struct node{
	int x,y;
};
queue <Node1> main_q;
queue <node> myq;
Node1 new_node=Node1(0,0,0);


#endif