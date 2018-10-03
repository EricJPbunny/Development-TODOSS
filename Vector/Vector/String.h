#ifndef STRING
#define STRING

#include <string.h>
#include <assert.h>

class String {

private:

	char* string = nullptr;
	unsigned int allocated_memory = 0u;

public:

	
	String() 
	{
		string = (char*)"";
	};
	

	String(const char* txt)
	{
		assert(txt != nullptr);
		allocated_memory = (strlen(txt)+1);
		this->string = new char[allocated_memory];
		
		strcpy_s(string,allocated_memory,txt);

	}
	~String() 
	{
		delete[] this->string;
		string = nullptr;
	};

	char* GetString() 
	{
		return this->string;
	}

	String(const String& txt)
	{
		assert(txt.string != nullptr);
		allocated_memory = (strlen(txt.string) + 1);
		this->string = new char[allocated_memory];

		strcpy_s(string, allocated_memory, txt.string);
	}

	String operator=(const char* txt) 
	{
		return string = (char*)txt;
	}

	String operator=(const String& txt) 
	{
		return string = txt.string;
	}
	String operator==(const String& txt)
	{/*
		for (int i = 0; i < ; ++i)
		{

		}*/
	}

};
#endif // STRING
