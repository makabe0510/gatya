#include<iostream>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "SSR_list.h"
#include "SR_list.h"
#include "R_list.h"
#include <vector>

using namespace std;

int count=0,flag=-1,SSRcount=0;
vector<int> check(50,0);

#define jewel8400 9800
#define jewel4200 5000
#define jewel2650 3200
#define jewel1300 1600
#define jewel760 960
#define jewel360 480
#define jewel60 120
#define money9800 8400
#define money5000 4200
#define money3200 2650
#define money1600 1300
#define money960 760
#define money480 360
#define money120 60

void *list(int,char*);
void *write(int,int,char*);
int keisan(int);

int main(){
  int num,i;
  char name[10][100];
  cout<<"お迎えしたいSSRの番号を入力してください。"<<endl;
  for(i=0;i<27;i++){
    cout<<i<<" "<<SSR_list[i]<<endl;
  }
  cin>>num;
  srand((unsigned) time(NULL));
  cout<<"結果は、\n"<<endl;
  while(1){
    //SSRcount=0;
    for(i=0;i<10;i++){
      list(i,name[i]);
      count+=1;
      cout<<name[i]<<endl;
    }
    cout<<"-----------------------------------------------------------"<<endl;
    if(flag==num){
      break;
    }
  }
  cout<<"です。\n"<<endl;
  cout<<count<<"連で、"<<SSR_list[flag]<<" をお迎えしました。\n"<<endl;
  cout<<"引いたSSRは、\n"<<endl;
  for(i=0;i<50;i++){
    if(check[i]!=0){
      cout<<SSR_list[i]<<" "<<check[i]<<"枚"<<endl;
    }
  }
  cout<<"\nです。\n"<<endl;
  cout<<"かかったお金は"<<keisan(count)<<"円です。"<<endl;
  return 0;
}

void *list(int i,char *str){
  int rarity,seed;
  int num=0;
  seed=rand()%1000;
  switch(num){
  case 0:
    if(i<9){
      if(seed>=0&&seed<=884){
	rarity=0;
      }else if(seed>=885&&seed<=984){
	rarity=1;
      }else{
	rarity=2;
      }
    }else{
      if(seed>=0&&seed<=984){
	rarity=1;
      }else{
	rarity=2;
      }
    }
    write(num,rarity,str);
  }
}

void *write(int num,int rarity,char *str){
  int i;
  switch(rarity){
  case 0:
    i=rand()%71;
    strcpy(str,R_list[i]);
    break;
  case 1:
    i=rand()%54;
    strcpy(str,SR_list[i]);
    break;
  case 2:
    i=rand()%27;
    strcpy(str,SSR_list[i]);
    flag=i;
    check[i]+=1;
    SSRcount+=1;
    break;
  }
}

int keisan(int count){
  int jewel=count*250;
  int money=0,tmp=0;
  while(1){
    if(jewel>=8400){
      tmp=jewel/8400;
      money+=tmp*jewel8400;
      jewel-=tmp*8400;
    }else if(jewel>=4200){
      tmp=jewel/4200;
      money+=tmp*jewel4200;
      jewel-=tmp*4200;
    }else if(jewel>=2650){
      tmp=jewel/2650;
      money+=tmp*jewel2650;
      jewel-=tmp*2650;
    }else if(jewel>=1300){
      tmp=jewel/1300;
      money+=tmp*jewel1300;
      jewel-=tmp*1300;
    }else if(jewel>=760){
      tmp=jewel/760;
      money+=tmp*jewel760;
      jewel-=tmp*760;
    }else if(jewel>=360){
      tmp=jewel/360;
      money+=tmp*jewel360;
      jewel-=tmp*360;
    }else if(jewel>=60){
      tmp=jewel/60;
      money+=tmp*jewel60;
      jewel-=tmp*60;
    }else if(jewel<60&&jewel>0){
      money+=jewel60;
      break;
    }else if(jewel==0){
      break;
    }
  }
  return money;
}
