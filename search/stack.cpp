#include "stdafx.h"
#include "stack.h"
#include <iostream>

using namespace std;


stack::stack(int size){
	top = -1;
	maxTop = size - 1;
	valuesi = new int[size];
	valuesj = new int[size];
}

void stack::displayStack(){
	if (isEmpty())
		cout << "Erorr ! Stack is empty";
	else
	for (int i = top; i >= 0; i--){
		cout << "\t"<<valuesi[i] << " " << valuesj[i] << endl;
	}
}

void stack::pop(){
	if (isEmpty())
		cout << "Erorr ! Stack is empty";
	else
		top--;
}

void stack::push(int i,int j){
	if (isFull())
		cout << "Erorr ! Stack is full\n";
	else{
		top++;
		valuesi[top] = i;
		valuesj[top] = j;
	}
}