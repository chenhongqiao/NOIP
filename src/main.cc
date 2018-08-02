/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2018 Harrychen <harrychen0314@gmail.com>
 * 
 * NOIP is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * NOIP is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
void test1(void)
{
	int n;
	cin>>n;
	int t;
	int a=0;
	for(int i=0;i*50<=n;i++){
		for(int j=0;j*20<=n;j++){ 
			for(int k=0;k*10<=n;k++){
				t=50*i+20*j+10*k;
				if(t==n){
					a++;
				}
			}
		}
	}
	cout<<a<<endl;
}
void test2()
{
	int n;
	cin>>n;
	do{
		int y;
		y=n;
		n=n/2;
		y=y-n*2;
		cout<<"商"<<n<<","<<"余"<<y<<endl;
		if(n==0){
			break;
		}
	}while(1);
	
}
void test3()
{
	int d[25];
	int n[15];
	int i=0;
	int t=0;
	memset(n,0,sizeof(n));
	for(int i=0;i<25;i++){
		cin>>d[i];
		n[d[i]]+=1;
	}
	for(int i=1;i<=13;i++){
		if(n[i]!=2){
			cout<<i<<endl;
			break;
		}
	}
}
void test4()
{
	int n;
	cin>>n;
	int r=1;
	for(int i=1;i<=n;i++){
		r=r*2;
	}
	cout<<r<<endl;
}
void test5()
{
	int n,m,k,x;  
	cin>>n>>m>>k>>x;
	int last=m;  
	for(int i=0;i<k;i++){
		last=(last*10)%n;
	}
	last=(last+x)%n;
	cout<<last<<endl;
}
int d[10];
int total=0;
void test6_1(int dep,const int p,int last)
{
	int i=0;
	if(dep<8){
		while(i<=9){
			int used=0;
			for(int j=i;j>=0;j++){
				if(i==d[j]){
					used=1;
				}
			}
			if(used!=1){
				d[dep]=i;
				last=i;
			}
			test6_1(dep+1,p,last);
			i++;
		}
	}else{
		if(d[0]<d[6]<d[8] && d[1]<d[3] && d[6]<d[7] && d[2]<d[4] && d[0]+d[1]+d[3]+d[6]==d[6]+d[7]+d[8]==d[8]+d[4]+d[2]+d[0]==p){
			total++;
		}
		return;
	}
}
void test6()
{
	int p;
	cin>>p;
	test6_1(0,p,-1);
	cout<<total<<endl;
}	
void test7()
{
	int n;
	cin>>n;
	int* d;
	d=(int*)calloc(n+1,sizeof(int));
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	int l=1999999999;
	int sub=-1;
	for(int i=0;i<n;i++){
		if(d[i]<l){
			l=d[i];
			sub=i;
		}
	}
	int* tmp;
	tmp=(int*)calloc(n+1,sizeof(int));
	for(int i=0;i<n;i++){
		tmp[i+1]=d[i];
	}
	tmp[0]=l;
	for(int i=0;i<n;i++){
		if(i!=sub){
			cout<<d[i]<<endl;
		}
	}
}
void test8()
{
	int sub=1;
	int j=0;
	int h[10]={0};
	for(int i=0;i<1000;i++){
		sub=(sub+j)%10;
		h[sub]=1;
		j++;
	}
	for(int i=1;i<=10;i++){
		if(h[i]!=1){
			cout<<i<<endl;
			break;
		}
	}
}
void test9()
{
	int d[53];
	memset(d,1,sizeof(int));
	for(int i=2;i<=52;i++){
		for(int j=i;j<=52;j+=i){
			d[j]=-d[j];
		}
	}
	int t=0;
	for(int i=1;i<=52;i++){
		if(d[i]==1){
			total++;
			cout<<d[i]<<endl;
		}
	}
}
struct volunteer
{
	int id;
	int score;
};
int comp(const volunteer &a,const volunteer &b)
{
    return a.score>b.score;
}
void worldExpoVol()
{
	int n,m;
	cin>>n>>m;
	struct volunteer *d;
	d=(struct volunteer*)calloc(n+1,sizeof(struct volunteer));
	for(int i=0;i<n;i++){
		cin>>d[i].id>>d[i].score;
	}
	sort(d,d+n+1,comp);
	int ls=d[(int)(floor(m*1.5))].score;
	int in=0;
	for(int i=0;i<n;i++){
		if(d[i].score>=ls){
			in++;
		}
	}
	cout<<ls<<" "<<in<<endl;
	for(int i=0;i<n;i++){
		if(d[i].score>=ls){
			cout<<d[i].id<<" "<<d[i].score<<endl;
		}
	}
}
void runout()
{
	int m,t;
	cin>>m>>t;
	int l=(t/7)*120=(t%7)*17;
	if(l>=n){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
		cout<<l<<endl;
	}
}
void runout2()
{
	int m,t;
	cin>>m>>t;
	int p=0;
	const int m1=m;
	for(int i=0;t>=0;i++){
		int tmp=0;
		if(t<7){
			m-=17;
			t+=1;
		}
		else if(m<=120){
			m-=17;
			t=1;
		}else{
			if(p<10){
				//wait utill power full
				tmp+=floor(t/4);
				t-=tmp;
				p+=tmp;
			}
			if(p>=10){
				m-=60;
				t-=10;
			}
		}
	}
	if(m<m1){
		cout<<"NO"<<endl;
		cout<<m1-m<<endl;
	}else{
		cout<<"YES"<<endl;
	}
}
int runout3_1(int m,int t,int p)
{
	if(m>0&&t>0){
		runout3_1(m-17,t-1,p);
		runout3_1(m,t-1,p+4);
		runout3_1(m-=60,t-1,p-10);
	}else if(m<=0){
		return -1;
	}else if(t<=0){
		return m;
	}
	return -2;
}
void runout3(void)
{
	int m,t;
	cin>>m>>t;
	int result=runout3_1(m,t,0);
	if(result==-1){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
		cout<<result<<endl;
	}
}
void takepicture(void){
	int n;
	cin>>n;
	int *data=(int*)calloc(n,sizeof(int));
}
int main()
{
	worldExpoVol();
	return 0;
}
