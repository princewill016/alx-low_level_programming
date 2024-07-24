#ifndef DOG_H_
#define DOG_H_

/**
 * struct dog - A structure to represent a dog
 * @name: The name of the dog (char pointer)
 * @age: The age of the dog (float)
 * @owner: The name of the dog's owner (char pointer)
 */
typedef struct dog {
	char *name;
	float age;
	char *owner;
	} dog_t;

#endif /* DOG_H_ */
