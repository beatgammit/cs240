#ifndef __URLRESOLVER_H__
#define __URLRESOLVER_H__

#include "url.h"

/*
 * Resolves a URL given a base URL and a relative URL.
 */
class URLResolver
{
	public:
		/*
		 * Constructor.
		 * The URL passed in can be used multiple times to resolve multiple URLs
		 * 
		 * @param pBaseURL- the URL to base future URL resolutions on
		 */
		URLResolver(URL* pBaseURL);

		/*
		 * Resolves a URL given a relative URL.
		 * 
		 * @param relativeURL- The relative URL
		 * @return The new URL as a string
		 */
		string resolve(string relativeURL);

		/*
		 * Destructor.  Frees all allocated memory.
		 */
		virtual ~URLResolver();
	protected:
	private:
		/* The base URL */
		URL* baseURL;
};
#endif
