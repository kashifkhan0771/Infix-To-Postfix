#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class stacks
{
private:
    int topopr,topopn,first,con,r,c;
    char operands[250];
    char operators[250];
    char converted[500];
public:
    stacks()
    {
        topopr=-1;
        topopn=-1;
        first=-1;
        con=-1;
        r=0;
    }
    char rtopopr()
    {
        return operators[r];
    }
       void pushconverted(char con12)
    {
        if(con>250)
       {
           cout<<"OVERFLOW OCCURRED"<<endl;
           exit(0);
       }
       converted[++con]=con12;
    }
    char popconverted()
    {
       if(con<0)
       {
           cout<<"UNDERFLOW OCCURRED"<<endl;
           exit(0);
       }
       if(con>250)
       {
            cout<<"OVERFLOW OCCURRED"<<endl;
           exit(0);
       }
       return converted[r++];
    }
    void addcon()
    {
        con++;
    }
    bool empcon()
    {
        con--;
        if(con>=0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void push(char op)
    {
        if(!isopr(op))
        {
        if(topopn>250)
        {
            cout<<"OVERFLOW OCCURRED"<<endl;
            exit(0);
        }
       operands[++topopn]=op;
        }
        if(isopr(op))
        {
        if(topopr>250)
        {
            cout<<"OVERFLOW OCCURRED"<<endl;
            exit(0);
        }
       operators[++topopr]=op;
        }
    }
    char popoperands()
    {
       if(topopn<0)
       {
           cout<<"UNDERFLOW OCCURRED"<<endl;
           exit(0);
       }
       while(!emptyopn())
       {
       return operands[topopn--];
       }
    }
    char popoperators()
    {   if(topopr<0)
       {
           cout<<"UNDERFLOW OCCURRED"<<endl;
           exit(0);
       }
       while(!emptyopr())
       {
       return operators[topopr--];
       }
    }
    bool emptyopn()
    {
        if(topopn>=0)
        {
            return false;
        }
        else
            return true;
    }
        bool emptyopr()
    {
        if(topopr>=0)
        {
            return false;
        }
        else
            return true;
    }
    bool checkprcd(char opr1,char opr2)
    {
        if((opr1=='+'&&opr2==')')||(opr1=='-'&&opr2==')')||(opr1=='^'&&opr2==')')||(opr1=='*'&&opr2==')')||(opr1=='/'&&opr2==')')||(opr1=='/'&&opr2=='-')||(opr1=='/'&&opr2=='+')||(opr1=='^'&&opr2=='^')||(opr1=='^'&&opr2=='/')||(opr1=='^'&&opr2=='*')||(opr1=='^'&&opr2=='+')||(opr1=='^'&&opr2=='-')||(opr1=='*'&&opr2=='*')||(opr1=='*'&&opr2=='/')||(opr1=='/'&&opr2=='*')||(opr1=='/'&&opr2=='/')||(opr1=='+'&&opr2=='+')||(opr1=='+'&&opr2=='-')||(opr1=='-'&&opr2=='-')||(opr1=='-'&&opr2=='+'))
            return true;
        else
            return false;
    }
    bool isopr(char op3)
    {
        if(op3=='+'||op3=='^'||op3=='/'||op3=='*'||op3=='-')
            return true;
        else
            return false;
    }
};
int main()
{
    stacks st1;
    char infix[500];
    system("cls");
    cout<<"ENTER AN INFIX EXPERSSION(PUT ? AT END) "<<endl;
    for(int k=0;k<=500;k++)
    {
    cin>>infix[k];
    if(infix[k]=='?')
        break;
    }
    for(int i=0;i<=500;i++)
    {
        if(infix[i]=='?')
        {
            while(!st1.emptyopr())
            {
            st1.pushconverted(st1.popoperators());
            }
            break;
        }
        if(!st1.isopr(infix[i]))
        {
            st1.push(infix[i]);
            st1.pushconverted(infix[i]);
        }
        if(!st1.emptyopr()&&st1.isopr(infix[i])&&st1.checkprcd(st1.rtopopr(),infix[i]))
        {
            while(!st1.emptyopr())
            {
            st1.pushconverted(st1.popoperators());
            }
            st1.push(infix[i]);
        }
else if(st1.isopr(infix[i]))
{
    st1.push(infix[i]);
}
    }

    cout<<endl;
    cout<<endl;
    cout<<"POSTFIX:"<<endl;
    st1.addcon();
    cout<<endl;
    while(!st1.empcon())
    {
    cout<<st1.popconverted();
    }
    cout<<endl;
    cout<<endl;
return 0;
}
