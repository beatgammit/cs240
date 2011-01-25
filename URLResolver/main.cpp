#include <iostream>
#include "url.h"
#include "urlresolver.h"

using namespace std;

int main(int argc, char** argv)
{
	// the program name, the base-url and the relative url
	if(argc == 3){
		URL tURL(argv[1]);

		char* tOutput = NULL;

		URLResolver* tResolver = new URLResolver();
		tResolver->resolve(&tURL, argv[2], &tOutput);

		delete tResolver;

		// output the resolved URL
		cout << tOutput << endl;

		// clean up after ourselves
		delete[] tOutput;

		return 0;
	}else{
		cout << "Invalid input. You entered " << (argc - 1) << (argc - 1 > 1 ? " arguments." : " argument.") << " Follow this schema:" << endl;
		cout << "url-resolver <base-url> <relative-url>" << endl;
		return -1;
	}
}
