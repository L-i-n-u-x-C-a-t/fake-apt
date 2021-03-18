#include <iostream>
#include <vector>
#include <3ds.h>
#include <3ds/types.h>
static std::vector<SwkbdDictWord> words;
std::string setkbdString(uint maxLength, const std::string &Text);