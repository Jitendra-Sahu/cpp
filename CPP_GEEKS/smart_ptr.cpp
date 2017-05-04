#include<iostream>

using namespace std;

/*template<class T>
class SmartPtr {
	private:
		T* ptr;
	public:
		explicit SmartPtr(T *p=nullptr):ptr(p) {}
		~SmartPtr() {delete ptr;}
		T* operator->(){return ptr;}
		T& operator*(){return *ptr;}
};

int main()
{
	SmartPtr<int> sp(new int());
	*sp = 20;
	cout<<*sp<<endl;
	
	return 0;
}*/

class RC {
	private:
		int count;
	public:
		void AddRef()
		{
			++count;
		}
		int Release()
		{
			return(--count);
		}
};

template<class T>
class SmartPtr {
	private:
		T* pData;
		RC* ref_count;
	public:
		SmartPtr():pData(0), ref_count(0)
		{
			ref_count = new RC();
			ref_count->AddRef();
		}
		SmartPtr(T* pValue):pData(pValue), ref_count(0)
		{
			ref_count = new RC();
                        ref_count->AddRef();
		}
		SmartPtr(const SmartPtr<T>& sp):pData(sp.pData), ref_count(sp.ref_count)
		{
                        ref_count->AddRef();
		}
		SmartPtr<T>& operator=(const SmartPtr<T>& sp)
		{
			if(this != &sp)
			{
				if(ref_count->Release() == 0)
				{
					delete pData;
					delete ref_count;
				}
				pData = sp.pData;
				ref_count = sp.ref_count;
				ref_count->AddRef();
			}
			return *this;
		}
		~SmartPtr()
		{
			if(ref_count->Release() == 0)
			{
				delete pData;
                                delete ref_count;
                        }
		}
		T& operator*()
		{
			return *pData;
		}
		T* operator->()
		{
			return pData;
		}
};

int main()
{
	SmartPtr<int> sp = new int(5);
	SmartPtr<int> sp1 = sp;
	cout<<*sp;
	cout<<*sp1;

	return 0;
}
