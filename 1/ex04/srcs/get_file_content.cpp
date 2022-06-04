#include <iostream>
#include <fstream>
#include <string>

void exit_with_error(const std::string msg);

std::string get_file_content(const std::string file_name)
{
	const std::string open_err = "File open error";
	const std::string load_err = "File loading error";
	std::string file_content;
	std::string buf;
	std::ifstream ifs(file_name.data(), std::ios::in);

	if (!ifs)
		exit_with_error(open_err);

	while (std::getline(ifs, buf))
	{
		file_content += buf;
		if (!ifs.eof())
			file_content += "\n";
	}

	if (!ifs.eof())
		exit_with_error(load_err);
	return (file_content);
}
