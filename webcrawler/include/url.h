#ifndef __URL_H__
#define __URL_H__

/*
 * The scheme of the URL.  Represents whether the URL is a local file or 
 * a network resource.
 */
enum SCHEME{SCH_NULL, SCH_HTTP, SCH_FILE};

/*
 * The domain and port number of the URL (if it is a network resource).
 */
struct NET_LOC{
	char* domain;
	int portNumber;
};

/*
 * Represents a URL. Each chunk is broken up ints smaller chunks for easier
 * comparison with other URLs.
 */
class URL
{
    public:
		/*
		 * Initializes member variables.
		 */
		void initialize();

		/*
		 * Breaks up the url into chunks to prepare it for resolving.
		 * 
		 * @param urlRaw- The raw text of the URL
		 */
		URL(string url);

		/*
		 * Turns the URL into a string.
		 * 
		 * @param output- Where to store the string
		 */
		void toString(char** output);

		/*
		 * Updates this URL with a piece of a relative URL.
		 * 
		 * @param token- The part of a relative URL to parse
		 */
		void updateURL(char* token);

		/*
		 * Destructer. Deletes all instance data.
		 */
		virtual ~URL();

	private:
		/*
		 * Removes the filename from the end of the URL
		 */
		void removeFilename();

		/*
		 * Kills the path part of this URL.
		 */
		void killPath();

		/* Whether this is a local file URL or one on the internet */
		SCHEME type;

		/* The domain and port number. This should never change */
		NET_LOC net_loc;

		/* The current length of the path string */
		int pathLen;

		/* The path string */
		char* path;

		/* The length of the query string */
		int queryLen;

		/* The query string */
		char* query;

		/* The length of the fragment string */
		int fragmentLen;
		
		/* The fragment string */
		char* fragment;

		/*
		 * Reads the Scheme (file || html) and returns the Scheme.
		 * 
		 * @param iIndex- The current index in the input string
		 * @param iLength- The total length of the input string
		 * @param rawPath- The input string
		 * @return The scheme of this URL
		 */
		SCHEME	readScheme		(int* iIndex, int iLength, char* rawPath);
		/*
		 * Reads the NET_LOC (domain and port number) and returns whether
		 * it was succesful.
		 * 
		 * @param iIndex- The current index in the input string
		 * @param iLength- The total length of the input string
		 * @param rawPath- The input string
		 * @return True if one was found, false otherwise.
		 */
		bool	readNetLoc		(int* iIndex, int iLength, char* rawPath);

		/*
		 * Reads the path (everything before the query or fragment) from the
		 * input string and returns true if one was found.
		 * 
		 * @param iIndex- The current index in the input string
		 * @param iLength- The total length of the input string
		 * @param rawPath- The input string
		 * @return True if one was found, false otherwise.
		 */
		bool	readPath		(int* iIndex, int iLength, char* rawPath);

		/*
		 * Reads the query (starts with ?) from the input string and returns
		 * true if one was found.
		 * 
		 * @param iIndex- The current index in the input string
		 * @param iLength- The total length of the input string
		 * @param rawPath- The input string
		 * @return True if one was found, false otherwise.
		 */
		bool	readQuery		(int* iIndex, int iLength, char* rawPath);
		/*
		 * Reads the fragment (starts with a #) from the input string and
		 * returns true if one was found.
		 * 
		 * @param iIndex- The current index in the input string
		 * @param iLength- The total length of the input string
		 * @param rawPath- The input string
		 * @return true if a fragment was found, false otherwise
		 */
		bool	readFragment	(int* iIndex, int iLength, char* rawPath);
};
#endif
