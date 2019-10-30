#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


//define prototypes
struct entry;
struct entry * begin = NULL;
struct entry * createNode (char *entry, char *define);
void addWord (char *entry, char *define);
void Reset();
void searchword (char *array);
void deleteWord (char *array);
void init();



int main(){

    init();
    int i = 0;
    printf("**__My Dictionary__**\n");
    while (i == 0) {
        printf("Option 1-Insert new entry\n");
        printf("Option 2-Search a entry\n");
        printf("Option 3-Delete a entry\n");
        printf("Option 4-Reset\n");
        printf("Option 5-Quit\n");

        printf("*#*#*#*#*#*#*#*#*#\n");

        char n;
        printf("Choose one of the option:: ");
        scanf("%c",&n);

        printf("*#*#*#*#*#*#*#*#*#\n");

        char* wordName = (char *) calloc(50, sizeof(char));
        char val;
        switch(n){
            case '1':
                ;
                char* definition = (char *) calloc(100 , sizeof(char));
                printf("Enter a word:");
                scanf("%c", &val);
                gets(wordName);
                printf("Definition of word:");
                gets(definition);
                addWord(wordName, definition);   
                printf("*****************\n");
                break;

            case '2':
                ;
                printf("Enter a word to search: ");
                scanf("%c", &val);
				gets(wordName);
                searchword(wordName);
                printf("*****************\n");
                break;

            case '3':
                ;
                printf("Enter a word to remove: ");
                scanf("%s", wordName);
                scanf("%c", &val);
//				gets(wordName);
                deleteWord(wordName);
                printf("*****************\n");
                break;

            case '4':
                Reset();
                scanf("%c", &val);
                break;
                
            case '5':
                i = 1;
                scanf("%c", &val);
                break;

            default:
                printf("Wrong input\n");
                scanf("%c", &val);
                return 0;
        }
    }
}


struct entry {
    struct entry * next;
    char *word;
    char *definition;
}; 


struct entry * createNode (char *entry, char *define){
    struct entry * newWord = (struct entry *) malloc(sizeof(struct entry));
    newWord -> word = entry;
    newWord -> definition = define;
    newWord -> next = NULL;

    return newWord;
}


//To insert new word

void addWord (char *entry, char *define){
    struct entry * new = createNode(entry, define);
    struct entry * ptr = begin;
    struct entry * preptr = begin;
    if (begin != NULL){
        while (ptr != NULL){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = new;
    }
    else{
        begin = new;
    }
}





//To Reset your dictionary
void Reset(){
    struct entry *ptr = begin;
    while (ptr != NULL){
        struct entry *val = ptr;
        begin = ptr->next;
        ptr = ptr->next;
        free(val);
    }
}



//To search a word
void searchword (char *array){
    struct entry * ptr = begin;
    while (ptr != NULL){
        if(strcmp(ptr->word,array) == 0){
            puts(ptr->definition);
            return;
        }
        ptr = ptr->next;
    }
    if (ptr == NULL)
        printf("This Word is not in your dictionary\n");
}



//To delete a word
void deleteWord (char *array){
    struct entry * ptr = begin;
    struct entry * preptr = begin;

    if(strcmp(begin->word,array) == 0){
        ptr = ptr->next;
        begin = ptr;
        free(preptr);
    }else{
        while (ptr != NULL){
            if(strcmp(ptr->word,array) == 0){
                preptr->next = ptr->next;
                free(ptr);
                return;
            }
            preptr = ptr;
            ptr = ptr->next;
        }
    }
}




void init(){
    addWord("Photocopy","Photographic copy of printed or written matrical");
    addWord("Binding","strong covering holding the pages of a document");
    addWord("Laminate","overly with a layer of plastic or some other protective material");
    addWord("Dozen","set of twelve");
    addWord("Scan","convert image or file to a digital file");
    addWord("Typesetting", "arrange text and images for documents ");
    addWord("Digital printing","methods of printing from a digital-based image directly to a variety of media ");
    addWord("Photo printing","process of producing a final image on paper for viewing, using chemically sensitized paper ");
    addWord("Internet cafe","computers are provided for accessing the internet for computer-related tasks ");
    addWord("Email","messages distributed by electronic means from one computer user to one or more recipients via a network ");
    addWord("Graphic designing","process of visual communication and problem-solving through the use of typography, photography and illustration ");
    addWord("Fax","an exact copy of a document made by electronic scanning and transmitted as data by telecommunications links ");
    addWord("Calls","contact someone by phone ");
}
