#include <iostream>
#include <fstream>
#include <string>

void exit_with_error(const std::string msg);

void write_to_new_file(
	const std::string file_content, const std::string input_file_name)
{
	const std::string open_err = "File open error";
	const std::string write_err = "File writing error";
	const std::string output_file_name = input_file_name + ".replace";
	std::ofstream ofs(output_file_name.data());

	if (!ofs)
		exit_with_error(open_err);

	ofs << file_content;

	if (!ofs)
		exit_with_error(write_err);
}
