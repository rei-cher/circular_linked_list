# YOU SHOULD NOT PUSH ANY MODIFICATION TO THE FILES IN THIS DIRECTORY

- If you identify a problem with any of the tests in this directory, make an issue on your repo.

## JQR requirements for a circularly linked list
Demonstrate skill in creating and using a circularly linked list that accepts any data type:
- Creating a circularly linked list with n number of items
- Navigating through a circularly linked list
- Finding the first occurrence of an item in a circularly linked list
- Sorting the circularly linked list alphanumerically using a function pointer
- Removing selected items from the circularly linked list
- Inserting an item into a specific location in a circularly linked list
- Removing all items from the circularly linked list
- Destroying a circularly linked list
  
This circularly linked list does things slightly differently than the letter of the law listed above. For your line items in the JQR please explain some of the variations present in this implementation.
- set length vs variable length
- sorting on command vs sorting on insert
- removing all items vs just destroying and creating a new one
Otherwise this implementation should meet the above requirements. Also wanted to highlight this line from the .c again "This list doesn't need to keep track of the head/tail, since all nodes point both forward and backwards you can just keep track of any node (or the last one that was inserted). From that node, you can get to any other node. This way your list is "circular". If you keep track of a head and tail pointer and the tail just points back to the head, that's not really "circular". " 

## Explain your unit testing here
