#include "Card.h"

Card::Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{} 

int Card::GetValue() const
{
	int value;

	if(m_IsFaceUp) value = 0;
	else value = m_Rank;

	return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}
