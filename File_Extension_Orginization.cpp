
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;
#include <algorithm>
#include <iostream>
namespace File_Extension_Org
{
	std::vector<fs::path> collect_all_file_extensions(std::vector<fs::path>& vector_of_files) 
	{	
		std::vector<fs::path> sorted_file_extensions;
		size_t run_total = 0;
		for (size_t increment_next_filename = 0; increment_next_filename != vector_of_files.size(); ++increment_next_filename) 
		{
			if (vector_of_files[increment_next_filename].has_extension())
			{
				++run_total;
				sorted_file_extensions.push_back(vector_of_files[increment_next_filename].extension());
			}
		}
		std::cout << "[*] " << run_total << "\tTotal Number of Files Found" << '\n';
		std::sort(sorted_file_extensions.begin(), sorted_file_extensions.end());
		return sorted_file_extensions;
	}

	std::vector<fs::path> create_extension_directory
						(std::vector<fs::path>& unique_file_extensions, fs::path& save_to_directory)
	{
		std::sort(unique_file_extensions.begin(), unique_file_extensions.end());
		std::vector<fs::path> file_extension_paths;
		for (auto& i : unique_file_extensions)
		{
			//get the file directory name, and filename type extension, erase the '.' from it
			//then save that new name as the a_extension_path eg. folder [.[png]] -> [png]
			std::string extension_dir_path  = i.filename().string();
			extension_dir_path = extension_dir_path.erase(0,1);
			fs::path a_extension_path = save_to_directory.string() + extension_dir_path;
			
			if (!fs::exists(a_extension_path))
			{
				if (extension_dir_path == a_extension_path.filename().string()) 
				{
						fs::create_directory(a_extension_path.string()+'/');
						file_extension_paths.push_back(a_extension_path);
						std::cout <<  "[*] " << a_extension_path << "\tCreated Directory...\n";

				}
			}
		}
		return file_extension_paths;
	}
};
