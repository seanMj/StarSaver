#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
#include <vector>
#include <regex>
#include <string>
namespace Star_Saver
{

	/*
	*	isSymboled
	*	using a user-defined regex pattern, search for the file name
	*	[this overload is slow.... very very slow, use next overload for speed]
	*/
	const bool isSymboled (const std::string file_name, std::regex pattern)
	{
		std::smatch __smatch;
		if(std::regex_search(file_name, __smatch, pattern))
		{
			return true;
		}
		return false;
	}

	/*
	*	isSymboled
	*	this function counts the amount of symbols within a filename, 
	*	will return true if filename w/ correct critera is located
	*	false otherwise
	*	[This overload does not use STL regex]
	*/
	const bool isSymboled(const std::string file_name, const char symbol_being_used)
	{
		unsigned short count = 0;
		for (auto& fn_iter : file_name) 
		{
			if (fn_iter == symbol_being_used)
			{
				count += 1;
				if (count == 2) 
				{
					std::cout <<  "[+] " << file_name << "\t File Fits Critera For symbol\n";
					return true;
				}
			}
			else {
				count = 0;
			}
		}
		return false;
	}
	/*
	*	search_directory_files
	*	Search a directory provided by the user, and go file by file
	* 	to check if the file meets the star saver symbol criteria
	*	[!] returns the filenames that have a symbol inline with regex - within a directory
	**	[This overload uses regex instead of my much faster routine]
	*/
	std::vector<fs::path> search_directory_files(const fs::path where_to_look, std::regex pattern) 
	{
		std::vector<fs::path> symboled_files{};
		for (const fs::directory_entry& where_to_check
			: fs::recursive_directory_iterator{ where_to_look, std::filesystem::directory_options::skip_permission_denied })
		{
			const fs::path file_path = where_to_check;

			if (file_path.has_filename() || !(fs::is_directory(file_path)) || !(fs::is_empty(file_path))) 
			{
				if (isSymboled(file_path.filename(), pattern))
				{
					symboled_files.push_back(file_path);
				}
			}
		}
		return symboled_files;
	}

	/*
	*	search_directory_files
	*	Search a directory provided by the user, and go file by file
	* 	to check if the file meets the star saver symbol criteria
	*	[!] returns the filenames that have a symbol within a directory
	**	[this overload uses my symbol check routine instead of regex]
	*/

	std::vector<fs::path> search_directory_files(const fs::path where_to_look, const char symbol_being_used)
	{
		std::vector<fs::path> symboled_files{};
		for (const fs::directory_entry& where_to_check : fs::recursive_directory_iterator{ where_to_look, std::filesystem::directory_options::skip_permission_denied })
		{
			const fs::path file_path = where_to_check;
			if (file_path.has_filename() || !fs::is_empty(file_path))
			{
				if (isSymboled(file_path.filename(), symbol_being_used))
				{
					symboled_files.push_back(file_path);
				}
			}
		}
		return symboled_files;
	}

	/*
	*	search_directory_files
	*	Search a directory(s) provided by the user in the form of a vector
	* 	and go file by file to check if the file meets the star saver symbol criteria
	*	[!] returns the filenames that have a symbol within a directory
	**	[this overload uses my symbol check routine instead of regex, or single path variable]
	*/
	std::vector<fs::path> search_directory_files(const std::vector<fs::path>& where_to_look , const char symbol_being_used)
	{
		std::vector<fs::path> symboled_files{};
		for(auto& current_vector_directory : where_to_look){
			for (const fs::directory_entry& where_to_check : fs::recursive_directory_iterator{ current_vector_directory, std::filesystem::directory_options::skip_permission_denied })
			{
				const fs::path file_path = where_to_check;
				if (file_path.has_filename() || !fs::is_empty(file_path))
				{
					if (isSymboled(file_path.filename(), symbol_being_used))
					{
						symboled_files.push_back(file_path);
					}
				}
			}
		}
		return symboled_files;
	}
	/*
	*	save_copy_of_symbol_files
	*	go through data of symboled files and save them to the desired backup location
	*	[only saves to a single folder, does not have organization in mind basic backup]
	*/
	void save_copy_of_symbol_files(std::vector<fs::path>& symbol_files, fs::path where_to_save) 
	{
		for (auto& ii : symbol_files)
		{
			std::string removed_dot_extension = ii.extension().string();
			removed_dot_extension = removed_dot_extension.erase(0, 1);
			
			const auto copy_options = fs::copy_options::update_existing | fs::copy_options::recursive;		
			
			if (!fs::exists(where_to_save.string() + removed_dot_extension)) 
			{
				std::cout <<  "[+] " << where_to_save.string() << "\tSaving a "<< ii.extension().string() <<" file\n";
				fs::copy(ii, where_to_save, copy_options);
			}

		}	
	}

	//Overload Of: save_copy_of_symbol_files(std::vector<fs::path>& symbol_files, fs::path& where_to_save) ^
	/*
	*	save_copy_of_symbol_files
	*	go through data of symboled files and save them to the desired backup location
	*	[saves the data to its respected file ext. folder name for easier use]
	*/
	void save_copy_of_symbol_files(std::vector<fs::path>& symbol_files, std::vector<fs::path>& where_to_save)
	{
		for (auto i = 0; i != where_to_save.size(); ++i)
		{
			for (auto& ii : symbol_files)
			{
				std::string removed_dot_extension = ii.extension().string();
				removed_dot_extension = removed_dot_extension.erase(0, 1);
			
				if (removed_dot_extension == where_to_save[i].filename())
				{
					const auto copy_options = fs::copy_options::update_existing | fs::copy_options::recursive;				
					if (!fs::exists(where_to_save[i].string() + removed_dot_extension)) 
					{
						std::cout <<  "[+] " << where_to_save[i].string() << "\tSaving a "<< ii.extension().string() <<" file\n";
						fs::copy(ii, where_to_save[i], copy_options);
					}
				}
			}
		}
	}

	/*	linux_star_removal_service
	*	go through the list of files saved at backup location
	*	then rename those files to remove the symbol from that filename
	*/
	//example of removeing the dot from the front of a file extension eg. [filename[.[png]]]
			//																  ^
			//																[filename[png]]
			//																  ^^^
			//																  		  png
	void linux_star_removal_service(fs::path directory_to_remove_symbols_from, const char symbol_to_be_removed)
	{
		for(const fs::directory_entry& curr_dir : fs::recursive_directory_iterator{directory_to_remove_symbols_from})
		{
			const fs::path curr_file = curr_dir;
			std::string removed_dot_extension = curr_file.extension().string();
			removed_dot_extension = removed_dot_extension.erase(0, 1);

			if(isSymboled(curr_file, symbol_to_be_removed))
			{
				std::string curr_file_to_string = curr_file.filename().string();
				std::string curr_file_symbol_erase = curr_file_to_string.erase(0,2);

				//worst written part of the code... thats better.. fixed its crazyness
				std::cout << "[+] " << directory_to_remove_symbols_from.string()	+
							removed_dot_extension				+
							"/" 								+ 
							curr_file_to_string << "\tRemoving Symbol From Filename...\n";
				//this can be optimized as to not have to reiterate through a directory again.
				fs::rename(curr_file, 
							directory_to_remove_symbols_from.string()	+
							removed_dot_extension				+
							"/" 								+ 
							curr_file_symbol_erase);
			}
		}
	}
};
