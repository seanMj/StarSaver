
#include "Star_Saver.cpp"

namespace Star_Saver
{
	const bool	isSymboled		(const std::string file_name, std::regex pattern);
	const bool	isSymboled		(const std::string file_name, const char symbol_being_used);

	std::vector<fs::path>	search_directory_files	(const fs::path where_to_look, const char symbol_being_used);
	std::vector<fs::path>	search_directory_files	(const fs::path where_to_look, std::regex pattern);
	std::vector<fs::path>	search_directory_files	(const std::vector<fs::path>& where_to_look , const char symbol_being_used);
	
	void		save_copy_of_symbol_files	(std::vector<fs::path>& symbol_files, fs::path where_to_save);
	void		save_copy_of_symbol_files	(std::vector<fs::path>& symbol_files, std::vector<fs::path>& where_to_save);
	
	void 		linux_star_removal_service	(fs::path directory_to_remove_from, const char symbol_to_be_removed);

};