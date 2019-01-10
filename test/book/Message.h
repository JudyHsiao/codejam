#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>
#include <iostream>

class Folder;

class Message {
  friend class Folder;
  friend void swap(Message &, Message &);
  friend void swap(Folder &, Folder &);
public:
  explicit Message(const std::string &s = "") : contents(s), folders() {}

  Message(const Message &);
  Message &operator=(const Message &);
  ~Message();

  void save(Folder &);
  void remove(Folder &);

  void print();

private:
  std::string contents;
  std::set<Folder *> folders;

  void add_to_folders(const Message &);
  void remove_from_folders();

  void addFdr(Folder *);
  void remFdr(Folder *);
};

void swap(Message &, Message &);


#endif