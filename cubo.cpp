#include<iostream>
using namespace std;
//-----------------------------------------------
char white[9];
char red[9];
char orange[9];
char blue[9];
char green[9];
char yellow[9];
//----------------------------------
void display(char face[9])
{
  for(int i=0;i<9;i++)
  {
    cout<<face[i]<<" ";
  }
  cout<<endl<<endl;
}
void swap(char &a,char &b)
{
    char t=a;
    a=b;
    b=t;
}
void rotate_clock(char choice)
{
  if (choice=='w')
  {
    cout<<"White"<<endl;
    swap(white[7],white[3]);
    swap(white[6],white[4]);
    swap(white[0],white[2]);
    swap(white[7],white[5]);
    swap(white[0],white[4]);
    swap(white[1],white[3]);
    //-------------------------
    swap(blue[0],orange[0]);
    swap(blue[7],orange[7]);
    swap(blue[6],orange[6]);
    swap(orange[6],green[6]);
    swap(orange[7],green[7]);
    swap(orange[0],green[0]);
    swap(green[6],red[6]);
    swap(green[7],red[7]);
    swap(green[0],red[0]);
  }
  //-------------------------
  else if(choice=='r')
  {
    cout<<"Red"<<endl;
    swap(red[0],red[4]);
    swap(red[7],red[5]);
    swap(red[1],red[3]);
    swap(red[0],red[6]);
    swap(red[1],red[5]);
    swap(red[2],red[4]);
    //-------------------------
    swap(blue[6],white[3]);
    swap(blue[5],white[2]);
    swap(blue[4],white[1]);
    swap(white[1],green[0]);
    swap(white[2],green[1]);
    swap(white[3],green[2]);
    swap(green[0],yellow[3]);
    swap(green[1],yellow[2]);
    swap(green[2],yellow[1]);
    //--------------------------
  }
  //-----------------------------------
  else if(choice=='y')
  {
    cout<<"Yellow"<<endl;
    swap(yellow[1],yellow[5]);
    swap(yellow[2],yellow[4]);
    swap(yellow[0],yellow[6]);
    swap(yellow[1],yellow[3]);
    swap(yellow[0],yellow[4]);
    swap(yellow[7],yellow[5]);
    //--------------------------
    swap(blue[4],red[4]);
    swap(blue[3],red[3]);
    swap(blue[2],red[2]);
    swap(red[2],green[2]);
    swap(red[3],green[3]);
    swap(red[4],green[4]);
    swap(green[4],orange[4]);
    swap(green[3],orange[3]);
    swap(green[2],orange[2]);
    //--------------------------
  }
  //-------------------------------------
  else if(choice=='o')
  {
    cout<<"Orange"<<endl;
    swap(orange[4],orange[0]);
    swap(orange[3],orange[1]);
    swap(orange[5],orange[7]);
    swap(orange[4],orange[2]);
    swap(orange[5],orange[1]);
    swap(orange[6],orange[0]);
    //--------------------------
    swap(blue[2],yellow[5]);
    swap(blue[1],yellow[6]);
    swap(blue[0],yellow[7]);
    swap(yellow[5],green[6]);
    swap(yellow[6],green[5]);
    swap(yellow[7],green[4]);
    swap(green[6],white[7]);
    swap(green[5],white[6]);
    swap(green[4],white[5]);
    //--------------------------
  }
  //-------------------------------------
  else if(choice=='g')
  {
    cout<<"Green"<<endl;
    swap(green[6],green[2]);
    swap(green[5],green[3]);
    swap(green[7],green[1]);
    swap(green[4],green[6]);
    swap(green[7],green[3]);
    swap(green[0],green[2]);
    //--------------------------
    swap(white[5],orange[2]);
    swap(white[4],orange[1]);
    swap(white[3],orange[0]);
    swap(yellow[3],orange[2]);
    swap(yellow[4],orange[1]);
    swap(yellow[5],orange[0]);
    swap(yellow[3],red[6]);
    swap(yellow[4],red[5]);
    swap(yellow[5],red[4]);
    //--------------------------
  }
  //-------------------------------------------
  else if(choice=='b')
  {
    cout<<"Blue";
    swap(blue[1],blue[7]);
    swap(blue[2],blue[6]);
    swap(blue[5],blue[3]);
    swap(blue[2],blue[0]);
    swap(blue[7],blue[3]);
    swap(blue[6],blue[4]);
    //--------------------------
    swap(yellow[1],orange[4]);
    swap(yellow[0],orange[5]);
    swap(yellow[7],orange[6]);
    swap(white[7],orange[4]);
    swap(white[0],orange[5]);
    swap(white[1],orange[6]);
    swap(white[7],red[0]);
    swap(white[0],red[1]);
    swap(white[1],red[2]);
    //--------------------------
  }
}

void white_bottom(char q)
{
    if((yellow[0]=='w' && blue[3]==q) || (yellow[2]=='w' && red[3]==q) || (yellow[4]=='w' && green[3]==q) || (yellow[6]=='w' && orange[3]==q))
    {
        if(q=='b')
        {
            while(blue[3]!=q || yellow[0]!='w')
            {rotate_clock('y');}
        }
        if(q=='r')
        {
            while(red[3]!=q || yellow[2]!='w')
            {rotate_clock('y');}
            if(q!='b')
            {
                while(white[0]!='w' && blue[7]!='b')
                {rotate_clock('w');}
            }
        }
        if(q=='g')
        {
            while(green[3]!=q || yellow[4]!='w')
            {rotate_clock('y');}
            if(q!='b')
            {
                while(white[0]!='w' && blue[7]!='b')
                {rotate_clock('w');}
            }
        }
        if(q=='o')
        {
            while(orange[3]!=q || yellow[6]!='w')
            {rotate_clock('y');}
            if(q!='b')
            {
                while(white[0]!='w' && blue[7]!='b')
                {rotate_clock('w');}
            }
        }
        rotate_clock(q);rotate_clock(q);
    }
}
void right_alg(char a,char c)
{
    rotate_clock(a);rotate_clock(a);rotate_clock(a);
    rotate_clock('y');rotate_clock(a);white_bottom(c);
}
void white_right(char q)
{
    if(blue[1]=='w' || red[1]=='w' || green[1]=='w' ||orange[1]=='w')
    {
        if(blue[5]==q && red[1]=='w')
        {right_alg('b',q);}
        if(red[5]==q && green[1]=='w')
        {right_alg('r',q);}
        if(green[5]==q && orange[1]=='w')
        {right_alg('g',q);}
        if(orange[5]==q && blue[1]=='w')
        {right_alg('o',q);}
    }
}
void left_alg(char a,char c)
{
    rotate_clock(a);rotate_clock('y');rotate_clock(a);
    rotate_clock(a);rotate_clock(a);white_bottom(c);
}
void white_left(char q)
{
    if(blue[5]=='w' || red[5]=='w' || green[5]=='w' ||orange[5]=='w')
    {
        if(blue[5]=='w' && red[1]==q)
        {left_alg('r',q);}
        if(red[5]=='w' && green[1]==q)
        {left_alg('g',q);}
        if(green[5]=='w' && orange[1]==q)
        {left_alg('o',q);}
        if(orange[5]=='w' && blue[1]==q)
        {left_alg('b',q);}
    }
}
void top_alg(char a,char b,char c)
{
    rotate_clock(a);rotate_clock(a);rotate_clock(a);
    rotate_clock('w');rotate_clock(b);rotate_clock('w');
    rotate_clock('w');rotate_clock('w');white_bottom(c);
}
void white_top(char q)
{
    if(blue[7]=='w' && white[0]==q)
    {top_alg('b','r',q);}
    if(red[7]=='w' && white[2]==q)
    {top_alg('r','g',q);}
    if(green[7]=='w' && white[4]==q)
    {top_alg('g','o',q);}
    if(orange[7]=='w' && white[6]==q)
    {top_alg('o','b',q);}
}
void inv_alg(char a,char b,char c)
{
    rotate_clock(a);rotate_clock(b);rotate_clock('y');
    rotate_clock('y');rotate_clock('y');rotate_clock(b);
    rotate_clock(b);rotate_clock(b);rotate_clock(a);
    rotate_clock(a);rotate_clock(a);white_bottom(c);
}
void white_bottom_inverted(char q)
{
    if(blue[3]=='w' || red[3]=='w' || green[3]=='w' || orange[3]=='w')
    {
        if(blue[3]=='w' && yellow[0]==q)
        {inv_alg('b','r',q);}
        if(red[3]=='w' && yellow[2]==q)
        {inv_alg('r','g',q);}
        if(green[3]=='w' && yellow[4]==q)
        {inv_alg('g','o',q);}
        if(orange[3]=='w' && yellow[6]==q)
        {inv_alg('o','b',q);}
    }
}

void solve_white_cross()
{
    char prefer[4]={'b','r','g','o'};
    for(int i=0;i<4;i++)
    {
        if(white[0]=='w' && blue[7]==prefer[i]){rotate_clock('b');}
        if(white[2]=='w' && red[7]==prefer[i]){rotate_clock('r');}
        if(white[4]=='w' && green[7]==prefer[i]){rotate_clock('g');}
        if(white[6]=='w' && orange[7]==prefer[i]){rotate_clock('o');}
        white_bottom(prefer[i]);white_bottom_inverted(prefer[i]);white_left(prefer[i]);white_right(prefer[i]);white_top(prefer[i]);
        if(i!=0)
        {while(blue[7]!='b'){rotate_clock('w');}}
        if(white[0]=='w' && white[2]=='w' && white[4]=='w' && white[6]=='w' &&blue[7]=='b' && red[7]=='r' && green[7]=='g' && orange[7]=='o')
        {break;}
    }
}

void white_corners_alg_left()
{
    rotate_clock('b');rotate_clock('b');rotate_clock('b');
    rotate_clock('y');rotate_clock('y');rotate_clock('y');
    rotate_clock('b');
}
void white_corners_alg_right()
{
    rotate_clock('r');
    rotate_clock('y');
    rotate_clock('r');rotate_clock('r');rotate_clock('r');
}
void solve_white_corners()
{
    while(red[0]!='r' || red[6]!='r' || blue[0]!='b' || blue[6]!='b' || orange[0]!='o' || orange[6]!='o' || green[0]!='g' || green[6]!='g')
    {
        while(red[7]!='r')
        {