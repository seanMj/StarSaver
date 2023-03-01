#include "File_Extension_Orginization.cpp"
namespace File_Extension_Org {
	std::vector<fs::path> 		collect_all_file_extensions	(std::vector<fs::path>& vector_of_files);
	std::vector<fs::path> 		create_extension_directory	(std::vector<fs::path>& unique_file_extensions, fs::path& save_to_directory);
}