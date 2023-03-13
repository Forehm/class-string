class StringException : public exception
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

class String
{
public:
	String()
	{
		str_ = nullptr;
		size_ = 0;
	}

	String(const char* str)
	{
		size_ = strlen(str);
		this->str_ = new char[size_ + 1];


		for (int i = 0; i < size_; i++)
		{
			this->str_[i] = str[i];
		}
		this->str_[size_] = '\0';
	}

	String(const String& other)
	{
		size_ = strlen(other.str_);
		this->str_ = new char[size_ + 1];

		for (int i = 0; i < size_; ++i)
		{
			this->str_[i] = other.str_[i];
		}

		this->str_[size_] = '\0';

	}

	String(const int& new_size, const char& symbol)
	{
		if (new_size <= 0)
		{
			throw StringException(2);
		}

		size_ = new_size;
		this->str_ = new char[size_ + 1];

		for (int i = 0; i < size_; ++i)
		{
			this->str_[i] = symbol;
		}
		str_ += '\0';
	}

	String& operator = (const String& other)
	{
		if (str_ != nullptr)
		{
			delete[] str_;
		}

		size_ = strlen(other.str_);
		this->str_ = new char[size_ + 1];

		for (int i = 0; i < size_; i++)
		{
			this->str_[i] = other.str_[i];
		}
		this->str_[size_] = '\0';


		return *this;
	}

	String operator + (const String& other)
	{
		String newstr;
		int thislength = strlen(this->str_);
		int otherlength = strlen(other.str_);

		newstr.size_ = thislength + otherlength;

		newstr.str_ = new char[thislength + otherlength + 1];

		int i;

		for (i = 0; i < thislength; i++)
		{
			newstr.str_[i] = this->str_[i];
		}

		for (int j = 0; j < otherlength; i++, j++)
		{
			newstr.str_[i] = other.str_[j];
		}
		newstr.str_[thislength + otherlength] = '\0';

		return newstr;
	}

	bool operator == (const String& other)
	{
		if (this->size_ != other.size_)
		{
			return false;
		}

		for (int i = 0; i < other.size_; i++)
		{
			if (this->str_[i] != other.str_[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator != (const String& other)
	{
		return !(this->operator==(other));
	}

	char& operator [] (int index)
	{
		return this->str_[index];
	}

	~String()
	{
		delete[] this->str_;
	}

	void Print()
	{
		std::cout << str_ << std::endl;
	}

	int Size()
	{
		return size_;
	}

	char* c_str()
	{
		return str_;
	}

	void push_back(const char& symbol)
	{

		char* array = new char[size_ + 2];

		for (int i = 0; i < size_; ++i)
		{
			array[i] = str_[i];
		}
		array[size_] = symbol;
		array[size_ + 1] = '\0';

		this->str_ = array;
		array = nullptr;
		++size_;
	}

	void pop_front()
	{
		char* array = new char[size_];
		for (int i = 1; i < size_; ++i)
		{
			array[i - 1] = str_[i];
		}

		this->str_ = array;
		array = nullptr;
		--size_;
	}

	void pop_back()
	{
		--size_;
		char* array = new char[size_];
		for (int i = 0; i < size_; ++i)
		{
			array[i] = str_[i];
		}

		this->str_ = array;
		array = nullptr;

	}

	friend std::ostream& operator << (std::ostream& os, String& s);

	bool operator < (const String& other) { return this->size_ < other.size_; }

	bool operator > (const String& other) { return this->size_ > other.size_; }

	bool operator <= (const String& other) { return this->size_ <= other.size_; }

	bool operator >= (const String& other) { return this->size_ >= other.size_; }

	bool Find(const char& symbol)
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

	char& At(const int& index)
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

	bool is_empty()
	{
		return size_ == 0;
	}

	void Fill(const int& count_of_symbols, const char& symbol)
	{
		if (str_ != nullptr)
		{
			delete[] str_;
		}
		str_ = new char[count_of_symbols];

		for (int i = 0; i < count_of_symbols; ++i)
		{
			str_[i] = symbol;
		}
		str_ += '\0';

		size_ = count_of_symbols;
	}



private:
	char* str_;
	int size_;
};



std::ostream& operator << (std::ostream& os, String& s)
{
	for (int i = 0; i < s.Size(); ++i)
	{
		os << s.str_[i];
	}

	return os;
}


