#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>

// made by rishabh and nishad :)

int tic[10];
char c;
int turn=0;
int count=0;
void init()
{
    for(int i=0;i<10;i++)
    {
        tic[i]=0;
    }
}
void drawx(int num)
{
    int x,y;
    setcolor(5);
    if(num>6)
    {
        y=300;
    }
    else if(num>3)
    {
        y=200;
    }
    else
    {
        y=100;
    }
    num = num%3;
    switch (num)
    {
    case 0:
        x = 300;
        break;
    case 1:
        x=100;
        break;
    case 2:
        x=200;
        break;
    }
    line(x,y,x+100,y+100);
    line(x+100,y,x,y+100);
}
void drawcircle(int num)
{
    int x,y;
    setcolor(3);
    if(num>6)
    {
        y=300;
    }
    else if(num>3)
    {
        y=200;
    }
    else
    {
        y=100;
    }
    num = num%3;
    switch (num)
    {
    case 0:
        x = 300;
        break;
    case 1:
        x=100;
        break;
    case 2:
        x=200;
        break;
    }
    circle(x+50,y+50,50);
}
void layout()
{
    setcolor(2);
    rectangle(100,100,400,400);
    line(200,100,200,400);
    line(300,100,300,400);
    line(100,200,400,200);
    line(100,300,400,300);
    for(int i=1;i<=9;i++)
    {
        if(tic[i]==1)
        {
            drawx(i);
        }
        else if(tic[i]==2)
        {
            drawcircle(i);
        }
    }
}

void gameplay()
{
    char c = getch();
    int a = c;
    c=c-48;
    switch(turn)
    {
    case 1:
        tic[c]=1;
        turn =2;
        break;
    case 2:
        tic[c]=2;
        turn=1;
        break;
    }

}

bool checkrow()
{
    for(int i =1;i<=7;i+=3)
    {
        if(tic[i]==tic[i+1] && tic[i+1]==tic[i+2] && tic[i+1]!=0)
        {
            return true;
        }
    }
    return false;
}
bool checkcol()
{
    for(int i=1;i<=3;i++)
    {
        if(tic[i]==tic[i+3] && tic[i+3]==tic[i+6] && tic[i+3]!=0)
        {
            return true;
        }
    }
    return false;
}
bool checkdiag()
{
    if(tic[1]==tic[5] && tic[5]==tic[9] && tic[5]!=0)
    {
        return true;
    }
    else if (tic[3]==tic[5] && tic[5]==tic[7] && tic[5]!=0)
    {
        return true;
    }
    return false;
}

bool check()
{
    if(checkrow()||checkcol()||checkdiag())
    {
        return true;
    }
    return false;
}
void instructions()
{
    setcolor(10);
    outtextxy(50,55,"Player 1 is X");
    outtextxy(250,55,"Player 2 is O");
    outtextxy(450,100,"1 2 3");
    outtextxy(450,120,"4 5 6");
    outtextxy(450,140,"7 8 9");
}


int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    bool gameover = false;
    turn=1;
    char arr[50];
    init();
    while(!gameover)
    {
        instructions();
        sprintf(arr,"Player %d turn",turn);
        outtextxy(200,450,arr);
        layout();
        gameplay();
        gameover = check();
        cleardevice();
        count++;
        if(count>=9)
            gameover = true;
    }
    layout();
    settextstyle(3,0,5);
    outtextxy(100,400,"Game Over");
    getch();
}
