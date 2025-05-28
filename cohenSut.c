#include<stdio.h>
#define TOP 8
#define BOTTOM 4
#define RIGHT 2
#define LEFT 1
#define INSIDE 0
float xmin = 50, ymin = 50, xmax = 100, ymax = 100;
int compute(float x, float y){
	int code = INSIDE;
	if(x < xmin)
 		code |= LEFT;
	if(x > xmax)
 		code |= RIGHT;
	if(y < ymin)
 		code |= BOTTOM;
	if(y > ymax)
 		code |= TOP;
	return code;
}
void cohen_sutherland(float x1, float y1, float x2, float y2){
	int code1 = compute(x1, y1);
	int code2 = compute(x2, y2);
	int accept = 0;
	int clipped = 0;
	while(1){
    		if((code1 == 0) && (code2 == 0)){
        			accept = 1;
        			printf("Trivial Accepted\n");
        			break;
    		} else if(code1 & code2){
        			printf("Trivial Rejection\n");
        			break;
    		}else{
        			clipped = 1;
        			int code_out;
        			float x, y;
        			code_out = code1 ? code1 : code2;
        	if(code_out & TOP){
            	x = x1 + ((x2-x1)*(ymax - y1))/(y2-y1);
            	y=ymax;
        	}else if(code_out & BOTTOM){
            	x = x1 + ((x2-x1) * (ymin - y1))/(y2-y1);
            	y = ymin;
        	}else if(code_out & RIGHT){
            	y = y1 + ((y2-y1) * (xmax - x1))/(x2-x1);
            	x = xmax;
        	}else if(code_out & LEFT){
            	y = y1 + ((y2-y1) * (xmin - x1))/(x2-x1);
            	x = xmin;
        	}
        			if(code_out == code1){
            		x1 = x;
            		y1 =y;
            		code1 = compute(x1,y1);
        		} else {
            		x2 = x;
            		y2 = y;
            		code2 = compute(x2,y2);
        		}
    		}
	}
	if(accept){
        		if(clipped)
printf("Line partially accepted from (%.2f, %.2f) to (%.2f, %.2f)\n", x1,y1,x2,y2);
else 
printf("Line completely accepted from (%.2f, %.2f) to (%.2f, %.2f)\n", x1,y1,x2,y2);
    	}
    	else printf("Line Rejected\n");
}
int main(){
	float x1, x2, y1, y2;
	printf("Enter Endpoints: ");
	scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
	cohen_sutherland(x1,y1,x2,y2);
}

