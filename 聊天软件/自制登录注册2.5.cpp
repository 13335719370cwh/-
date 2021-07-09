#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#define SIZE 100//最大用户容量
using namespace std;
void Display();//调用display显示switch()界面
int scount = 0,password1;//用作储存当前已注册用户数
class User
{
private:
	string ID;		//名称 
	string phone;	//号码 
	string name;	//姓名 
	string Email;   //邮箱 
	string password;//密码 
public:
	User() {};
	void Registers();//注册
	void Login();//登录
	void save();//保存
	void read();//读取
}us;

vector<User> people;
User user[SIZE];
void mima(){
flag:
	int pw1;
	int pw2;
	cout<<"密码(两次）：";
	cin>>pw1;
	cin>>pw2;
	if(pw1!=pw2) goto flag;
	else password1=pw1;
}
//保存
void User::save()
{
	ofstream ofile;
	ofile.open("user.txt", ios::out);

	for (int i = 0; i < scount; i++)
	{
		ofile << user[i].phone << endl;
		ofile << user[i].password << endl;
	}
	ofile.close();
}
//读取
void User::read()
{
	ifstream ifile;
	ifile.open("user.txt", ios::in);
	scount = 0;
	if (!ifile.is_open())
	{
		//cout << "文件打开失败！" << endl;
		return;
	}
	for (int i = 0; !ifile.eof(); i++)
	{
		ifile >> user[i].phone;
		ifile >> user[i].password;
		scount++;
	}
	scount--;
	ifile.close();
}
//注册
void User::Registers() {
	us.read();
    User person;
	cout<<"请设置您的ID：";
flag:
   	cin>>person.ID;
   	for(int i=0;i<people.size();i++){
   		if(people.at(i).ID==person.ID){
   			cout<<"该ID已存在，请重新设置:";
   			goto flag;
   		}
   	}
   	cout<<"请设置您的用户名：";
   	cin>>person.name;
   	cout<<"请绑定您的邮箱：";
   	cin>>person.Email;
   	cout<<"请绑定您的电话：";
   	cin>>person.phone;
   	cout<<"请设置您的密码：";
	mima();
	cout<<"注册成功！"<<endl;
    person.password=password1;
    people.push_back(person);
}
void User::Login() {
	us.read();//读取已储存用户数据
	string ph;//电话
	string pw;//密码
flag:
	cout<<"1、登录   2、忘记密码"<<endl; 
	int choice;//选择界面string pword;
    User person;
	char ch, passwords0[20];
	int x = 0,time =0;
	cin>>choice;
	switch(choice)
    {
	    case 1:
	    	cout<<"【系统提示】请输入手机号";
			cin>>ph ;
	        cout << "【系统提示】请输入密码：";
			while((ch = _getch()) != '\r'){
   				if(ch != '\b'){
					printf("*") ;
					password[x++] = ch ;
				}
				else{
					printf("\b \b") ;
					x-- ;
				}
			}
				password[x] = '\0' ;
				cout << endl;
			//依次比较已储存信息，比较是否匹配（如不匹配则提示错误）
			for (int i = 0; i < peolpe.size(); i++)
			{
				if (ph == user[i].phone && passwords0 == user[i].password)
				{
					time++;
				}
			}
			if (time == 0)
			{
				cout << "【系统提示】手机号或密码错误！" << endl;
				goto flag;
				}
			else cout << "【系统提示】登录成功！" << endl; 
			break;
	    case 2:
	        mima(); 
			cout<<"更改成功"<<endl;
    		person.password=password1;
    		people.push_back(person);
    		goto flag;
	        break;
   	}
}
int main()
{
	system("color B0");
	User user;
	user.Registers();//调用函数
	user.Login();
	cin.get();
	return 0;
}
