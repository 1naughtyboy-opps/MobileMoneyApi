#ifndef functions_H_INCLUDED_
#define functions_H_INCLUDED_
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;

vector<string> seperate(string input) {
    vector<string> ret;

    while(input.find(" ")!=string::npos) {
        ret.push_back(input.substr(0, input.find(" ")));
        input.erase(0, input.find(" ")+1);
    } ret.push_back(input);

    return ret;
}

string pipe_terminal(string command) {
	string data;
	FILE * stream;
	const int max_buffer = 1024;
	char buffer[max_buffer];
	command.append(" 2>&1");

	stream = popen(command.c_str(), "r");
	if (stream) {
		while (!feof(stream)) if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
		pclose(stream);
	}
	return data;
}

#endif