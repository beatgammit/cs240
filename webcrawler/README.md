Basic Intro
===========

WebCrawler takes an initial webpage and indexes and crawls all pages in a breadth-first search, which is done in a series of steps:

* Parse the text of the document, pulling out important words and details
    * Words are checked against a set of "stop words" to refine the index
	* Title tag is used as the page description
	* Text in script tags and HTML comments are ignored
* Store links and process each one after the page has been parsed
    * Visited URLs are stored and each link checked against this set
	* For simplicity, webcrawler only processes links in the current domain
	* Only HTML files are parsed
* Output the results in a formatted XML document

Classes
=======

These are the basic classes in WebCrawler with their functions and basic implementation notes.

WebCrawler
----------

WebCrawler is the start point of the application, and drives the execution of the program.  In particular, this is the basic flow:

* Parse commandline input and initialize data structures
    * Initialize StopWords class
	* Initialize KeywordIndex class
    * Initialize PageQueue with start URL
    * Initialize PagesParsed class
* Loop over PageQueue until empty
	* Pop URL
    * Download page
    * Parse page with HTMLParser
    * Add page to PagesParsed
* Output PagesParsed as XML using XMLPrinter

HTMLParser
----------

HTMLParser parses a page in the following procedure:

* Store page URL in new page struct
* Parse text unless either a link or the title tag is found
    * Check words against the stop words
	* Add keywords to keyword index
* Store title tag text in Page as the description
* Add links to PageQueue if they are in scope and not in PagesParsed
* Return pointer to Page

StopWords
---------

* Binary search tree- fast lookup
* Words will be sorted first, then added intelligently to ensure best-case

PageQueue
---------

* Queue implemented as a LinkedList
* Should be small enough to not impact speed too much
* Contains URLs

PagesParsed
-----------

* Implemented as binary search tree, not optimized
* Contains pointers to Page structs

Page
----

* Struct that contains a description and a URL

URL
---

* Takes a base URL and relative URL
* Compare method to determine equivelence (same domain, port and path)

URLResolver
-----------

The URL resolver from the URLResolver lab rewritten to use the string class.

KeywordIndex
------------

* Map implemented as a binary search tree (possibly self balancing)
* Maps a word to an occurence map (maps page to a count)

Occurrence
----------

* Map implemented as a binary search tree
* Maps a URL to a count (number of times a word appears at this URL)

XMLPrinter
----------

* Prints start URL
* Prints the pages crawled (from PagesParsed)
    * Prints URL
    * Prints page description
* Prints the KeywordIndex as formatted XML
    * Prints each word with associated value and occurrences

LinkedList
----------

The LinkedList from the Collections lab with minor modifications.

BST
---

The binary search tree from the Collections lab with minor modifications.
