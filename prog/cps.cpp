#include <bits/stdc++.h>
#include <windows.h>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;

void instruction()
{
	cout<<"Yintaru 8086 Assemble Simulator v0.1.0\n";
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

int main(int argc, char* argv[])
{
	int n;
	cout<<"Enter assemble code length(lines): ";
	cin>>n;
	if(n<=0)
	{
		cerr<<"What are you doing?\n";
		system("pause");
		exit(-1);
	}
	if(n>64)
	{
		cerr<<"Too much codes! the chip only support up to 64 codes!\n";
		system("pause");
		exit(-1);
	}
	string input[64];
	cout<<"Now enter the codes, one assemble in one line:\n\n";
	for(int i=0;i<n;++i)
	{
		cin>>input[i];
	}
	
	system("cls");
	char c = 0, d=-114;
	short registers[8];
	char regaddr=0;
	char ip;
	short eax=-114, ebx=-114;
	for(int i=0;i<8;++i)
	{
		registers[i]=-114;
	}
	while(1)
	{
		if(input[c]=="ret")
		{
			break;
		}
		else if(input[c]=="get")
		{
			cout<<"+++++ Input? >";
			cin>>ip;
			registers[regaddr]=ip;
		}
		else if(input[c]=="prt")
		{
			cout<<"+++++ Output: "<<registers[regaddr]<<endl;
		}
		else if(input[c]=="inc")
		{
			++registers[regaddr];
		}
		else if(input[c]=="dec")
		{
			--registers[regaddr];
		}
		else if(input[c]=="clr")
		{
			registers[regaddr]=0;
		}
		else if(input[c]=="cpy")
		{
			registers[regaddr]=eax;
		}
		else if(input[c]=="nxt")
		{
			++regaddr;
			if(regaddr>7)
			{
				cerr<<"\nSimulation failed: register address > 7 at line "<<(int)c<<"\n";
				Sleep(114514);
				system("pause");
				exit(-2);
			}
		}
		else if(input[c]=="pre")
		{
			--regaddr;
			if(regaddr<0)
			{
				cerr<<"\nSimulation failed: register address < 0 at line "<<(int)c<<"\n";
				Sleep(114514);
				system("pause");
				exit(-2);
			}
		}
		else if(input[c]=="mva")
		{
			eax=registers[regaddr];
		}
		else if(input[c]=="mvb")
		{
			ebx=registers[regaddr];
		}
		else if(input[c]=="add")
		{
			registers[regaddr]=eax+ebx;
		}
		else if(input[c]=="sub")
		{
			registers[regaddr]=eax-ebx;
		}
		else if(input[c]=="tag")
		{
			d=c+1;
		}
		else if(input[c]=="jmp")
		{
			if(d==-114)
			{
				cerr<<"\nSimulation failed: attempt to jump to an address that haven't been initalized at program line"<<(int)c<<"\n";
				Sleep(114514);
				system("pause");
				exit(-2);
			}
			c=d;
			cout<<">>>>>>>>>>>>>JMP\n";
			continue;
		}
		else if(input[c]=="jnz")
		{
			if(d==-114)
			{
				cerr<<"\nSimulation failed: attempt to jump to an address that haven't been initalized at program line"<<(int)c<<"\n";
				Sleep(114514);
				system("pause");
				exit(-2);
			}
			if(registers[regaddr]!=0)
			{
				c=d;
				cout<<">>>>>>>>>>>>>JMP\n";
				continue;
			}
		}
		cout<<"-----\n\nNow Running : Line #"<<(int)c<<", \""<<input[c]<<"\"\n\n";
		cout<<"Registers:\n";
		for(int i=0;i<8;++i)
		{
			printf("#%d\t\t",i);
		}
		cout<<"\n";
		for(int i=0;i<8;++i)
		{
			printf("%05d\t\t",registers[i]);
		}
		cout<<"\n";
		for(int i=0;i<regaddr;++i)
		{
			cout<<"\t\t";
		}
		cout<<"$\n\n";
		cout<<"AX: "<<eax<<endl;
		cout<<"BX: "<<ebx<<endl;
		cout<<"Storaged instruction address by \"tag\": "<<(int)d<<"\n\n\n";
		
		c++;
		Sleep(200);
		while(!KEY_DOWN(VK_SPACE));
	}
	cout<<"\n\n\nProgram execution ended.\n";
	Sleep(114514);
	system("pause");
	
	return 0;
}
