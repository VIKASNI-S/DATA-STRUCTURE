//Menu Driven Program to calulate the area of square, cube, rectangle,cuboid

#include<cstdio>
#include<stdlib.h>

class Geometric_Shapes{
private:
int side;
int length;
int breadth;
int height;
public:
int sq_area(int side){
return (side*side);
}
int cub_area(int side){
return(6*side*side);
}
int rec_area(int length, int breadth){
    return(length*breadth);
}
int cubo_area(int length, int breadth, int height){
    return(2*((length*breadth)+(length*height)+(height*breadth)));
}

};


int main(){
int choice;
Geometric_Shapes shape;
int area;
do{
printf("\nMenu Driven Program: \n1)Square \n 2)Cube\n 3)Rectangle\n 4)Cuboid\n 5)Exit\n");
scanf("%d", &choice);
switch(choice){
case 1:
int sq_side;
printf("Enter the side: ");
scanf("%d" ,&sq_side);
area=shape.sq_area(sq_side);
printf("Area of Square of length %d is %d sq units",sq_side,area);
break;
case 2:
int cub_side;
printf("Enter the side: ");
scanf("%d" ,&cub_side);
area=shape.cub_area(cub_side);
printf("Total Surface Area of cube of length %d is %d sq units",cub_side,area);
break;
case 3:
int rec_len;
int rec_bre;
printf("Enter the length of the rectangle: ");
scanf("%d", &rec_len);
printf("Enter the breadth of the rectangle: ");
scanf("%d", &rec_bre);
area=shape.rec_area(rec_len,rec_bre);
printf("Area of rectangle of length %d and breadth %d is %d sq units",rec_len,rec_bre,area);
break;
case 4:
int cubo_len;
int cubo_bre;
int cubo_hei;
printf("Enter the length of the cuboid: ");
scanf("%d",&cubo_len);
printf("Enter the breadth of the cuboid: ");
scanf("%d",&cubo_bre);
printf("Enter the height of the cuboid: ");
scanf("%d",&cubo_hei);
area=shape.cubo_area(cubo_len,cubo_bre,cubo_hei);
printf("Total Surface Area of a Cuboid with %d length, %d breadth and %d height is %d sq unit. ", cubo_len,cubo_bre,cubo_hei,area);
break;
case 5:
printf("Exiting program....");
return 0;
default:
printf("Enter a valid choice.\n");
break;
}
}while(choice!=5);
}
