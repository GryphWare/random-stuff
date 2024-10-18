#include <stdio.h>
#include <math.h>
 //khai bao bien
 int a1,b1,c1 ;
 int a2,b2,c2 ;
 float x,y ;
int main(){
	printf("nhap a1 = ",a1);
	scanf("%d",&a1);
	printf("nhap b1 = ",b1);
	scanf("%d",&b1);
	printf("nhap c1 = ",c1);
	scanf("%d",&c1);
	printf("nhap a2 = ",a2);
	scanf("%d",&a2);
	printf("nhap b2 = ",b2);
	scanf("%d",&b2);
	printf("nhap c2 = ",c2);
	scanf("%d",&c2);
	printf("phuong trinh co dang: \n%dx + %dy = %d \n%dx + %dy = %d",a1,b1,c1,a2,b2,c2);
int d=(a1*b2)-(a2*b1) ,dx=(c1*b2)-(c2*b1) ,dy=(a1*c2)-(a2*c1);
	x= dx/d;
	y= dy/d;
	printf("\nNghiem (x,y) cua phuong trinh la \n (%f,%f)",x,y);
	return 0 ; 
} 