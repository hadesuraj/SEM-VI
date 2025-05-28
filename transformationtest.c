#include<stdio.h>
#include<math.h>
#define PI 3.14
void multiplyMatrix(float m[3][3], float point[3]){
	float result[3] = {0};
	for(int i = 0; i < 3; i++)
    		for(int j = 0; j < 3; j++)
        		result[i] += m[i][j] * point [j];
        		printf("Transformed Point: %.2f, %.2f\n", result[0],result[1]);
}
int main(){
	float x, y;
	printf("Enter coordinates(x,y): ");
	scanf("%f %f", &x, &y);
	int choice;
	printf("Choose Transformation: \n");
	printf("1. Translation\n2. Scaling\n3. Rotation\n4. Shearing\n");
	scanf("%d", &choice);
	float transform[3][3] = {0};
	float point[3] = {x,y,1};
	switch(choice){
    	case 1: {
        	float tx, ty;
        	printf("Enter translation(tx,ty): ");
        	scanf("%f %f", &tx, &ty);
        	transform[0][0] = 1;
        	transform[0][2] = tx;
        	transform[1][1] = 1;
        	transform[1][2] = ty;
        	transform[2][2] = 1;
        	break;
    	}
    	case 2: {
        	float sx, sy;
        	printf("Enter translation(sx,sy): ");
        	scanf("%f %f", &sx, &sy);
        	transform[0][0] = sx;
        	transform[1][1] = sy;
        	transform[2][2] = 1;
        	break;
    	}
    	case 3: {
        	float angle;
        	printf("Enter rotation angle in degrees: ");
        	scanf("%f", &angle);
        	float rad = angle * PI/180;
        	transform[0][0] = cos(rad);
        	transform[0][1] = -sin(rad);
        	transform[1][0] = sin(rad);
        	transform[1][1] = cos(rad);
        	break;
    	}
    	case 4: {
        	float shx, shy;
        	printf("Enter Shearing (shx,shy): ");
        	scanf("%f %f", &shx, &shy);
        	transform[0][0] = 1;	 
        	transform[0][1] = shx;	 
        	transform[1][0] = shy;	 
        	transform[1][1] = 1;
        	transform[2][2] = 1;
        	break;     	 
    	}
    	default:
        	printf("Invalid Choice\n");
        	return 1;
	}
	multiplyMatrix(transform, point);
	return 0;
}

