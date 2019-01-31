#include <bits/stdc++.h>
using namespace std;

const string inp = ".in";
const string out = ".out";
const bool delRunFile = true;

string TASK;
int numTest, numDigit;

void Write(int color, string something) {
	cout << "\033[1;" << color << "m" << something << "\033[0m";
}

void WriteRegular(int color, string something) {
	cout << "\033[0;" << color << "m" << something << "\033[0m";
}

string NumToString(int n) {
	string s;
	while (n > 0) {
		s = char (n % 10 + '0') + s;
		n /= 10;
	}
	while ((int) s.size() < numDigit) s = "0" + s;
	return s;
}

void CheckExist (string File) {
	if (!fopen (File.c_str(), "r")) {
		Write (31, "\t  Error!!!\n");
		Write (33, "  File ");
		Write (34, File + " ");
		Write (33, "cannot be found.\n");
		exit (0);
	}
}

void MakeFile(string RunFile, string FileResult, string FileIO, string Folder) {
	int exitCode = system (("./" + RunFile).c_str());
	
	if (exitCode != 0) {
		Write (31, "\n\t  Error!!!\n");
		Write (33, "\t  Run error file ");
		Write (34, RunFile + ".cpp\n");
		Write (31, "\t  Exitcode " + NumToString (exitCode));
		exit (0);
	}

	system (("cd " + TASK  + "/" + Folder + "&& touch " + FileIO).c_str());
	system (("cp " + FileResult + " " +  TASK  + "/" + Folder + "/" + FileIO).c_str());
	return;
}

void Compile(string File) {
	int exitCode = system (("g++ -o " + File + " " + File + ".cpp").c_str());
	if (exitCode != 0) {
		Write (31, "\tError!!!\n");
		Write (33, "  Compile error file ");
		Write (34, File + ".cpp\n");
		exit (0);
	}
}

int main() {
	Write (33, "Welcome to TestCreator\n\n");
	Write (35, "  Your Problem 's name : "); cin >> TASK;
	Write (35, "  Number of testcases : "); cin >> numTest; cout << '\n';
	numDigit = numTest > 0 ? (int) log10 (numTest - 1) + 1 : 1;

	CheckExist ("GenInput.cpp");
	CheckExist ("Solution.cpp");

	if (system (("test -d " + TASK).c_str()) == 0) {
		Write (31, "  \u26A0 ");
		WriteRegular (33, " Folder ");
		Write (34, TASK);
		WriteRegular (33, " exists.\n\n");
	} else system (("mkdir " + TASK).c_str());

	Compile ("GenInput");
	Compile ("Solution");

	Write (32, "  Start creating Testcase:\n\n");
	for (int iTest = 0; iTest < numTest; iTest++) {
		Write (31, "\t\u27A4  ");
		Write (36, "Test "); 
		Write (33, NumToString(iTest));
		Write (36, ": ");

		string Folder = "test" + NumToString(iTest);
		string Link = TASK  + "/" + Folder;
		if (system (("test -d " + Link).c_str()) == 0) {
			Write (31, "\u26A0 ");
			WriteRegular (33, " Folder ");
			Write (34, Folder);
			WriteRegular (33, " exists.\n");
		}
		else {
			system (("cd " + TASK + " && mkdir " + Folder).c_str());

			MakeFile ("GenInput", "input.txt", TASK + inp, Folder);
			MakeFile ("Solution", "answer.txt", TASK + out, Folder);

			cout << "\033[0;" << 37 << "m" << "Complete" << "\033[0m";
			cout << "\033[0;" << 32 << "m" << " \u2713" << "\033[0m\n";
		}
	}

	if (fopen ("input.txt", "r")) {
		system ("rm input.txt answer.txt");
		system ("rm GenInput Solution");
		if (delRunFile) system ("rm TestFormat");
	}

	Write (31, "\n  B");
	Write (32, "i");
	Write (33, "n");
	Write (34, "g");
	Write (35, "o ");
	Write (37, "...\n");

	return 0;
}	