#include<stdlib.h>
#include<stdio.h>
void ellipsePoint(int x, int y){
	if(x == 0){
    		printf("%d, %d\n", x,y);
    		printf("%d, -%d\n", x,y);
	} else if(y == 0) {
    	printf("%d, %d\n", x,y);
    		printf("-%d, %d\n", x,y);
	} else {
    		printf("%d, %d\n", x,y);
    		printf("-%d, %d\n", x,y);
    		printf("%d, -%d\n", x,y);
    		printf("-%d, -%d\n", x,y);
	}
}
void midEllipse(int a, int b){
	int x = 0;
	int y = b;
	int a2 = a * a;
	int b2 = b * b;
	float d1 = b2 - (a2 * b) + (0.25 * a2);
	int dx = 2 * b2 * x;
	int dy = 2 * a2 * y;
	while(dx<dy){
    		ellipsePoint(x,y);
    		if(d1<0){
        			x++;
        			dx += 2 * b2;
        			d1 += dx + b2;
    		} else {
        			x++;
        			y--;
        			dx += 2 * b2;
        	dy -= 2 * a2;
        	d1 += dx - dy + b2;
    		}
	}
	float d2 = (b2 * (x + 0.5) * (x + 0.5)) + (a2 * (y - 1) * (y - 1)) - (a2 * b2);
	while(y>=0){
    	ellipsePoint(x,y);
    	if(d2>0){
        		y--;
        	dy -= 2 * a2;
        	d2 += a2 - dy;
    } else {
        	y--;
        	x++;
        	dx += 2 * b2;
        	dy -= 2 * a2;
        	d2 += dx - dy + a2;
    		}
	}
}
int main(){
	int a, b;
	printf("Enter horizontal radius(a): ");
	scanf("%d", &a);
	printf("Enter horizontal radius(b): ");
	scanf("%d", &b);
	printf("Midpoint Ellipse Algorithm Output:\n");
	midEllipse(a,b);
	return 0;
}

