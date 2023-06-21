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

	iterator begin() const noexcept;
	iterator end() const noexcept;

	reverse_iterator rbegin() const noexcept;
	reverse_iterator rend() const noexcept;

	const_iterator cbegin() const noexcept;
	const_iterator cend() const noexcept;
	const_reverse_iterator crbegin() const noexcept;
	const_reverse_iterator crend() const noexcept;

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
	char* c_str() const;
	char& operator [] (const size_t index);

	bool IsEmpty() noexcept const;
	bool IsNotEmpty() noexcept const;
	bool Find(const char& symbol) noexcept const;
	
	void Fill(const size_t& count_of_symbols, const char& symbol) noexcept;
	void Change(const int& index, const char& symbol);
	void Change(iterator& it, const char& symbol);
	void ChangeFromTo(const char& symbol_to_change, const char& new_symbol);
	void EraseEvery(const char& symbol_to_erase);
	void Erase(const int& index);
	void PushBack(const char& symbol);
	void PopFront();
	void PopBack();
	
	bool operator < (const std::string& other) const noexcept;
	bool operator > (const std::string& other) const noexcept;
	bool operator == (const std::string& other) const noexcept;
	bool operator != (const std::string& other) const noexcept;
	bool operator < (const String& other) const noexcept;
	bool operator > (const String& other) const noexcept;
	bool operator <= (const String& other) const noexcept;
	bool operator >= (const String& other) const noexcept;
	bool operator == (const String& other) const noexcept;
	bool operator != (const String& other) const noexcept;

	size_t Count(const char& symbol) const noexcept;
	size_t Size() const noexcept;
	friend std::ostream& operator << (std::ostream& os, String& s);
	char& At(const size_t& index);
	
private:
	char* str_;
	size_t size_;

	void SwapArrays(char* array);
};



std::ostream& operator << (std::ostream& os, String& s)
{
	for (int i = 0; i < s.Size(); ++i)
	{
		os << s.str_[i];
	}

	return os;
}


