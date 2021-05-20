#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

void print();
void randomarray();
void check();
void move();

int as[5][5], size, arrwidth, shuffle_score=0, flagwin=0;
int i, j, t1, t2, points=0;
char vs=186, hs=205;

int mainshuffle()
{

  clrscr();
  flagwin=0;
  points=0;
  cout<<"enter size (2-5):";
  cin>>arrwidth;

  t1=t2=arrwidth-1;
  randomarray();

  while(1){
    check();
    if(flagwin)
     break;
    print();
    move();

  }

  getch();
  return (shuffle_score);

}

void randomarray()
{
   randomize();
   int i,k,j;
   int elements; int b[25];
   l:
   elements= (arrwidth*arrwidth)-1;

   for(i=1; i<=25; i++)
     b[i-1]=i;

   for(i=0; i<arrwidth; i++)
   {
     for(j=0; j<arrwidth; j++)
     {
       k=random(elements);
       as[i][j]=b[k];
       b[k]=b[elements-1];
       elements--;
     }
   }
   as[arrwidth-1][arrwidth-1]=0;

   if(a[0][0]==1)
   goto l;
}

void print()
{
  clrscr();
  cout<<endl<<endl<<"                              Shuffle game"<<endl<<endl<<endl<<endl;
  cout<<endl<<' ';
  int z=0;
  while(z++<arrwidth)
   cout<<hs<<hs<<hs<<hs<<' ';
  cout<<endl;

  for(i=0; i<arrwidth; i++)
   {
     cout<<vs<<' ';
     for(j=0; j<arrwidth; j++)
      {
	 if(as[i][j]==0)
	  cout<<' '<<' '<<' '<<vs<<' ';
	 else
	  {
	    if(as[i][j]/10==0)
	     cout<<as[i][j]<<' '<<' '<<vs<<' ';
	    else
	      cout<< as[i][j]<<' '<<vs<<' ';
	  }
      }
     cout<<endl<<' ';
     z=0;
     while(z++<arrwidth)
      cout<<hs<<hs<<hs<<hs<<' ';
     cout<<endl;
   }
   cout<<endl<<endl<<endl<<endl;


}

void move()
{
  int c,flag=0;
  cout<<"Enter number to move or 0 to exit:";
  cin>>c;
  points++;
  cout<<"Number of moves:"<<points;

  if(c==0)
   exit(0);

  for(i=0; i<arrwidth; i++)
  {
    for(j=0; j<arrwidth; j++)
     if(as[i][j]==c)
       {
	 as[t1][t2]=c;
	 as[i][j]=0;
	 t2=j; t1=i;
	 flag=1;
	 break;
      }
    if(flag)
     break;
  }
 }

void check()
{

  int flag=0, number=1;
  for(i=0; i<arrwidth; i++)
  {
    for(j=0; j<arrwidth; j++)
    {
     if(as[i][j]==0)
       as[i][j]=arrwidth*arrwidth;
     if(as[i][j]!=number)
       {
	 flag=1;
	 break;
       }
     number++;
    }
    if(flag)
     break;

  }

  if(as[i][j]==arrwidth*arrwidth)
   as[i][j]=0;

  if(!flag)
  {
     clrscr();
     cout<<endl<<endl<<endl<<endl<<"You have won!";
     cout<<endl<<endl<<"Total Points: "<<100-points;
     shuffle_score=100-points;
     getch();
     flagwin=1;
  }
}



