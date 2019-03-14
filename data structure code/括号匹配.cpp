#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 1000
typedef char elem;
using namespace std;

typedef struct stack {
	elem data [N];
	int front;
}Stack;

//≥ı ºªØ 
void init (Stack &s)
{
	s.front=-1;
}

void match (char a)
{
	
}

int main ()
{
	Stack s;
	//init
	init(s); 
	//input
	cout<<"plz enter a string to match :";
	char a[N];
	cin>>a;
	//pipei
	match(a);
	
	
	return 0;
 } 
