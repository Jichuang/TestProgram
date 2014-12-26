#include <iostream>
#include <iomanip> //I/O流控制头文件

using namespace std;

void printMonth(int year,int month);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month);
int getStartDay(int year, int month);
int getNubmerOfDaysInMonth(int year, int month);
int getTotalNumberOfDay(int year,int month);
bool isLeapYear(int year);

int main()
{
	char ch;
	bool flag=true;
	while(flag)
	{
		//输入年份
		cout<<"请输入年份："<<endl;
		int year;
		cin>>year;
		while( year<1800 )
		{
			cout<<"输入的年份不合法请重新输入:"<<endl;
			cin>>year;
		}

		//输入月份
		cout<<"请输入月分(1-12):"<<endl;
		int month;
		cin>>month;
		while( month<1 || month>12 )
		{
			cout<<"输入的月份不合法请重新输入:"<<endl;
			cin>>month;
		}

		system("cls");

		//输出这一年某个月的日历
		printMonth(year,month);

		cout<<endl<<endl<<"查询？(Y/N):"<<endl;
		cin>>ch;
		if(ch=='Y' | ch=='y')
		{
			flag=true;
		}
		else
		{
			flag=false;
		}
	}

    return 0;
}

void printMonth(int year,int month)
{
	printMonthTitle( year, month);

	printMonthBody(year,month);
}

void printMonthTitle(int year,int month)
{
	printMonthName(month);
	cout<<"           "<<year<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sta  "<<endl;
}

void printMonthName(int month)
{
	switch (month)
	{
	case 1:
		cout<<setw(16)<<"January";//设域宽为16个字节
		break;
	case 2:
		cout<<setw(16)<<"February";
		break;
	case 3:
		cout<<setw(16)<<"March";
		break;
	case 4:
		cout<<setw(16)<<"April";
		break;
	case 5:
		cout<<setw(16)<<"May";
		break;
	case 6:
		cout<<setw(16)<<"June";
		break;
	case 7:
		cout<<setw(16)<<"July";
		break;
	case 8:
		cout<<setw(16)<<"August";
		break;
	case 9:
		cout<<setw(16)<<"September";
		break;
	case 10:
		cout<<setw(16)<<"Octoter";
		break;
	case 11:
		cout<<setw(16)<<"November";
		break;
	case 12:
		cout<<setw(16)<<"December"; 
		break;
	}
}

void printMonthBody(int year,int month)
{
	//得到这个月的第一天是周几
	int startDay=getStartDay(year,month);

	//得到这个月的天数
	int numberOfDayInMonth=getNubmerOfDaysInMonth(year,month);

	int i;
	for(i=0;i<startDay;i++)
	{
		cout<<"     ";
	}
	for(i=1;i<=numberOfDayInMonth;++i)
	{
		cout<<setw(5)<<i; //设域宽为5个字节

		if ((i+startDay)%7==0)
		{
			cout<<endl;
		}
	}
}

int getStartDay(int year,int month)
{
	//第一天从 1800-1-1开始
	int startDay1800=3;

	int totalNumberOfDay=getTotalNumberOfDay(year,month);

	return (startDay1800+totalNumberOfDay)%7;
}

int getTotalNumberOfDay(int year,int month)
{
	int total=0;
	for(int i=1800;i<year;++i)
	{
		if(isLeapYear(i))
		{
			total+=366;
		}
		else
		{
			total+=365;
		}
	}

	for(int i=1;i<month;++i)
	{
		total+=getNubmerOfDaysInMonth(year,i);
	}

	return total;
}

int getNubmerOfDaysInMonth(int year,int month)
{
	if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
	{
		return 31;
	}
	if(month==4 || month==6 || month==9 || month==11)
	{
		return 30;
	}
	if(month==2)
	{
		return isLeapYear(year) ? 29 : 28;
	}
	return 0;//若月份不正确
}

bool isLeapYear(int year)
{
	return year%400==0 ||(year%4==0 && year%100!=0);
}