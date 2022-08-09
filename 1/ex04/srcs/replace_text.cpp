#include <iostream>
#include <string>

void replace_text(
	std::string &file_content, const std::string s1, const std::string s2)
{
	const std::size_t s1_len = s1.length();
	const std::size_t s2_len = s2.length();
	std::size_t i = 0;

	while (i < file_content.length()) {
		i = file_content.find(s1, i);
		if (i == (std::size_t)-1)
			break;
		file_content.erase(i, s1_len);
		file_content.insert(i, s2);
		i += s2_len;
	}
}
