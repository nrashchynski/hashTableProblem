#include <iostream>
#include <fstream>
#include <vector>

int main() {
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	int m, c, n, key;
	fin >> m >> c >> n;
	// std::cin >> m >> c >> n;
	std::vector<int>hashTable(m, -1);

	for (int i = 0; i < n; ++i) {
		fin >> key;
		//std::cin >> key;
		int j = 0;
		while (true) {
			int index = ((key % m) + c * j) % m;
			if (hashTable[index] == -1 || hashTable[index] == key) {
				hashTable[index] = key; 
				break; 
			}
			++j;
		}
	}

	for (int i = 0; i < m; ++i) {
		fout << hashTable[i] << ' '; 
		//std::cout << hashTable[i] << ' ';
	}

    fin.close(); 
	fout.close();
	return 0;
}