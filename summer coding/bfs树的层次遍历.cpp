#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#define maxn 1000

using namespace std;

char s[maxn];
bool failed = false;

struct node {
	bool have_value;
	int v;
	node *left, *right;
	node() :have_value(false), left(NULL), right(NULL) {};
};

node *root;

node* newnode()
{
	return new node();
}

void addnode(int v, char *s)
{
	int n = strlen(s);
	node * u = root;
	for (int i = 0; i<n; i++)
	{
		if (s[i] == 'L')
		{
			if (u->left == NULL) u->left = newnode();
			u = u->left;
		}
		else if (s[i] == 'R')
		{
			if (u->right == NULL) u->right = newnode();
			u = u->right;
		}
		if (u->have_value) failed = true;
		u->v = v;
		u->have_value = true;
	}
}


bool read_input()
{

	root = newnode();
	for (; ; )
	{
		if (scanf("%s", s) != 1) return false;
		if (!strcmp(s, "()")) break;
		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s, ',') + 1);
	}
	return true;
}

bool bfs(vector<int> &ans)
{
	queue<node *> q;
	ans.clear();
	q.push(root);
	while (!q.empty())
	{
		node *u = q.front(); q.pop();
		if (!u->have_value) return false;
		ans.push_back(u->v);
		if (u->left != NULL) q.push(u->left);
		if (u->right != NULL) q.push(u->right);
	}
	return true;
}

int main()
{


	
	return 0;
}
 

