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

    std::string output();
    static bool isRelative(std::string tURL);
private:
    URLTYPE type;
    std::string head;
    std::string path;
    bool bFixup;

    void applyChange(char* tToken);
    void fixup();
    void clearPath();
};

#endif	/* URL_H */
