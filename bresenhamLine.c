#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int midPoint(int x1, int y1, int x2, int y2){
	int dx = x2-x1;
	int dy = y2-y1;
	int d = 2*(dy-dx);
	int eIncr = 2*dy;
	int neIncr = 2*(dy-dx);
	int x = x1;
	int y = y1;
	printf("Line Coordinates Are: ");
	printf("%d,%d\n",x,y);
	while(x<x2){
    	if(d<=0){
        	d+=eIncr;
        	x++;
    	}else{
        	d+=neIncr;
        	x++;
        	y++;
    	}
    	printf("%d,%d\n",x,y);
	}
	return 0;
}
int main(){
	int x1,y1,x2,y2;
	printf("Enter starting point: ");
	scanf("%d %d", &x1,&y1);
	printf("Enter ending point: ");
	scanf("%d %d", &x2,&y2);
	if(x1>x2){
    	int temp = x1;
    	x1 = x2;
    	x2 = temp;
    	temp = y1;
    	y1 = y2;
    	y2 = temp;
	}
	midPoint(x1,y1,x2,y2);
	return 0;
}

