#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include <string>

enum command_code{
    clist,
    cadd,
    cremove,
    ccart,
    ccheckout,
    cexit,
    cexeption
};

command_code get_command(std::string const &command);
bool full_command_cycle(std::string const &command, unsigned int id, unsigned int count);
bool part_command_cycle(std::string const &command);

void list();
void add(unsigned int id, unsigned int count);
void remove(unsigned int id, unsigned int count);
void cart();
void checkout();

#endif

