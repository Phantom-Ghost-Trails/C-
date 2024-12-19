#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{	
	int answer,input;
	srand(time(0));
	answer=rand()%100+1;
	cout<<"猜数字"<<endl;
	//cout<<"请输入你要猜的数字:"<<endl;
	//cout<<answer;
	//cin>>input;
	//此处应循环 
	do {
        cout<<"请输入你要猜的数字:";
        cin>>input;
        if (input>answer) 
		{
            cout<<"你猜的数字大了"<<endl;
        } 
		else if (input<answer) 
		{
            cout <<"你猜的数字小了"<< endl;
        } 
		else 
		{
            cout <<"恭喜你！你猜对了！"<< endl;
        }
    } while (input!=answer);
	//cout<<b;
	return 0;
}
