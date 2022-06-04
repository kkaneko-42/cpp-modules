#ifndef SED_HPP
# define SED_HPP
# include <string>

std::string get_file_content(const std::string file_name);
void replace_text(
	std::string &file_content, const std::string s1, const std::string s2);
void write_to_new_file(
	const std::string file_content, const std::string new_file_name);
void exit_with_error(const std::string msg);

#endif //SED_HPP