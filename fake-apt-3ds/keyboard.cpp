#include <3ds.h>
#include <3ds/types.h>
#include <iostream>
#include <vector>
static std::vector<SwkbdDictWord> words;

/*
	Return a string of the keyboard.
	uint maxLength: The max length.
	const std::string &Text: Const Reference to the Text.
	const std::vector<std::unique_ptr<StoreEntry>> &entries: Const Reference of all entries for the words to suggest.
*/
//shoutouts to Universal-Team
std::string setkbdString(uint maxLength, const std::string &Text) {
	
	SwkbdState state;
	swkbdInit(&state, SWKBD_TYPE_NORMAL, 2, maxLength);
	char temp[maxLength + 1] = { 0 };
	swkbdSetHintText(&state, Text.c_str());
	swkbdSetValidation(&state, SWKBD_NOTBLANK_NOTEMPTY, SWKBD_FILTER_PROFANITY, 0);

	SwkbdButton ret = swkbdInputText(&state, temp, sizeof(temp));
	temp[maxLength] = '\0';

	return (ret == SWKBD_BUTTON_CONFIRM ? temp : "");
}
