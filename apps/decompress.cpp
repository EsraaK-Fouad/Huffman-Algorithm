#include "huffman.hpp"
#include <iostream>
#include <queue>
#include <map>
#include "helpers.hpp"



 int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string text = getFileFirstLine(argv[1]);

        std::map<char, std::string> huffmanCode;

	huffman::encode(huffman::HuffmanTree (text), "", huffmanCode);
    std::string encodedstring = "";
	for (char ch: text) {
		encodedstring += huffmanCode[ch];
	}

	int index = -1;
	std::cout << "\nDecoded string is: \n";
	while (index < (int)encodedstring .size() - 2) 
    {
	huffman::decode(huffman::HuffmanTree(text ), index, encodedstring );
	}
    
}
return 0;
}