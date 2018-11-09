#include <iostream>
#include <stdio.h>
using namespace std;

/*
常言道“小赌怡情”。这是一个很简单的小游戏：首先由计算机给出第一个整数；然后玩家下注赌第二个整数将会比第一个数大还是小；玩家下注t个筹码后，计算机给出第二个数。若玩家猜对了，则系统奖励玩家t个筹码；否则扣除玩家t个筹码。

注意：玩家下注的筹码数不能超过自己帐户上拥有的筹码数。当玩家输光了全部筹码后，游戏就结束。

输入格式：

输入在第一行给出2个正整数T和K（<=100），分别是系统在初始状态下赠送给玩家的筹码数、以及需要处理的游戏次数。随后K行，每行对应一次游戏，顺序给出4个数字：

n1 b t n2

其中n1和n2是计算机先后给出的两个[0, 9]内的整数，保证两个数字不相等。b为0表示玩家赌“小”，为1表示玩家赌“大”。t表示玩家下注的筹码数，保证在整型范围内。

输出格式：

对每一次游戏，根据下列情况对应输出（其中t是玩家下注量，x是玩家当前持有的筹码量）：

玩家赢，输出“Win t! Total = x.”；
玩家输，输出“Lose t. Total = x.”；
玩家下注超过持有的筹码量，输出“Not enough tokens. Total = x.”；
玩家输光后，输出“Game Over.”并结束程序。
*/


int main()
{
	int T,K,i;//T是筹码
	int n1,b,t,n2;
	cin >> T >> K;
	for(i = 0; i < K; i++)
	{
		cin >> n1 >> b >> t >> n2;
		if(T <= 0)
		{
			cout<<"Game Over."<<endl;
			return 0;
		}
		else if(t > T)
		{
			cout<<"Not enough tokens.  Total = "<<T<<"."<<endl;
			continue;
		}
		if(b)//大,n1比n2大
		{
			if(n1 < n2)//嬴了
			{
				T += t;
				cout<<"Win "<<t<<"!  Total = "<<T<<"."<<endl;
			}
			else
			{
				T -= t;
				cout<<"Lose "<<t<<"."<<"  Total = "<<T<<"."<<endl;
			}
		}
		else
		{
			if(n1 > n2)
			{
				T += t;
				cout<<"Win "<<t<<"!  Total = "<<T<<"."<<endl;
			}
			else
			{
				T -= t;
				cout<<"Lose "<<t<<"."<<"  Total = "<<T<<"."<<endl;
			}
		}
		
	}
	return 0;
}

