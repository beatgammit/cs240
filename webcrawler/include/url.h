/*
 * File:   URL.h
 * Author: testtake
 *
 * Created on February 2, 2011, 4:14 PM
 */

#ifndef URL_H
#define	URL_H

#include "string"

#define MAX_STR 1024


enum URLTYPE {
    HTTP = 1,
    FILETYPE = 2
};

class URL {
public:
    URL(std::string path);
    URL(const URL& orig);
    virtual ~URL();

    std::string resolve(std::string relative);
    bool domainMatches(URL* tURL);
    bool pathMatches(URL* tURL);
    std::string getExtension();

    static bool isRelative(std::string tURL);
private:
    URLTYPE type;
    char* head;
    char* path;
    bool bFixup;

    void applyChange(char* tToken);
    std::string output();
    void fixup();
    void clearPath();
};

#endif	/* URL_H */
