// PIAA_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

/*5.1*/
int _KMP(std::string str1, std::string str2) {
	int k = 0;
	int n = str1.size();
	int m = str2.size();
	for (int i = 0; i < n - m + 1; ++i) {
		for (int j = 0; j < m; ++j) {
			k++;
			if (str2[j] != str1[i + j]) { break; }
			//if (j == m - 1) { ++k; }
		}
	}
	return k;
}

/*5.2*/
std::vector<int> pref(std::string str1) {
	int n = str1.size();
	int P = 0;
	std::vector<int> prefix(n);
	for (int i = 1; i < n; ++i) {
		while (P > 0 && str1[P] != str1[i])
			P = prefix[P - 1];
			if (str1[P] == str1[i])
				++P;
			prefix[i] = P;
	}
	return prefix;
}
/*5.3*/
std::vector <int> KMP(std::string str1, std::string str2) {
	std::vector<int> Kvec = {};
	int k = 0;
	int n = str1.size();
	int m = str2.size();
	for (int i = 0; i < n - m + 1; ++i) {
		if (str1.substr(i, m) == str2) { ++k; Kvec.push_back(i); }
	}
	return Kvec;
}
/*5.4*/
int sdvig(std::string str1, std::string str2) {
	for (int i = 0; i < str1.size(); ++i) {
		if ((str1.substr(i, str1.size() - i) + str1.substr(0, i)) == str2) return i + 1;
	}
	return -1;
}
/*6.1*/
void poisk(std::string str1, std::vector <std::string> substr) {
	for (int i = 0; i < str1.size(); ++i) {
		for (int j = 0; j < substr.size(); ++j) {
			if (str1.substr(i, substr[j].size()) == substr[j]) { std::cout << i + 1 << " - " << j + 1 << "\n"; }
		}
	}
}
/*6.2*/
std::string _joker(std::string str1, std::string str2, char joke) {
	std::string k = "";
	int n = str1.size();
	int m = str2.size();
	for (int i = 0; i < n - m + 1; ++i) {
		for (int j = 0; j < m; ++j) {
			if (str2[j] == joke) { if (j == m - 1) { k += std::to_string(i + 1) + ", "; } continue; }
			if (str2[j] != str1[i + j]) { break; }
			if (j == m - 1) { k += std::to_string(i + 1) + ", "; }
		}
	}
	return k;
}


//int joker(std::string str1, std::string str2, char joke) {
//	int k = 0;
//	int n = str1.size();
//	int m = str2.size();
//	for (int i = 0; i < n - m + 1; ++i) {
//		for (int j = 0; j < m; ++j) {
//			if (str2[j] == joke) { if (j == m - 1) { ++k; } continue; }
//			if (str2[j] != str1[i + j]) { break; }
//			if (j == m - 1) { ++k; }
//		}
//	}
//	return k;
//}



//bool sdvig(std::string str1, std::string str2) {
//	for (int i = 0; i < str1.size(); ++i) {
//		if ((str1.substr(i, str1.size() - i) + str1.substr(0, i)) == str2) return 1;
//	}
//	return 0;
//}


//int KMP(std::string str1, std::string str2) {
//	int k = 0;
//	int n = str1.size();
//	int m = str2.size();
//	for (int i = 0; i < n - m + 1; ++i) {
//			if (str1.substr(i, m) == str2) { ++k; }
//	}
//	return k;
//}

void main()
{
	std::vector <int> Kvec = {};
	/*5.1*/
	std::cout << "_KMP = " << _KMP("abacabca", "aba") << "\n";
	/*5.2*/
	for (int i = 0; i < pref("abcdabcabcdabcdab").size(); ++i) {
		std::cout << "Pref" << i <<" = " << pref("abcdabcabcdabcdab")[i] << "\n";
	}
	/*5.3*/
	Kvec = KMP("abab", "ab");
	if (Kvec.size() == 0) { std::cout << "KMP = -1"; }
	else {
		for (int i = 0; i < Kvec.size(); ++i) {
			std::cout <<"KMP " << i << " = " << Kvec[i] << "\n";
		}
	}
	/*5.4*/
	std::cout <<"Sdvig = " << sdvig("defabc", "abcdef") << "\n";
	/*6.1*/
	poisk("CCCA", {"CC"});
	/*6.2*/
	std::cout << "joke = " << _joker("xabvccbababcax", "ab??c?", '?') << "\n";

	system("pause");
}

