#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

class Object {
	long ID;
public:
	Object(long id);
	long get_ID();
	void set_ID(long id);
};

class Object_nao_existe: public Object {
public:
	Object_nao_existe(long id): Object {id} {};
	virtual ~Object_nao_existe() {};
};

#endif /* SRC_OBJECT_H_ */
