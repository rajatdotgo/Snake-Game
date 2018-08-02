#include<dos.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>

//************* global variable *********//
static int px,py;
static int sz=6,score=0;
int snkx[100],snky[100];
char y='s';
//******* end of global variables *****//

//************* function prototype ********//
void food();
void foodGen();
void swap();
void border();
void automatic();
void checkHit();
void ate();
void stop();
void welcome();
//*********** end of function prototype *******//

void main()

{
   int gdriver=DETECT,gnode;
   initgraph(&gdriver,&gnode,"c:\\TURBOC3\\BGI");
   welcome();
   foodGen();
   for(int i=0;i<6;i++)
   {
   snkx[i]=60+(i*12);
   snky[i]=60;

   }

   do{
	if(!kbhit())
	  {
	     cleardevice();
	     checkHit();
	     ate();
	     setbkcolor(YELLOW);
	     food();
	     border();
	     automatic();
	     for(int j=0;j<sz;j++)
	     {
		setcolor(RED);
		circle(snkx[j],snky[j],6);
	     }
	     delay(80);
	 }

	 if( kbhit())

	 {
	    checkHit();
	    ate();
	    y=getch();

	    if(y=='p')
	    {
	       stop();
	    }
	    else if(y!='w'&&y!='d'&&y!='s'&&y!='a'&&y!='e')
	    {
	       stop();
	    }

	 }

   }while( y!='e')  ;

}


void foodGen()
{ int min=12;

  px=12*(rand()%50);
  py=12*(rand()%37);
  px+=min;
  py+=min;

}

void food()
{
   setcolor(GREEN);
   outtextxy(px,py,"*");

}


void swap()
{
    for(int i=sz-1;i>0;i--)
    {
      snky[i]=snky[i-1];
      snkx[i]=snkx[i-1];

    }
}

void border()
{
   char a1;
   setfillpattern(&a1,RED); bar(0,0,639,10);
   bar(0,0,10,479);
   bar(629,0,639,479);
   bar(0,469,639,479);
}

void automatic()
{
 switch(y)
 {
  case 'w':
     swap();
     snky[0]-=12;
     break;

  case 's':
      swap();
      snky[0]+=12;
      break;
  case 'a':
     swap();
     snkx[0]-=12;
     break;

  case 'd':
     swap();
     snkx[0]+=12;
     break;
 }
}
void checkHit()
{
     for(int l=0;l<sz-1;l++)
     {
	 for(int k=l+1;k<sz;k++)
	 {
	    if(snkx[l]==snkx[k]&&snky[l]==snky[k])
	    {
	       char msg[20];
	       cleardevice();
	       border();
	       setcolor(RED);
	       settextstyle(5,0,3);
	       sprintf(msg,"SCORE %d",score);
	       outtextxy(200,150,"GAME OVER");
	       outtextxy(350,150,msg);
	       delay(1200);
	       exit(0);

	    }
	 }
     }

     if(snkx[0]<=10||snkx[0]>=629||snky[0]<=10||snky[0]>=469)
     {
	       char msg[20];
	       cleardevice();
	       border();
	       setcolor(RED);
	       settextstyle(5,0,3);
	       sprintf(msg,"SCORE %d",score);
	       outtextxy(200,150,"GAME OVER");
	       outtextxy(350,150,msg);
	       delay(1200);
	       exit(0);


     }

}

void ate()
{
  if(snkx[0]==px&&snky[0]==py)
  {
	 sz+=1;
	 score+=1;
	 foodGen();
	 food();

  }
}
void stop()
{
 getch();
}
void welcome()
{
   border();
   setbkcolor(GREEN);
   setcolor(RED);
   settextstyle(4,0,4);
   outtextxy(230,150,"Snake");
   outtextxy(350,200,"Game");
   settextstyle(0,0,1);
   delay(900);
}

