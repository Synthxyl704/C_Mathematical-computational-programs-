#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

                                                              /*

printf("\n%sISO7/Shell ->%s ", BOLD, FG_WHITE;
          ^              ^    
      "\x1b[1m"      "\x1b[37m"
                                                              */

#define RESET "\x1b[0m"

#define BOLD "\x1b[1m"

#define FG_BLACK "\x1b[30m"
#define FG_RED "\x1b[31m"
#define FG_GREEN "\x1b[32m"
#define FG_YELLOW "\x1b[33m"
#define FG_BLUE "\x1b[34m"
#define FG_MAGENTA "\x1b[35m"
#define FG_CYAN "\x1b[36m"
#define FG_WHITE "\x1b[37m"

#define MAX_TAG_STR_LEN 100
#define MAX_TASK_STR_LEN 1000

int tagCount  = 0;
int taskCount = 0;

// STRUCTS / NODES //

// a struct for task storage
typedef struct Task {
  char name[MAX_TASK_STR_LEN];                        // blank but works
  struct Task *next;                                  // next pointer
} Task;                                         

// a struct for tag storage
typedef struct Tag {
  char name[MAX_TAG_STR_LEN];                         // tag name
  Task *taskList;                                     // store the tasks list at this pointer
  struct Tag *next;                                   // next pointer
} Tag;                                               

Tag *headTag = NULL;                 // NULL it 
                                     // the first of the tags list
                                     // initialize current[s] to this thing

// STRUCT / NODES / OVER //

void returnUserInputCmdShell(char *inputMainShellCmd) {
  printf("\n%s%sISO7/Shell ->%s ", BOLD, FG_MAGENTA, RESET);
  scanf(" %[^\n]", inputMainShellCmd);                 // i dont know why this works
}                                                      // but it does
                                                       // i better leave it like this
void commandExpository() {
  puts("-> help   |   Shows all available commands");
  puts("-> show   |   Shows all existing tags and tasks");
  printf("\n");
}

void commandHelp() {
  printf("\n%s%sCommands list:%s\n", BOLD, FG_GREEN, RESET);
  printf("-> %s#<tagName>             - adds a new tag and prompts for a task to be entered%s\n", FG_WHITE, RESET);
  printf("-> /select #<tag>         - selects the required tag and displays the tasks within it\n");
  printf("-> add to #<tag>          - Add a new task with an allotted tag\n");
  printf("-> rm #<tag>              - Remove all tasks with a specific allotted tag\n");
  printf("-> -exit ISO7            - Exits the shell with RETURN_SUCCESS / 0\n");
  printf("\n%s(Note: Enter the tag name in pascalCases)", FG_BLACK);
  printf("\nEnter #<tagName> for starting off!%s\n", RESET);
}


// looks cleaner this way


// [-> show] prompt
void showTagsAndTasks() {
  Tag *currentTag = headTag;                         
                                                        
  // if N/A tags?
  if (currentTag == NULL) {                                                                   
      printf("%s%s[N/A] tags available%s\n", BOLD, FG_RED, RESET);                        // print that theres no tags
      printf("\n%s(Note: Enter the tag name in pascalCases)", FG_BLACK);
      printf("\nEnter #<tagName> for starting off!%s\n", RESET); 
  } 

  // print the amount of tags and tasks present at that moment
  printf("\n%sTheres [%d] tags currently available\n", FG_BLUE, tagCount);
  printf("Theres [%d] tasks currently assigned%s\n", taskCount, RESET);
  printf("\n");

  // if tags exist?
  while (currentTag != NULL) {               
    printf("Tag: %s%s[#%s]%s\n", BOLD, FG_WHITE, currentTag->name, RESET);                
    Task *currentTask = currentTag->taskList;              // keep iterating & printing until current tag is NULL

  // if tasks exist?
    while (currentTask != NULL) {
      printf("- | Task: %s\n", currentTask->name);
      currentTask = currentTask->next;                     // Keep I&P until NULL = true
    } currentTag = currentTag->next;                       // once out, actually set it to the next pointer 
      printf("\n");
  } 
}

// add/store user inputted tags here
void addTag(char *tagName) {
  Tag *newTag = (Tag*) malloc(sizeof(Tag));
  strcpy(newTag->name, tagName);                         // copy inputted tag --> name
  newTag->taskList = NULL;                               // for penetration
  newTag->next = headTag;                                // ???
  headTag = newTag;                                     
  tagCount++;                                            // inc++ tagCount for displaying total stuff
}

// adding a task to an existing tag?
void addTaskToTag(char *taskName, char *tagName) {       // prompt for task name and tag name
  Tag *currentTag = headTag;                             // brainfuck again
 
  while (currentTag != NULL) {                                   // while this thing is NOT NULL --> iteration++
    if (strcmp(currentTag->name, tagName) == 0) {        // compare for correct tag finding val
      Task *newTask = (Task*) malloc(sizeof(Task));      // ???
      strcpy(newTask->name, taskName);                   // add to the first of the list
      newTask->next = currentTag->taskList;
      currentTag->taskList = newTask;
      taskCount++;
      return;
    } currentTag = currentTag->next;                     // point to next node/tag (which is empty/NULL)
  } printf("%s%s[N/A] tags found%s\n", BOLD, FG_RED, RESET);               // if tag is not found
}

// for finding any existing [#]-tags
Tag *findTag(char *tagName) {                            // prompt for tag name
  Tag *currentTag = headTag;                             // iterate from the first of tags list
  while (currentTag != NULL) {                          
    if (strcmp(currentTag->name, tagName) == 0) {        // iterate and if 0 = true then finding is correct
      return currentTag;
    }
    currentTag = currentTag->next;                       // point to next node/tag
  }
  return NULL;                                           // return nothing if finding is not successful
}

// selecting a tag?
void selectTag(char *tagName) {                          // prompt tag name
  Tag *selectedTag = findTag(tagName);                   // recursive call to check if the tag is even true/existing
  if (selectedTag != NULL) {                           
    printf("Selected tag: [%s]\n", selectedTag->name);
    Task *currentTask = selectedTag->taskList;           // keep going my boy

    while (currentTask != NULL) {
      printf("-Task: %s\n", currentTask->name);          // print the existing task
      currentTask = currentTask->next;                   // move to next task if there
    }
  } else {                                             
    printf("%s%sISO [N/A] - Tag not found%s\n", BOLD, FG_RED, RESET);
  }
}

// selecting and adding?
void selectTagAndAdd(char *tagName) {                     // prompt tag name
  Tag *selectedTag = findTag(tagName);                    // check for the tag name if exists
  if (selectedTag != NULL) {                              // if it exists then it prompts for adding a task to it
    char taskName[MAX_TASK_STR_LEN];
    printf("Enter task for [#%s]: ", tagName);
    scanf(" %[^\n]", taskName);
    addTaskToTag(taskName, tagName);                       // adds to THAT selected task
  } else {
    printf("%s%sISO [N/A] - Tag not found%s\n", BOLD, FG_RED, RESET);
  }
}

void removeTasksByTag(char *tagName) {                     // prompt for the tag name ONLY
  Tag *currentTag = headTag;                               // iterate from 1st tag
  Tag *prevTag = NULL;                                     // to reference to the previous tag
   
  while (currentTag != NULL) {
    if (strcmp(currentTag->name, tagName) == 0) {
      Task *currentTask = currentTag->taskList;

     // (currentTask) is the same as (currentTask != NULL) 
      
      while (currentTask != NULL) {
        Task *nextTask = currentTask->next;
        free(currentTask);                                 // free the soul trapped in the current tag
        currentTask = nextTask;                            // point to next task
      }
      taskCount--;
      
      if (prevTag != NULL) {                               
        prevTag->next = currentTag->next;                  // link any prev tag to the next pointer, ie replacing the deleted tag
      } else {
        headTag = currentTag->next;                        // if no prev, that means its the headTag
      }                                                    // put it as next pointer, replacing the deleted tag with it
       
      free(currentTask);                                   // ---------------> task <-------------
      free(currentTag);                                    // free the deleted tag from its misery
      tagCount--; 

      printf("All tasks with [#%s] tag removed\n", tagName);
      return;
    }
    
    prevTag = currentTag;                                  // switch previous tag with any the next tag/node
    currentTag = currentTag->next;                         // pointer for the next node (ie NULL) until added
  }
  
  printf("%s%sISO [N/A] - Tag not found%s\n", BOLD, FG_RED, RESET);
}

int main(int argc, char *argv[]) {
  int tagCount  = 0;
  int taskCount = 0;

  char inputMainShellCmd[100];
  char restOfCommand[MAX_TASK_STR_LEN];

  if (argc > 0) {
    printf("%s%s\n\nCL args received:%s\n", BOLD, FG_GREEN, RESET);
    for (int inc = 1; inc < argc; inc++) {
      printf("Arg %d: [%s]\n", inc, argv[inc]);
    }
  }

  printf("\n%s-----------------------------%s\n", FG_YELLOW, RESET);
  printf("   %s%sE2+7_IsoAris's terminal%s\n", BOLD, FG_YELLOW, RESET);
  printf("%s-----------------------------%s\n\n", FG_YELLOW, RESET);

  //  ------------------------------------------------------------------------  //

  //  -  may sound very fancy but it is actually and its pretty simple
  //  -  E2+7 = 007       |      [NULL]E^2/+2 = 00 , +7 --> 00+7 = 007
  //  -  007_IsoAris
  //  -  IsoAris -復活-
  //  -  007IsoAris_

  //  ------------------------------------------------------------------------  //

  printf("%s%sAvailable shell commands: %s\n", BOLD, FG_GREEN, RESET);                                           // show all commands
  commandExpository();

  // conditional selection structure (hell)
  // comments added for extra assistance 

  while (true == true) {                                                       // who wouldve thought                                               
    returnUserInputCmdShell(inputMainShellCmd);
    
    if (strncmp(inputMainShellCmd, "help", 4) == 0) {                          // help/show all commands
        commandHelp();

    } else if (strncmp(inputMainShellCmd, "show", 4) == 0) {                   // show all tags and tasks
        showTagsAndTasks();

    } else if (strncmp(inputMainShellCmd, "/select", 7) == 0) {                // select
        char tagName[MAX_TAG_STR_LEN];                                         // had to change [#select] -> [/select] due to some probs
        sscanf(inputMainShellCmd, "/select #%s %[^\n]", tagName);              // %[^\n] reads until \n by user has been entered
        selectTag(tagName);       
                                                                               // doesnt work with scanf since it excludes [/select] entirely
    } else if (strncmp(inputMainShellCmd, "add to #", 8) == 0) {
        char tagName[MAX_TAG_STR_LEN];                                         // prompts for the tag's name

        Tag *tag = findTag(tagName);                                           // find the tag if existing
        char taskName[MAX_TASK_STR_LEN];
        printf("Enter task for [#%s] ", tagName);
        scanf(" %[^\n]", taskName);
        addTaskToTag(taskName, tagName);

    } else if (strncmp(inputMainShellCmd, "rm #", 4) == 0) {
        char tagName[MAX_TAG_STR_LEN];                                          // only the tag name 
        sscanf(inputMainShellCmd, "rm #%s", tagName);                           // since it couldnt save with the [#] included
        removeTasksByTag(tagName);

    } else if (inputMainShellCmd[0] == '#') {                                   // debugged #4
        char tagName[MAX_TAG_STR_LEN];                                          // SYS --> [?]
        sscanf(inputMainShellCmd, "#%s", tagName);                              // include the [#] for tag name
        addTag(tagName);                                                        // add the string into tagName

        char taskName[MAX_TASK_STR_LEN];
        printf("Enter task for [#%s]: ", tagName);
        scanf(" %[^\n]", taskName);
        addTaskToTag(taskName, tagName);
    } else if (strcmp(inputMainShellCmd, "-exit ISO7") == 0) {                   // cool syntax command yes
        break;      
    } else {
        printf("%s%sShell error: Invalid ISO command | [UNDEFINED]%s\n", BOLD, FG_RED, RESET);             //   |
    }
  } return EXIT_SUCCESS;        // added extra tabbed space for readablity
}
