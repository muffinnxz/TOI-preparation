#include<iostream>
#include<string.h>
#include<string>
#include<queue>
using namespace std;

int checkifseq(char LF[],int wordc)
{
	int i,alphatbet[26];
	for(i=0;i<26;i++)
		alphatbet[i]=0;
	if(wordc<4) return 0;
	for(i=0;i<wordc-1;i++)
	{
		if(int(LF[i])!=int(LF[i+1])-1) return 0;
		alphatbet[int(LF[i])-65]++;
		if(alphatbet[int(LF[i])-65]>1) return 0;
	}
	return 1;
}
int checknL(int LL[],int wordc)
{
	int i,check=LL[0]-LL[1];
	for(i=1;i<wordc-1;i++)
	{
		if(LL[i]-LL[i+1]!=check) return 0;
	}
	return 1;
}
main()
{
	char sente[1000],word[100];
	char *pch,*clet;
	int *pint;
	gets(sente);
	pch=strtok(sente," ");
	int i,wordc=0,listLetter[100];
	char listFirstL[100];
	while(pch!=NULL)
	{
		int letterc=0;
		wordc++;
		strcpy(word,pch);
		clet=&word[0];
		listFirstL[wordc-1]=word[0];
		while(*clet!='\0')
		{
			letterc++;
			clet++;
		}
		listLetter[wordc-1]=letterc;
		pch=strtok(NULL," ");
	}
	pch=listFirstL;
	pint=listLetter;
	if(!checkifseq(pch,wordc)) cout<<"Not Ordered Sentence";
	else if(!checknL(pint,wordc)) cout<<"Ordered Sentence";
	else if(listLetter[0]-listLetter[1]==0) cout<<"Constant Ordered Sentence";
	else if(listLetter[0]-listLetter[1]>0) cout<<"Decreasing Ordered Sentence";
	else cout<<"Increasing Ordered Sentence";
}
