#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define CHAR_SIZE 26
template <class T>
class  Vector {
	T * ptr;
	int size;
	int currSize;
public:
	void displayArray() {
		for (int i = 0; i < currSize; ++i)
			cout << ptr[i] << endl;
	}
	Vector<T>(int s = 10) {
		size = s;
		currSize = 0;
		ptr = new T[size];

	}
	Vector<T>(const Vector<T>& v) {
		size = v.size;
		currSize = v.currSize;
		ptr = new T[size];
		for (int i = 0; i < currSize; ++i)
			ptr[i] = v.ptr[i];

	}
	~Vector<T>() {
		delete[] ptr;
	}
	int getSize()const {
		return currSize;
	}
	Vector<T>& operator = (const Vector<T> &v) {
		if (v.size != 0)
		{
			size = v.size;
			currSize = v.currSize;
			delete[] ptr;
			ptr = new T[v.size];
			for (int i = 0; i < currSize; ++i)
				ptr[i] = v.ptr[i];

			return *this;
		}
		else
			exit(1);
	}
	T& operator[](int x) {
		if (x<0 || x>size)
		{
			cout << "Sorry!" << endl;
			exit(1);
		}
		else

			return ptr[x];
	}
	void insert(T x) {
		if (currSize < size) {
			ptr[currSize] = x;
			++currSize;
		}
		else {
			T* temp = new T[size];
			for (int i = 0; i < size; ++i)
				temp[i] = ptr[i];
			delete[] ptr;
			size = size * 2;
			ptr = new T[size];
			for (int i = 0; i < currSize; ++i)
				ptr[i] = temp[i];
			ptr[currSize] = x;
			++currSize;
			delete[] temp;
		}
	}
	bool insertAt(T x, int index) {
		if (index<0 || index>size)
			return false;

		if (currSize < size)
		{
			ptr[currSize] = x;
			++currSize;
		}
		else {
			T* temp = new T[size];
			for (int i = 0; i < currSize; ++i)
				temp[i] = ptr[i];
			delete[] ptr;
			size = size * 2;
			ptr = new T[size];
			for (int i = 0; i < currSize; ++i)
				ptr[i] = temp[i];
			ptr[currSize] = x;
			++currSize;
		}
		return true;
	}

	bool deleteElement(T x) {
		for (int i = 0; i < this->getSize(); i++)
		{
			if (ptr[i] == x)
			{
				for (int j = i + 1; j < this->getSize(); j++)
				{
					ptr[j - 1] = ptr[j];
				}
				currSize--;
				return true;
			}
		}
		return false;
	}

};
int index(char x) {
	return (int)x - 97;
}
class TRIE {
private:
	struct TrieNode
	{
		string meaning;
		char key;
		Vector<string> synonyms;
		TrieNode *Array[26];
		bool isLeaf;
		TrieNode()
		{
			for (int i = 0; i < 26; ++i)
				Array[i] = NULL;

		}

	};
	TrieNode *Root;
	void OutputAscending(TrieNode* node, Vector<string> & s, string word)
	{
		if (node != NULL)
		{
			if (((int)node->key >= 97 && (int)node->key <= 122) || ((int)node->key >= 65 && (int)node->key <= 90))
				word += node->key;
			if (node->isLeaf == true)
			{
				s.insert(word);
			}

			for (int i = 0; i < 26; ++i)
				OutputAscending(node->Array[i], s, word);
		}
	}
	void OutDescending(TrieNode* node, Vector<string> & s, string word)
	{
		if (node != NULL)
		{
			if (((int)node->key >= 97 && (int)node->key <= 122) || ((int)node->key >= 65 && (int)node->key <= 90))
				word += node->key;
			if (node->isLeaf == true)
			{
				s.insert(word);
			}

			for (int i = 25; i >= 0; i--)
				OutDescending(node->Array[i], s, word);

		}
	}
	bool FindWord(TrieNode *Node, string key)
	{
		if (Node != NULL)
		{

			for (int i = 0; i < key.length(); i++)
			{
				if (!Node->Array[index(key[i])])
					return false;

				Node = Node->Array[index(key[i])];
			}

		}
		return (Node != NULL && Node->isLeaf);
	}
	string FindMeaning(TrieNode * Node, string key)
	{
		if (Node != NULL)
		{
			for (int i = 0; i < key.length(); i++)
			{
				if (Node->Array[index(key[i])])
					Node = Node->Array[index(key[i])];
			}
		}
		return Node->meaning;

	}
	void OutputSmaller(TrieNode* Node, Vector<string> &s, int l, string key, int a)
	{

		if (Node != NULL)
		{
			if (((int)Node->key >= 97 && (int)Node->key <= 122) || ((int)Node->key >= 65 && (int)Node->key <= 90)) {

				key += Node->key;
				a++;

			}
			if (a < l && Node->isLeaf == true)
			{
				//cout << "key " << key << endl;
				s.insert(key);

			}
			for (int i = 0; i < 26; i++)
				OutputSmaller(Node->Array[i], s, l, key, a);
		}
	}
	void OutputSE(TrieNode *Node, Vector <string>& s, int l, string key, int a)
	{
		if (Node != NULL)
		{
			if (((int)Node->key >= 97 && (int)Node->key <= 122) || ((int)Node->key >= 65 && (int)Node->key <= 90)) {

				key += Node->key;
				a++;

			}
			if (a <= l && Node->isLeaf == true)
			{
				s.insert(key);
			}
			for (int i = 0; i < 26; i++)
				OutputSE(Node->Array[i], s, l, key, a);


		}
	}
	void OutputGreater(TrieNode *Node, Vector <string>& s, int l, string key, int a)
	{
		if (Node != NULL)
		{
			if (((int)Node->key >= 97 && (int)Node->key <= 122) || ((int)Node->key >= 65 && (int)Node->key <= 90)) {

				key += Node->key;
				a++;

			}
			if (a > l && Node->isLeaf == true)
			{
				//	cout << "key " << key << endl;
				s.insert(key);


			}
			for (int i = 0; i < 26; i++)
				OutputGreater(Node->Array[i], s, l, key, a);


		}
	}
	Vector<string> FindSynonyms(TrieNode* Node, string key)
	{
		if (Node != NULL)
		{

			for (int i = 0; i < key.length(); i++)
			{
				if (Node->Array[index(key[i])])
					Node = Node->Array[index(key[i])];


			}
		}
		return Node->synonyms;

	}
	void OutputPrefix(TrieNode *Node, Vector<string> &s, string key)
	{
		if (Node != NULL)
		{
			if (((int)Node->key >= 97 && (int)Node->key <= 122) || ((int)Node->key >= 65 && (int)Node->key <= 90))
				key += Node->key;
			if (Node->isLeaf == true)
			{
				s.insert(key);
			}

			for (int i = 0; i < 26; ++i)
				OutputAscending(Node->Array[i], s, key);
		}
	}

public:
	TRIE()
	{
		Root = new TrieNode;
		Root->isLeaf = false;
	}

	~TRIE() {  }
	void insertNode(string word, string meaning, Vector<string> syn)
	{
		TrieNode *temp = Root;
		for (int i = 0; i < word.length(); ++i)
		{
			TrieNode* newNode = new TrieNode;
			newNode->key = word[i];
			if (i == word.length() - 1)
			{
				newNode->isLeaf = true;
				newNode->meaning = meaning;
				newNode->synonyms = syn;
			}
			else
				newNode->isLeaf = false;
			if (temp->Array[index(word[i])] == NULL)
				temp->Array[index(word[i])] = newNode;
			temp = temp->Array[index(word[i])];
		}
	}
	void CreateDictionary(const char* Path)
	{
		string word = "";
		TrieNode *cur;
		int count = 0;
		string myWord = "";
		string myMeaning = "";
		//	Vector<string> mysyn;
		ifstream myFile(Path);
		if (!myFile.fail())
		{
			while (!myFile.eof())
			{
				if (count == 0)
				{
					getline(myFile, word);

				}count++;
				if (word[0] == '-' && word[1] != '-')
				{
					for (int i = 1, j = 0; i < word.length(); ++i)
					{
						if (word[i] != ' ')
						{
							myWord += word[i];
							j++;
						}

					}
					getline(myFile, word);
					if (word[0] == '-' && word[1] == '-')
					{
						Vector<string> mysyn;

						for (int j = 2, k = 0; j < word.length(); j++, k++)
						{
							myMeaning += word[j];
						}
						getline(myFile, word);
						while (word[0] != '-' && !myFile.eof())
						{
							mysyn.insert(word);
							getline(myFile, word);

						}
						insertNode(myWord, myMeaning, mysyn);
						myMeaning = "";
						myWord = "";

						continue;
					}
				}

			}
		}
		myFile.close();
	}
	Vector<string> OutputAscending()
	{
		Vector<string> ascen;
		OutputAscending(Root, ascen, "");
		return ascen;
	}
	Vector<string> OutputDescending()
	{
		Vector<string> des = OutputAscending();
		Vector<string> tmp;
		int size = des.getSize();
		string str;
		for (int i = size - 1; i >= 0; i--)
		{
			str = des[i];
			tmp.insert(str);
		}
		return tmp;
	}
	bool FindWord(string key)
	{
		return FindWord(Root, key);
	}
	string FindMeaning(string key) {
		return FindMeaning(Root, key);
	}
	Vector< string> OutputSmaller(int length) {
		Vector<string> s;
		OutputSmaller(Root, s, length, "", 0);
		return s;

	}
	Vector< string> OutputSE(int length) {
		Vector<string> s;
		OutputSE(Root, s, length, "", 0);
		cout << s.getSize() << endl;
		s.displayArray();
		return s;
	}
	Vector< string> OutputGreater(int length) {
		Vector<string> s;
		OutputGreater(Root, s, length, "", 0);
		return s;
	}
	Vector< string> FindSynonyms(string key) {
		return  FindSynonyms(Root, key);
		// return s;
	}
	Vector< string> OutputPrefix(string prefix)
	{
		Vector<string> s;
		OutputPrefix(Root, s, "");
		string subStr;
		for (int i = 0; i < s.getSize(); i++)
		{
			subStr = s[i].substr(0, prefix.length());
			if (subStr != prefix && subStr != "")
			{
				s.deleteElement(s[i]);
				i--;
			}
		}
		return s;
	}
	Vector< string> OutputSuffix(string suffix) {
		Vector<string> s = OutputAscending();
		string subStr;
		int suffixSize = suffix.length();
		for (int i = 0; i < s.getSize(); i++)
		{
			subStr = s[i].substr(s[i].length() - suffixSize, s[i].length() - 1);
			if (subStr != suffix && subStr != "")
			{
				s.deleteElement(s[i]);
				i--;
			}
		}
		return s;
	}
	Vector< string> OutputAnagrams(string key) {
		int count = 0;
		string temp = "";
		Vector <string> s = OutputAscending();
		Vector <string> s1;

		for (int i = 0; i < s.getSize(); i++)
		{
			if (s[i].length() == key.length())
			{

				if (s[i] != key)
				{
					for (int j = 0; j < key.length(); j++)
					{
						temp = s[i];
						for (int k = 0; k < key.length(); k++)
						{
							if (temp[j] == key[k])
							{
								count++;
								break;
							}
						}

					}
					if (count == key.length())
					{
						s1.insert(s[i]);
					}

					count = 0;
				}
			}
		}
		return s1;
	}


};