#include <iostream>
#include <vector>

#include "Hand.h"

Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()  
{
    Clear();
}

void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}
 
void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    m_Cards.clear();
}

int Hand::GetTotal() const
{
	int total = 0;
    int alter_ace_value = 11;
    for(auto itr = m_Cards.begin(); itr != m_Cards.end(); ++itr){
        if((*itr)->GetValue() == 1){
            if(total < 11){
                total += alter_ace_value;
            }else{
                total += (*itr)->GetValue();
            }
        }else{
            total += (*itr)->GetValue();
        }
    }
    
    

    return total;
}
