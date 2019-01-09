#include <iostream>
using namespace std;

double Div(double x, double y)
{
	if (y == 0){
		throw "除0错误！";
	}
	else
		return x / y;
}
void Func()
{
	int len, time;
	cin >> len >> time;
	cout << Div((double)len, (double)time) << endl;
}
void Test1()
{
	try{
		Func();
	}
	catch (const char* arg){
		cout << arg << endl;
	}
	catch (const int x){
		cout << x << endl;
	}
	catch (...){
		cout << "Unknow Error!" << endl;
	}
}
void Func1()
{
	int* p = new int[10];
	try{
		int len, time;
		cin >> len >> time;
		cout << Div((double)len, (double)time) << endl;
	}
	catch (...){
		cout << "delete[] p false" << p << endl;
		delete[] p; //有异常
		throw;      //重新抛出
	}
	delete[] p;  //没有异常
	cout << "delete[] p true" << endl;
}
void Test2()
{
	try{
		Func1();
	}
	catch (const char* arg){
		cout << arg << endl;
	}
	catch (...){
		cout << "Unknow Error!" << endl;
	}
}
class Base{
public:
	virtual void Print(){
		cout << "i am Base!" << endl;
	}
public:
	int num = 0;
	string msg;
};
class Dierve :public Base{
public:
	virtual void Print(){
		cout << "i am Dierve!" << endl;
	}
public:
	int id = 1;
};
void Func3(Base& x)
{
	x.Print();
	try{
		Dierve d;
		if (x.num == 0){
			d.msg = "Dierve error!";
			throw d;
		}
		else{
			x.msg = "base true!";
		}
	}
	catch (int i){
		cout << i << endl;
	}
}
void Test3()
{
	try{
		Base b;
		Dierve d;
		Func3(d);
	}
	catch (Base& b){
		cout << b.msg.c_str() << endl;
	}
}
int main()
{
	//Test1();        //异常的捕获与抛出
	//Test2();     //异常的重新抛出
	Test3();       //抛派生类，用基类捕获,基本都是这样
	return 0;
}