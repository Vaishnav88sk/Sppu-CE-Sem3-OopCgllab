#include<stdio.h>
#include<graphics.h>
#define ScreenWidthgetmaxx()
#define ScreenHeightgetmaxy()
#define GroundYScreenHeight*0.74
//Use *1 for full screen
int ldisp=0;
void DrawManAndUmbrella(int x,int ldisp)
{
//head
circle(x,GroundY-90,10);
line(x,GroundY-80,x,GroundY-30);
//hand
line(x,GroundY-70,x+10,GroundY-60);
line(x,GroundY-65,x+10,GroundY-55);
line(x+10,GroundY-60,x+20,GroundY-70);
line(x+10,GroundY-55,x+20,GroundY-70);
//legs
line(x,GroundY-30,x+ldisp,GroundY);
line(x,GroundY-30,x-ldisp,GroundY);
//umbrella
pieslice(x+20,GroundY-120,0,180,40);
line(x+20,GroundY-120,x+20,GroundY-70);
}
void Rain(int x)
{
inti,rx,ry;
for(i=0;i<400;i++)
{
rx=rand() % ScreenWidth;
ry=rand() % ScreenHeight;
if(ry<GroundY-4)
{
if(ry<GroundY-120 || (ry>GroundY-120 && (rx<x-20 || rx>x+60)))
line(rx,ry,rx+0.5,ry+4);
}
}
}
void main()
{
intgd=DETECT,gm,x=0;
//Change BGI directory according to yours
initgraph(&gd,&gm,“C:\\TurboC3\\BGI“);
//If you fill here (0) then you will show like flashlight
while(!kbhit())
{
//Draw Ground
line(1, GroundY,ScreenWidth,GroundY);
Rain(x);
// Increase value of(ldisp+4) for Fast moving leg 
ldisp=(ldisp+4)%20;
DrawManAndUmbrella(x,ldisp);
delay(75);
cleardevice();
//If insted of(x+1) you use(x+5) or Decreasing the value moving Fast
x=(x+4)%ScreenWidth;
}
closegraph();
getch();
}