#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

/** @file
 *
 * @brief Header da classe Object.
 *
 * Praticamente todas as outras classes sao subclasses de Object.
 **/

/**
 * @brief Classe com toda o id de qualquer objeto da biblioteca
 *
 * Todas as classes com um id sao subclasses de Object (ou de uma subclasse de Object)
 **/
class Object {

	unsigned long ID; /**< @brief codigo de identificacao do objeto **/

public:

	/**
	 * @brief Construtor de Object
	 *
	 * @param id codigo de identificacao do objeto
	 **/
	Object(unsigned long id);

	/**
	 * @brief Funcao para obter o id de um objeto
	 *
	 * @return long com o id
	 **/
	unsigned long get_ID() const;
};

#endif /* SRC_OBJECT_H_ */
