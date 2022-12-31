#include <iostream>     	// for cout, cin
#include <fstream>      	// for ifstream
#include <sstream>      	// for stringstream
#include <filesystem>   	// making inputting files easier
#include <unordered_set>	// containers for the wikiscraper
#include <vector>
#include <queue>
#include <unordered_map>
#include "wikiscraper.h"    // wikiscraper methods

using std::cout;            using std::endl;
using std::ifstream;        using std::stringstream;
using std::string;          using std::vector;
using std::priority_queue;  using std::unordered_map;
using std::unordered_set;   using std::cin;

int main() {
    // a quick working directory fix to allow for easier filename inputs
    auto path = std::filesystem::current_path() / "res/";
    std::filesystem::current_path();
    std::string filenames = "Available input files: ";
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string filename = entry.path().string();
        filename = filename.substr(filename.rfind("/") + 1);
        filenames += filename + ", ";
    }
    // omit last ", ".
    cout << filenames.substr(0, filenames.size() - 2) << "." << endl;

    /* Container to store the found ladders in */
    vector<vector<string>> outputLadders;

    cout << "Enter a file name:";
    string filename;
    getline(cin, filename);
    cout << "\ntyped file name = " << filename << endl;

    /* 
        TODO: Create a filestream from the filename.
        For each pair {start_page, end_page} in the input file,
        retrieve the result of findWikiLadder(start_page, end_page)
        and append that vector to outputLadders.
    */
    // Write code here

    ifstream curr_file("res/"+filename);
    if(!curr_file.is_open()){
        std::cerr << "ERROR: the file name is not valid! Please type the correct file name." << endl;
        return -1;
    }
    
    string line;
    if(!getline(curr_file, line)){
        std::cerr << "ERROR: the first line should be an integer represents the number of entries." << endl;
        return -1;
    }
    int num_of_lines = std::stoi(line);

    for(int i = 1; i <= num_of_lines; i++){
        if(getline(curr_file, line)){
            size_t spacePos = line.find(' ');
            string start_page = line.substr(0, spacePos);
            string end_page = line.substr(spacePos+1);
            cout << "start = " << start_page << " ,end = " << end_page << endl;
            // file 'wikiscraper.cpp.o' is needed for this part of code
            // vector<string> res_list = findWikiLadder(start_page, end_page);
            // outputLadders.push_back(res_list);
        }
        else{
            std::cerr << "ERROR: the first line should be an integer represents the number of entries." << endl;
            return -1;
        }
    }

    curr_file.close();


    /*
     * Print out all ladders in outputLadders.
     * We've already implemented this for you!
     */
    // Write code here
    
    // file 'wikiscraper.cpp.o' is needed for this part of code
    // this part is skipped

    

    return 0;
}




