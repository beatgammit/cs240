#ifndef URLRESOLVER_H
#define URLRESOLVER_H

#include "url.h"

class URLResolver
{
	public:
		URLResolver();
		void resolve(URL* baseURL, char* relativeURL, char** output);
		virtual ~URLResolver();
	protected:
	private:
		URL* baseURL;
};

#endif // URLRESOLVER_H
