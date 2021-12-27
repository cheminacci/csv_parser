// parse.cpp:
#include "parse.h"

struct Candle 
{
	std::string date;
	std::string time;
	double open;
	double high;
	double low;
	double close;
	double volume;
};

void Parse()
{	std::string filename;
	std::cout << "Please input the name of the file to be parsed\n\n";
	std::cout << "----->\t";
	std::getline(std::cin, filename);

	std::cout << "\nPress ENTER to read the CSV file...\n";
	std::getchar();	

	std::string data_buffer;

	// File Being Read	
	std::ifstream read_myfile;
	read_myfile.open(filename);

	// File Being Written to
	std::ofstream newfile;
	newfile.open("newcsv.txt");

	size_t lines {0};
	size_t storage_index {0};
	std::string string_to_find = "\r";
	std::string string_to_replace  = ",";
      
	// Search for all carraige returns and change to a commas
	if(read_myfile.is_open())
	{
		while(getline(read_myfile, data_buffer)) 
		{
			for( size_t search_position = data_buffer.find(string_to_find) ;\
				    search_position != std::string::npos ;\
				    search_position = data_buffer.find(string_to_find, search_position) )

				{ 
					data_buffer.replace(search_position, string_to_find.length(), string_to_replace);
			       		++lines;	
				}
			newfile << data_buffer;
		}
	}
		std::cout << lines << " lines were read. \n" ;		

    if(lines != 0)
    {	
		std::vector<std::string> Data;
		Data.reserve(10000000);
		std::cout << "\nThe new storage vector has a size of " << Data.capacity() << '\n';
		std::cout << "\nPress ENTER to continue. This process will fill the Data Vector. \n";
		std::getchar();

	read_myfile.close();
	newfile.close();
	
	read_myfile.open("newcsv.txt");	
	newfile.open("tempfile");	

	// Reading the CSV File, Using comma as delimiter, Placing each value into a storage vector.
		while(getline(read_myfile, data_buffer, ',' ) ) 
		{
			newfile << data_buffer << '\n';
			Data.push_back(data_buffer);	
			++storage_index;
		}
	

	read_myfile.close();
	newfile.close();
	
	std::cout << "The Data vector holds " << Data.size() << "\n\n";
	
/*
	 Preparing Vector Container to Transfer Values into the Struct Elements
	 These values can now be easily passed into the finance functions, based on their relative positions
*/

	std::vector<Candle> Position;
	Position.reserve(Data.size());

/*	
	std::cout << "Here is the converted data from the storage vector into the Position struct.\n\n";
	std::cout << "Press ENTER to continue\n";
	getchar();
*/

	size_t element_per_row = 7;
	Position.reserve(lines+1);

	std::string new_file_name;
	std::cout << "Please input the name of the file to store the restructured data...\n\n------>\t";
	std::getline(std::cin, new_file_name);
	std::ofstream structured_data;
	structured_data.open(new_file_name);

	for(size_t row = 0; row != lines; row++)
	{	
		Position[row].date = (Data[ (row * element_per_row) + 0 ]); 
		Position[row].time = (Data[ (row * element_per_row) + 1 ]); 
		Position[row].open = std::stod(Data[ (row * element_per_row) + 2 ]); 	
		Position[row].high = std::stod(Data[ (row * element_per_row) + 3 ]);
		Position[row].low = std::stod(Data[ (row * element_per_row) + 4 ]); 
		Position[row].close = std::stod(Data[ (row * element_per_row) + 5 ]); 
		Position[row].volume = std::stod(Data[ (row * element_per_row) + 6 ]); 
/*
		std::cout << "Date [" << row << "]:\t" << Position[row].date << '\n';
		std::cout << "Time [" << row << "]:\t" << Position[row].time <<  '\n';
		std::cout << "Open [" << row << "]:\t" << Position[row].open <<  '\n';
		std::cout << "High [" << row << "]:\t" << Position[row].high <<  '\n';
		std::cout << "Low [" << row << "]:\t" << Position[row].low <<  '\n';
		std::cout << "Close [" << row << "]:\t" << Position[row].close << '\n';
		std::cout << "Volume [" << row << "]:\t" << Position[row].volume <<  "\n\n";
*/
  		structured_data	<< "Date [" << row << "]:\t" << Position[row].date << '\n';
		structured_data	<< "Time [" << row << "]:\t" << Position[row].time <<  '\n';
		structured_data	<< "Open [" << row << "]:\t" << Position[row].open <<  '\n';
		structured_data	<< "High [" << row << "]:\t" << Position[row].high <<  '\n';
		structured_data	<< "Low [" << row << "]:\t" << Position[row].low <<  '\n';
		structured_data	<< "Close [" << row << "]:\t" << Position[row].close << '\n';
		structured_data	<< "Volume [" << row << "]:\t" << Position[row].volume <<  "\n\n";
	}
	
	structured_data.close();
	
	std::cout << "\nData has been stored in the file named:\t" << new_file_name <<'\n';
  }	

    if(lines == 0)
    { std::cout << "\n\nThe selected file is empty or does not exist.\n\n";}


}


