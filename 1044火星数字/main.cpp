#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;


int change(char a[],int len)
{
	int i,sum = 0,temp;
	for(i = 0; i < len; i++)
	{
		temp = a[len - i - 1] - '0';
		sum += temp * pow(10,i);
	}
	return sum;
}



int main()
{
	char mars[][5] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	char upmars[][5] = {" ","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	int N,i,j,k = 0,flag = 1,len,sum;
	int cnt = 0,temp1;
	scanf("%d",&N);
	char str[100];
	getchar();
	for(i = 0; i < N; i++)
	{
		gets(str);
		len = strlen(str);
		if(str[0] >= '0' && str[0] <= '9')
			flag = 1;
		else if(str[0] >= 'a' && str[0] <= 'z')
			flag = 0;
		if(flag)//如果是数字 
		{
			sum = change(str,len);//转换为整数
			if(sum < 13)
			{
				cout << mars[sum] << endl;
			}
			else
			{
				if(sum % 13 == 0)
				{
					cout << upmars[sum/13 - 1] << endl;
				}
				else
				{
					cout << upmars[sum/13 - 1] << " " << mars[sum%13] << endl;
				}
			}
		}
		else//如果是火星文
		{	
			temp1 = 0;
            char *result = strtok(str," "); 
             for(j = 0;j < 13; j++)
			 {
                 if(strcmp(upmars[j],result) == 0)
				 {
                     temp1 = temp1 + j * 13;
                 }
             }
             for(j = 0; j < 13; j++)
			 {
                 if(strcmp(mars[j],result) == 0)
				 {
                     temp1 = temp1 + j;
                 }
             }
             result = strtok(NULL," ");
             if(result != NULL)
			 {
               for(j = 0; j < 13; j++)
			   {
                     if(strcmp(mars[j],result) == 0)
					 {
                        temp1 = temp1 + j;
					 }
               }
            }
            cout << temp1 << endl;
		}
	
	}
	
	return 0;
}


/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int main(){
    char low[13][5]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    char up[13][5]={" ","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    char temp[10];
    int temp1;
    int n;
    scanf("%d",&n);
    getchar(); 
    for(int i=0;i<n;i++){
        gets(temp);
        if(temp[0]>='0'&&temp[0]<='9'){
            int a = atoi(temp);
            if(a/13!=0){
                if(a%13){
                    printf("%s ",up[a/13]);
                    printf("%s\n",low[a%13]);
                }
                else
                    printf("%s\n",up[a/13]);
            }
            else    
                printf("%s\n",low[a%13]);
        }    
        else{
            temp1 = 0;
            char *result = strtok(temp," "); 
            for(int j=0;j<13;j++){
                if(strcmp(up[j],result)==0){
                    temp1 = temp1+j*13;
                }
            }
            for(int j=0;j<13;j++){
                if(strcmp(low[j],result)==0){
                    temp1 = temp1+j;
                }
            }
            result = strtok(NULL," ");
            if(result!=NULL){
                for(int j=0;j<13;j++){
                    if(strcmp(low[j],result)==0){
                        temp1 = temp1+j;
                    }
                }
            }
            printf("%d\n",temp1);
        }
        
    } 
}
*/