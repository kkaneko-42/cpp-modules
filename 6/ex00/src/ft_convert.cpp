#include <string>
#include <iostream>
#include <sstream>

static bool ft_isprint(char c)
{
	return (' ' <= c && c <= '~');
}

char ToChar( const std::string &str )
{
	const std::string kInvalidMsg = "String is informative";

	if (str.length() > 1 || ft_isprint(str[0]));
	return ('\0');
}

int ToInt( const std::string &str )
{

}

float ToFloat( const std::string &str )
{

}

double ToDouble( const std::string &str )
{
	
}
