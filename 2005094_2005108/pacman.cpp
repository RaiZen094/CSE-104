#include "iGraphics.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
typedef struct titan
{
    int row;
    int column;

} titan;

titan t1= {15,15};
titan t2= {6,8};
titan t3= {8,7};
titan t4= {7,8};


int m=32,dx=50,dy=50;
char img[10][20]= {"pacman1.bmp","pacman2.bmp","pacman3.bmp","pacman4.bmp","pacman5.bmp","pacman6.bmp","pacman7.bmp","pacman8.bmp"};
char img2[10][20]= {"erwin.bmp","armin.bmp","eren.bmp","levi2.bmp","mikasa.bmp"};
int index,pic,total,life=3,page=0,mze=1,pix,pause=1,k=1,index2,music=1;
int scores[20],sscores[20];
int dead();
int pacCellx=1,pacCelly=1;
int grun=0,grun2=0,grun3=0,grun4=0;
int pacmanX=pacCellx*m+150,pacmanY=pacCelly*m+150;
char score[20],energy[20],points[20];
void eating();
void  display_score();
void show_life();
void respawn_maze();
void reset_status();
void score_collect();
void score_show();
FILE *fp;
int maze[17][17]=
{

    {1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1},
    {1,0,1,2,0,0,0,0,0,0,0,0,0,0,1,2,1},
    {1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,1,2,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
    {0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,2,1,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1},
    {1,2,1,0,0,0,0,0,0,0,0,0,0,2,1,0,1},
    {1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
};

void drawmaze(int maze[17][17]);
void iDraw()
{
    //place your drawing codes here
    iClear();
    //iShowBMP(150,150,"field.bmp");
    if(page==0)
    {
        iClear();
        iShowBMP(0,0,"titlescreen2.bmp");

        iPauseTimer(0);
        iPauseTimer(1);
        iPauseTimer(2);
        iPauseTimer(3);
        iPauseTimer(4);
        if(music==0)
        {
            iShowBMP2(900,700,"on.bmp",0);

        }
        else if(music==1)
        {
            iShowBMP2(900,700,"off2.bmp",0);

        }
    }
    else if(page==1)
    {
        iClear();

        iShowBMP(750,500,"Pause.bmp");
        drawmaze(maze);
        pacmanX=pacCellx*m+150;
        pacmanY=pacCelly*m+150;
        iShowBMP2(pacmanX,pacmanY,img[index],0);
        iShowBMP2(t1.row*m+150,t1.column*m+150,"beast.bmp",0);
        iShowBMP2(t2.row*m+150,t2.column*m+150,"female.bmp",0);
        iShowBMP2(t3.row*m+150,t3.column*m+150,"colossal.bmp",0);
        iShowBMP2(t4.row*m+150,t4.column*m+150,"armored.bmp",0);
        if(mze==1)
        {
            iShowBMP(800,600,"sina.bmp");

        }
        if(mze==2)
        {
            iShowBMP(800,600,"maria.bmp");

        }
        if(mze==3)
        {
            iShowBMP(800,600,"rose.bmp");

        }
        dead();
        eating();
        display_score();
        show_life();
        if(total==k*1630)
        {
            respawn_maze();
            k++;
        }
        if(life==0)
        {
            page=7;
            score_collect();
            reset_status();
            respawn_maze();

        }
    }
    else if(page==2)
    {
        iClear();
        iShowBMP(0,0,"titlescreen.bmp");
        iSetColor(255,255,255);
        iText(350,670,"CHOOSE ONE MAZE",GLUT_BITMAP_HELVETICA_18);
        iShowBMP2(675,300,"levi.bmp",0);
        iShowBMP2(200,550,"wall sina2.bmp",0);
        iShowBMP2(200,400,"wall maria2.bmp",0);
        iShowBMP2(200,250,"wall rose2.bmp",0);
        iText(700,100,"Back",GLUT_BITMAP_HELVETICA_18);




    }
    else if(page==3)
    {
        iClear();
        iText(700,100,"Back",GLUT_BITMAP_HELVETICA_18);
        iShowBMP(0,0,"highhscore3.bmp");
        iText(700,100,"Back",GLUT_BITMAP_HELVETICA_18);
        score_show();
    }
    else if(page==4)
    {
        iClear();
        iShowBMP(0,150,"instructiond.bmp");
        iText(700,100,"Back",GLUT_BITMAP_HELVETICA_18);
    }
    else if(page==6)
    {
        iClear();
        iShowBMP(0,100,img2[index2]);
        iShowBMP2(400,700,"resume.bmp",0);
    }
    else if(page==7)
    {
        iClear();

        iShowBMP(0,200,"moveforward.bmp");
        iShowBMP2(225,75,"gameover2.bmp",0);
        iSetColor(0,200,255);
        iText(425,50,"press F/f to continue",GLUT_BITMAP_HELVETICA_18);
        iText(425,25,"press E/e to exit",GLUT_BITMAP_HELVETICA_18);
        iSetColor(255,255,255);

    }
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
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
        if (page==0)
        {
            if(mx>=425&&mx<=575&&my>=550&&my<=575) page=1;
            if(mx>=420&&mx<=565&&my>=465&&my<=490) page=2;
            if(mx>=360&&mx<=665&&my>=370&&my<=410) page=3;
            if(mx>=345&&mx<=680&&my>=280&&my<=315) page=4;
            if(mx>=900&&mx<=950&&my>=700&&my<=750)
            {

                music++;
                if(music>=2)
                {
                    music=0;
                }
                if(music==0)
                {

                    mciSendString("play music2.wav",NULL,0,NULL);

                }
                else if(music==1)
                {

                    mciSendString("pause music2.wav",NULL,0,NULL);
                }

            }
            if((mx>=453&&mx<=553)&&(my>=200&&my<=225)) exit(0);

        }
        if(page==1)
        {


            iResumeTimer(0);
            iResumeTimer(1);
            iResumeTimer(2);
            iResumeTimer(3);
            iResumeTimer(4);


        }
        // printf("x = %d, y= %d\n",mx,my);


        if(page==2)
        {
            if(mx>=700&&mx<=745&&my>=100&&my<=115) page=0;

            if(mx>=200&&mx<=700&&my>=552&&my<=664) mze=1;
            if(mx>=200&&mx<=700&&my>=400&&my<=514)mze=2;
            if((mx>=200&&mx<=700)&&(my>=250&&my<=365)) mze=3;

        }
        if(page==3)
        {
            if(mx>=700&&mx<=745&&my>=100&&my<=115) page=0;

        }
        if(page==4)
        {
            if(mx>=700&&mx<=745&&my>=100&&my<=115) page=0;


        }
        if(page==6)
        {
            if(mx>=800&&mx<=875&&my>=550&&my<=565)
            {
                iResumeTimer(0);
                iResumeTimer(1);
                iResumeTimer(2);
                iResumeTimer(3);
                iResumeTimer(4);
                page=1;
            }


        }
        if(page==7)
        {
            if(mx>=500&&mx<=700&&my>=400&&my<=415) page=0;

        }

    }



    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {




    }
}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(page==1)
    {
        if(key=='p'||key=='P')
        {

            iPauseTimer(0);
            iPauseTimer(1);
            iPauseTimer(2);
            iPauseTimer(3);
            iPauseTimer(4);
            page=6;

            index2=rand()%5;


        }


    }
    if(page==6)
    {
        if(key=='r'||key=='R')
        {

            iResumeTimer(0);
            iResumeTimer(1);
            iResumeTimer(2);
            iResumeTimer(3);
            iResumeTimer(4);
            page=1;


        }



    }
    if(page==7)
    {
        if(key == 'f'||key=='F')
        {
            reset_status();
            respawn_maze();
            page=1;


        }
        else if(key=='E'||key=='e')
        {
            reset_status();
            respawn_maze();
            page=0;
        }
        //place your codes for other keys here
    }
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

    if(key == GLUT_KEY_UP)
    {
        pic=4;

        if(maze[pacCellx][pacCelly+1]!=1&&pacCelly<=17)
        {

            pacCelly++;

        }
        else if(pacCelly==16&&pacCellx==8)
        {
            pacCelly++;
            if(pacCelly==17&&pacCellx==8)
            {
                pacCelly=0;
                pacCellx=8;
            }

        }

    }

    if(key == GLUT_KEY_DOWN)
    {
        pic=3;

        if(maze[pacCellx][pacCelly-1]!=1&&pacCelly>=1)
        {

            pacCelly--;
        }
        else if(pacCellx==8&&pacCelly==0)
        {
            pacCelly--;
            if(pacCelly==-1&&pacCellx==8)
            {
                pacCelly=16;
                pacCellx=8;
            }
        }


    }

    if(key == GLUT_KEY_RIGHT)
    {

        pic=1;
        if(maze[pacCellx+1][pacCelly]!=1&&pacCellx<16)
        {
            pacCellx++;

        }
        else if(pacCellx==16&&pacCelly==8)
        {
            pacCellx++;
            if(pacCellx==17&&pacCelly==8)
            {
                pacCelly=8;
                pacCellx=0;
            }
        }

    }

    if(key == GLUT_KEY_LEFT)
    {

        pic=2;
        if(maze[pacCellx-1][pacCelly]!=1&&pacCellx>0)
        {
            pacCellx--;


        }
        else if(pacCellx==0&&pacCelly==8)
        {
            pacCellx--;
            if(pacCellx==-1&&pacCelly==8)
            {
                pacCellx=16;
                pacCelly=8;
            }
        }

    }




}

//place your codes for other keys here
void ghostrun() //moves the enemy
{

    int tx=t1.row, ty=t1.column;
    switch(grun)
    {
    case 0:
        if(maze[tx][ty-1]!=1)
        {

            ty--;
        }


        else if(maze[tx][ty-1]==1)
        {
            /*ty++;*/
            grun=rand()%4;
        }

        break;
    case 1:
        if(maze[tx][ty+1]!=1)
        {

            ty++;
        }
        else if(maze[tx][ty+1]==1)
        {
            /*ty--;*/
            grun=rand()%4;
        }
        break;
    case 3:
        if(maze[tx+1][ty]!=1)
        {

            tx++;

        }
        else if(maze[tx+1][ty]==1)
        {
            /* tx--; */
            grun=rand()%4;
        }
        break;
    case 2:
        if(maze[tx-1][ty]!=1)
        {

            tx--;

        }
        else if(maze[tx-1][ty]==1)
        {
            /* tx++;*/
            grun=rand()%4;
        }

        break;
    }
    if(tx==16)
    {

        grun=2;


    }
    else if(tx==0)
    {


        grun=3;
    }
    if(ty==16)
    {
        grun=1;
    }
    else if(ty==0)
    {

        grun=0;
    }
    if (tx==pacCellx)
    {
        if (ty<pacCelly) grun=1;
        else grun=0;
    }

    if (ty==pacCelly)
    {
        if (tx<pacCellx) grun=3;
        else grun=2;
    }

    t1.row=tx;
    t1.column=ty;



}
void ghostrun2()
{

    int tx2=t2.row, ty2=t2.column;
    switch(grun2)
    {
    case 3:
        if(maze[tx2][ty2-1]!=1)
        {

            ty2--;
        }


        else if(maze[tx2][ty2-1]==1)
        {
            /*ty++;*/
            grun2=rand()%4;
        }

        break;
    case 2:
        if(maze[tx2][ty2+1]!=1)
        {

            ty2++;
        }
        else if(maze[tx2][ty2+1]==1)
        {
            /*ty--;*/
            grun2=rand()%4;
        }
        break;
    case 0:
        if(maze[tx2+1][ty2]!=1)
        {

            tx2++;

        }
        else if(maze[tx2+1][ty2]==1)
        {
            /* tx--; */
            grun2=rand()%4;
        }
        break;
    case 1:
        if(maze[tx2-1][ty2]!=1)
        {

            tx2--;

        }
        else if(maze[tx2-1][ty2]==1)
        {
            /* tx++;*/
            grun2=rand()%4;
        }

        break;
    }
    if(tx2==16)
    {

        grun2=1;


    }
    else if(tx2==0)
    {


        grun2=0;
    }
    if(ty2==16)
    {
        grun2=3;
    }
    else if(ty2==0)
    {

        grun2=2;
    }
    if (tx2==pacCellx)
    {
        if (ty2<pacCelly) grun2=2;
        else grun2=3;
    }

    if (ty2==pacCelly)
    {
        if (tx2<pacCellx) grun2=0;
        else grun2=1;
    }
    t2.row=tx2;
    t2.column=ty2;

}
void ghostrun3()
{

    int tx3=t3.row, ty3=t3.column;
    switch(grun2)
    {
    case 1:
        if(maze[tx3][ty3-1]!=1)
        {

            ty3--;
        }


        else if(maze[tx3][ty3-1]==1)
        {

            grun3=rand()%4;
        }

        break;
    case 0:
        if(maze[tx3][ty3+1]!=1)
        {

            ty3++;
        }
        else if(maze[tx3][ty3+1]==1)
        {

            grun3=rand()%4;
        }
        break;
    case 2:
        if(maze[tx3+1][ty3]!=1)
        {

            tx3++;

        }
        else if(maze[tx3+1][ty3]==1)
        {

            grun3=rand()%4;
        }
        break;
    case 3:
        if(maze[tx3-1][ty3]!=1)
        {

            tx3--;

        }
        else if(maze[tx3-1][ty3]==1)
        {

            grun3=rand()%4;
        }

        break;
    }
    if(tx3==16)
    {

        grun3=3;


    }
    else if(tx3==0)
    {


        grun3=2;
    }
    if(ty3==16)
    {
        grun3=1;
    }
    else if(ty3==0)
    {

        grun3=0;
    }
      if (tx3==pacCellx)
    {
        if (ty3<pacCelly) grun3=0;
        else grun3=1;
    }

    if (ty3==pacCelly)
    {
        if (tx3<pacCellx) grun3=2;
        else grun3=3;
    }
    t3.row=tx3;
    t3.column=ty3;

}
void ghostrun4()
{

    int tx4=t4.row, ty4=t4.column;
    switch(grun4)
    {
    case 2:
        if(maze[tx4][ty4-1]!=1)
        {

            ty4--;
        }


        else if(maze[tx4][ty4-1]==1)
        {

            grun4=rand()%4;
        }

        break;
    case 3:
        if(maze[tx4][ty4+1]!=1)
        {

            ty4++;
        }
        else if(maze[tx4][ty4+1]==1)
        {

            grun4=rand()%4;
        }
        break;
    case 1:
        if(maze[tx4+1][ty4]!=1)
        {

            tx4++;

        }
        else if(maze[tx4+1][ty4]==1)
        {

            grun4=rand()%4;
        }
        break;
    case 0:
        if(maze[tx4-1][ty4]!=1)
        {

            tx4--;

        }
        else if(maze[tx4-1][ty4]==1)
        {

            grun4=rand()%4;
        }

        break;
    }
    if(tx4==16)
    {

        grun4=0;


    }
    else if(tx4==0)
    {


        grun4=1;
    }
    if(ty4==16)
    {
        grun4=3;
    }
    else if(ty4==0)
    {

        grun4=2;
    }
    if (tx4==pacCellx)
    {
        if (ty4<pacCelly) grun4=3;
        else grun4=2;
    }

    if (ty4==pacCelly)
    {
        if (tx4<pacCellx) grun4=1;
        else grun4=0;
    }
    t4.row=tx4;
    t4.column=ty4;



}
int dead() //death mechanism
{
    if((pacCellx==t1.row&&pacCelly==t1.column)||(pacCellx==t2.row&&pacCelly==t2.column)||(pacCellx==t3.row&&pacCelly==t3.column)||(pacCellx==t4.row&&pacCelly==t4.column))
    {

        life--;
        PlaySound("eatmusic.wav",NULL,SND_ASYNC);
        pacCellx=1;
        pacCelly=1;
        iDelay(1);

    }


}
void eating() //eating points&bonuses
{

    if(maze[pacCellx][pacCelly]==0)
    {

        total=total+10;
        maze[pacCellx][pacCelly]=3;

    }
    else if(maze[pacCellx][pacCelly]==2)
    {

        total=total+30;
        maze[pacCellx][pacCelly]=4;
        PlaySound("eatpoint.wav",NULL,SND_ASYNC);


    }


}
void display_score() //shows score on playscreen
{


    iText(800,350,"SCORE : ",GLUT_BITMAP_8_BY_13);
    itoa(total,score,10);
    iText(860,350,score,GLUT_BITMAP_HELVETICA_18);



}
void show_life() //shows life on playscreen
{

    iText(800,450,"LIFE : ",GLUT_BITMAP_8_BY_13);
    itoa(life,energy,10);
    iText(860,450,energy,GLUT_BITMAP_HELVETICA_18);




}
void respawn_maze() //resets the maze after certain points reached
{

    int p,n;
    for(p=0; p<17; p++)
    {

        for(n=0; n<17; n++)
        {
            if(maze[p][n]==3)
            {
                maze[p][n]=0;

            }
            else if(maze[p][n]==4)
            {
                maze[p][n]=2;

            }

        }


    }

}

void score_collect() //collects score
{
    int i,j,temp;
    fp=fopen("honor_board.txt","r");


    for(i=0; i<5; i++)
    {

        fscanf(fp,"%d\n",&scores[i]);


    }
    fclose(fp);
    if(total>scores[4])
    {
        scores[4]=total;
        for(i=0; i<4; i++)
        {
            for(j=i+1; j<5; j++)
            {
                if(scores[j]>scores[i])
                {

                    temp=scores[i];
                    scores[i]=scores[j];
                    scores[j]=temp;
                }


            }

        }

        fp=fopen("honor_board.txt","w");


        for(i=0; i<5; i++)
        {


            fprintf(fp,"%d\n",scores[i]);


        }
        fclose(fp);
    }

}
void score_show() //shows previous score
{
    int i;
    fp=fopen("honor_board.txt","r");

    for(i=0; i<5; i++)
    {

        fscanf(fp,"%d\n",&sscores[i]);


    }
    fclose(fp);
    iSetColor(125,213,255);
    iText(100,480,itoa(sscores[0],points,10),GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100,430,itoa(sscores[1],points,10),GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100,380,itoa(sscores[2],points,10),GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100,330,itoa(sscores[3],points,10),GLUT_BITMAP_TIMES_ROMAN_24);
    iText(100,280,itoa(sscores[4],points,10),GLUT_BITMAP_TIMES_ROMAN_24);




}
void reset_status() //resets every attributes of the charecters
{
    life=3;
    total=0;
    pacCellx=1,pacCelly=1,t1.row=15,t1.column=15,t2.row=6,t2.column=8,t3.row=8,t3.column=7,t4.row=7,t4.column=8;


}
void drawmaze(int maze[17][17]) //initiates the maze
{

    int i,j;
    for(i=0; i<17; i++)
    {

        for(j=0; j<17; j++)
        {

            if(maze[i][j]==1)
            {

                if(mze==1)
                {
                    iShowBMP(100+m*i+dx,100+m*j+dy,"concrete.bmp");
                }
                else if(mze==2)
                {
                    iShowBMP(100+m*i+dx,100+m*j+dy,"concrete2.bmp");
                }
                else if(mze==3)
                {
                    iShowBMP(100+m*i+dx,100+m*j+dy,"concrete3.bmp");
                }

            }
            if (maze[i][j]==0)
            {

                iShowBMP2(100+m*i+dx+10,100+m*j+dy+15,"gabi.bmp",0);
            }
            else if(maze[i][j]==2)
            {

                iShowBMP2(100+m*i+dx,100+m*j+dy,"warhammer.bmp",0);
            }

        }

    }

}
//place your codes for other keys here



void render() //renders the pacman
{

    if(pic==1)
    {

        index++;
        if(index>=2)
        {
            index=0;
        }
    }


    if(pic==2)
    {

        index++;
        if(index>=6)
        {
            index=4;
        }
    }
    if(pic==3)
    {

        index++;
        if(index>=4)
        {
            index=2;
        }
    }
    if(pic==4)
    {

        index++;
        if(index>=8)
        {
            index=6;
        }
    }



}


int main()
{
    //place your own initialization codes here.

    srand( time(0) );
    iSetTimer(100,render);
    iSetTimer(300,ghostrun);
    iSetTimer(200,ghostrun2);
    iSetTimer(200,ghostrun3);
    iSetTimer(212,ghostrun4);

    iInitialize(1000, 800, "PacManXAttackOnTitan");

    return 0;
}


