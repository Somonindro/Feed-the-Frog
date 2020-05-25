# include "iGraphics.h"
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>

char str5[200];
char str6[200];
char str7[200];
char str8[100];
char str[100];

/*  str for changing background
    str6 for music
    str5 for first animation
    str7 for credit animation
    str8 for expression animation

*/

char str1[10][1000];//control the writing inside the box

int x,y;
int g=38,h=0;
int g1,h1; //to start credit option
int k,k1,k2,k3,k4; //to vanish writing
int l;//To rotate expression animation
int mode;
int trigger;//Draw the rectangle of the name box

int axis[50];//Draw diff object
int len;//User name er control

int c,c1,c2,c3,c4;//To control life
int d,d1,d2,d3,d4;//Good,Bad,Excellent controlling er jonno

int lev;//To make counter[2] zero
int counter[100];//100 flags to control inputs

int lvl2_j;
int lvl3_i;
int lvl4_i;
int lvl5_i1;
int lvl5_i2;
int lvl5_i3;

double theta,theta1,theta2;
double p,q;
double p1,q1;
double p2,q2;
double p3,q3;
double p4,q4;
double angle,increase;
double b,a;
double angle1,increase1;
double b1,a1;
double angle2,increase2;
double b2,a2;


void install(void);
void drawbox(void);
void drawlevel(void);

void level_1(void);
void level_2(void);
void level_3(void);
void level_4(void);
void level_5(void);

void lvl_1(void);
void lvl_2(void);
void lvl_3(void);
void lvl_4(void);
void lvl_5(void);

void drawcontinue(void);
void gameover(void);


void keypress(int x,int y)
{
    if(x>=740 && x<=995 && y>=255 && y<=305 && counter[0]==0 && counter[4]==0 && counter[61]==0)//Enter the new game
    {
        strcpy(str,"2.bmp");
        counter[0]=1;
    }

    if(x>=765 && x<=955 && y>=185 && y<=235 && counter[0]==0 && counter[61]==0)//enter credit option
    {

        h1=1;
        counter[4]=1;

    }

    if(x>=790 && x<=930 && y>=115 && y<=165 && counter[0]==0 && counter[4]==0  && counter[61]==0)//Exit's the whole program
    {
        exit(0);
    }

    if(x>=0 && y>=0 && counter[1]==0)
    {
        mode=1;
        counter[1]=1;//Stopping From Multiple input
    }

    //to enter level 1
    if(x>=50 && x<=215 && y>=40 && y<=95 && counter[2]==1 && counter[29]==0 && counter[3]==0 && counter[6]==0 && counter[7]==0 && counter[17]==0 && counter[22]==0 && counter[30]==0 && counter[56]==0)
    {
        //level 1 starts
        strcpy(str,"5.bmp");
        counter[3]=1;
    }

    //pause option in all level
    if(x>=60 && x<=130 && y>=510 && y<=545 && (counter[3]==1||counter[7]==1||counter[17]==1||counter[22]==1||counter[30]==1))
    {
        strcpy(str,"19.bmp");
        counter[29]=1;
        if(counter[3]==1) //for level 1
        {
            iPauseTimer(0);
            counter[3]=0;
            counter[6]=1;//notun counter
            counter[16]=0;
        }

        if(counter[7]==1)//for level 2
        {
            counter[7]=0;
            counter[8]=1;
            counter[39]=0;
        }

        if(counter[17]==1)//for level 3
        {
            iPauseTimer(2);
            counter[17]=0;
            counter[20]=1;
        }

        if(counter[22]==1)//for level 4
        {
            iPauseTimer(3);
            counter[22]=0;
            counter[23]=1;
        }

        if(counter[30]==1)//for level 5
        {
            iPauseTimer(5);
            counter[30]=0;
            counter[35]=1;
        }
    }

    //countinue te no option
    if(x>=500 && x<=580 && y>=350 && y<=400 && (counter[6]==1 || counter[8]==1||counter[20]==1||counter[23]==1||counter[35]==1))
    {
        exit(0);
    }

    //countinue te yes option
    if(x>=350 && x<=430 && y>=350 && y<=400 && (counter[6]==1||counter[8]==1||counter[20]==1||counter[23]==1||counter[35]==1))
    {
        if(counter[6]==1)
        {
            strcpy(str,"5.bmp");
            counter[3]=1;
            counter[6]=0;
        }

        if(counter[8]==1)
        {
            strcpy(str,"24.bmp");
            counter[7]=1;
            counter[8]=0;
        }

        if(counter[20]==1)
        {
            strcpy(str,"7.bmp");
            counter[17]=1;
            counter[20]=0;
        }

        if(counter[23]==1)
        {
            strcpy(str,"8.bmp");
            counter[22]=1;
            counter[23]=0;
        }

        if(counter[35]==1)
        {
            strcpy(str,"24.bmp");
            counter[30]=1;
            counter[35]=0;
        }
    }

    if(x>=600 && x<=700 && y>=85 && y<=130 && counter[3]==1 ) //level 1 er switch press korle
    {
        axis[5]=axis[6]=axis[7]=axis[8]=0;
        counter[12]=1;
    }

    if(x>=850 && x<=950 && y>=65 && y<=110 && counter[7]==1) //level 2 er switch press korle
    {
        axis[33]=axis[34]=axis[35]=axis[36]=0;
        counter[36]=1;
    }

    if(x>=620 && x<=720 && y>=70 && y<=115 && counter[17]==1) //level 3 er switch press korle
    {
        counter[18]=1;
        axis[13]=p2;
        axis[14]=q2;
    }

    if(x>=620 && x<=720 && y>=70 && y<=115 && counter[22]==1) //level 4 er switch press korle
    {
        counter[24]=1;
        axis[19]=axis[20]=axis[21]=axis[22]=0;
    }

    if(x>=870 && x<=970 && y>=70 && y<=115 && counter[30]==1) //level 5 er switch press korle
    {
        counter[31]=counter[32]=1;

    }

    if(x>=350 && x<=500 && y>=85 && y<=135 && (counter[15]==1 || counter[19]==1 || counter[28]==1 || counter[34]==1 || counter[40]==1 || counter[33]==1))//gameover a replay
    {
        install();//Replay the game

    }

    if(x>=550 && x<=700 && y>=85 && y<=135 && (counter[15]==1 || counter[19]==1 || counter[28]==1 || counter[34]==1 || counter[40]==1 || counter[33]==1))//gameover a exit
    {
        exit(0);

    }


    if(x>=755 && x<=910 && y>=22 && y<=88 && counter[56]==1 && counter[3]==0 && counter[7]==0 && counter[17]==0 && counter[22]==0 && counter[30]==0) //next option
    {
        counter[14]=1;
        strcpy(str,"level2.bmp");
    }

    if(x>=755 && x<=910 && y>=22 && y<=88 && counter[57]==1 && counter[3]==0 && counter[7]==0 && counter[17]==0 && counter[22]==0 && counter[30]==0) //next option
    {
        counter[38]=1;
        strcpy(str,"level3.bmp");
    }

    if(x>=755 && x<=910 && y>=22 && y<=88 && counter[58]==1 && counter[3]==0 && counter[7]==0 && counter[17]==0 && counter[22]==0 && counter[30]==0) //next option
    {
        counter[21]=1;
        strcpy(str,"level4.bmp");
    }

    if(x>=755 && x<=910 && y>=22 && y<=88 && counter[59]==1 && counter[3]==0 && counter[7]==0 && counter[17]==0 && counter[22]==0 && counter[30]==0) //next option
    {
        counter[26]=1;
        strcpy(str,"level5.bmp");
    }

    if(x>=755 && x<=910 && y>=22 && y<=88 && counter[60]==1 && counter[3]==0 && counter[7]==0 && counter[17]==0 && counter[22]==0 && counter[30]==0) //next option
    {
        strcpy(str,"21.bmp");
        counter[33]=1;
    }

    if(x>=50 && x<=215 && y>=40 && y<=95 && counter[2]==1 && counter[38]==0 && counter[7]==0 && counter[8]==0 && counter[14]==1 && counter[17]==0 && counter[22]==0 && counter[30]==0 && counter[57]==0)
    {
        //level 2 starts after passing level 1
        strcpy(str,"24.bmp");
        counter[7]=1;
    }

    if(x>=50 && x<=215 && y>=40 && y<=95 && counter[2]==1 && counter[7]==0  &&counter[8]==0 && counter[38]==1 && counter[17]==0 && counter[22]==0 && counter[30]==0 && counter[21]==0 && counter[58]==0)
    {
        //level 3 starts after passing level 2
        strcpy(str,"7.bmp");
        counter[17]=1;
    }

    if(x>=50 && x<=215 && y>=40 && y<=95 && counter[2]==1 && counter[7]==0 && counter[26]==0 && counter[8]==0 && counter[21]==1 && counter[17]==0 && counter[22]==0 && counter[30]==0 && counter[59]==0)
    {
        //level 4 starts from passing level 3
        strcpy(str,"8.bmp");
        counter[22]=1;
    }

    if(x>=50 && x<=215 && y>=40 && y<=95 && counter[2]==1 && counter[26]==1 && counter[3]==0 && counter[6]==0 && counter[7]==0 && counter[17]==0 && counter[22]==0 && counter[30]==0 && counter[60]==0)
    {
        //level 5 starts from passing level 4
        strcpy(str,"24.bmp");
        counter[30]=1;
    }
}

void iDraw()
{
    if(g<=703 && h==0)
    {
        Sleep(70);
        strcpy(str5,"intro\\\\1 (");
        itoa(g,str5+10,10);
        strcat(str5,").bmp");
        iShowBMP(0,0,str5);
        iSetColor(255,255,255);
        iText(40,25,"press (Esc) to skip dramatic scene",GLUT_BITMAP_TIMES_ROMAN_24);
        g++;
        counter[61]=1;
        if(g==704)
            counter[61]=0;

    }

    else
    {
        if(g1<253 && h1==1)
        {
            Sleep(70);
            strcpy(str7,"Credit\\\\2 (");
            itoa(g1,str7+11,10);
            strcat(str7,").bmp");
            strcpy(str,str7);
            g1++;
            if(g1==253)
            {
                counter[4]=0;
                strcpy(str,"1.bmp");
                h1=0;
                g1=20;
            }
        }

        iClear();
        iShowBMP(0, 0, str);

        if(counter[4]==1)
        {
            iSetColor(0,0,0);
            iText(40,20,"press (F5) to skip this",GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(trigger==1)
            drawbox();

        iSetColor(0,0,0);
        iText(520,425,str1[3],GLUT_BITMAP_TIMES_ROMAN_24);

        if(lev==1)
        {
            counter[2]=1;
        }

        if(counter[3]==1 || counter[16]==1)
        {
            iResumeTimer(0);
            k++;

            if(k<90)
                iShowBMP(0,0,"5.1.bmp");

            /*if(k>160&&k<280)
                iShowBMP(0,0,"5.2.bmp");*/

            l=l%60;
            l++;
            strcpy(str8,"Expression\\\\2 (");
            itoa(l,str8+15,10);
            strcat(str8,").bmp");
            if(counter[56]==0)
                iShowBMP2(755,60,str8,0);

            level_1();
        }

        if(counter[6]==1 || counter[8]==1 || counter[20]==1 || counter[23]==1 || counter[35]==1)
        {
            drawcontinue();
        }

        if(counter[15]==1 || counter[19]==1 || counter[28]==1 || counter[34]==1 || counter[40]==1 || counter[33]==1)
        {
            gameover();
            counter[2]=0;
        }

        if(counter[7]==1||counter[39]==1)
        {
            //iResumeTimer(7);
            k1++;

            if(k1<70)
                iShowBMP(0,0,"24.1.bmp");

            /*if(k1>120&&k1<200)
                iShowBMP(0,0,"24.2.bmp");*/

            level_2();
        }

        if(counter[17]==1)
        {
            iResumeTimer(2);
            k2++;

            if(k2<90)
                iShowBMP(0,0,"7.1.bmp");

            /*if(k2>140&&k2<280)
                iShowBMP(0,0,"7.2.bmp");*/

            l=l%60;
            l++;
            strcpy(str8,"Expression\\\\2 (");
            itoa(l,str8+15,10);
            strcat(str8,").bmp");
            if(counter[58]==0)
                iShowBMP2(747,63,str8,0);
            //iShowBMP2(750,60,"42.bmp",0);
            level_3();
        }

        if(counter[22]==1)
        {
            iResumeTimer(3);
            k3++;
            if(k3<90)
                iShowBMP(0,0,"8.1.bmp");
            /*if(k3>140&&k3<270)
                iShowBMP(0,0,"8.2.bmp");*/
            l=l%60;
            l++;
            strcpy(str8,"Expression\\\\2 (");
            itoa(l,str8+15,10);
            strcat(str8,").bmp");
            if(counter[59]==0)
                iShowBMP2(728,73,str8,0);
            //iShowBMP2(735,70,"42.bmp",0);
            level_4();
        }

        if(counter[30]==1)
        {
            iResumeTimer(5);
            k4++;

            if(k4<90)
                iShowBMP(0,0,"24.1.bmp");

            /*if(k4>120&&k4<220)
                iShowBMP(0,0,"24.2.bmp");*/

            l=l%60;
            l++;
            strcpy(str8,"Expression\\\\2 (");
            itoa(l,str8+15,10);
            strcat(str8,").bmp");
            if(counter[60]==0)
                iShowBMP2(93,70,str8,0);
            //iShowBMP2(93,77,"42.bmp",0);
            level_5();
        }
    }
}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        keypress(mx,my);
    }
}

void iKeyboard(unsigned char key)
{
    if(key==27)
    {
        h=1;
        counter[61]=0;

    }

    if(key == 'r' && counter[0]==1 && counter[3]==0 && counter[5]==0)
    {
        strcpy(str,"3.bmp");
        trigger=1;

    }

    if(mode==1 && counter[0]==1)
    {
        if(key=='\r')
        {
            strcpy(str,"level1.bmp");
            lev=1;
            axis[2]=0;
            axis[3]=0;
            strcpy(str1[4],str1[3]);//player nam level er majhe
            strcpy(str1[3],"\0");
            mode=0;
            //printf("%s\n",str1[4]);
        }

        if(key)
        {

            if(key=='r'&&counter[11]==0)
            {
                counter[11]=1;
            }

            else if(counter[11]==1)
            {
                str1[3][len]=key;
                if(key!=8)
                    len++;

                else if(key==8)//if you press backspace
                {
                    len--;
                    str1[3][len]='\0';
                }
            }
        }
    }


    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_F5 && counter[0]==0)
    {
        h1=0;
        strcpy(str,"1.bmp");
        counter[4]=0;
        g1=20;

    }
    if(key == GLUT_KEY_F1)
    {

        if(counter[56]==1 && counter[3]==1)
        {
            if(d==0)
                strcpy(str,"bad.bmp");

            if(d==1)
                strcpy(str,"passed.bmp");

            if(d==2)
                strcpy(str,"GOOD.bmp");

            if(d==3)
                strcpy(str,"excellent.bmp");

            counter[3]=0;
            //counter[56]=1;
            counter[16]=0;
        }

        if(counter[57]==1 && counter[7]==1)
        {
            if(d1==0)
                strcpy(str,"bad.bmp");

            if(d1==1)
                strcpy(str,"passed.bmp");

            if(d1==2)
                strcpy(str,"GOOD.bmp");

            if(d1==3)
                strcpy(str,"excellent.bmp");

            counter[7]=0;
            //counter[57]=1;
            counter[39]=0;
        }

        if(counter[58]==1 && counter[17]==1)
        {
            if(d2==0)
                strcpy(str,"bad.bmp");
            if(d2==1)
                strcpy(str,"passed.bmp");
            if(d2==2)
                strcpy(str,"GOOD.bmp");
            if(d2==3)
                strcpy(str,"excellent.bmp");
            counter[17]=0;
            //counter[58]=1;
        }

        if(counter[59]==1 && counter[22]==1)
        {
            if(d3==0)
                strcpy(str,"bad.bmp");
            if(d3==1)
                strcpy(str,"passed.bmp");
            if(d3==2)
                strcpy(str,"GOOD.bmp");
            if(d3==3)
                strcpy(str,"excellent.bmp");


            counter[22]=0;
            //counter[59]=1;
        }

        if(counter[60]==1 && counter[30]==1)
        {
            if(d4==0)
                strcpy(str,"bad.bmp");

            if(d4==1)
                strcpy(str,"passed.bmp");

            if(d4==2)
                strcpy(str,"GOOD.bmp");

            if(d4==3)
                strcpy(str,"excellent.bmp");

            counter[30]=0;
            //counter[60]=1;
        }

    }
    if(key == GLUT_KEY_DOWN)
    {

    }
    //place your codes for other keys here
}

//to draw the box to write the user name
void drawbox()
{
    iSetColor(255,255,255);
    iFilledRectangle(500,400,axis[2],axis[3]);
    counter[5]=1;
}


void level_1()
{
    iSetColor(0,0,255);
    iFilledCircle(480,500,10,200);
    iSetColor(255,0,0);
    iFilledCircle(p,q,20,200);
    iSetColor(255,255,0);
    iFilledCircle(p,q,15,200);
    iSetColor(255,0,0);
    iFilledCircle(p,q,10,200);
    iSetColor(255,255,0);
    iFilledCircle(p,q,5,200);
    iSetColor(153,0,0);
    iLine(axis[5],axis[6],axis[7],axis[8]);//Dorir upor nich
    iSetColor(0,0,0);
    iText(850,520,"Level: 1",GLUT_BITMAP_TIMES_ROMAN_24);
    if(c==1)
        iText(850,495,"Life : 3",GLUT_BITMAP_TIMES_ROMAN_24);
    if(c==2)
        iText(850,495,"Life : 2",GLUT_BITMAP_TIMES_ROMAN_24);
    if(c==3)
        iText(850,495,"Life : 1",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(50,30,"Player's Name: ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(210,30,str1[4],GLUT_BITMAP_TIMES_ROMAN_24);
    if(counter[56]==0){
    iRectangle(60,510,70,35);
    iText(65,520,"Pause",GLUT_BITMAP_TIMES_ROMAN_24);}
    //iRectangle(160,510,60,35);
    //iText(165,520,"Back",GLUT_BITMAP_TIMES_ROMAN_24);
    //iFilledRectangle(630,60,100,45);
    if(counter[12]==0)
        iShowBMP2(600,50,"26.bmp",0);
    if(counter[12]==1)
        iShowBMP2(600,50,"25.bmp",0);
    //iText(635,30,"Switch",GLUT_BITMAP_TIMES_ROMAN_24);
    //iRectangle(800,80,80,40);
    if(counter[50]==0)
        iShowBMP2(580,230,"27.bmp",0);
    if(counter[51]==0)
        iShowBMP2(650,170,"27.bmp",0);
    if(counter[52]==0)
        iShowBMP2(490,220,"27.bmp",0);
}

void level_2()
{
    iSetColor(0,0,255);
    iFilledCircle(450,500,10,200);
    iSetColor(255,0,0);
    iFilledCircle(p1,q1,20,200);
    iSetColor(255,255,0);
    iFilledCircle(p1,q1,15,200);
    iSetColor(255,0,0);
    iFilledCircle(p1,q1,10,200);
    iSetColor(255,255,0);
    iFilledCircle(p1,q1,5,200);
    iSetColor(153,0,0);
    iLine(axis[33],axis[34],axis[35],axis[36]);
    iSetColor(0,0,0);
    iText(50,30,"Player's Name: ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(885,520,"Level: 2",GLUT_BITMAP_TIMES_ROMAN_24);
    if(c1==1)
        iText(885,495,"Life : 3",GLUT_BITMAP_TIMES_ROMAN_24);
    if(c1==2)
        iText(885,495,"Life : 2",GLUT_BITMAP_TIMES_ROMAN_24);
    if(c1==3)
        iText(885,495,"Life : 1",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(210,30,str1[4],GLUT_BITMAP_TIMES_ROMAN_24);
    if(counter[57]==0){
    iRectangle(60,510,70,35);
    iText(65,520,"Pause",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(counter[57]==0)
        iShowBMP2(axis[37],axis[38],"23.bmp",0);
    if(counter[57]==1)
        iShowBMP2(axis[37],axis[38],"frog.bmp",0);

    if(counter[36]==0)
        iShowBMP2(850,30,"26.bmp",0);

    if(counter[36]==1)
        iShowBMP2(850,30,"25.bmp",0);

    if(counter[53]==0)
        iShowBMP2(500,240,"27.bmp",0);

    if(counter[54]==0)
        iShowBMP2(270,150,"27.bmp",0);

    if(counter[55]==0)
        iShowBMP2(400,220,"27.bmp",0);
}

void level_3()
{
    axis[15]=p2;
    axis[16]=q2;
    iSetColor(0,0,255);
    iFilledCircle(300,500,10,200);
    iSetColor(255,0,0);
    iFilledCircle(p2,q2,20,200);
    iSetColor(255,255,0);
    iFilledCircle(p2,q2,15,200);
    iSetColor(255,0,0);
    iFilledCircle(p2,q2,10,200);
    iSetColor(255,255,0);
    iFilledCircle(p2,q2,5,200);
    iSetColor(255,255,255);
    iLine(axis[13],axis[14],axis[15],axis[16]);
    iSetColor(255,255,255);
    iText(875,525,"Level: 3",GLUT_BITMAP_TIMES_ROMAN_24);

    if(c2==1)
        iText(875,495,"Life : 3",GLUT_BITMAP_TIMES_ROMAN_24);

    if(c2==2)
        iText(875,495,"Life : 2",GLUT_BITMAP_TIMES_ROMAN_24);

    if(c2==3)
        iText(875,495,"Life : 1",GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(255,255,255);
    iText(50,30,"Player's Name: ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(210,30,str1[4],GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(255,255,255);
    if(counter[58]==0){
    iRectangle(60,510,70,35);
    iText(65,520,"Pause",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    iSetColor(153,0,0);
    iShowBMP2(axis[17],axis[18],"10.bmp",0);

    if(counter[18]==0)
        iShowBMP2(620,38,"26.bmp",0);

    if(counter[18]==1)
        iShowBMP2(620,38,"25.bmp",0);//switch

    if(counter[41]==0)
        iShowBMP2(275,180,"27.bmp",0);//star akano

    if(counter[42]==0)
        iShowBMP2(800,220,"27.bmp",0);

    if(counter[43]==0)
        iShowBMP2(800,310,"27.bmp",0);
}

void level_4()
{
    iSetColor(0,0,255);
    iFilledCircle(250,500,10,200);
    iSetColor(255,0,0);
    iFilledCircle(p3,q3,20,200);
    iSetColor(255,255,0);
    iFilledCircle(p3,q3,15,200);
    iSetColor(255,0,0);
    iFilledCircle(p3,q3,10,200);
    iSetColor(255,255,0);
    iFilledCircle(p3,q3,5,200);
    iSetColor(255,255,255);
    iLine(axis[19],axis[20],axis[21],axis[22]);
    iText(875,525,"Level: 4",GLUT_BITMAP_TIMES_ROMAN_24);

    if(c3==1)
        iText(875,495,"Life : 3",GLUT_BITMAP_TIMES_ROMAN_24);

    if(c3==2)
        iText(875,495,"Life : 2",GLUT_BITMAP_TIMES_ROMAN_24);

    if(c3==3)
        iText(875,495,"Life : 1",GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(255,255,255);
    iText(50,30,"Player's Name: ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(210,30,str1[4],GLUT_BITMAP_TIMES_ROMAN_24);
    if(counter[59]==0){
    iRectangle(60,510,70,35);
    iText(65,520,"Pause",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    iShowBMP2(axis[23],axis[24],"10.bmp",0);
    if(counter[24]==0)
        iShowBMP2(620,38,"26.bmp",0);

    if(counter[24]==1)
        iShowBMP2(620,38,"25.bmp",0);

    if(counter[44]==0)
        iShowBMP2(260,180,"27.bmp",0);

    if(counter[45]==0)
        iShowBMP2(190,250,"27.bmp",0);

    if(counter[46]==0)
        iShowBMP2(790,270,"27.bmp",0);
}

void level_5()
{
    iSetColor(0,0,255);
    iSetColor(255,0,0);
    iFilledCircle(p4,q4,20,200);
    iSetColor(255,255,0);
    iFilledCircle(p4,q4,15,200);
    iSetColor(255,0,0);
    iFilledCircle(p4,q4,10,200);
    iSetColor(255,255,0);
    iFilledCircle(p4,q4,5,200);
    iSetColor(0,0,0);
    iLine(350,400,700,400);
    iLine(axis[25],axis[26],axis[27],axis[28]);
    iSetColor(255,255,255);
    iText(890,525,"Level: 5",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(890,495,"Life : 1",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(50,30,"Player's Name: ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(210,30,str1[4],GLUT_BITMAP_TIMES_ROMAN_24);
    if(counter[60]==0){
    iRectangle(60,510,70,35);
    iText(65,520,"Pause",GLUT_BITMAP_TIMES_ROMAN_24);
    }
    iShowBMP2(axis[29],axis[30],"10.bmp",0); //ulta magic hat
    iShowBMP2(axis[31],axis[32],"15.bmp",0);

    if(counter[31]==0 && counter[32]==0)
        iShowBMP2(870,40,"26.bmp",0);

    if(counter[31]==1 && counter[32]==1)
        iShowBMP2(870,40,"25.bmp",0);

    if(counter[47]==0)
        iShowBMP2(140,250,"27.bmp",0);

    if(counter[48]==0)
        iShowBMP2(500,170,"27.bmp",0);

    if(counter[49]==0)
        iShowBMP2(660,170,"27.bmp",0);
}

void lvl_1(void)
{
    if(counter[12]==0)
    {
        if(a==270)
        {
            angle=270;
        }
        else
        {
            angle=angle+increase;
            if(angle==b)
            {
                increase=-increase;
                counter[13]=1;
            }
            else if(angle==a)
            {
                increase=-increase;
                counter[13]=0;//candir poth controlling er jonno
            }
        }
        theta=angle*acos(-1)*(1/180.0);    //determining pi
        p=480+200*cos(theta);
        q=500+200*sin(theta);
        axis[7]=p;
        axis[8]=q;

    }

    else if(counter[12]==1)//Switch press er por
    {
        if(counter[13]==0)
        {
            p+=5;
            q-=4;
        }
        else if(counter[13]==1)
        {
            p-=5;
            q-=4;
        }

    }

    if(p>=580 && p<=630 && q>=230 && q<=280 && counter[50]==0)//1st star er box
    {
        counter[50]=1;//Star vanish er jonno
        d+=1;
    }

    if(p>=650 && p<=700 && q>=170 && q<=220 && counter[51]==0)//2nd
    {
        counter[51]=1;
        d+=1;
    }

    if(p>=490 && p<=540 && q>=220 && q<=270 && counter[52]==0)//3rd
    {
        counter[52]=1;
        d+=1;
    }

    if(p>=800 && p<=880 && q>=80 && q<=120 && counter[12]==1) //level 1 passed excellent
    {
        counter[56]=1;
        p=q=0;

        strcpy(str,"frog1.bmp");

    }

    if(q<=0 && counter[12]==1 && counter[56]==0 && c<3) //3 bar live pabe
    {
        c++;
        axis[5]=480;//dorir line
        axis[6]=500;
        axis[7]=p;
        axis[8]=q;
        counter[16]=1;
        counter[12]=0;
        counter[50]=counter[51]=counter[52]=0;
        d=0;
    }

    if(q<=0 && counter[12]==1 && counter[56]==0 && c>=3) //game over
    {
        strcpy(str,"17.bmp");
        counter[3]=0;
        counter[15]=1;
        counter[16]=0;
    }
}

void lvl_2(void)
{
    axis[37]+=lvl2_j;

    if(axis[37]>710 || axis[37]==0)
        lvl2_j=-lvl2_j;

    if(counter[36]==0)
    {
        if(a1==270)
        {
            angle1=270;
        }
        else
        {
            angle1=angle1+increase1;
            if(angle1==b1)
            {
                increase1=-increase1;
                counter[37]=1;
            }
            else if(angle1==a1)
            {
                increase1=-increase1;
                counter[37]=0;
            }
        }

        theta1=angle1*acos(-1)*(1/180.0);    //determining pi
        p1=450+200*cos(theta1);
        q1=500+200*sin(theta1);
        axis[35]=p1;
        axis[36]=q1;

    }

    else if(counter[36]==1)
    {
        if(counter[37]==0)
        {
            p1+=6;
            q1-=5;
        }
        else if(counter[37]==1)
        {
            p1-=6;
            q1-=5;
        }

    }

    if(p1>=500 && p1<=550 && q1>=240 && q1<=290 && counter[53]==0)
    {
        counter[53]=1;
        d1+=1;
    }

    if(p1>=270 && p1<=320 && q1>=150 && q1<=200 && counter[54]==0)
    {
        counter[54]=1;
        d1+=1;
    }

    if(p1>=400 && p1<=450 && q1>=220 && q1<=270 && counter[55]==0)
    {
        counter[55]=1;
        d1+=1;
    }

    if(q1<=0 && counter[36]==1 && counter[57]==0 && c1<3) //3 bar live pabe
    {
        c1++;
        axis[33]=450;//dorir line
        axis[34]=500;
        axis[35]=p1;
        axis[36]=q1;
        counter[39]=1;
        counter[36]=0;
        counter[53]=counter[54]=counter[55]=0;
        d1=0;
    }

    if(p1>=axis[37]+34 && p1<=axis[37]+102 && q1>=axis[38]+16 && q1<=axis[38]+64 && counter[36]==1) //level 2 passed excellent
    {

        strcpy(str,"244.bmp");
        counter[57]=1;
        p1=q1=lvl2_j=0;
    }

    if(q1<=0 && counter[36]==1 && counter[57]==0 && c1>=3) //game over
    {
        strcpy(str,"17.bmp");
        counter[7]=0;
        counter[40]=1;
        counter[39]=0;
    }
}

void lvl_3(void)
{
    axis[17]=axis[17]+lvl3_i;

    if(axis[17]>550 || axis[17]==0)//Hat controlling er jonno
        lvl3_i=-lvl3_i;

    if(counter[18]==1)//Switch
    {
        q2-=5;
        axis[14]=q2;
    }

    if( p2>=axis[17] && p2<=axis[17]+85 && q2>=axis[18]+35 && q2<=axis[18]+65 && counter[18]==1)
    {
        p2=822;//Coordinate shift
        q2=410;
        q2-=5;
        axis[14]=q2;
        axis[13]=p2;
    }

    if(p2>=275 && p2<=325 && q2>=180 && q2<=230 && counter[41]==0)
    {
        counter[41]=1;
        d2+=1;
    }

    if(p2>=800 && p2<=850 && q2>=220 && q2<=270 && counter[42]==0)
    {
        counter[42]=1;
        d2+=1;
    }

    if(p2>=800 && p2<=850 && q2>=310 && q2<=360 && counter[43]==0)
    {
        counter[43]=1;
        d2+=1;
    }

    else if(q2==0 && counter[18]==1 && c2<3) //3 bar live pabe
    {
        c2++;
        axis[13]=300;//dorir line
        axis[14]=500;
        axis[16]=q2=300;
        axis[15]=p2=300;
        counter[18]=0;
        counter[41]=counter[42]=counter[43]=0;//Star er jonno
        d2=0;
    }

    if(q2==0 && counter[18]==1 && c2>=3 && counter[58]==0) //Gameover
    {
        strcpy(str,"17.bmp");
        counter[17]=0;
        counter[19]=1;
    }

    if(p2>=790 && p2<=870 && q2>=80 && q2<=120) //excellent in level 3
    {
        p2=q2=axis[13]=axis[14]=0;
        lvl3_i=0;
        counter[58]=1;
        strcpy(str,"frog3.bmp");
    }
}

void lvl_4(void)
{
    axis[23]+=lvl4_i;
    if(axis[23]>520 || axis[23]==0)//Hat control
        lvl4_i=-lvl4_i;
    if(counter[24]==0)
    {
        if(a2==270)
        {
            angle2=270;
        }
        else
        {
            angle2=angle2+increase2;
            if(angle2==b2)
            {
                increase2=-increase2;
                //a2=a2+3;
                counter[25]=1;
            }
            else if(angle2==a2)
            {
                increase2=-increase2;
                //b2=b2-3;
                counter[25]=0;
            }
        }

        theta2=angle2*acos(-1)*(1/180.0);    //determining pi
        p3=250+150*cos(theta2);
        q3=500+150*sin(theta2);
        axis[21]=p3;
        axis[22]=q3;

    }

    else if(counter[24]==1)
    {
        if(counter[25]==0)//barir sorto bame
        {
            p3+=3;
            q3-=5;
        }
        else if(counter[25]==1)//dane
        {
            p3-=3;
            q3-=5;
        }
    }

    if(counter[24]==1 && p3>=axis[23] && p3<=axis[23]+85 && q3>=axis[24]+35 && q3<=axis[24]+65)
    {
        p3=822;
        q3=410;
        counter[27]=1;
    }

    if(p3>=260 && p3<=310 && q3>=180 && q3<=230 && counter[44]==0)
    {
        counter[44]=1;
        d3+=1;
    }

    if(p3>=190 && p3<=240 && q3>=250 && q3<=300 && counter[45]==0)
    {
        counter[45]=1;
        d3+=1;
    }

    if(p3>=790 && p3<=840 && q3>=270 && q3<=320 && counter[46]==0)
    {
        counter[46]=1;
        d3+=1;
    }

    if(counter[27]==1)
    {
        q3-=2;
        if(counter[25]==0)
            p3-=3;
        if(counter[25]==1)
            p3+=3;
    }

    if(q3<0 && counter[24]==1 && counter[59]==0 && c3<3) //3 bar live pabe
    {
        c3++;
        axis[19]=250;
        axis[20]=500;
        axis[21]=p3=100;
        axis[22]=q3=500;
        counter[22]=1;
        counter[24]=0;
        counter[44]=counter[45]=counter[46]=0;
        d3=0;
    }

    if(p3>=790 && p3<=870 && q3>=80 && q3<=120 && counter[24]==1) //excellent in level 4
    {
        p3=q3=lvl4_i=0;
        counter[59]=1;
        strcpy(str,"frog4.bmp");
    }

    if(q3<0 && counter[24]==1 &&  counter[59]==0 && c3>=3) //Gameover
    {
        strcpy(str,"17.bmp");
        counter[22]=0;
        counter[28]=1;
    }
}


void lvl_5(void)
{

    axis[29]+=lvl5_i1;//box er doura douri
    axis[31]+=lvl5_i2;

    if(axis[29]>750 || axis[29]==230)
        lvl5_i1=-lvl5_i1;

    if(axis[31]>600 || axis[31]==0)
        lvl5_i2=-lvl5_i2;

    if(counter[32]==0)
        p4+=lvl5_i3;

    else
        p4=p4; //vanish the rope

    axis[25]+=lvl5_i3;

    if(counter[31]==0)
    {
        axis[27]=p4;
        axis[28]=q4;
    }

    else
    {
        axis[27]=axis[25];
        axis[28]=axis[26];
    }

    if(p4>700 || p4==350)
        lvl5_i3=-lvl5_i3;

    if(counter[31]==1)
        q4-=6;

    if(counter[31]==1 && p4>=axis[29] && p4<=axis[29]+85 && q4>=axis[30]+35 && q4<=axis[30]+65)//axis shifting
    {
        p4=axis[31]+40;
        q4=axis[32];
    }

    if(p4>=140 && p4<=190 && q4>=250 && q4<=300 && counter[47]==0)//star
    {
        counter[47]=1;
    }

    if(p4>=500 && p4<=550 && q4>=170 && q4<=220 && counter[48]==0)
    {
        counter[48]=1;
    }

    if(p4>=660 && p4<=710 && q4>=170 && q4<=220 && counter[49]==0)
    {
        counter[49]=1;
    }

    if(counter[31]==1 && p4>=128 && p4<=214 && q4>=80 && q4<=120) //level 5 passed excellent
    {

        strcpy(str,"frog5.bmp");
        p4=q4=lvl5_i1=lvl5_i2=lvl5_i3=0;
        counter[60]=1;
    }

    if(q4<0 && counter[31]==1 && counter[60]==0) //gameover in level 5
    {
        strcpy(str,"17.bmp");
        counter[30]=0;
        counter[34]=1;
    }
}

void drawcontinue(void)
{
    iSetColor(255,0,0);
    iFilledRectangle(350,350,80,50);
    iFilledRectangle(500,350,80,50);
    iSetColor(255,255,255);
    iText(370,370,"YES",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(520,370,"NO",GLUT_BITMAP_TIMES_ROMAN_24);
}

void gameover(void)
{
    iSetColor(229,204,255);
    iFilledRectangle(350,85,150,50);
    iFilledRectangle(550,85,150,50);
    iSetColor(0,0,0);
    iText(370,103,"Play Again",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(600,103,"Exit",GLUT_BITMAP_TIMES_ROMAN_24);
}

int main()
{
    iSetTimer(13,lvl_1);
    iSetTimer(1,lvl_3);
    iSetTimer(5,lvl_4);
    iSetTimer(3,lvl_5);
    iSetTimer(1,lvl_2);


    install();//initializes parameter
    iInitialize(1000, 573, "TEAM PROJECT");
    return 0;
}

void install(void)
{

    int ii;
    int jj;
    int kk;

    for(jj=0; jj<100; jj++)
        axis[jj]=0;

    for(ii=0; ii<100; ii++)
    {
        counter[ii]=0;
    }

    str5[0]='\0';
    str6[0]='\0';
    str7[0]='\0';
    str8[0]='\0';
    str[0]='\0';

    for(ii=0; ii<100; ii++)
    {
        str1[3][ii]='\0';
    }

    axis[0]=200;//Initializing axis for box making box visible
    axis[1]=50;
    axis[2]=400;
    axis[3]=65;
    axis[4]=75;//hight and width of the level boxes
    axis[5]=480;//dorir line
    axis[6]=500;
    axis[33]=450;
    axis[34]=500;
    axis[38]=30;
    axis[9]=550;//dorir line
    axis[10]=450;
    axis[13]=300;//dorir line
    axis[14]=500;
    axis[17]=0;
    axis[18]=60;
    axis[19]=250;
    axis[20]=500;
    axis[23]=0;
    axis[24]=60;
    axis[25]=350;
    axis[26]=400;
    axis[29]=230;//level 4 er duita box
    axis[30]=60;
    axis[31]=0;
    axis[32]=450;


    g1=20;
    h1=0;
    l=0;
    mode=0;
    trigger=0;
    len=0;

    c=1,c1=1,c2=1,c3=1,c4=1;
    d=0,d1=0,d2=0,d3=0,d4=0;
    lev=0;

    angle=180.0;
    increase=2.5;
    b=360;
    a=180;
    angle2=180.0;
    increase2=3;
    angle1=180.0;
    increase1=2.5;
    a1=180;
    b1=360;
    b2=360;
    a2=180;

    p=280,q=500;
    p1=250,q1=500;
    p2=300,q2=300;
    p3=100,q3=500;
    p4=350,q4=250;

    k=k1=k2=k3=k4=0;

    lvl2_j=6;
    lvl3_i=8;
    lvl4_i=7;
    lvl5_i1=5;
    lvl5_i2=9;
    lvl5_i3=7;


    strcpy(str,"1.bmp");


    iPauseTimer(0);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(5);


    strcpy(str6,"music\\intro.wav");
    PlaySound(str6, NULL, SND_LOOP|SND_ASYNC);
}
