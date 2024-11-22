#include "SFD.hpp"
#include <fstream>

int main(int argc, char** argv) {
	std::printf("%i\n",argc);
	if(argc == 1){
		throw("Input required.");
	}
	PRUtils::Search::SearchForWAV(argv[1]);
}