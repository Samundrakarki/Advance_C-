#include "Card.h"

Card::Card(rank r, suit s, bool ifu):  m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{} 

int Card::GetValue() const
{
	int value;

	if(!m_IsFaceUp()){
        value = 0;
    }else if (m_Rank <=10 ){
        value = m_Rank;
    }else if(m_rank > 10){
        value = 10;
    }

	return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}
