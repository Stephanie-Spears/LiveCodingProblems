//
// Created by Stephanie Spears on 2/20/18.
//

#ifndef LIVECODINGPROBLEMS_USERINTERFACE_H
#define LIVECODINGPROBLEMS_USERINTERFACE_H

int readInt(const char prompt[]);
double readDouble(const char prompt[]);
char readChar(const char prompt[]);
//char readString(const char prompt[], char aString[]);

void displayMenu();
int readInCommand();
void processCommand(char command);


#endif //LIVECODINGPROBLEMS_USERINTERFACE_H
