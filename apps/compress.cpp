#include "huffman.hpp"
#include <iostream>
#include <queue>
#include <map>
#include "helpers.hpp"




 int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string dna = getFileFirstLine(argv[1]);

        std::map<char, std::string> huffmanCode;

	huffman::encode(huffman::HuffmanTree (dna), "", huffmanCode);
	std::string encodedstring = "";
	for (char ch: dna) {
		encodedstring += huffmanCode[ch];
	}

	std::cout << "\nEncoded string is :\n" << encodedstring << '\n';
          
    }

    return 0;
}