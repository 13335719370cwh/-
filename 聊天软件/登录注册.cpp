  #include<iostream>
    #include<string>
    #include <vector>
    #include <conio.h>
    void Display();//����display��ʾswitch()����
    void Register();//ע��
    void Enter();//��¼
    using namespace std; 
    class user{
	    private:
	    	 string ID;
	    	 string Name;
	    	 string Email;
	    	 string Password;
	    public:
	    	user(){};
	    	void Register();
	    	void Enter();
    } ;
    vector<user> people;
    
    void user:: Register()//ע��
    {
    	string pw1;
    	string pw2;
    	user person;
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
    	cin>>person.Name;
    	cout<<"����������䣺";
    	cin>>person.Email;
    	cout<<"�������������룺";
    flag0:
    	cin>>pw1;
    	cout<<"���ٴ�ȷ���������룺";
    	cin>>pw2;
    		if(pw1!=pw2)
    		{
    			cout<<"ǰ�������������벻һ�£���������������:";
    			goto flag0;
    		}
    	cout<<"ע��ɹ���"<<endl;
    	person.Password=pw1;
    	people.push_back(person);
    	Display();
    }
    void user::Enter()//��¼
    {
    	cout<<"����������ID��";
    flag1:
    	string id;
    	string pwd;
    	cin>>id;
    	for(int i=0;i<people.size();i++){//��֤ID�Ƿ����
    		int tk=1;tk++;
    		if(people.at(i).ID==id){
    			tk=2;
    			cout<<"�������������룺";
    flag2:
	    		cin>>pwd;
	    		if(people.at(i).Password!=pwd){
	    			cout<<"�����������������:";
	    			goto flag2;
	    			//�˳����� 
	    		}
    		cout<<"��¼�ɹ���"<<endl;
    		cout<<"     (1)Information�鿴��Ϣ\n     (2)Exit�˳�\n\nChoice:";
		    int choice;//ѡ�����
		    cin>>choice; switch(choice)
	    	{
		    case 1://�鿴��Ϣ
		    	cout<<"����IDΪ��"<<people.at(i).ID<<endl;
		    	cout<<"��������Ϊ��"<<people.at(i).Password<<endl;
		    	cout<<"�����û���Ϊ��"<<people.at(i).Name<<endl;
		    	cout<<"��������Ϊ��"<<people.at(i).Email<<endl;
		    	Display();
		    }
	    	}
    	}
    	cout<<"��ID�����ڣ�����������:";
    		goto flag1;
    }
    
    void Display()//����
    {
	    cout<<"     (1)Registerע��\n     (2)Enter��¼\n     (3)Exit�˳�\n\nChoice:";
	    int choice;//ѡ�����
	    user u;
	    cin>>choice; switch(choice)
    	{
		    case 1://ע��
		       u.Register();//���ú���
		        break;
		    case 2://��¼
		        u.Enter();//���ú���
		        break;
   		 }
    }
    int main()
    {
	    Display();//��ʾ���桡����ע�᣻����¼��3�˳�
	    cin.get();
	    return 0;
    }
