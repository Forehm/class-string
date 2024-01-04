# Class string

It is my one of the first projects. I have done it to understand how the real class std::string works. I used the primitive iterators here that I have found in some other project in the network, a lot of cycles and the RAII idiom. The interesting fact is that this project is made without any STL feautures, it was some kind of challange. I added here some more methods that should be in real std::string as I think, so I have realized it here. 
 **System requirements: C++17, C17, x86 platform.**

The project is a final class that consists of following metods:

  1. begin, cbegin, crbegin, end, cend, crend
  2. five different constructors (std::string is supported)
  3. operators of comparison (>, <, ==, != etc.)
  4. methods data as in std::string and rdata(new one) that is reversed data()
  5. c_str as in std::string
  6. size() as in std::string
  7. Count() - it counts the number of the certain character in the string
  8. PushBack, PopFront, PopBack
  9. Fill() that fills the string with a certain character
  10. Change - my own realisation that changes the symbol
  11. ChangeFromTo - replaces every certain symbol with another one
  12. Erase - erases
  13. EraseEvery - erases every certain symbol
  14. IsEmpty, IsNotEmpty - boolean methods
  15. Method At that works like in std::string
  16. Method Find() this method works as a method count in std::set or std:map
  17. operator + and =
  18. destructor
4) I have a plan to add a concept of exceptions here to handle some extraordinary cases, I want to make this part with the help of std::exception.
