#pragma once 
#include "Globals.h"
#include "Player.h"
#include "World_Block.h"
#include "Hyena.h"
#include "Gift.h"
#include "Vulture.h"
#include "Hedgehog.h"
#include "Lizard.h"
#include "Decoration.h"
#include <typeinfo>
#include <map>
#include <string>
#include <typeindex>
#include "GameObject.h"
#include "HealthGift.h"
#include "LifeGift.h"
#include "SunGift.h"
#include "CheckPointGift.h"
#include "StaticBlock.h"
#include "SpecialBlock.h"

//-----------------------------------------------------------------
//			_______________Collisions_________________________
//		This Cass control all about the collision proccess 
//		accures all about the game object. for instance - here we
//		control at the situation what will happen if the main player
//		 meet an enemy? wich kind of enemy? etc... for another example -
//		what will happed if an enemy meets a background? etc...
//-----------------------------------------------------------------
namespace {
	void PlayerGift(GameObject& p, GameObject& g) 
	{
		Player& player = dynamic_cast<Player&>(p);
		Gift& gift = dynamic_cast<Gift&>(g);
		player.handleCollision(gift);
		gift.handleCollision(player);
	}

	void GiftPlayer(  GameObject& g, GameObject& p)
	{
		PlayerGift(p, g);
	} 

	void PlayerStaticBlock(GameObject& p, GameObject& b)
	{
		Player& player = dynamic_cast<Player&>(p);
		StaticBlock& block = dynamic_cast<StaticBlock&>(b);
		player.handleCollision(block);
	}
	void StaticBlockPlayer(GameObject& b, GameObject& p)
	{
			PlayerStaticBlock(p,b);	
	}

	void hedgehogPlayer(GameObject& he, GameObject& p)
	{
		Hedgehog& hesgehog = dynamic_cast<Hedgehog&>(he);
		Player& player = dynamic_cast<Player&>(p);
		hesgehog.handleCollision(player);
	}
	void Playerhedgehog(GameObject& p, GameObject& he)
	{
		Player& player = dynamic_cast<Player&>(p);
		Hedgehog& hesgehog = dynamic_cast<Hedgehog&>(he);
		player.handleCollision(hesgehog);
		hedgehogPlayer(he, p);
	}

	void HedgehogStaticBlock(GameObject& he, GameObject& wb )
	{
		Hedgehog& hesgehog = dynamic_cast<Hedgehog&>(he);
		StaticBlock& block = dynamic_cast<StaticBlock&>(wb);
		hesgehog.handleCollision(block);
	}

	void  StaticBlockHedgehog(GameObject& wb, GameObject& he)
	{
		HedgehogStaticBlock(he, wb);
	}
	void LizardStaticBlock(GameObject& liz, GameObject& wb)
	{
		Lizard& lizard = dynamic_cast<Lizard&>(liz);
		StaticBlock& block = dynamic_cast<StaticBlock&>(wb);
		lizard.handleCollision(block);
	}

	void StaticBlockLizard(GameObject& wb, GameObject& liz)
	{
		LizardStaticBlock(liz, wb);
	}

	void LizardPlayer(GameObject& liz, GameObject& p)
	{
		Player& player = dynamic_cast<Player&>(p);
		Lizard& lizard = dynamic_cast<Lizard&>(liz);
		lizard.handleCollision(player);
	}
	void PlayerLizard(GameObject& p, GameObject& liz)
	{
		Player& player = dynamic_cast<Player&>(p);
		Lizard& lizard = dynamic_cast<Lizard&>(liz);
		player.handleCollision(lizard);
	 	LizardPlayer(liz, p);
	}
	void HyenaPlayer(GameObject& h, GameObject& p)
	{
		Player& player = dynamic_cast<Player&>(p);
		Hyena& hyena = dynamic_cast<Hyena&>(h);
		hyena.handleCollision(player);
	}

	void PlayerHyena(GameObject& p, GameObject& h)
	{
		Player& player = dynamic_cast<Player&>(p);
		Hyena& hyena = dynamic_cast<Hyena&>(h);
		player.handleCollision(hyena);
		HyenaPlayer(h,p);
		
	}

	void HyenaStaticBlock(GameObject& h, GameObject& wb)
	{
		Hyena& hyena = dynamic_cast<Hyena&>(h);
		StaticBlock& block = dynamic_cast<StaticBlock&>(wb);
		hyena.handleCollision(block);
	}

	void StaticBlockHyena(GameObject& wb, GameObject& h)
	{
		HyenaStaticBlock(h,wb);
	}

	void PlayerDecoration(GameObject& p, GameObject& d)
	{
		Player& player = dynamic_cast<Player&>(p);
		Decoration& decoration = dynamic_cast<Decoration&>(d);
		player.handleCollision(decoration);
	}

	void DecorationPlayer(GameObject& d, GameObject& p)
	{
		PlayerDecoration(p, d);
	}
	void VultureStaticBlock(GameObject& v, GameObject& b)
	{
		Vulture& vulture = dynamic_cast<Vulture&>(v);
		StaticBlock& block = dynamic_cast<StaticBlock&>(b);
		vulture.handleCollision(block);
	}
	void StaticBlockVulture(GameObject& b, GameObject& v)
	{
		VultureStaticBlock(v, b);
	}

	void PlayerVulture(GameObject& p, GameObject& v)
	{
		Vulture& vulture = dynamic_cast<Vulture&>(v);
		Player& player = dynamic_cast<Player&>(p);
		vulture.handleCollision(player);
		player.handleCollision(vulture);
	}
	void VulturePlayer(GameObject& v, GameObject& p)
	{
		PlayerVulture(p, v);
	}
	using HitFunctionPtr = void (*)(GameObject&, GameObject&);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;
	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Key(typeid(Player), typeid(StaticBlock))] = &PlayerStaticBlock;
		phm[Key(typeid(Player), typeid(Hyena))] = &PlayerHyena;
		phm[Key(typeid(Player), typeid(Lizard))] = &PlayerLizard;
		phm[Key(typeid(Player), typeid(Gift))] = &PlayerGift; 
		phm[Key(typeid(Gift), typeid(Player))] = &GiftPlayer; 
		phm[Key(typeid(Hyena), typeid(StaticBlock))] = &HyenaStaticBlock;
		phm[Key(typeid(Hyena), typeid(Player))] = &HyenaPlayer;
		phm[Key(typeid(StaticBlock), typeid(Hyena))] = &StaticBlockHyena;
		phm[Key(typeid(StaticBlock), typeid(Player))] = &StaticBlockPlayer;
		phm[Key(typeid(StaticBlock), typeid(Hedgehog))] = &StaticBlockHedgehog;
		phm[Key(typeid(StaticBlock), typeid(Lizard))] = &StaticBlockLizard;
		phm[Key(typeid(Hedgehog), typeid(StaticBlock))] = &HedgehogStaticBlock;
		phm[Key(typeid(Player), typeid(Hedgehog))] = &Playerhedgehog;
		phm[Key(typeid(Hedgehog), typeid(Player))] = &hedgehogPlayer;
		phm[Key(typeid(Lizard), typeid(StaticBlock))] = &LizardStaticBlock;
		phm[Key(typeid(Lizard), typeid(Player))] = &LizardPlayer;
		phm[Key(typeid(Player), typeid(Decoration))] = &PlayerDecoration;
		phm[Key(typeid(Decoration), typeid(Player))] = &DecorationPlayer;
		phm[Key(typeid(Vulture), typeid(StaticBlock))] = &VultureStaticBlock;
		phm[Key(typeid(StaticBlock), typeid(Vulture))] = &StaticBlockVulture;
		phm[Key(typeid(Player), typeid(Vulture))] = &PlayerVulture;
		phm[Key(typeid(Vulture), typeid(Player))] = &VulturePlayer;
		phm[Key(typeid(Player), typeid(CheckPointGift))] = &PlayerGift;
		phm[Key(typeid(CheckPointGift), typeid(Player))] = &GiftPlayer;
		phm[Key(typeid(Player), typeid(SunGift))] = &PlayerGift;
		phm[Key(typeid(SunGift), typeid(Player))] = &GiftPlayer;
		phm[Key(typeid(Player), typeid(HealthGift))] = &PlayerGift;
		phm[Key(typeid(HealthGift), typeid(Player))] = &GiftPlayer;
		phm[Key(typeid(Player), typeid(LifeGift))] = &PlayerGift;
		phm[Key(typeid(LifeGift), typeid(Player))] = &GiftPlayer;
		return phm;
	}

	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}

	void processCollision(GameObject& object1, GameObject& object2)
	{
		auto phf = lookup(typeid(object1), typeid(object2));
		if (!phf)
		{
			return;
			//throw UnknownCollision(object1, object2);
		}
		phf(object1, object2);	//yona added &
	}
} // end namespace


	// STL-like algorithm to run over all pairs
template <typename FwdIt, typename Fn>
void for_each_pair(FwdIt begin, FwdIt end, Fn fn)
{
	for (; begin != end; ++begin)
		for (auto second = begin + 1; second != end; ++second)
			fn(*begin, *second);
}

