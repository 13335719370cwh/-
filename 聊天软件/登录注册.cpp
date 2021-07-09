  #include<iostream>
    #include<string>
    #include <vector>
    #include <conio.h>
    void Display();//调用display显示switch()界面
    void Register();//注册
    void Enter();//登录
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
    
    void user:: Register()//注册
    {
    	string pw1;
    	string pw2;
    	user person;
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
    	cin>>person.Name;
    	cout<<"请绑定您的邮箱：";
    	cin>>person.Email;
    	cout<<"请设置您的密码：";
    flag0:
    	cin>>pw1;
    	cout<<"请再次确认您的密码：";
    	cin>>pw2;
    		if(pw1!=pw2)
    		{
    			cout<<"前后两次输入密码不一致，请重新设置密码:";
    			goto flag0;
    		}
    	cout<<"注册成功！"<<endl;
    	person.Password=pw1;
    	people.push_back(person);
    	Display();
    }
    void user::Enter()//登录
    {
    	cout<<"请输入您的ID：";
    flag1:
    	string id;
    	string pwd;
    	cin>>id;
    	for(int i=0;i<people.size();i++){//验证ID是否存在
    		int tk=1;tk++;
    		if(people.at(i).ID==id){
    			tk=2;
    			cout<<"请输入您的密码：";
    flag2:
	    		cin>>pwd;
	    		if(people.at(i).Password!=pwd){
	    			cout<<"密码错误，请重新输入:";
	    			goto flag2;
	    			//退出程序 
	    		}
    		cout<<"登录成功！"<<endl;
    		cout<<"     (1)Information查看信息\n     (2)Exit退出\n\nChoice:";
		    int choice;//选择界面
		    cin>>choice; switch(choice)
	    	{
		    case 1://查看信息
		    	cout<<"您的ID为："<<people.at(i).ID<<endl;
		    	cout<<"您的密码为："<<people.at(i).Password<<endl;
		    	cout<<"您的用户名为："<<people.at(i).Name<<endl;
		    	cout<<"您的邮箱为："<<people.at(i).Email<<endl;
		    	Display();
		    }
	    	}
    	}
    	cout<<"该ID不存在，请重新输入:";
    		goto flag1;
    }
    
    void Display()//界面
    {
	    cout<<"     (1)Register注册\n     (2)Enter登录\n     (3)Exit退出\n\nChoice:";
	    int choice;//选择界面
	    user u;
	    cin>>choice; switch(choice)
    	{
		    case 1://注册
		       u.Register();//调用函数
		        break;
		    case 2://登录
		        u.Enter();//调用函数
		        break;
   		 }
    }
    int main()
    {
	    Display();//显示界面　　１注册；２登录；3退出
	    cin.get();
	    return 0;
    }
