#include <bits/stdc++.h>

using namespace std;

struct Point{
	double x,y;
};

double X,Y,R;

void cicular(Point px1, Point px2, Point px3)
{
    int x1, y1, x2, y2, x3, y3;
    int a, b, c, g, e, f;
    x1 = px1.x;
    y1 = px1.y;
    x2 = px2.x;
    y2 = px2.y;
    x3 = px3.x;
    y3 = px3.y;                                             
    e = 2 * (x2 - x1);
    f = 2 * (y2 - y1);
    g = x2*x2 - x1*x1 + y2*y2 - y1*y1;
    a = 2 * (x3 - x2);
    b = 2 * (y3 - y2);
    c = x3*x3 - x2*x2 + y3*y3 - y2*y2;
    X = (g*b - c*f) / (e*b - a*f);
    Y = (a*g - c*e) / (a*f - b*e);
    R = sqrt((X-x1)*(X-x1)+(Y-y1)*(Y-y1));
 
}
int main()
{
	Point point[4];
	while (~scanf("%d%d",&point[0].x,&point[0].y))
	{
		X = 0, Y = 0, R = 0;
		for(int i = 1; i <3; ++i)
		{
			scanf("%d%d",&point[i].x,&point[i].y);
		}
		cicular(point[0],point[1],point[2]);
		cout << X << Y;
	}
	
	
	
	return 0;
 } 
