#include<stdio.h>
#include<string.h>
int main()
{
    char str1[1000],str2[1000];
    int cnt=0,n;
    scanf("%s %d",&str1,&n);
    gets(str2);
    while(strcmp(str2,"#"))
    {
    	gets(str2);
        if(strcmp(str1,str2)==0 && strcmp(str2,"#") !=0)
        {
            printf("Welcome in");
            break;
        }
        else if(strcmp(str1,str2)!=0 && strcmp(str2,"#") !=0)
        {
            cnt++;

            if(cnt == n)
            {
                printf("Wrong password: %s\nAccount locked",str2);break;
            }
            else
            {
                printf("Wrong password: %s\n",str2);
            }
        }
    }

    return 0;
}
