//by. Sean Jesky i hope this helps someone out there. Please don't use in a responsible way.. 
//see this i wrote dont instead of do, everything i do online I mess up and say the wrong thing the wrong way.  My heart hurts because I'm so stupid online..
/* Failure is what makes the code look better. */
/* 
 * FILE('s): main.cpp
 * DATE&TIME: feb 2023
 * CREATED_BY: Sean Jesky (dumbest idiot on earth right now, I can promise that)
 * CREATED_FOR: the dream
 * WHAT_IT_DOES: searches system directory for a file that has symbols as in > **filename.txt
                 This data is saved in users requested location. Segregation and organization of file extension type. 
              
 */
//TODO: try and find a way to store data within the .reloc section of the code itself
//otherwise, store in reg. key for further use.

#include <vector>
#include "Star_Saver.hpp"
#include "File_Extension_Orginization.hpp"

#include "StarTimeSaver.hpp"

int main()
{
	//Regex's are slowest thing in/on planet C++, do not use unless user specifies its use, and
	//make sure the user understands the speed of the slow before they decide to use it
	//std::wregex pattern{ L"([@^]{2}.)" };
	std::cout << "Do you wish to use regex(R) or use a single symbol(S) to find files to backup\n";
	std::cout << "Please press R for regex or S for symbol to continue\n";
	char users_character_choice = 'c';
	std::cin  >> users_character_choice;
	char symbol = '*';
	std::regex reg_search_critera;
	if(users_character_choice == 'r' || users_character_choice == 'R')
	{
		std::cout << "Please enter a Regex that you will use to find files:\n";
		std::string reg_cvrt;
		std::cin >> reg_cvrt;
		reg_search_critera = reg_cvrt;
	}else if(users_character_choice == 's' || users_character_choice == 'S')
	{
		std::cout << "Please enter a symbol that you will add to front of filename eg. * or, #, etc\n";
		std::cin >> symbol;
	}
	else{
		return EXIT_FAILURE;
	}

	std::cout << "please enter what sleep mode to use\n[+] level 1 : 1 min\n[+] level 2 : 60 min\n[+] level 3 : 1 day\n";
	size_t level = 1;
	std::cin >> level;
	//..


	fs::path where_to_save;
	/*std::vector<fs::path>*/fs::path where_to_search_for_symboled_files;


	std::cout << "please enter where to save:\n";
	std::cin >> where_to_save;
	
	std::cout << "please enter a directory to be searched:\n";
	std::cin >> where_to_search_for_symboled_files;

	while(level >= 1 && level <= 3)
	{	
		std::vector<fs::path> search_this_Data;
		if(users_character_choice == 'S' || users_character_choice == 's')
		{
			search_this_Data
			= Star_Saver::search_directory_files(where_to_search_for_symboled_files, symbol);
		}
		else if(users_character_choice == 'R' || users_character_choice == 'r'){
			search_this_Data
			= Star_Saver::search_directory_files(where_to_search_for_symboled_files, reg_search_critera);
		}

		std::vector<fs::path> file_extensions
			= File_Extension_Org::collect_all_file_extensions(search_this_Data);

		std::vector<fs::path> directories_of_extensions
			= File_Extension_Org::create_extension_directory(file_extensions, where_to_save);

		Star_Saver::save_copy_of_symbol_files(search_this_Data, directories_of_extensions);
		
		if(users_character_choice == 'S' || users_character_choice == 's'){
			Star_Saver::linux_star_removal_service(where_to_save, symbol);
		}

		how_often_to_repeat(level);
	}
}
