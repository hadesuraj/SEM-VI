#include<stdio.h>
void circlePoint(int x, int y){
	printf("%d, %d\n", x, y);
	printf("%d, %d\n", y, x);
	printf("%d, -%d\n", y, x);
	printf("%d, -%d\n", x, y);
	printf("-%d, -%d\n", x,y);
	printf("-%d, -%d\n", y,x);
	printf("-%d, %d\n", y, x);
	printf("-%d, %d\n", x, y);
}
void midpointCircle(int radius){
	int x = 0;
	int y = radius;
	int d = 1-radius;
	circlePoint(x,y);
	while(x<y){
    		if(d<0){
        			d+=2*x+1;
    		} else {
        			d+=2*(x-y)+1;
        			y--;
    		}
    		x++;
    		circlePoint(x,y);
	}
}
int main(){
	int radius;
	printf("Enter radius: ");
	scanf("%d", &radius);
	printf("Midpoint Circle Algorithm Output:\n");
	midpointCircle(radius);
	return 0;
}

