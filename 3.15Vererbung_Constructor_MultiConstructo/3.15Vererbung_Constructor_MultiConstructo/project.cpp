#include <iostream>
using namespace std;


//四：虚基类，虚继承，虚派生





//三:类型转换
class Grand
{
public:
	Grand() {};
	Grand(int i, int j, int k){}

};

class A:public Grand
{
public:
	A() {};
	A(int i, int j, int k):Grand(i,j,k) {};
	virtual void func() { cout << "run funcA" << endl; }
public:
	void funcPrintA() { cout << "调用A的funcPrintA（）成员函数" << endl; }
	
};

class B
{
public:
	B(int tv) {};
	void func() { cout << "run funcB" << endl; }
};

class C :public A, public B
{

public:
	using A::A;
	using B::B;	

public:
	C(int i, int j, int k) :A(i,j,k),B(i) {};
	void func() { cout << "run funcC" << endl; }
	void funcprintC() { cout << "调用C的funcPrintC（）成员函数" << endl; }
};
int main()
{
	Grand* pg = new C(1,2,3);
	A* pa = new C(4,5,6);
	pa->func();		//		run funcC
	pa->A::func();	//		run funcA	//如果要调用父类A的函数与C的同名成员函数同名的话就要在父类函数前用virtual语句	
	pa->funcPrintA();//不是同名的话可以正常调用。
	C c(1);
	c.funcprintC();
	

	
	//B* pb = new C(7, 8, 9);
	//C myc(898);
	//Grand mygrand(myc);//不熟悉可回顾3章十一节
	//C c(1, 2, 3);
}






////(2.4)从多个父类继承构造函数。例如一个子类继承多个父类。
////子类要定义同参数的构造函数的自己的版本。
//
//class A
//{
//public:
//	A(int tv) {};
//	void func() { cout << "run funcA" << endl; }
//};
//
//class B
//{
//public:
//	B(int tv) {};
//	void func(){ cout << "run funcB"<<endl; }
//};
//class C :public A, public B
//{
//public:
//	using A::A;	//继承A的构造函数，为的是不用再写自己的构造函数。	C(int tv):A(tv){}
//	using B::B;//继承B的构造函数，为的是不用再写自己的构造函数。	C(int tv):B(tv){}	但是这里将出现错误，因为A和B的构造函数相同。
//	//如果一个类从他的的基类继承了相同的构造函数，这个类必须为该构造函数定义他自己的版本。
//	C(int tv):A(tv),B(tv) {};//在C中定义自己的构造函数版本。
//	void func() { cout << "run funcC" << endl; }
//};
//int main()
//{
//	
//	
//	
//}

////	二: 2）静态成员变量
//		//静态成员属于类，不属于对象
//	//(2.3)派生类构造函数与析构函数
//	//a)构造一个派生类对象将同时构造并初始化所有的基类对象。
//	//b）派生类的构造函数初始化列表值初始化他的直接父类。每个类的构造函数都负责初始化他的直接父类，就会让所有类都得到初始化。
//	//c）派生类构造函数初始化列表将实参分别传递给每个直接父类；子类的构造顺序跟派生列表中父类的出现顺序保持一致。
//	//重要概念：显式初始化基类，和隐士初始化，当基类有默认构造函数时，子类可以不用初始化基类的默认构造函数，这是就用到了隐士初始化基类功能。
//	
//
//class Grand
//{
//public:
//	Grand (int i):m_valuegrand(i){}//父类构造函数。
//
//public://父类成员函数。。
//	void myinfo()
//	{
//		cout << m_valuegrand;
//	}
//
//public:
//	int m_valuegrand;
//	virtual ~Grand() {}
//
//public:
//	static int m_static;//生明一个静态成员。如果你在代码中不用m static，那么你可以不定义，如果代码中用到m static，则必须定义，否则连接出错。
//};
//
//int Grand::m_static = 8;//为了能够使用我们定义的这个静态成员变量，我们定义了这个静态成员变量(分配内存)；
//
//class A :public Grand
//{
//public:
//
//	A(int i): Grand(i),m_valuea(i)//构造函数
//	{
//		
//	}
//	virtual ~A()
//	{
//
//	}
//	void myinfo()
//	{
//		cout << "调用了 A myinfo"<< endl;
//	}
//
//public:
//	int m_valuea;
//};
//
//class B//类B不继承Grand
//{
//public:
//	B(int i):m_valueb(i){}
//	~B(){}
//	
//	//virtual void myinfoB() = 0;
//
//public:
//	void funbBprint()//父类的成员函数
//	{
//		cout << "funBprint"<<endl;
//	}
//public:
//	int m_valueb;
//};
//
////类C同时继承父类A和类B
//class C:public A, public B //派生列表
//{
//public:
//	C():m_valuec(0),A(0),B(0){}
//	C(int a, int b, int c):A(a),B(b),m_valuec(c)
//	{
//
//	}
//	/*void myinfoB()
//	{
//		cout << "调用了myinfoB"<< endl;
//	}*/
//public:
//	void myinfo() 
//	{
//
//		cout << "调用了C myinfo()";
//	}
//	void myinforc()
//	{
//		cout << m_valuec << endl;
//	}
//public:
//	void returnBfunc()//在这里里面调用父类的成员函数。
//	{
//		B::funbBprint();
//	}
//	~C()
//	{
//
//	}
//
//public:
//	int m_valuec;
//};
//
//
//int main()
//{
//	C c(22,23,24);
//	c.returnBfunc();
//	c.m_static = 5;//可以用对象名来引用静态变量。
//	Grand::m_static = 1;//可以用类名来引用静态变量。
//	A::m_static = 2;
//	//B::m_static = 4;//B没有继承任何类所以不行。
//	C::m_static = 3;
//	
//	
//}


//二:1） //单继承，如果从多个父类来产生出子类： 多重继承；
//class Grand
//{
//public:
//	Grand (int i):m_valuegrand(i){}//父类构造函数。
//
//public://父类成员函数。。
//	void myinfo()
//	{
//		cout << m_valuegrand;
//	}
//
//public:
//	int m_valuegrand;
//	virtual ~Grand() {}
//
//public:
//	static int m_static;//生明一个静态成员。如果你在代码中不用m static，那么你可以不定义，如果代码中用到m static，则必须定义，否则连接出错。
//};
//
//int Grand::m_static = 8;//为了能够使用我们定义的这个静态成员变量，我们定义了这个静态成员变量(分配内存)；
//
//class A :public Grand
//{
//public:
//	//二：1）多重继承
//	/*为什么在子类中一定要负责父类的初始化：
//	构造方法用来初始化类的对象，与父类的其它成员不同，它不能被子类继承（子类可以继承父类所有的成员变量和成员方法，但不继承父类的构造方法）。因此，在创建子类对象时，为了初始化从父类继承来的数据成员，系统需要调用其父类的构造方法。
//
//		如果没有显式的构造函数，编译器会给一个默认的构造函数，并且该默认的构造函数仅仅在没有显式地声明构造函数情况下创建。
//
//		构造原则如下：
//
//		1. 如果子类没有定义构造方法，则调用父类的无参数的构造方法。
//		2. 如果子类定义了构造方法，不论是无参数还是带参数，在创建子类的对象的时候, 首先执行父类无参数的构造方法，然后执行自己的构造方法。
//		3. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数，则会调用父类的默认无参构造函数。
//		4. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类自己提供了无参构造函数，则会调用父类自己的无参构造函数。
//		5. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类只定义了自己的有参构造函数，则会出错（如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法）。
//		6. 如果子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式.*/
//
//	//如果子类的构造函数没有显示调用父类的构造函数且父类只定义了自己的有参构造函数，则会出错（如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法）。
//	//Grand(i)的意思是每个子类的构造函数初始化列表里面，负责解决自己父类的初始化问题，调用父类类名并初始化参数。
//	A(int i): Grand(i),m_valuea(i)//构造函数
//	{
//		
//	}
//	virtual ~A()
//	{
//
//	}
//	void myinfo()
//	{
//		cout << "调用了 A myinfo"<< endl;
//	}
//
//public:
//	int m_valuea;
//};
//
//class B//类B不继承Grand
//{
//public:
//	B(int i):m_valueb(i)
//	{
//	}
//	~B()
//	{
//	}
//	virtual void myinfoB() = 0;
//
//public:
//	void funbBprint()//父类的成员函数
//	{
//		cout << "funBprint"<<endl;
//	}
//public:
//	int m_valueb;
//};
////类C同时继承父类A和类B
//class C:public A, B
//{
//public:
//	C(int a, int b, int c):A(a),B(b),m_valuec(c)
//	{
//
//	}
//	void myinfoB()
//	{
//		cout << "调用了myinfoB"<< endl;
//	}
//public:
//	void myinfo() 
//	{
//
//		cout << "调用了C myinfo()";
//	}
//	void myinforc()
//	{
//		cout << m_valuec << endl;
//	}
//public:
//	void returnBfunc()//在这里里面调用父类的成员函数。
//	{
//		B::funbBprint();
//	}
//	~C()
//	{
//
//	}
//
//public:
//	int m_valuec;
//};
//
//int main()
//{
//	C c(45,46,49);
//	c.myinforc();
//	c.A::myinfo();
//	c.myinfo();
//	c.myinfoB();
//	c.returnBfunc();//如何调用父类的成员函数，
//	
//}
//
//
//
////一: 继承的构造函数
//
//class A
//{
//public:
//	A(int i, int j, int k )
//	{}
//	A(){}
//	A(int i){}
//
//};
//
//class B :public A
//{
//public:
//	//B(int i, int j, int k): A(i,j,k){}B先不用写自己的构造函数了
//	using A::A;	//继承A的构造函数.函数遮蔽的时候用using（3章七节）使父类中的同名函数在子类中可见，using它的主要功能就是让某个名字在当前作用域内可见。
//					//在这里::后面是构造函数名A,编译器遇到这行代码时，会把父类的每一个构造函数，都生成一个与之对应的派生类构造函数。
//						//A::A大概会生成这样的一个函数>
//							//B（构造函数形参列表...）:A（照抄的构造函数形参列表）{}:函数为空
//									//B(int i, int j, int k): A(i,j,k){};
//	//如果父类A的构造函数有默认参数的话，那么编译器遇到这种using A::A的时候，就会帮咱们在派生类B中构造出多个构造函数出来。
//	//a) 第一构造函数是带有所有参数的构造函数。
//	//b）其余的构造函数，每个分别省略掉一个默认参数。
//	//B(int i, int j, in k): A(i,j,k){}
//	//B(int i, int j){}
//	//如果父类含多个构造函数，则多数情况下，派生类会继承成所有这些构造函数，但如下例外情况:
//	
//};
//
//
//int main1()
//{
//	//一: 继承的构造函数
//	//一个类只继承其直接父类的构造函数。默认，拷贝，移动函数式不能被继承的。
//	//1）如果你在派生类中定义的构造函数与基类构造函数有相同的参数列表，那么从从父类中继承来的构造函数会被你在派生类中的定义覆盖掉（相当于你只继承了父类一部分构造函数）。
//	//派生类的构造函数优先覆盖通过父类构造的构造函数。
//	//2)父类中默认和拷贝移动构造函数这些是不会被继承的，如果一个类没有构造函数的话，它会自动提供一个隐士的默认构造函数，也就是一个无参的构造函数，但是如果我们
//	//定义了自己的构造函数的话，编译器就不会自动定义默认构造函数了。
//	//如果类B，只含有using A::A从A类继承来的构造函数的话，那么编译器是会给她合成默认构造函数的。
//	B b1(1,2,3);//现在用的是A构造函数
//	B b2;
//
//	
//}