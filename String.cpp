class String
{
public:
	String()
	{
		str = nullptr;
		length = 0;
	}

	String(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];


		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}

	String(const String& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; ++i)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

	}

	String& operator = (const String& other)
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

	String operator + (const String& other)
	{
		String newstr;
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

	bool operator == (const String& other)
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

	bool operator != (const String& other)
	{
		return !(this->operator==(other));
	}


	char& operator [] (int index)
	{
		return this->str[index];
	}


	~String()
	{
		delete[] this->str;
	}

	void Print()
	{
		std::cout << str << std::endl;
	}

	int Size()
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

	friend std::ostream& operator << (std::ostream& os, String& s);

	bool operator < (const String& other) { return this->length < other.length; }

	bool operator > (const String& other) { return this->length > other.length; }

	bool operator <= (const String& other) { return this->length <= other.length; }

	bool operator >= (const String& other) { return this->length >= other.length; }

	bool Find(const char& symbol)
	{
		for (int i = 0; i < length; ++i)
		{
			if (str[i] == symbol)
			{
				return true;
			}
		}
		return false;
	}

	char& At(const int& index)
	{
		if (index >= length || index <= 0)
		{
			////exception will be here soon
		}
		else
		{
			return str[index - 1];
		}

	}

	bool is_empty()
	{
		return length == 0;
	}

	void Fill(const int& count_of_symbols, const char& symbol)
	{
		if (str != nullptr)
		{
			delete[] str;
		}
		str = new char[count_of_symbols];

		for (int i = 0; i < count_of_symbols; ++i)
		{
			str[i] = symbol;
		}
		str += '\0';

		length = count_of_symbols;
	}



private:
	char* str;
	int length;
};



std::ostream& operator << (std::ostream& os, String& s)
{
	for (int i = 0; i < s.Size(); ++i)
	{
		os << s.str[i];
	}

	return os;
}
