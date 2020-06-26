#include <iostream>
#include <string>
#include <queue>
#include <map>
struct HuffmanNode
{
    char data;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;
};
struct greater
{
    bool operator()(HuffmanNode *l, HuffmanNode *r)
    {
        return (l->freq > r->freq);
    }
};
namespace huffman {

HuffmanNode* getnewNode(char ch, int freq, HuffmanNode* left, HuffmanNode* right)
{
	HuffmanNode* node = new HuffmanNode();

	node->data = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

HuffmanNode * HuffmanTree (std::string text)
{
std::map< char ,int> freq;

 //calculating the frequency of each character in text and put it's value in it's map node.
	for (char ch: text) {
		freq[ch]++;
	}
using PriorityQueue = std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, greater>;

//building  empty PriorityQueue called Q.
PriorityQueue Q;

//pushing map elements to the periority_queue (Q) as a leaf.
for (auto element: freq) {
		Q.push(getnewNode(element.first, element.second, nullptr, nullptr));
	}

// reducing Huffman tree to it's root.	
    while (Q.size() > 1)
	{
		
		HuffmanNode *left =Q.top();
        Q.pop();
		HuffmanNode *right = Q.top();
        Q.pop();

		int sum = left->freq + right->freq;
		Q.push(getnewNode( '\0', sum, left, right)) ;

	}

   HuffmanNode* root = Q.top();
   return (root) ;

}

//encoding function which take :
// the huffmanCode :it is a map at which every node contain the character and it's string code.
void encode(HuffmanNode* root, std::string code,std::map<char, std::string> &huffmanCode)
{ 

	if (root == nullptr)
		return;

	
if (!root->left && !root->right) {
		huffmanCode[root->data] = code;
	}

	encode(root->left, code + "0",huffmanCode);
	encode(root->right, code + "1",huffmanCode);

    
}
void decode(HuffmanNode* root, int &index, std::string code)
{
	if (root == nullptr) {
		return;
	}

	if (!root->left&& !root->right)
	{
		std::cout << root->data;
		return;
	}

	index++;

	if (code[index] =='0')
		decode(root->left, index, code);
	else
		decode(root->right, index,code);
}
}