#include "Card.h"

#include <iostream>
#include <map>
#include <Windows.h>
#include <cstdio>

typedef std::map<Rank, std::string> RankToString;
typedef std::map<Suit, std::string> SuitToString;

const std::string clubs_cout("\xe2\x99\xa3");
const std::string diamonds_cout("\xe2\x99\xa6");
const std::string hearts_cout("\xe2\x99\xa5");
const std::string spades_cout("\xe2\x99\xa0");

const RankToString cout_rank =
{
	{ Rank::Ace,	"A"	},
	{ Rank::Two,	"2"	},
	{ Rank::Three,	"3"	},
	{ Rank::Four,	"4"	},
	{ Rank::Five,	"5"	},
	{ Rank::Six,	"6"	},
	{ Rank::Seven,	"7"	},
	{ Rank::Eighth, "8" },
	{ Rank::Nine,	"9"	},
	{ Rank::Ten,	"T"	},
	{ Rank::Jack,	"J"	},
	{ Rank::Queen,	"Q"	},
	{ Rank::King,	"K"	},
};

const SuitToString cout_suit =
{
	{ Suit::Clubs,		clubs_cout		},
	{ Suit::Diamonds,	diamonds_cout	},
	{ Suit::Hearts,		hearts_cout		},
	{ Suit::Spades,		spades_cout		},
};

Card::Card(Rank r, Suit s)
{
	rank = r;
	suit = s;
	SetConsoleOutputCP(CP_UTF8);
}

void Card::PrintCard() const
{
	std::cout << cout_rank.at(rank) << cout_suit.at(suit) << std::endl;
}

int Card::CardValue() const
{
	int rank_int = 0;

	switch (rank)
	{
	case Rank::Ace:
		rank_int = 1;
		break;
	case Rank::Two:
		rank_int = 2;
		break;
	case Rank::Three:
		rank_int = 3;
		break;
	case Rank::Four:
		rank_int = 4;
		break;
	case Rank::Five:
		rank_int = 5;
		break;
	case Rank::Six:
		rank_int = 6;
		break;
	case Rank::Seven:
		rank_int = 7;
		break;
	case Rank::Eighth:
		rank_int = 8;
		break;
	case Rank::Nine:
		rank_int = 9;
		break;
	case Rank::Ten:
	case Rank::Jack:
	case Rank::Queen:
	case Rank::King:
		rank_int = 10;
		break;
	default:
		std::cout << "Error: CardValue() default." << std::endl;
		rank_int = -1000;
	}

	return rank_int;
}

Rank Card::GetRank() const
{
	return rank;
}
