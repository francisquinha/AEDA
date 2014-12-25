
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

/** @file
 *
 * @brief Source da classe Object.
 *
 * Praticamente todas as outras classes sao subclasses de Object.
 **/

Object::Object(unsigned long id): ID {id} {}

unsigned long Object::get_ID() {
	return ID;
}
