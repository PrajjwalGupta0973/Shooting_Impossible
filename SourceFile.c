
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include <process.h>
#include <string.h>



		void main()


{
float i=1,ym /*(maximum of y axis)*/,xmd /*(middle of the x axis)*/ ,ymd /*(middle of the y axis)*/,x3,xc,yc,hit=0,missfire=0,totalfire=1,accuracy=0;
int tempy,tempx,tempx1,tempy1,dly=15 /*(delay in ball movement and will be used in level increment. dly inversly proportionl to speed)*/, dly_dec=0;
 char score[10];
		// Entering into graphics mode
int gd=DETECT,gm;
char ch;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
		// graphic initialization done

cleardevice();
ymd=getmaxy()/2;
xmd=getmaxx()/2;
ym=getmaxy();

settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
outtextxy(xmd/8,ymd/4+40,"How to play and quit the game :");
settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
outtextxy(xmd/8,((ymd/4)+80),">When the ball comes into the target box, press 'H' to shoot.");
outtextxy(xmd/8,((ymd/4)+100),">You will get 1 point per hit.");
outtextxy(xmd/8,((ymd/4)+120),">Press 'Q' to quit.");
outtextxy(xmd/2,((ymd/4)+160),"Now press 'ENTER' to start the game.");
getch();
cleardevice();

			//Making Background

setbkcolor(BROWN);

		    //target box


setcolor(WHITE);
rectangle(xmd-22,3,xmd+22,37);
setfillstyle(SOLID_FILL,WHITE);
floodfill(xmd,16,WHITE);
setcolor(GREEN);
rectangle(xmd-20,5,xmd+20,35);
setfillstyle(SOLID_FILL,RED);
floodfill(xmd,16,GREEN);
setcolor(BLUE);
rectangle(xmd-22,10,xmd+22,30);

			//erasing mid part of target box

setfillstyle(SOLID_FILL,BROWN);
floodfill(xmd,20,BLUE);
setcolor(BROWN);
rectangle(xmd-22,10,xmd+22,30);

  //erasing complete


	//target box end

			//gun
	      //gun box base boundary
setcolor(BLUE);
rectangle(xmd-100,ym-50,xmd+100,ym);
setfillstyle(SOLID_FILL,GREEN);
floodfill(xmd,ym-40,BLUE);
			//box's base boundary done

			//Middle red eclipse


setcolor(BLUE);
ellipse(xmd,ym-45,0,360,4,6);
setfillstyle(SOLID_FILL,RED);
floodfill(xmd,ym-45,BLUE);

setcolor(BLUE);
ellipse(xmd,ym-30,0,360,4,6);
setfillstyle(SOLID_FILL,RED);
floodfill(xmd,ym-30,BLUE);

setcolor(BLUE);
ellipse(xmd,ym-15,0,360,4,6);
setfillstyle(SOLID_FILL,RED);
floodfill(xmd,ym-15,BLUE);

			//Middle red eclipse completed

				//Side upper eclipses

setcolor(BLUE);
ellipse(xmd-50,ym-30,0,360,10,5);
setfillstyle(SOLID_FILL,YELLOW);
floodfill(xmd-50,ym-30,BLUE);

setcolor(BLUE);
ellipse(xmd+50,ym-30,0,360,10,5);
setfillstyle(SOLID_FILL,YELLOW);
floodfill(xmd+50,ym-30,BLUE);
				//side upper eclipses completed

				//Side lower eclipses

setcolor(BLUE);
ellipse(xmd-70,ym-10,0,360,10,5);
setfillstyle(SOLID_FILL,BLUE);
floodfill(xmd-70,ym-10,BLUE);

setcolor(BLUE);
ellipse(xmd+70,ym-10,0,360,10,5);
setfillstyle(SOLID_FILL,BLUE);
floodfill(xmd+70,ym-10,BLUE);
				//side lower eclipses completed

				//Increasing thickness of boundary

for(i=0,tempx=xmd-100+1,tempy=ym-50+1,tempx1=xmd+100-1;i<3;i++)
{
setcolor(RED);
line(tempx,tempy,tempx1,tempy);
tempy++;
}
for(i=0,tempx=xmd-100+1,tempy=ym-50+1,tempy1=ym;i<3;i++)
{
setcolor(RED);
line(tempx,tempy,tempx,tempy1);
tempx++;
}
for(i=0,tempx=xmd+100-1,tempy=ym-50+1,tempy1=ym;i<3;i++)
{
setcolor(RED);
line(tempx,tempy,tempx,tempy1);
tempx--;
}


				//thickness done

				//corner arc

setcolor(RED);                       //left corner arc
arc(xmd-100+3,ym-50+3,270,0,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(xmd-100+4,ym-50+4,RED);

setcolor(RED);                       //right corner arc
arc(xmd+100-3,ym-50+3,180,270,15);
setfillstyle(SOLID_FILL,BLUE);
floodfill(xmd+100-4,ym-50+4,RED);

				//corner arc done

				//Tube

setcolor(BLUE);
ellipse(xmd,ym-40-50,0,360,10,5);
setfillstyle(SOLID_FILL,BLUE);
floodfill(xmd,ym-40-50,BLUE);

setcolor(BLUE);
rectangle(xmd-10,ym-40-50,xmd+10,ym-50);
setfillstyle(SOLID_FILL,RED);
floodfill(xmd,ym-20-50,BLUE);   //Tube done

				// Side supporter

arc(xmd-100,ym,90,180,25);   //right side
arc(xmd-100,ym,90,180,20);
setfillstyle(SOLID_FILL,BLUE);
floodfill(xmd-100-1,ym-20-1,BLUE);
setfillstyle(SOLID_FILL,RED);
floodfill(xmd-100-1,ym-20+1,BLUE);

				//left side
arc(xmd+100,ym,0,90,25);
arc(xmd+100,ym,0,90,20);
setfillstyle(SOLID_FILL,BLUE);
floodfill(xmd+100+1,ym-20-1,BLUE);
setfillstyle(SOLID_FILL,RED);
floodfill(xmd+100+1,ym-20+1,BLUE);

				//side supporters done

					//right side text information
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
setcolor(WHITE);
outtextxy(getmaxx()-150,100,"Press 'H' for HIT.");
outtextxy(getmaxx()-150,130,"Press 'Q' for QUIT.");
setcolor(WHITE);
outtextxy(getmaxx()-150,160,"Score : ");

				//gun end


settextstyle(DEFAULT_FONT,HORIZ_DIR,2);

				//Game starts


do
{
xc=0;
yc=20;
while(xc<=xmd+100)
{

	if(kbhit())           // detecting whether any key is pressed
	{
	   ch=getch();
	   if(ch=='h')
		 {
			//gun activties
	setcolor(BLUE);
	ellipse(xmd-50,ym-30,0,360,10,5);
	setfillstyle(SOLID_FILL,RED);
	floodfill(xmd-50,ym-30,BLUE);

	setcolor(BLUE);
	ellipse(xmd+50,ym-30,0,360,10,5);
	setfillstyle(SOLID_FILL,RED);
	floodfill(xmd+50,ym-30,BLUE);

	setcolor(RED);
	rectangle(xmd-10,38,xmd+10,ym-40-50-5);
	setfillstyle(SOLID_FILL,RED);
	floodfill(xmd,39,RED);
	delay(100);

	setcolor(BROWN);
	rectangle(xmd-10,38,xmd+10,ym-40-50-5);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(xmd,39,BROWN);

	setcolor(BLUE);
	ellipse(xmd+50,ym-30,0,360,10,5);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(xmd+50,ym-30,BLUE);

	setcolor(BLUE);
	ellipse(xmd-50,ym-30,0,360,10,5);
	setfillstyle(SOLID_FILL,YELLOW);
	floodfill(xmd-50,ym-30,BLUE);


	 //gun activities end



				     //collision detected


				if((xc>(xmd-22-10))&&(xc<(xmd+22+10)))
				{
					// increasing levels by decreasing dly and cheering up
				dly_dec=(int)hit;
					if((dly_dec%3)==0)
					{
						if(dly_dec!=0)
						{
						dly=dly-3;
							if(dly<9)
							{   setcolor(WHITE);
							settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
							outtextxy(xmd+100,ymd+100,"You can do it.Common!");
							}
						}
					}
				//Creating sound
				sound(200);
				delay(100);
				nosound();      //sound off
					settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
					setcolor(BROWN);
					//writing text with same backgroung color(BROWN) to clear the old text
					outtextxy(0,ymd+20,"OOPS MISSED");
					setcolor(BROWN);
					outtextxy(0,ymd,"Wohoo!it's a HIT");
					// text clearing done

					delay(50);
					setcolor(WHITE);
					outtextxy(0,ymd,"Wohoo!it's a HIT");
					setcolor(5);
					circle(xc,yc,8);
					setfillstyle(SOLID_FILL,MAGENTA);
					floodfill(xc,yc,MAGENTA);
						delay(200);
					hit++;
					       // printing score :
					sprintf(score,"%d",((int)(hit-1)));
					setcolor(BROWN); //to clears old score
					outtextxy(getmaxx()-50,160,((const char far*)(score)));  // clearing old score
					sprintf(score,"%d",(int)hit);
					setcolor(WHITE);   //latest score score
					outtextxy(getmaxx()-50,160,((const char far*)(score))); //printing latest score

					//score printed
				      }

			else
			{                 //generating sound
			sound(500);
			delay(100);
			nosound();         //sound generated

					 // clearing old text
			setcolor(BROWN);
			outtextxy(0,ymd,"Wohoo!it's a HIT");
			setcolor(BROWN);
			outtextxy(0,ymd+20,"OOPS MISSED");
					// old text cleared
			delay(50);
			setcolor(YELLOW);
			outtextxy(0,ymd+20,"OOPS MISSED");
			setcolor(WHITE);
			circle(xc,yc,8);
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(xc,yc,WHITE);
			missfire++;
			delay(200);
			}

		}
	 else
		if((ch=='n')||ch=='q' || ch=='N'||ch=='Q')
		{
		setcolor(BROWN);
		outtextxy(0,ymd+20,"OOPS MISSED");
		setcolor(BROWN);
		outtextxy(0,ymd,"Wohoo!it's a HIT");
		 totalfire=hit+missfire;
		 if(totalfire==0)
		 {
		 totalfire=1;     //To eliminate 0/0
		 }
		 accuracy=(hit/totalfire)*100;
		 printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tSCORE : %d\n\t\t\t\tACCURACY : %f %",((int)hit),accuracy);
		 getch();
		 exit(1);
		 }
	}

setcolor(WHITE);
circle(xc,yc,10);
setfillstyle(SOLID_FILL,WHITE);
floodfill(xc,yc,WHITE);
				//   speed decided by dly
				delay(dly);
				//
setcolor(BLUE);
circle(xc,yc,10);
setfillstyle(SOLID_FILL,BROWN);
floodfill(xc,yc,BLUE);
setcolor(BROWN);
circle(xc,yc,10);
xc=xc+6;
}
i++;
} while(i);
getch();
closegraph();
}
