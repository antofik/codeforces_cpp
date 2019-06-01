#define stringifyImpl(name) #name
#define stringify(name) stringifyImpl(name)
#define TASK_CLASS(name) CONCAT(Task, name)

#include "Windows.h"
#include <iostream>
#include <streambuf>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <locale>
#include <functional>
#include <vector>

void task();

using namespace std;

static inline string rtrim(string s) {
	s.erase(find_if(s.rbegin(), s.rend(),
		not1(ptr_fun<int, int>(isspace))).base(), s.end());
	return s;
}

int main()
{
	const string TaskLetter = stringify(TASK);

	HANDLE  handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(handle);

	SetConsoleTextAttribute(handle, 6); // gold

	SetConsoleTextAttribute(handle, 15); // white

	vector<int> tests = { TEST };

	SetConsoleTextAttribute(handle, 14);
	cout << "*********************" << "Task " << TaskLetter << "*****************" << endl ;

	for (int test : tests) {
		std::ifstream resultFile(".\\Task" + TaskLetter + "\\Results\\test" + to_string(test) + ".txt");
		if (!resultFile.is_open()) {
			continue;
		}
		std::stringstream buffer;
		buffer << resultFile.rdbuf();
		string correctOutput = rtrim(buffer.str());
		if (correctOutput.empty()) continue;

		auto success = freopen((string(".\\Task") + TaskLetter + "\\Tests\\test" + to_string(test) + ".txt").c_str(), "r", stdin);
		cin.seekg(cin.beg);
		int state = cin.rdstate();
				
		if (success == 0) {
			SetConsoleTextAttribute(handle, 4); // red
			cout << "Failed to open files for test #1" << endl;
			continue;
		}

		SetConsoleTextAttribute(handle, 15);
		cout << endl << "-------------------- Test " << test << "----------------" << endl << endl;

		stringbuf new_buffer;
		streambuf* old_buffer = cout.rdbuf(&new_buffer);

		task();

		cout.rdbuf(old_buffer);

		string programOutput = rtrim(new_buffer.str());
		if (correctOutput == programOutput) {
			// correct answer
			SetConsoleTextAttribute(handle, 7); // dim white
			cout << programOutput << endl;
			SetConsoleTextAttribute(handle, 10); // green
			cout << " Correct" << endl;
		}
		else {
			// incorrect answer
			SetConsoleTextAttribute(handle, 12); // red
			cout << programOutput << endl;
			SetConsoleTextAttribute(handle, 8);
			cout << "-----------------" << endl;
			SetConsoleTextAttribute(handle, 14); // dim white
			cout << correctOutput << endl;
			SetConsoleTextAttribute(handle, 12); // red
			cout << endl << " Wrong" << endl;
		}
		SetConsoleTextAttribute(handle, 15); // red
	}

	cout << "-------------------------------------------" << endl << endl;

	return 0;
}
