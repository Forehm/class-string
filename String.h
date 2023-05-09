#pragma once
#include <iostream>



class String
{
public:

	class iterator
	{
	public:

		iterator(char* ptr) : ptr_(ptr) { }
		iterator operator++() { iterator i = *this; ptr_++; return i; }
		iterator operator++(int junk) { ptr_++; return *this; }
		char& operator*() { return *ptr_; }
		char* operator->() { return ptr_; }
		bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }


	private:
		char* ptr_;
	};

	class const_iterator
	{
	public:


		const_iterator(char* ptr) : ptr_(ptr) { }
		const_iterator operator++() { const_iterator i = *this; ptr_++; return i; }
		const_iterator operator++(int junk) { ptr_++; return *this; }
		const char& operator*() { return *ptr_; }
		const char* operator->() { return ptr_; }
		bool operator==(const const_iterator& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const const_iterator& rhs) { return ptr_ != rhs.ptr_; }


	private:
		char* ptr_;
	};

	class reverse_iterator
	{
	public:
		reverse_iterator(char* ptr) : ptr_(ptr) { }
		reverse_iterator operator++() { reverse_iterator i = *this; ptr_--; return i; }
		reverse_iterator operator++(int junk) { ptr_--; return *this; }
		char& operator*() { return *ptr_; }
		char* operator->() { return ptr_; }
		bool operator==(const reverse_iterator& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const reverse_iterator& rhs) { return ptr_ != rhs.ptr_; }

	private:
		char* ptr_;
	};

	class const_reverse_iterator
	{
	public:
		const_reverse_iterator(char* ptr) : ptr_(ptr) { }
		const_reverse_iterator operator++() { const_reverse_iterator i = *this; ptr_--; return i; }
		const_reverse_iterator operator++(int junk) { ptr_--; return *this; }
		const char& operator*() { return *ptr_; }
		const char* operator->() { return ptr_; }
		bool operator==(const const_reverse_iterator& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const const_reverse_iterator& rhs) { return ptr_ != rhs.ptr_; }

	private:
		char* ptr_;
	};

	iterator begin() const { return iterator(str_); }

	iterator end() const { return iterator(str_ + size_); }

	reverse_iterator rbegin() const { return reverse_iterator(&str_[size_ - 1]); }

	reverse_iterator rend() const { return reverse_iterator(str_ - 1); }

	const_iterator cbegin() const { return const_iterator(str_); }

	const_iterator cend() const { return const_iterator(str_ + size_); }

	const_reverse_iterator crbegin() const { return const_reverse_iterator(&str_[size_ - 1]); }

	const_reverse_iterator crend() const { return const_reverse_iterator(str_ - 1); }

	String()
	{
		str_ = nullptr;
		size_ = 0;
	}

	String(const char* str)
	{
		size_ = strlen(str);
		this->str_ = new char[size_ + 1];


		for (size_t i = 0; i < size_; i++)
		{
			this->str_[i] = str[i];
		}
		this->str_[size_] = '\0';
	}

	String(const String& other)
	{
		size_ = strlen(other.str_);
		this->str_ = new char[size_ + 1];

		for (size_t i = 0; i < size_; ++i)
		{
			this->str_[i] = other.str_[i];
		}

		this->str_[size_] = '\0';

	}

	String(const size_t& new_size, const char& symbol)
	{
		if (new_size <= 0)
		{
			throw StringException(2);
		}

		size_ = new_size;
		this->str_ = new char[size_ + 1];

		for (size_t i = 0; i < size_; ++i)
		{
			this->str_[i] = symbol;
		}
		str_ += '\0';
	}
	
	String(std::string& str)
    	{
        	str_ = new char[str.size()];
        	for(size_t i = 0; i < str.size(); ++i)
       		{
           		str_[i] = str[i];
        	}
        	size_ = str.size();
    	}

	String& operator = (const String& other);

	String operator + (const String& other);

	bool operator == (const String& other);

	bool operator != (const String& other);

	char& operator [] (const size_t& index);

	~String()
	{
		delete[] this->str_;
	}

	char* data();

	char* rdata();

	void Print();

	int Size();

	char* c_str();

	void push_back(const char& symbol);

	void pop_front();

	void pop_back();

	friend std::ostream& operator << (std::ostream& os, String& s);

	bool operator < (const String& other);

	bool operator > (const String& other);

	bool operator <= (const String& other);

	bool operator >= (const String& other);

	bool Find(const char& symbol);

	char& At(const size_t& index);

	bool is_empty();

	bool is_not_empty();
	
	size_t Count(const char& symbol);
	
	void Fill(const size_t& count_of_symbols, const char& symbol);

	void Change(const int& index, const char& symbol);

	void Change(iterator& it, const char& symbol);

	void change_from_to(const char& symbol_to_change, const char& new_symbol);

	void erase_every(const char& symbol_to_erase);

	void Erase(const int& index);
	 
	bool operator < (const std::string& other);
	
	bool operator > (const std::string& other);
	
	bool operator == (const std::string& other);
	
	bool operator != (const std::string& other);
	
private:
	char* str_;
	size_t size_;

	void SwapArrays(char* array)
	{
		delete[]str_;
		str_ = array;
		array = nullptr;
	}

	class StringException : public std::exception
	{
	private:
		int error_number_ = 0;

	public:
		StringException(const int& error)
		{
			error_number_ = error;
		}

		const char* What()
		{
			switch (error_number_)
			{
			case 1:
			{
				return "index is out of array range";
				break;
			}
			case 2:
			{
				return "the size cannot be negative";
				break;
			}
			case 3:
			{
				return "the size of the array is too low";
				break;
			}
			default:
			{
				return "Some unknown exception";
				break;
			}
			}
		}
	};
};



std::ostream& operator << (std::ostream& os, String& s)
{
	for (int i = 0; i < s.Size(); ++i)
	{
		os << s.str_[i];
	}

	return os;
}


