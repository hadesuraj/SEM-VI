#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#define ROUND(a) ((int)(a+0.5))
void lineDDA (int xa, int ya, int xb, int yb){
	int dx = xb - xa;
	int dy = yb - ya;
	int steps;
	float xIncr, yIncr;
	float x = xa, y = ya;
	if (abs(dx)>abs(dy)) steps = abs(dx);
	else steps = abs(dy);    
	xIncr = dx/(float)steps;
	yIncr = dy/(float)steps;    
	printf("DDA Line Points:\n");
	printf("(%d, %d)\n", ROUND(x),ROUND(y));
	for(int i = 0; i < steps; i++){
    	x += xIncr;
    	y += yIncr;
    	printf("(%d, %d)\n", ROUND(x),ROUND(y));
	}
}
int main(){
	int xa,ya,yb,xb;    
	printf("Enter coordinates of start point: ");
	scanf("%d %d", &xa,&ya);
	printf("Enter coordinates of end point: ");
	scanf("%d %d", &xb,&yb);   
	lineDDA(xa,ya,xb,yb);
	return 0;
}

