#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#define SIZE 100//����û�����
using namespace std;
void Display();//����display��ʾswitch()����
int scount = 0,password1;//�������浱ǰ��ע���û���
class User
{
private:
	string ID;		//���� 
	string phone;	//���� 
	string name;	//���� 
	string Email;   //���� 
	string password;//���� 
public:
	User() {};
	void Registers();//ע��
	void Login();//��¼
	void save();//����
	void read();//��ȡ
}us;

vector<User> people;
User user[SIZE];
void mima(){
flag:
	int pw1;
	int pw2;
	cout<<"����(���Σ���";
	cin>>pw1;
	cin>>pw2;
	if(pw1!=pw2) goto flag;
	else password1=pw1;
}
//����
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
//��ȡ
void User::read()
{
	ifstream ifile;
	ifile.open("user.txt", ios::in);
	scount = 0;
	if (!ifile.is_open())
	{
		//cout << "�ļ���ʧ�ܣ�" << endl;
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
//ע��
void User::Registers() {
	us.read();
    User person;
	cout<<"����������ID��";
flag:
   	cin>>person.ID;
   	for(int i=0;i<people.size();i++){
   		if(people.at(i).ID==person.ID){
   			cout<<"��ID�Ѵ��ڣ�����������:";
   			goto flag;
   		}
   	}
   	cout<<"�����������û�����";
   	cin>>person.name;
   	cout<<"����������䣺";
   	cin>>person.Email;
   	cout<<"������ĵ绰��";
   	cin>>person.phone;
   	cout<<"�������������룺";
	mima();
	cout<<"ע��ɹ���"<<endl;
    person.password=password1;
    people.push_back(person);
}
void User::Login() {
	us.read();//��ȡ�Ѵ����û�����
	string ph;//�绰
	string pw;//����
flag:
	cout<<"1����¼   2����������"<<endl; 
	int choice;//ѡ�����string pword;
    User person;
	char ch, passwords0[20];
	int x = 0,time =0;
	cin>>choice;
	switch(choice)
    {
	    case 1:
	    	cout<<"��ϵͳ��ʾ���������ֻ���";
			cin>>ph ;
	        cout << "��ϵͳ��ʾ�����������룺";
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
			//���αȽ��Ѵ�����Ϣ���Ƚ��Ƿ�ƥ�䣨�粻ƥ������ʾ����
			for (int i = 0; i < peolpe.size(); i++)
			{
				if (ph == user[i].phone && passwords0 == user[i].password)
				{
					time++;
				}
			}
			if (time == 0)
			{
				cout << "��ϵͳ��ʾ���ֻ��Ż��������" << endl;
				goto flag;
				}
			else cout << "��ϵͳ��ʾ����¼�ɹ���" << endl; 
			break;
	    case 2:
	        mima(); 
			cout<<"���ĳɹ�"<<endl;
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
	user.Registers();//���ú���
	user.Login();
	cin.get();
	return 0;
}
