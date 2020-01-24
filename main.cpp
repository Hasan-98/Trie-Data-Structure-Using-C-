#include "TRIE.h"
int main() {
	TRIE t;
	t.CreateDictionary("dictionary.txt");
	cout << "ascending order:\n";
	t.OutputAscending().displayArray();
	//cout << "descending order:\n";
	//
	//cout <<endl<<endl
	//if (t.FindWord("peck")==1  )
	//{
	//	cout << "Found :\n";
	//}
	//else
	//	cout << "Not found:\n";


	//if (t.FindWord("piper") == 1)
	//{
	//	cout << "Found :\n";
	//}
	//else
	//	cout << "Not found:\n";



	//if (t.FindWord("apple") == 1)
	//{
	//	cout << "Found :\n";
	//}
	//else
	//	cout << "Not found:\n";


	//	cout <<t.FindMeaning("piper")<<endl;
	//	t.OutputSE(5).displayArray();
	//t.OutputGreater(6).displayArray();
	//t.OutputSmaller(7).displayArray();



	//t.FindSynonyms("peck").displayArray();
	//t.OutputSmaller(7).displayArray();

	//t.OutputGreater(6).displayArray();
	//t.OutputSmaller(7).displayArray();

	//t.FindSynonyms("piper").displayArray();

	//t.OutputAscending().displayArray();	t.OutputPrefix("pick").displayArray();



	//t.OutputAscending().displayArray();
	//t.OutputSuffix("cked").displayArray();
	//t.OutputDescending().displayArray();
	t.OutputAnagrams("silent").displayArray();
	//
	system("pause");

	return 3;
}