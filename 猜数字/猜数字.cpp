#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{	
	int answer,input;
	srand(time(0));
	answer=rand()%100+1;
	cout<<"������"<<endl;
	//cout<<"��������Ҫ�µ�����:"<<endl;
	//cout<<answer;
	//cin>>input;
	//�˴�Ӧѭ�� 
	do {
        cout<<"��������Ҫ�µ�����:";
        cin>>input;
        if (input>answer) 
		{
            cout<<"��µ����ִ���"<<endl;
        } 
		else if (input<answer) 
		{
            cout <<"��µ�����С��"<< endl;
        } 
		else 
		{
            cout <<"��ϲ�㣡��¶��ˣ�"<< endl;
        }
    } while (input!=answer);
	//cout<<b;
	return 0;
}
