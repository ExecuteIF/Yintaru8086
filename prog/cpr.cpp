#include <bits/stdc++.h>

using namespace std;

void instruction()
{
	cout<<"Yintaru 8086 Assemble Compiler v0.1.0\n";
	cout<<"Maxium code length: 64\n\n";
	cout<<"0\t0000\tret\t(;)\n";
	cout<<"1\t0001\tget\t(,)\n";
	cout<<"2\t0010\tprt\t(.)\n";
	cout<<"3\t0011\tinc\t(+)\n";
	cout<<"4\t0100\tdec\t(-)\n";
	cout<<"5\t0101\tclr\t(c)\n";
	cout<<"6\t0110\tcpy\t(p)\n";
	cout<<"7\t0111\tnxt\t(>)\n";
	cout<<"8\t1000\tpre\t(<)\n";
	cout<<"9\t1001\tmva\t(a)\n";
	cout<<"10\t1010\tmvb\t(b)\n";
	cout<<"11\t1011\tadd\t(j)\n";
	cout<<"12\t1100\tsub\t(s)\n";
	cout<<"13\t1101\ttag\t([)\n";
	cout<<"14\t1110\tjmp\t(})\n";
	cout<<"15\t1111\tjnz\t(])\n";
	cout<<"\n\n\n\n\n\n";
}

class items{
	public:
		const string id = "minecraft:diamond";
		int slot=0;
		int count=1;
		char data='\0';
		string combie()
		{
			return (string)("{Slot:"+to_string(slot)+",id:\""+id+"\",Count:"+to_string(count)+",tag:{display:{Name:\"{\\\"text\\\":\\\""+data+"\\\"}\"}}}");
		}
		string combie2()
		{
			return (string)"Slot:"+to_string(slot)+", Count:"+to_string(count)+", Data:"+data;
		}
};

int main(int argc, char* argv[])
{
	instruction();
	string a;
	char shorts[64] = {0};
	short bin[64] = {0};
	char hex[64] = {0};
	items it[64];
	int n=0;
	cout<<"Enter assemble code length(lines): ";
	cin>>n;
	if(n<=0)
	{
		cerr<<"What are you doing?\n";
		system("pause");
		exit(-2);
	}
	cout<<"Enter all the codes, one code in a single line:\n\n";
	for(int i=0;i<n;++i)
	{
		cin>>a;
		if(i==n-1&&a!="ret")
		{
			cout<<"\n!\n";
			cout<<"|~~~~~Here.\n\n";
			cout<<"ERROR: Program must be ended with assemble instruction \"ret\"."<<endl;
			cout<<"Compilation aborted.\n\n";
			system("pause");
			exit(-1);
		}
		if(a=="ret")
		{
			shorts[i]=';';
			bin[i]=0;
			hex[i]='0';
		}
		else if(a=="get")
		{
			shorts[i]=',';
			bin[i]=1;
			hex[i]='1';
		}
		else if(a=="prt")
		{
			shorts[i]='.';
			bin[i]=10;
			hex[i]='2';
		}
		else if(a=="inc")
		{
			shorts[i]='+';
			bin[i]=11;
			hex[i]='3';
		}
		else if(a=="dec")
		{
			shorts[i]='-';
			bin[i]=100;
			hex[i]='4';
		}
		else if(a=="clr")
		{
			shorts[i]='c';
			bin[i]=101;
			hex[i]='5';
		}
		else if(a=="cpy")
		{
			shorts[i]='p';
			bin[i]=110;
			hex[i]='6';
		}
		else if(a=="nxt")
		{
			shorts[i]='>';
			bin[i]=111;
			hex[i]='7';
		}
		else if(a=="pre")
		{
			shorts[i]='<';
			bin[i]=1000;
			hex[i]='8';
		}
		else if(a=="mva")
		{
			shorts[i]='a';
			bin[i]=1001;
			hex[i]='9';
		}
		else if(a=="mvb")
		{
			shorts[i]='b';
			bin[i]=1010;
			hex[i]='a';
		}
		else if(a=="add")
		{
			shorts[i]='j';
			bin[i]=1011;
			hex[i]='b';
		}
		else if(a=="sub")
		{
			shorts[i]='s';
			bin[i]=1100;
			hex[i]='c';
		}
		else if(a=="tag")
		{
			shorts[i]='[';
			bin[i]=1101;
			hex[i]='d';
		}
		else if(a=="jmp")
		{
			shorts[i]='}';
			bin[i]=1110;
			hex[i]='e';
		}
		else if(a=="jnz")
		{
			shorts[i]=']';
			bin[i]=1111;
			hex[i]='f';
		}
		else
		{
			cout<<"\n!\n";
			cout<<"|~~~~~Here.\n\n";
			cout<<"ERROR: Unknown assembly instruction at line "<<i+1<<endl;
			cout<<"Compilation aborted.\n\n";
			system("pause");
			exit(-1);
		}
	}
	cout<<"\n\n=====shortened=====\n";
	for(int i=0;i<n;++i)
	{
		printf("%c",shorts[i]);
		if((i+1)%8==0)
		{
			cout<<"\n";
		}
	}
	cout<<"\n\n=====binary=====\n";
	for(int i=0;i<n;++i)
	{
		printf("%04d ",bin[i]);
		if((i+1)%8==0)
		{
			cout<<"\n";
		}
	}
	cout<<"\n\n=====hexadecimal=====\n";
	for(int i=0;i<n;++i)
	{
		printf("%c",hex[i]);
		if((i+1)%8==0)
		{
			cout<<"\n";
		}
	}
	cout<<"\n\n\n";
	
	
	int j=0;
	for(int i=0;i<n;++i)
	{
		if(j==0)
		{
			goto nt;
		}
		if(it[j-1].data==hex[i])
		{
			++it[j-1].count;
			continue;
		}
		nt:
		it[j].slot=j;
		it[j].data=hex[i];
		it[j].count=1;
		++j;
	}
	cout<<"\n\n=====/give-command=====\n";
	if(j>27)
	{
		cout<<"\nWARNING: You have to manualy fill in a big chest with the following instructions instead of using the shulker boxes, \
			\nbecause your code is too long for automatical burning by shulker box but the 8086 processer can still process.\n\n\n";
		cout<<"Item ID: "<<it[0].id<<"\n\n";
		for(int i=0;i<j;++i)
		{
			cout<<it[i].combie2()<<endl;
		}
		goto end;	
	}
	cout<<"give @p minecraft:cyan_shulker_box{BlockEntityTag:{Items:[";
	for(int i=0;i<j;++i)
	{
		if(i!=0)
		{
			cout<<",";
		}
		cout<<it[i].combie();
	}
	cout<<"]}}";
	cout<<"\n\n";
	cout<<"NOTICE: this command must be executed in a command block or a command block minecart,\nsending the command by chatting may not execute the command properly.";
	end:
	cout<<"\n\n\n";
	system("pause");
	return 0;
}
