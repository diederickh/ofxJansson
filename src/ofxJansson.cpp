#include "ofxJansson.h"

float ofxJansson::getValueF(json_t* oNode,const char* sFieldName,  float fDefault) {
	json_t* field_node = json_object_get(oNode, sFieldName);
	if(json_is_null(field_node))
		return fDefault;
	if(!json_is_number(field_node)) {

		#ifdef DEBUG_JANSSON
			cout << "ERROR: The " << sFieldName << " field cannot be parsed as an float\n";	
		#endif
		return fDefault;	
	}
	return json_is_true(field_node);
}

bool ofxJansson::getValueB(json_t* oNode, const char* sFieldName, bool bDefault ) {
	json_t* field_node = json_object_get(oNode, sFieldName);
	if(json_is_null(field_node))
		return bDefault;
	if(!json_is_boolean(field_node)) {
		#ifdef DEBUG_JANSSON
			cout << "ERROR: The " << sFieldName << " field cannot be parsed as an boolean\n";	
		#endif
		return bDefault;	
	}

	return json_is_true(field_node);
}

// get string value.
string ofxJansson::getValueS(json_t* oNode,const char* sFieldName,  string sDefault ) {
	json_t* field_node = json_object_get(oNode, sFieldName);
	if(json_is_null(field_node))
		return sDefault;
	if(!json_is_string(field_node)) {
		#ifdef DEBUG_JANSSON
			cout << "ERROR: The " << sFieldName << " field cannot be parsed as a string\n";
		#endif
		return sDefault;	
	}
	
	return json_string_value(field_node);
}

// get integer value
long ofxJansson::getValueI(json_t* oNode, const char* sFieldName, int nDefault) {
	json_t* field_node = json_object_get(oNode, sFieldName);
	if(json_is_null(field_node))
		return nDefault;
	if(!json_is_integer(field_node)) {
		#ifdef DEBUG_JANSSON
			cout << "ERROR: The " << sFieldName << " field cannot be parsed as an integer\n";	
		#endif
		return nDefault;	
	}
	return json_integer_value(field_node);
}


