#ifndef OFXJANSSONH
#define OFXJANSSONH

#include "lib/jansson/jansson.h"
#include <string>
#include <iostream>

// uncomment this to see error while parsing JSON
//#define DEBUG_JANSSON


/** 
 * Tiny wrapper for jansson json parser.
 * 
 * @url http://www.digip.org/jansson/ 
 *
 */
using namespace std;
class ofxJansson {
	public:
		float	getValueF(json_t* oNode, const char* sFieldName, float fDefault = 0.0f);
		bool	getValueB(json_t* oNode, const char* sFieldName, bool bDefault = false);
		string	getValueS(json_t* oNode, const char* sFieldName, string sDefault = "");
		long	getValueI(json_t* oNode, const char* sFieldName, int nDefault = 0);
};
#endif