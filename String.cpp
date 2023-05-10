#include <iostream>
#include "String.h"


iterator String::begin() const { return iterator(str_); }

iterator Strng::end() const { return iterator(str_ + size_); }

reverse_iterator String::rbegin() const { return reverse_iterator(&str_[size_ - 1]); }

reverse_iterator String::rend() const { return reverse_iterator(str_ - 1); }

const_iterator String::cbegin() const { return const_iterator(str_); }

const_iterator String::cend() const { return const_iterator(str_ + size_); }



String& String::operator = (const String& other)
{
	if (str_ != nullptr)
	{
		delete[] str_;
	}

	size_ = strlen(other.str_);
	this->str_ = new char[size_ + 1];

	for (size_t i = 0; i < size_; i++)
	{
		this->str_[i] = other.str_[i];
	}
	this->str_[size_] = '\0';


	return *this;
}

String String::operator + (const String& other)
{
	String newstr;
	size_t thislength = strlen(this->str_);
	size_t otherlength = strlen(other.str_);

	newstr.size_ = thislength + otherlength;

	newstr.str_ = new char[thislength + otherlength + 1];

	size_t i;

	for (i = 0; i < thislength; i++)
	{
		newstr.str_[i] = this->str_[i];
	}

	for (size_t j = 0; j < otherlength; i++, j++)
	{
		newstr.str_[i] = other.str_[j];
	}
	newstr.str_[thislength + otherlength] = '\0';

	return newstr;
}

bool String::operator == (const String& other)
{
	if (this->size_ != other.size_)
	{
		return false;
	}

	for (size_t i = 0; i < other.size_; i++)
	{
		if (this->str_[i] != other.str_[i])
		{
			return false;
		}
	}
	return true;
}

bool String::operator != (const String& other)
{
	return !(this->operator==(other));
}

char& String::operator [] (const size_t& index)
{
	return this->str_[index];
}

char* String::data() { return this->str_; }

char* String::rdata() { return this->str_ + (size_ - 1); }

void String::Print() { std::cout << str_ << std::endl; }

int String::Size() { return size_; }

char* String::c_str() { return str_; }

void String::push_back(const char& symbol)
{

	char* arr = new char[size_ + 2];

	for (size_t i = 0; i < size_; ++i)
	{
		arr[i] = str_[i];
	}
	arr[size_] = symbol;
	arr[size_ + 1] = '\0';

	SwapArrays(arr);
	++size_;
}

void String::pop_front()
{
	char* arr = new char[size_];
	for (size_t i = 1; i < size_; ++i)
	{
		arr[i - 1] = str_[i];
	}
	SwapArrays(arr);
	--size_;
}

void String::pop_back()
{
	--size_;
	char* arr = new char[size_];
	for (size_t i = 0; i < size_; ++i)
	{
		arr[i] = str_[i];
	}
	SwapArrays(arr);
}

bool String::operator < (const String& other) { return this->size_ < other.size_; }

bool String::operator > (const String& other) { return this->size_ > other.size_; }

bool String::operator <= (const String& other) { return this->size_ <= other.size_; }

bool String::operator >= (const String& other) { return this->size_ >= other.size_; }

bool String::Find(const char& symbol)
{
	for (int i = 0; i < size_; ++i)
	{
		if (str_[i] == symbol)
		{
			return true;
		}
	}
	return false;
}

char& String::At(const size_t& index)
{
	if (index >= size_ || index <= 0)
	{
		throw StringException(1);
	}
	else
	{
		return str_[index - 1];
	}
}

bool String::is_empty() { return size_ == 0; }

bool String::is_not_empty() { return size_ != 0; }

size_t String::Count(const char& symbol)
{
	size_t counter = 0;

	for (size_t i = 0; i < size_; ++i)
	{
		if (str_[i] == symbol)
		{
			++counter;
		}
	}
	return counter;
}

void String::Fill(const size_t& count_of_symbols, const char& symbol)
{
	if (str_ != nullptr)
	{
		delete[] str_;
	}
	str_ = new char[count_of_symbols];

	for (size_t i = 0; i < count_of_symbols; ++i)
	{
		str_[i] = symbol;
	}
	str_ += '\0';

	size_ = count_of_symbols;
}

void String::Change(const int& index, const char& symbol)
{
	if (index <= size_)
	{
		str_[index] = symbol;
	}
}

void String::Change(iterator& it, const char& symbol) { *it = symbol; }

void String::change_from_to(const char& symbol_to_change, const char& new_symbol)
{
	for (size_t i = 0; i < size_; ++i)
	{
		if (str_[i] == symbol_to_change)
		{
			str_[i] = new_symbol;
		}
	}
}

void String::erase_every(const char& symbol_to_erase)
{
	int counter = 0;
	for (size_t i = 0; i < size_; ++i)
	{
		if (str_[i] == symbol_to_erase)
		{
			counter++;
		}
	}

	char* arr = new char[(size_ - counter) + 1];
	for (size_t i = 0, j = 0; i < size_; ++i, ++j)
	{
		if (str_[i] == symbol_to_erase)
		{
			++i;
		}
		arr[j] = str_[i];
	}

	arr[size_ - counter] = '\0';
	SwapArrays(arr);
	size_ = size_ - counter;
}

void String::Erase(const int& index)
{
	char* arr = new char[size_];

	for (size_t i = 0, j = 0; i < size_; ++i, ++j)
	{
		if (i != index)
		{
			arr[j] = str_[i];
		}
		else
		{

			++i;
			arr[j] = str_[i];
		}
	}

	arr[size_ - 1] = '\0';
	SwapArrays(arr);

	--size_;
}

bool String::operator < (const std::string& other) { return this->size_ < other.size(); }

bool String::operator > (const std::string& other) { return this->size_ > other.size(); }

bool String::operator == (const std::string& other) { return this->size_ == other.size(); }

bool String::operator != (const std::string& other) { return this->size_ != other.size(); }

