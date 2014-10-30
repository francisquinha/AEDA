
#include "tem_id.h"

// construtor tem_id
tem_id::tem_id(long id): ID{id} {}

// obter ID
long tem_id::get_ID(){
	return ID;
}

// atribuir ID
void tem_id::set_ID(long id) {
	ID = id;
}




