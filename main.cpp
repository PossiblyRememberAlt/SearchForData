#include "SFD.hpp"
#include <fstream>

int main(int argc, char *argv[]) {
	std::printf("%i, %s\n",argc,argv[1]);
	if(argc == 1){
		throw("Input required.");
	}
	PRUtils::Search::SearchForWAV(argv[1]);
}