
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

// construtor Object
Object::Object(long id): ID {id} {}

// obter ID
long Object::get_ID() {
	return ID;
}
