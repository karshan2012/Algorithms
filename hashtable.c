#include <stdio.h>

typedef struct _list_kk
{
	char* str;
	struct _list_kk* next;
}list_kk;

typedef struct _hashtable_kk
{
	int size;
	list_kk **table;
}hashtable_kk;

hashtable_kk* create_hash_table(int size)
{
	hashtable_kk *new_table;
	
	if (size<1)
	return NULL;
	
	/* attempted to allocate memory for table structure */
	if((new_table==malloc(sizeof(hashtable_kk)))==NULL)
	return NULL;
	
	/* attempted to allocate memory for table itself */
	if((new_table->table==malloc(sizeof(list_kk)*size))==NULL)
	return NULL;
	
	int i;
	
	for(i=0;i<size;i++)
	new_table->table[i]=NULL;
	
	new_table->size = size;
	
	return new_table;
	
	
}

int hashfunction(hashtable_kk *mytable,char *str)
{
	int sum = 0;
	for(int j=0;str[j]!='\0';j++)
	{
		sum+=str[j];
	}
	return sum%mytable->size;
}

list_kk* search_string(hashtable_kk *mytable,char *str)
{
	list_kk* list;
	int hashvalue = hashfunction(mytable,str);
	
	for(list = mytable->table[hashvalue];list!=NULL;list=list->next)
	{
		if(strcmp(str,list->str)==0) return list;
	}
	
	return NULL;
}


int add_string_to_hashtable(hashtable_kk *mytable,char *str)
{
	list_kk *new_list;
	list_kk *curr_list;
	
	/* get hashvalue to insert at that index */
	int hashvalue = hashfunction(mytable,str);
	
	/* allocate memory to new list */
	if((new_list=malloc(sizeof(list_kk)) == NULL) return 1;
	
	/*if str already exist then no need to insert it again */
	curr_list = search_string(mytable,str);
	if(curr_list != NULL) return 2;
	
	/* add string to newly created list */
	new_list->str = str;
	new_list->next = mytable->table[hashvalue];
	mytable->table[hashvalue] = new_list;
	
	return 0;
	
	
	
}


int main()
{
    hashtable_kk *mytable;
    int size_of_table = 10;
    mytable = create_hash_table(size_of_table);
    //printf("Hello world");
    printf(mytable);
    return 0;
}
