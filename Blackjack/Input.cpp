#include "Input.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

typedef std::map<std::string, Action> StringToAction;

const StringToAction convert_string_to_action =
{
	{ "H", Action::Hit	 },
	{ "S", Action::Stand },
};

Action Input::ReadInput()
{
	Action action = Action::Undefined;

	while (true)
	{
		std::string player_input;
		std::cout << "Choose from the following actions: (H)it, (S)tand." << std::endl;
		std::getline(std::cin, player_input);
		std::transform(player_input.begin(), player_input.end(), player_input.begin(), ::toupper);

		if (player_input.size() != 1)
		{
			std::cout << "'" << player_input << "' is invalid. Input must be 1 character long. Try again." << std::endl << std::endl;
			continue;
		}
		else if (player_input.at(0) != 'H' && player_input.at(0) != 'S')
		{
			std::cout << "'" << player_input << "' is invalid. Input must be either 'H' or 'S'. Try again." << std::endl << std::endl;
			continue;
		}
		else
		{
			action = convert_string_to_action.at(player_input);
			break;
		}
	}

	std::cout << std::endl;

	return action;
}