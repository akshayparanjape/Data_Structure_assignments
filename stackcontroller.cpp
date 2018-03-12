#include<iostream>
#include<cstring>
using namespace std;
# define Maxsize 10000

class stack
{
public:
    int top;
    string arr[Maxsize];
    int IsEmpty()
    {
        if (top <0)
            return 1;
        else
            return 0;
    }
    int IsFull()
    {
        if (top==Maxsize-1)
            return 1;
        else
            return 0;
    }
    void push(string v)
    {
        if (IsFull()==1)
            cout<< "Stack is full"<< endl;
        else
            {top=top+1;
            arr[top]=v;}
    }
    void pop()
    {
        if (IsEmpty()==1)
            cout << "Stack is empty" << endl;
        else
            top--;
    }
};

stack stack_c;

class all_string
{
public:
	
	string rule_matrix[Maxsize][Maxsize];
	string look_up[Maxsize][Maxsize];
	string input[Maxsize];
	string sym[Maxsize];
	int rules_applied[Maxsize];
};

all_string M;

int get_c(string a[], string s ){
    int i=0;
    while(a[i]!= s)
        i=i+1;
    return i;
}

int check(string a, string b){
    if (a==b)
        return 1;
    else
        return 0;
}

int power(int a,int b){
    if (b==0)
        return 1;
    else
        return a*power(a,b-1);
}

int number(string a, int initial){
    int size=a.size()-1;
    int num=0;
    int pow=-1;
    for(int i=size;i>initial;i--)
        {pow=pow+1;
        num=num+(a[i]-'0')*power(10,pow);}
    return num;
}

string no_to_string(int number){
    if (number == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

int size_arr_string(string a[]){
    int count=0;

    for(int i=0;i<Maxsize;i++)
        {if(check(a[i]," ")==0 && check(a[i],"")==0)
                  count=count+1;}
    return count;
}

int Rule(int i){
    int size=size_arr_string(M.rule_matrix[i-1])-1;
    int count;
    for (int top=stack_c.top;top>=0;top--)
        {
        count = 0;
        for (int j=0;j<size-1;j++)
            {
            count=count+check(M.rule_matrix[i-1][size-j],stack_c.arr[top-2*j-1]);}
        if (count == (size-1))
            {stack_c.top=top- 2*(size-1);
            break;}
        }
    stack_c.push(M.rule_matrix[i-1][0]);
    int r=number(stack_c.arr[stack_c.top-1],-1);
    int c=get_c(M.sym,M.rule_matrix[i-1][0]);
    int state=number(M.look_up[r][c],-1);
    stack_c.push(no_to_string(state));
    return state;
}

int final_task(int n){
    int r,c,state;
    r=0;
    string to_do;
    int count_rule=0;
    int flag;
    stack_c.push("0");
    for (int i=0;i<=Maxsize;i++)
        {   c=get_c(M.sym,M.input[i]);
            to_do=M.look_up[r][c][0];
            if (to_do=="p")
                {state=number(M.look_up[r][c],0);             
                stack_c.push(M.input[i]);
                stack_c.push(no_to_string(state));
                }
            else if (to_do=="r")
                {state=Rule(number(M.look_up[r][c],0));
                i=i-1;
                int v=number(M.look_up[r][c],0);
                M.rules_applied[count_rule]=v;
                count_rule=count_rule+1;}
            else if (to_do=="a")
                {cout << "accepted"<<endl;
             	flag=1;   
                break;}
            else
                {cout<<"rejected"<<endl;
                flag=0;
                break;}
            r=state;
        }

	int rev_rule[Maxsize];
	for (int i=0;i<count_rule;i++)
		{rev_rule[count_rule-i-1]=M.rules_applied[i];}
	
	if (flag==1)
	{for (int i=0;i<count_rule;i++)
		{
		for(int j=0;j<Maxsize;j++)
			cout<<M.rule_matrix[rev_rule[i]-1][j];
		cout<<endl;}
	}
}

main(){
    int no_rule;
    cin>> no_rule;
    cin.ignore();

    char arr[no_rule][Maxsize];

    for(int i=0 ; i<no_rule ; i++)
        {
        cin.getline(arr[i],Maxsize);
        }
    int n_count;
    for(int i=0 ; i<no_rule ; i++)
        {
        n_count =0;
        char* temp_char;
        temp_char=strtok(arr[i]," ");

        while (temp_char != NULL)
            {
            M.rule_matrix[i][n_count]=temp_char;
            temp_char = strtok(NULL, " ");
            n_count=n_count+1;
            }
        }

    int f,n_f;
    cin>> f;
    cin.ignore();
    cin >> n_f;
    cin.ignore();
    int t_sym=f+n_f;
    for(int i=0;i<t_sym;i++)
        {cin>> M.sym[i];
        cin.ignore();}
    int r,c;
    cin >>r;
    cin.ignore();
    cin >>c;
    cin.ignore();
    for(int i=0;i<r;i++)
    { 
        for(int j=0;j<c;j++)
            {
            cin >> M.look_up[i][j];
            cin.ignore();
            }
    }
    int no_seq;
    cin>>no_seq;
    cin.ignore();
    stack_c.top=-1;
    for(int i=0;i<no_seq;i++)
        {
        stack_c.top=-1;
        int n;
        for (int i=0;i<Maxsize; i++)
            {cin>> M.input[i];
            cin.ignore();
            if (M.input[i]=="$")
                {n=i;
                break;}
            }
        final_task(n);
        }
}
