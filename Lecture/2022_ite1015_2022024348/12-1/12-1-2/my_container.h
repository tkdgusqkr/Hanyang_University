#pragma once

template <class T>
class MyContainer
{
public:
    MyContainer(int size)
    {
        // Implement here
	n_elements = size;
	obj_arr = new T[n_elements];
    }
    ~MyContainer() 
    {
        // Implement here
	delete[] obj_arr;
    }
    void clear() 
    {
        // Implement here
	obj_arr = NULL;
	n_elements = 0;
    }
    int size()
    {
        // Implement here
	return n_elements;
    }

    template <class U>
    friend std::istream& operator>> (std::istream &in, MyContainer<U> &b);
    template <class U>
    friend std::ostream& operator<< (std::ostream &out, MyContainer<U> &b);

protected:
    T * obj_arr = NULL;
    int n_elements;
};

template<class T>
std::istream& operator>> (std::istream &in, MyContainer<T> &b)
{
// Implement here
	for(int i = 0;i < b.size();++i)
	{
		in >> b.obj_arr[i];
	}
	return in;
}

template<class T>
std::ostream& operator<< (std::ostream &out, MyContainer<T> &b)
{
            // Implement here
	for(int i = 0;i < b.size();++i)
	{
		out << b.obj_arr[i] << ' ';
	}
	return out;
}
