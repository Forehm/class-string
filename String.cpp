class MyString
{
public:
	MyString()
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];


		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}

	MyString(const MyString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; ++i)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

	}

	MyString& operator = (const MyString& other)
	{
		if (str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';


		return *this;
	}

	MyString operator +(const MyString& other)
	{
		MyString newstr;
		int thislength = strlen(this->str);
		int otherlength = strlen(other.str);

		newstr.length = thislength + otherlength;

		newstr.str = new char[thislength + otherlength + 1];

		int i;

		for (i = 0; i < thislength; i++)
		{
			newstr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherlength; i++, j++)
		{
			newstr.str[i] = other.str[j];
		}
		newstr.str[thislength + otherlength] = '\0';

		return newstr;
	}

	bool operator == (const MyString& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < other.length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator != (const MyString& other)
	{
		return !(this->operator==(other));
	}


	char& operator [] (int index)
	{
		return this->str[index];
	}


	~MyString()
	{
		delete[] this->str;
	}

	void print()
	{
		std::cout << str << std::endl;
	}

	int Length()
	{
		return length;
	}

	char* c_str()
	{
		return str;
	}

	void push_back(const char& symbol)
	{

		char* array = new char[length + 2];

		for (int i = 0; i < length; ++i)
		{
			array[i] = str[i];
		}
		array[length] = symbol;
		array[length + 1] = '\0';

		this->str = array;
		array = nullptr;
		++length;
	}

	friend std::ostream& operator << (std::ostream& os, MyString& s);

private:
	char* str;
	int length;
};


std::ostream& operator << (std::ostream& os, MyString& s)
{
	for (int i = 0; i < s.Length(); ++i)
	{
		os << s.str[i];
	}

	return os;
}
