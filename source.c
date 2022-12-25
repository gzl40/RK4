#include<stdio.h>
#include<math.h>

#include <graphics.h>
#include <conio.h>

#define G 6.67
#define p 0.1
double t=0;

/**
struct Planet{
0	double vx;
1	double vy;
2	double x;
3	double y;
4	double mass;
5	int fix;
6	double K1;
7	double L1;
8	double K2;
9	double L2;
10	double K3;
11	double L3;
12	double K4;
13	double L4;
};
struct Planet planet[4]={{123,32,43,2,5.965E24,0},{214,332,3844039,2,1023,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
**/

double planet[4][14]= {{0,0,0,0,59650,0},{0,1020,384,0,7342,0},{},{}};

double ffunc(double t,double x,double v){ //时间，原函数，一阶导
	return v;                
}

double gfunc(int i,int x_axis,int s, double h){ //求二阶导，即加速度的函数；（对象在数组中的序号，计算方向x轴还是y轴，rk法公式中的预测步，步长）
	int j;
	double buff=0;
	for(j=0;j<4;j++){
		if(x_axis==1){//x轴向计算
			if(fabs(planet[i][2]-planet[j][2])<p){continue;}
			if(s==1){
				if(planet[i][2]-planet[j][2]>0){buff-=G*planet[i][4]/pow(planet[i][2]-planet[j][2],2);}
				if(planet[i][2]-planet[j][2]==0){buff+=0;}
				if(planet[i][2]-planet[j][2]<0){buff+=G*planet[i][4]/pow(planet[i][2]-planet[j][2],2);}
			}
			if(s==2){
				if(planet[i][2]+h*planet[i][6]/2-planet[j][2]-h*planet[j][6]/2>0){buff-=G*planet[i][4]/pow(planet[i][2]+h*planet[i][6]/2-planet[j][2]-h*planet[j][6]/2,2);}
				if(planet[i][2]+h*planet[i][6]/2-planet[j][2]-h*planet[j][6]/2==0){buff+=0;}
				if(planet[i][2]+h*planet[i][6]/2-planet[j][2]-h*planet[j][6]/2<0){buff+=G*planet[i][4]/pow(planet[i][2]+h*planet[i][6]/2-planet[j][2]-h*planet[j][6]/2,2);}			
			}
			if(s==3){
				if(planet[i][2]+h*planet[i][8]/2-planet[j][2]-h*planet[j][8]/2>0){buff-=G*planet[i][4]/pow(planet[i][2]+h*planet[i][8]/2-planet[j][2]-h*planet[j][8]/2,2);}
				if(planet[i][2]+h*planet[i][8]/2-planet[j][2]-h*planet[j][8]/2==0){buff+=0;}
				if(planet[i][2]+h*planet[i][8]/2-planet[j][2]-h*planet[j][8]/2<0){buff+=G*planet[i][4]/pow(planet[i][2]+h*planet[i][8]/2-planet[j][2]-h*planet[j][8]/2,2);}
			}
			if(s==4){
				if(planet[i][2]+h*planet[i][10]-planet[j][2]-h*planet[j][10]>0){buff-=G*planet[i][4]/pow(planet[i][2]+h*planet[i][10]-planet[j][2]-h*planet[j][10],2);}
				if(planet[i][2]+h*planet[i][10]-planet[j][2]-h*planet[j][10]==0){buff+=0;}
				if(planet[i][2]+h*planet[i][10]-planet[j][2]-h*planet[j][10]<0){buff+=G*planet[i][4]/pow(planet[i][2]+h*planet[i][10]-planet[j][2]-h*planet[j][10],2);}
			}
		}
		if(x_axis==0){//y轴向计算
			if(fabs(planet[i][3]-planet[j][3])<p){continue;}
			if(s==1){
				if(planet[i][3]-planet[j][3]>0){buff-=G*planet[i][4]/pow(planet[i][3]+-planet[j][3],2);}
				if(planet[i][3]-planet[j][3]==0){buff+=0;}
				if(planet[i][3]-planet[j][3]<0){buff+=G*planet[i][4]/pow(planet[i][3]-planet[j][3],2);}
			}
			if(s==2){
				if(planet[i][3]+h*planet[i][6]/2-planet[j][3]-h*planet[j][6]/2>0){buff-=G*planet[i][4]/pow(planet[i][3]+h*planet[i][6]/2-planet[j][3]-h*planet[j][6]/2,2);}
				if(planet[i][3]+h*planet[i][6]/2-planet[j][3]-h*planet[j][6]/2==0){buff+=0;}
				if(planet[i][3]+h*planet[i][6]/2-planet[j][3]-h*planet[j][6]/2<0){buff+=G*planet[i][4]/pow(planet[i][3]+h*planet[i][6]/2-planet[j][3]-h*planet[j][6]/2,2);}			
			}
			if(s==3){
				if(planet[i][3]+h*planet[i][8]/2-planet[j][3]-h*planet[j][8]/2>0){buff-=G*planet[i][4]/pow(planet[i][3]+h*planet[i][8]/2-planet[j][3]-h*planet[j][8]/2,2);}
				if(planet[i][3]+h*planet[i][8]/2-planet[j][3]-h*planet[j][8]/2==0){buff+=0;}
				if(planet[i][3]+h*planet[i][8]/2-planet[j][3]-h*planet[j][8]/2<0){buff+=G*planet[i][4]/pow(planet[i][3]+h*planet[i][8]/2-planet[j][3]-h*planet[j][8]/2,2);}
			}
			if(s==4){
				if(planet[i][3]+h*planet[i][10]-planet[j][3]-h*planet[j][10]>0){buff-=G*planet[i][4]/pow(planet[i][3]+h*planet[i][10]-planet[j][3]-h*planet[j][10],2);}
				if(planet[i][3]+h*planet[i][10]-planet[j][3]-h*planet[j][10]==0){buff+=0;}
				if(planet[i][3]+h*planet[i][10]-planet[j][3]-h*planet[j][10]<0){buff+=G*planet[i][4]/pow(planet[i][3]+h*planet[i][10]-planet[j][3]-h*planet[j][10],2);}
			}

		}
	}
	return buff;
}

double rk4(double h){
	int i;
	for(i=0;i<4;i++){
		planet[i][6]=ffunc(t,planet[i][2],planet[i][0]);
		planet[i][7]=gfunc(i,1,1,h);}
	for(i=0;i<4;i++){
		planet[i][8]=ffunc(t+h/2,planet[i][2]+h*planet[i][6],planet[i][0]+h*planet[i][7]/2);
		planet[i][9]=gfunc(i,1,2,h);}
	for(i=0;i<4;i++){
		planet[i][10]=ffunc(t+h/2,planet[i][2]+h*planet[i][8]/2,planet[i][0]+h*planet[i][9]/2);
		planet[i][11]=gfunc(i,1,3,h);}
	for(i=0;i<4;i++){
		planet[i][12]=ffunc(t+h,planet[i][2]+h*planet[i][10],planet[i][0]+h*planet[i][11]);
		planet[i][13]=gfunc(i,1,4,h);}
	for(i=0;i<4;i++){
		planet[i][2]=(planet[i][6]+2*planet[i][8]+2*planet[i][10]+planet[i][12])*h/6;	
		planet[i][0]+=(planet[i][7]+2*planet[i][9]+2*planet[i][11]+planet[i][13])*h/6;
	//	planet[i][6]=planet[i][7]=planet[i][8]=planet[i][9]=planet[i][10]=planet[i][11]=planet[i][12]=planet[i][13]=0;
	}

	for(i=0;i<4;i++){
		planet[i][6]=ffunc(t,planet[i][3],planet[i][1]);
		planet[i][7]=gfunc(i,0,1,h);}
	for(i=0;i<4;i++){
		planet[i][8]=ffunc(t+h/2,planet[i][3]+h*planet[i][6],planet[i][1]+h*planet[i][7]/2);
		planet[i][9]=gfunc(i,0,2,h);}
	for(i=0;i<4;i++){
		planet[i][10]=ffunc(t+h/2,planet[i][3]+h*planet[i][8]/2,planet[i][1]+h*planet[i][9]/2);
		planet[i][11]=gfunc(i,0,3,h);}
	for(i=0;i<4;i++){
		planet[i][12]=ffunc(t+h,planet[i][3]+h*planet[i][10],planet[i][1]+h*planet[i][11]);
		planet[i][13]=gfunc(i,0,4,h);}

	for(i=0;i<4;i++){
		planet[i][3]+=(planet[i][6]+2*planet[i][8]+2*planet[i][10]+planet[i][12])*h/6;
		planet[i][1]+=(planet[i][7]+2*planet[i][9]+2*planet[i][11]+planet[i][13])*h/6;
//	planet[i][6]=planet[i][7]=planet[i][8]=planet[i][9]=planet[i][10]=planet[i][11]=planet[i][12]=planet[i][13]=0;
	}
	return 0;
}

int main(){

		initgraph(1024, 600);	
	while(1){
		rk4(0.01);
		printf("%lf %lf %lf %lf\n",planet[0][0],planet[0][1],planet[1][0],planet[1][1]);
		setcolor(GREEN);
		setfillcolor(GREEN);
		fillcircle((int)planet[0][2]/1+500, (int)planet[0][3]/1+300, 2);
		setcolor(BLUE);
		setfillcolor(BLUE);
		fillcircle((int)planet[1][2]/1+500, (int)planet[1][3]/1+300, 2);
	}
	return 0;
}
