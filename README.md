
# Huffman Algorithm for File Compression and decompression

## Introduction 
This project is made to take a text file with a large storing size and compress it to a smaller file in size (usually the produced file is in a zip form), it is also made to take a compressed file and return it to its original form (the text file).
## `Implementation Details`
The algorithm is made using a Huffman tree. The tree is implemented such that it receives the input text file and counting the frequency of each character in the text and store these frequencies in a map alongside with their characters then transforming each pair in the map into a leaf node and inserting these node in a priority queue with the lowest frequency having a highest priority (this is done by using a strut structure to compare).

Now to construct the tree each two nodes with the highest priority are put to be the children of an internal node this which has a frequency equal to the sum of its children, then this parent node is pushed to the queue. After finishing this process we will end up with a tree like structure with all characters and their frequencies as leaf nodes.  
## Compression
1.  The code is meant to Open the input file and construct the Huffman tree.
2.  Encode each character with a number of zeroes and ones this is made by iterating over the tree until reaching the desired character while putting a 0 when moving left and 1 by moving right.
3.  The previous process will result in a sequence of 0 and 1 for each character, characters with high frequency have small number of bits and characters with lowfrequency will have larger number of bits. So instead of storing the character in an 8-bit space the Huffman compress function can store it in smaller number of bits.
## Decompression 
1.  This function takes the code of each character along with the compressed file and starts to iterate over the compressed file and decode it to the original text using the code taken from the compressing function.
2.  The output of this function is the original text.

