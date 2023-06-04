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

	iterator begin() const;
	iterator end() const;

	reverse_iterator rbegin() const;
	reverse_iterator rend() const;

	const_iterator cbegin() const;
	const_iterator cend() const;
	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend() const;

	String();
	String(const char* str);
	String(const String& other);
	String(const size_t& new_size, const char& symbol);
	String(std::string& str);
	String& operator = (const String& other);
	String operator + (const String& other);

	~String();

	char* data();
	char* rdata();
	char* c_str();
	char& operator [] (const size_t& index);

	bool is_empty();
	bool is_not_empty();
	bool Find(const char& symbol);
	
	void Fill(const size_t& count_of_symbols, const char& symbol);
	void Change(const int& index, const char& symbol);
	void Change(iterator& it, const char& symbol);
	void change_from_to(const char& symbol_to_change, const char& new_symbol);
	void erase_every(const char& symbol_to_erase);
	void Erase(const int& index);
	void push_back(const char& symbol);
	void pop_front();
	void pop_back();
	void Print();
	
	bool operator < (const std::string& other);
	bool operator > (const std::string& other);
	bool operator == (const std::string& other);
	bool operator != (const std::string& other);
	bool operator < (const String& other);
	bool operator > (const String& other);
	bool operator <= (const String& other);
	bool operator >= (const String& other);
	bool operator == (const String& other);
	bool operator != (const String& other);

	size_t Count(const char& symbol);
	size_t Size();
	friend std::ostream& operator << (std::ostream& os, String& s);
	char& At(const size_t& index);
	
private:
	char* str_;
	size_t size_;

	void SwapArrays(char* array);

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


