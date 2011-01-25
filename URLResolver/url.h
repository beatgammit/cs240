#ifndef URL_H
#define URL_H

enum SCHEME{SCH_NULL, SCH_HTTP, SCH_FILE};
struct NET_LOC{
	char* domain;
	int portNumber;
};

class URL
{
    public:
		void initialize();
		URL(char* urlRaw);
		URL(URL* clone, bool bAppendPound = false);
		void removeFilename();
		void toString(char** output);
		void killPath();
		void updateURL(char* token);
		virtual ~URL();
	protected:
	private:
		SCHEME type;
		NET_LOC net_loc;
		int pathLen;
		char* path;
		int queryLen;
		char* query;
		int fragmentLen;
		char* fragment;

		// reads the Scheme (file || html) and returns the new index
		SCHEME	readScheme		(int* iIndex, int iLength, char* rawPath);
		bool	readNetLoc		(int* iIndex, int iLength, char* rawPath);
		bool	readPath		(int* iIndex, int iLength, char* rawPath);
		bool	readQuery		(int* iIndex, int iLength, char* rawPath);
		bool	readFragment	(int* iIndex, int iLength, char* rawPath);
};

#endif // URL_H
