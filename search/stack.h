#pragma once
#include <iostream>

using namespace std;

class stack{
	int * valuesi;
	int * valuesj;
	int top;
	int maxTop;
public:
	stack(int size = 100);
	bool isEmpty(){ return top == -1; }
	bool isFull(){ return top == maxTop; }
	int Top();
	void push(int,int);
	void pop();
	void displayStack();
};