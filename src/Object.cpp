#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

// construtor Object
Object::Object(long id): ID {id} {}

// obter ID
long Object::get_ID() {
	return ID;
}

// atribuir ID
void Object::set_ID(long id) {
	ID = id;
}
