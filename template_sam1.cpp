#include<iostream>

using namespace std;

template<typename T>
class Array
{
	public:
		Array(int len=10): 			len_(len), data_(new T[len]) {}
		~Array()				{delete []data_;}
		int len() const				{ return len_;}
		const T& operator[](int i)const		{ return data_[check(i)];}
		T& operator[](int i)			{ return data_[check(i)];}
		Array(const Array<T>&);
		Array<T>& operator=(const Array<T>&);
		void fun(const T& x);
	private:
		int len_;
		T* data_;
		int check(int i)const
		{
			if(i < 0 || i >=len_)
				throw;
			return i;
		}
};

template<typename T>
inline
void Array<T>::fun(const T& x)
{
	cout<<"\n template function with T type";
}

template<typename T>
class temp
{
	public:
		temp(int len=10):len_(len), data_(new T[len]){}
		~temp(){delete []data_;}
		temp<T>(const temp<T>&);
		temp<T>& operator=(const temp<T>&);
		const T& operator[](int i)const;
		T& operator[](int i);
		void fun(const T& x);
	private:
		int len_;
		T* data_;
};

template<typename T>
inline
void temp<T>::fun(const T& d)
{
	cout<<"\n this is normal template method";
}
template <>
inline
void temp<int>::fun(const int&x)
{
	cout<<"\n template specialization with int type";
}

int main()
{
	Array<int> ai;
	Array<float> af;

	temp<int> ti;
	temp<float> tf;

	int d = 10;
	ti.fun(d);

	float f = 10.2;
	tf.fun(f);

	cout<<endl;
	return 0;
}	
	
