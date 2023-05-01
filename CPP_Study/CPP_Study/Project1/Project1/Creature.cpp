#include "Creature.h"

void Creature::SetDamage(Creature* Attacked)
{
	int Damage = m_Attack - Attacked->m_Defence;
	if (Damage < 0)
		Damage = 0;

	Attacked->m_Hp -= Damage;

	if (Attacked->m_Hp < 0)
		Attacked->m_Hp = 0;


}