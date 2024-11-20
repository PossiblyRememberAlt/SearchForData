#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#define DEBUG
// https://docs.fileformat.com/audio/wav/

// Create WAV Template
//struct WAV{
//	const char[4] FileType = "RIFF";
//
//};


namespace PRUtils::Search
{ 
	void SearchForWAV(const char* apath) { // Search for WAV(s) in file
		std::filesystem::path path = apath;
#pragma region Begin Search
		bool found = false;

		auto filestream = std::fstream(path.c_str(), std::ios::binary);

		const char* header= "RIFF"; // Header to look for
		unsigned char iterator = 0; // Iterator for header char offset

		long long headerPosition = -1; // Go ahead and initialize current position so we can check if it's null

		while (!found) { // Loop through if not found
			if (filestream.get() == EOF) {// Make sure we haven't reached EOF (END OF FILE)
				break;
			}
			if (filestream.get() == header[iterator]) {
				++iterator;
				#ifdef DEBUG
				std::printf("%c", filestream.peek());
				#endif
			}
		}
		if (!found) { // Make sure we have something
			std::printf("Nothing found.");
		}
		headerPosition = static_cast<long long>(filestream.tellg()) - 4;

		#ifdef DEBUG
		printf("Debug: Header found at %ll", headerPosition); // DEBUG print header location
		#endif // DEBUG
		#pragma endregion

		long totalSize = 0; // Initialize total size (total size of WAV, header included!)
		
		filestream.read((char*)totalSize, 4);

		//filestream.seekg(headerPosition+44 /* header is always 44 bytes, so skip ahead to data */, std::ios::cur); // Skip ahead in the file until next important value. WIP, might parse more later
		filestream.seekg(headerPosition, std::ios::beg);

		std::ofstream WAV (std::filesystem::current_path().append("out.wav").c_str(),std::ios::binary);

		for (unsigned long long i = 0; i < totalSize; ++i) {
			WAV.put((char)filestream.get());
		}
	}
}