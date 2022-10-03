/* This program is written by Minji Park.
Student ID: 2021311928 */

#include <stdio.h>

int main()
{
	int choice;
	float radius;
	float width;
	float height;
	float area; //Declare variable
	
	printf("(1) Circle\n(2) Rectangle\n(3) Triangle\n");
	printf("Enter the shape: ");
	scanf("%d", &choice);
	if (choice == 1) { //shape=circle
		printf("Enter the radius of the circle: ");
		scanf("%f", &radius);
		printf("The area of the circle is %f", radius*radius*3.14);
	}
	else if (choice == 2) {//shape=rectangle
		printf("Enter the width of the rectangle: ");
		scanf("%f", &width);
		printf("Enter the height of the rectangle: ");
		scanf("%f", &height);
		area=width*height;
		printf("The area of the rectangle is %f", area);
	}
	else if (choice == 3) {//shape=triangle
		printf("Enter the width of the triangle: ");
		scanf("%f", &width);
		printf("Enter the height of the triangle: ");
		scanf("%f", &height);
		area=(width*height)/2;
		printf("The area of the Triangle is %f", area); //소숫점 자리를 맞추라는 별도의 말이 없어서 그냥 %f로 했습니다. 
	}
}
