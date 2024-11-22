#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#define DEBUG
#define CHARDEBUG
// https://docs.fileformat.com/audio/wav/

namespace PRUtils::Search
{ 
	void SearchForWAV(const char* apath) { // Search for WAV(s) in file
		#define path apath

#pragma region Begin Search
		bool found = false;

		std::ifstream filestream(path, std::ios::binary);

		if (!filestream) {
			throw("Invalid file.");
		}

		const char header[4] = { 'R', 'I', 'F', 'F' }; // Header to look for
		unsigned char iterator = 0; // Iterator for header char offset

		long long headerPosition = -1; // Go ahead and initialize current position so we can check if it's null

		while (!found) { // Loop through if not found
			if (iterator == 4) {
				found = true;
			}
			if (filestream.peek() == EOF) {// Make sure we haven't reached EOF (END OF FILE)
				break;
			}
			#ifdef CHARDEBUG
			std::printf("%c", filestream.peek());
			#endif
			if (filestream.peek() == header[iterator]) {
				++iterator;
			}
			else {
				iterator = 0;
			}

			filestream.seekg(1, filestream.cur);
		}
		if (!found) { // Make sure we have something
			std::printf("\nNothing found.\n");
			return;
		}
		headerPosition = static_cast<long long>(filestream.tellg()) - 5;

		#ifdef DEBUG
		printf("\nDebug: Header found at %lld\n", headerPosition); // DEBUG print header location
		#endif // DEBUG
		#pragma endregion

		// long totalSize; // Initialize total size (total size of WAV, header included!)

		// std::printf("%c", filestream.peek());

		// filestream.read((char*)&totalSize, 4);
		// #ifdef DEBUG
		// std::printf("%ld",totalSize);
		// #endif

		for(unsigned char i = 0; i < 4; ++i){
			printf("%i\n",(int)filestream.get());
		}

		//filestream.seekg(headerPosition+44 /* header is always 44 bytes, so skip ahead to data */, std::ios::cur); // Skip ahead in the file until next important value. WIP, might parse more later
		filestream.seekg(headerPosition, std::ios::beg);

		/*std::ofstream WAV (std::filesystem::current_path().append("out.wav").c_str(),std::ios::binary);

		for (unsigned long long i = 0; i < totalSize; ++i) {
			WAV.put((char)filestream.get());
		}*/
	}
}