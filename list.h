#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define t_INT 0
#define t_STRING 1
#define t_DICT 2
#define t_FUNC 3

struct Var {
	char* name;
	int type;
	void* ptr;
	struct Var* previous_node;
};

struct VarList { 
	struct Var* head;
	int size;
};

struct DictList {
	struct DictPair* head;
	int size;
};

struct DictPair {
	void* key;
	int key_type;

	void* value;
	int value_type;

	struct DictPair* previous_pair;
};

// Intitalize List
struct VarList* init_VarList(){
    
    // Create pointer to VarList
    struct VarList* varlist = (struct VarList*)malloc(sizeof(struct VarList));
    
    // Initialize VarList variables
    varlist->head = NULL;
    varlist->size = 0;

    // Return pointer
    return varlist;
}

// Search vor variable in List
struct Var* search_VarList(struct VarList* stack, char* term){

    struct Var* current_node = stack->head;

    for(int i=0; i<stack->size; i++){

        if(strcmp(term, current_node->name) == 0){
                return current_node;
        }

        current_node = current_node->previous_node;
    } 
    return NULL;
}

// Push variable in list or else update
int update_VarList(struct VarList* stack, char* name, int type, void* ptr){
    
	struct Var* node = search_VarList(stack, name);
	
	// Check if variable already exist
	if (node != NULL) {

		// Update name and pointer
		node->type = type;
		node->ptr = ptr;
		
		return 0;
	}
	
    // Create pointer to node
   	struct Var* new_node = (struct Var*)malloc(sizeof(struct Var));

	// Initialize node values
	new_node->name = name;
	new_node->type = type;
    	new_node->ptr = ptr;
   	 new_node->previous_node = stack->head;
    
    	// Get head
    	stack->head = new_node;
	
	// Increase size
    	stack->size++;
	
	return 1;
}

// Intitalize List
struct DictList* init_DictList(){
    
    // Create pointer to DictList
    struct DictList* dict = (struct DictList*)malloc(sizeof(struct DictList));
    
    // Initialize DictList variables
    dict->head = NULL;
    dict->size = 0;

    // Return pointer
    return dict;
}

// Search for variable in List
struct DictPair* search_DictList(struct DictList* dict, void* key, int type){

    	struct DictPair* current_pair = dict->head;

   	for(int i=0; i<dict->size; i++){

        	if (current_pair->key_type != type) continue;
		
		if (type == t_INT) {
			if(*(int*)current_pair->key == *(int*)key) return current_pair;
		}
		else if (type == t_STRING) {
			if(strcmp(( char*)key, (char*)current_pair->key ) == 0) return current_pair;
        	}
        
		current_pair = current_pair->previous_pair;
    	} 

    	return NULL;
}

// Push variable in list or else update
int update_DictList(struct DictList* dict, void* key, int key_type, void* value, int value_type) {
    
	struct DictPair* pair = search_DictList(dict, key, key_type);
	
	// Check if variable already exist
	if (pair != NULL) {

		// Update name and pointer
		pair->value_type = value_type;
		pair->value = value;
		
		return 0;
	}
	
    	// Create pointer to node
   	struct DictPair* new_pair = (struct DictPair*)malloc(sizeof(struct DictPair));

	// Initialize node values
	new_pair->key = key;
	new_pair->key_type = key_type;
	new_pair->value = value;
	new_pair->value_type = value_type;
   	new_pair->previous_pair = dict->head;
    
    	// Get head
    	dict->head = new_pair;
	
	// Increase size
    	dict->size++;
	
	return 1;
}

int setDefault_DictList(struct DictList* dict, void* key, int key_type, void* value, int value_type) {
    
	struct DictPair* pair = search_DictList(dict, key, key_type);
	
	// Check if variable already exist
	if (pair != NULL) {

		// DONT Update name and pointer
		//pair->value_type = value_type;
		//pair->value = value;
		
		return 0;
	}
	
    	// Create pointer to node
   	struct DictPair* new_pair = (struct DictPair*)malloc(sizeof(struct DictPair));

	// Initialize node values
	new_pair->key = key;
	new_pair->key_type = key_type;
	new_pair->value = value;
	new_pair->value_type = value_type;
   	new_pair->previous_pair = dict->head;
    
    	// Get head
    	dict->head = new_pair;
	
	// Increase size
    	dict->size++;
	
	return 1;
}

void print_DictList(struct DictList* dict) {
        printf("dict_items({");
        
        struct DictPair* current_pair = dict->head;

        for(int i = 0; i < dict->size; i++) {
                
                // Key print
                if(current_pair->key_type == t_INT) printf("(%d, ", *(int*)current_pair->key);
                else if(current_pair->key_type == t_STRING) printf("('%s', ", (char*)current_pair->key);

                // Value print
                if(current_pair->value_type == t_INT) printf("%d)", *(int*)current_pair->value);
                else if(current_pair->value_type == t_STRING) printf("'%s')", (char*)current_pair->value);
                else if(current_pair->value_type == t_DICT) print_DictList((struct DictList*)current_pair->value);

	            if(dict->size != i+1) printf(", ");
                current_pair = current_pair->previous_pair;        
        }

        printf("})\n");
}

void print_VarList(struct VarList* stack){

    	struct Var* current_node = stack->head;
	printf("VARIABLES:\n");
    	for(int i = 0; i < stack->size; i++){

		if (current_node->type == t_INT) {
		    
     			printf("name: %s,\t type: %d,\t value: %d\n", 
			current_node->name, current_node->type, *(int*)current_node->ptr);
		} 
		else if (current_node->type == t_STRING) {
			
     			printf("name: %s,\t type: %d,\t value: %s\n", 
			current_node->name, current_node->type, (char*)current_node->ptr);
		}
		else if (current_node->type == t_FUNC) {
			
     			printf("name: %s,\t type: %d,\t value: - \n", 
			current_node->name, current_node->type);
		}
                else if(current_node->type == t_DICT) {
                        printf("name: %s \t value: %d ", 
                        current_node->name, current_node->type);

                        print_DictList((struct DictList*)current_node->ptr);
                }

        	current_node = current_node->previous_node;
    	} 
}

void print(struct VarList* stack,char* var){

    	struct Var* current_node = stack->head;

		if (current_node->type == t_INT) {
		    
     			printf("name: %s,\t type: %d,\t value: %d\n", 
			current_node->name, current_node->type, *(int*)current_node->ptr);
		} 
		else if (current_node->type == t_STRING) {
			
     			printf("name: %s,\t type: %d,\t value: %s\n", 
			current_node->name, current_node->type, (char*)current_node->ptr);
		}


        	current_node = current_node->previous_node;
    	
}
		
/*

int main() {

	struct VarList* stack = init_VarList();
        
        char* var = "all this, is as boring as beans";
	update_VarList(stack, "tassos", t_STRING, (void*)var);

	char* var_2 = "i want to fuck";
	update_VarList(stack, "billaras", t_STRING, (void*)var_2);

	int var_3 = 420;
	update_VarList(stack, "alekos", t_INT, (void*)&var_3);

	print_VarList(stack);

	int var_4 = 69696969;
	update_VarList(stack, "tassos", t_INT, (void*)&var_4);
        print_VarList(stack);
        printf("_______________________\n");

        struct DictList* dict = init_DictList();
        struct DictList* nested_dict = init_DictList();

	char* key_1 = "o meletis einai sthn mandra";
        int value_1 = 4;
        update_DictList(dict, (void*)key_1, t_STRING, (void*)&value_1, t_INT);
        update_DictList(nested_dict, (void*)key_1, t_STRING, (void*)&value_1, t_INT);


        char* key_2 = "o loukas perni monster enema";
        char* value_2 = "polla";
        update_DictList(dict, (void*)key_2, t_STRING, (void*)value_2, t_STRING);
        update_DictList(nested_dict, (void*)key_2, t_STRING, (void*)value_2, t_STRING);

        int key_3 = 420;
        int value_3 = 4;
        update_DictList(dict, (void*)&key_3, t_INT, (void*)&value_3, t_INT);

        int key_nested = 888;
        update_DictList(dict, (void*)&key_nested, t_INT, (void*)nested_dict, t_DICT);
        print_D      printf("_______________________\n");
        update_VarList(stack, "bouzas", t_DICT, (void*)dict);
        print_Vaeturn 0;
}
*/