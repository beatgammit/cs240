#ifndef __XMLTOKENIZER_H__
#define __XMLTOKENIZER_H__

class XMLToken {
	public:
		/*
		 * Gets the name of this token.
		 * 
		 * @return The name of this token
		 */
		string getName();

	private:
		string name;
		List attributes;
}

class XMLTokenizer {
	friend class XMLToken;

	public:
		/*
		 * Constructor.
		 * 
		 * @param filename- file to tokenize
		 */
		XMLTokenizer(string filename);

		/*
		 * True if we have another token.
		 */
		bool hasNext();

		/*
		 * Gets the next token.
		 * 
		 * @return The next XML Token
		 */
		XMLToken next();
}

#endif
