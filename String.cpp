#include <iostream>
#include "String.h"

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