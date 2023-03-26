

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

	iterator begin() { return iterator(str_); }

	iterator end() { return iterator(str_ + size_); }

	reverse_iterator rbegin() { return reverse_iterator(&str_[size_ - 1]); }

	reverse_iterator rend() { return reverse_iterator(str_ - 1); }

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

	String& operator = (const String& other)
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

	String operator + (const String& other)
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

	bool operator == (const String& other)
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

	bool operator != (const String& other)
	{
		return !(this->operator==(other));
	}

	char& operator [] (const size_t& index)
	{
		return this->str_[index];
	}

	~String()
	{
		delete[] this->str_;
	}

	char* data() { return this->str_; }

	char* rdata() { return this->str_ + (size_ - 1); }

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

		for (size_t i = 0; i < size_; ++i)
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
		for (size_t i = 1; i < size_; ++i)
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
		for (size_t i = 0; i < size_; ++i)
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

	char& At(const size_t& index)
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

	bool is_not_empty()
	{
		return size_ != 0;
	}
	
	size_t Count(const char& symbol)
	{
	    size_t counter = 0;
	    
	    for(size_t i = 0; i < size_; ++i)
	    {
	        if(str_[i] == symbol)
	        {
	            ++counter;
	        }
	    }
	    return counter;
	}
	
	void Fill(const size_t& count_of_symbols, const char& symbol)
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

	void Change(const int& index, const char& symbol)
	{
		if (index <= size_)
		{
			str_[index] = symbol;
		}
	}

	void Change(iterator& it, const char& symbol)
	{
		*it = symbol;
	}

	void change_from_to(const char& symbol_to_change, const char& new_symbol)
	{
		for (size_t i = 0; i < size_; ++i)
		{
			if (str_[i] == symbol_to_change)
			{
				str_[i] = new_symbol;
			}
		}
	}

	void erase_every(const char& symbol_to_erase)
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
		delete[] str_;
		str_ = arr;/
		arr = nullptr;
		size_ = size_ - counter;
	}

	void Erase(const int& index)
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
		delete[] str_;
		str_ = arr;
		arr = nullptr;

		--size_;
	}
	 
	bool operator < (const std::string& other) { return this->size_ < other.size(); }
	
	bool operator > (const std::string& other) { return this->size_ > other.size(); }
	
private:
	char* str_;
	size_t size_;

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
};



std::ostream& operator << (std::ostream& os, String& s)
{
	for (int i = 0; i < s.Size(); ++i)
	{
		os << s.str_[i];
	}

	return os;
}


