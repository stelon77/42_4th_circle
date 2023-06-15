#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>

class Sed
{
public:
	Sed(std::string const filename, std::string const s1, std::string const s2);
	~Sed();

	void replace(void);

private:

	bool _createString(void);
	std::string _manipulateString(std::string str);
	bool		_createNewFile(void) const;
	std::string		_createNewFileName(void) const;


	std::string _filename;
	std::string const _s1;
	std::string const _s2;
	std::string _str;

};


#endif