#include "obse/GameObjects.h"
#include "obse/GameAPI.h"

typedef Sky * (* _Sky_GetSingleton)(void);

#if OBLIVION_VERSION == OBLIVION_VERSION_1_1

PlayerCharacter ** g_thePlayer = (PlayerCharacter **)0x00AEAAE4;

static const UInt32	s_Actor_EquipItem =					0x005E6380;
static const UInt32	s_Actor_GetBaseActorValue =			0x005E4D30;

static const UInt32	s_PlayerCharacter_SetActiveSpell =	0x00650C30;

static const _Sky_GetSingleton	Sky_GetSingleton = (_Sky_GetSingleton)0x00537420;
static const UInt32				s_Sky_RefreshClimate = 0x00537C00;

#elif OBLIVION_VERSION == OBLIVION_VERSION_1_2

PlayerCharacter ** g_thePlayer = (PlayerCharacter **)0x00B333C4;

static const UInt32	s_Actor_EquipItem =					0x005FACE0;
static const UInt32	s_Actor_GetBaseActorValue =			0x005F1750;

static const UInt32	s_PlayerCharacter_SetActiveSpell =	0x006641B0;

static const _Sky_GetSingleton	Sky_GetSingleton = (_Sky_GetSingleton)0x00542F10;
static const UInt32				s_Sky_RefreshClimate = 0x00543270;

#elif OBLIVION_VERSION == OBLIVION_VERSION_1_2_416

PlayerCharacter ** g_thePlayer = (PlayerCharacter **)0x00B333C4;

static const UInt32	s_Actor_EquipItem =					0x005FAEA0;
static const UInt32	s_Actor_GetBaseActorValue =			0x005F1910;

static const UInt32	s_PlayerCharacter_SetActiveSpell =	0x00664700;

static const _Sky_GetSingleton	Sky_GetSingleton = (_Sky_GetSingleton)0x00542EA0;
static const UInt32				s_Sky_RefreshClimate = 0x00543200;

#else

#error unsupported version of oblivion

#endif

void Actor::EquipItem(TESObjectREFR * objType, UInt32 unk1, UInt32 unk2, UInt32 unk3, bool lockEquip)
{
	ThisStdCall(s_Actor_EquipItem, this, objType, unk1, unk2, unk3, lockEquip);
}

UInt32 Actor::GetBaseActorValue(UInt32 value)
{
	return ThisStdCall(s_Actor_GetBaseActorValue, this, value);
}

EquippedItemsList Actor::GetEquippedItems()
{
	EquippedItemsList itemList;

	ExtraContainerChanges	* xChanges = static_cast <ExtraContainerChanges *>(baseExtraList.GetByType(kExtraData_ContainerChanges));
	if(xChanges && xChanges->data && xChanges->data->objList)
		for(ExtraContainerChanges::Entry * entry = xChanges->data->objList; entry; entry = entry->next)
			if(entry->data && entry->data->extendData && entry->data->type)
				for(ExtraContainerChanges::EntryExtendData * extend = entry->data->extendData; extend; extend = extend->next)
					if(extend->data && extend->data->HasType(kExtraData_Worn) || extend->data->HasType(kExtraData_WornLeft))
						itemList.push_back(entry->data->type);

	return itemList;
}

bool PlayerCharacter::SetActiveSpell(MagicItem * item)
{
	return ThisStdCall(s_PlayerCharacter_SetActiveSpell, this, item) != 0;
}

void PlayerCharacter::TogglePOV(bool bFirstPerson)
{
#if OBLIVION_VERSION == OBLIVION_VERSION_1_1
	ThisStdCall(0x00655560, this, bFirstPerson);
#elif OBLIVION_VERSION == OBLIVION_VERSION_1_2
	ThisStdCall(0x0066C040, this, bFirstPerson);
#elif OBLIVION_VERSION == OBLIVION_VERSION_1_2_416
	ThisStdCall(0x0066C580, this, bFirstPerson);
#else
#error unsupported Oblivion version 
#endif
}

Sky * Sky::GetSingleton(void)
{
	return Sky_GetSingleton();
}

void Sky::RefreshClimate(TESClimate * climate, UInt32 unk1)
{
	ThisStdCall(s_Sky_RefreshClimate, this, climate, unk1);
}

ScriptEventList* TESObjectREFR::GetEventList() const
{
	BSExtraData* xData = baseExtraList.GetByType(kExtraData_Script);
	if (xData)
	{
		ExtraScript* xScript = (ExtraScript*)Oblivion_DynamicCast(xData, 0, RTTI_BSExtraData, RTTI_ExtraScript, 0);
		if (xScript)
			return xScript->eventList;
	}

	return 0;
}

TESForm* TESObjectREFR::GetInventoryItem(UInt32 itemIndex, bool bGetWares)
{
	//if getWares == true, looks up info in g_DataHandler->unkCDC

	ExtraContainerChanges::EntryData* data;

#if OBLIVION_VERSION == OBLIVION_VERSION_1_1
	data = (ExtraContainerChanges::EntryData*)ThisStdCall(0x4CEB10, this, itemIndex, bGetWares);
#elif OBLIVION_VERSION == OBLIVION_VERSION_1_2
	data = (ExtraContainerChanges::EntryData*)ThisStdCall(0x4D88E0, this, itemIndex, bGetWares);
#elif OBLIVION_VERSION == OBLIVION_VERSION_1_2_416
	data = (ExtraContainerChanges::EntryData*)ThisStdCall(0x4D88F0, this, itemIndex, bGetWares);
#else
	#error unsupported Oblivion version
#endif

	if (data)
		return data->type;
	else
		return NULL;
}

typedef void (*_DisableRef)(TESObjectREFR *refr);
typedef void (*_EnableRef)(TESObjectREFR *refr);

#if OBLIVION_VERSION == OBLIVION_VERSION_1_1
const _DisableRef DisableRef = (_DisableRef)0x004F16A0;
const _EnableRef EnableRef = (_EnableRef)0x004F0650;
#elif OBLIVION_VERSION == OBLIVION_VERSION_1_2
const _DisableRef DisableRef = (_DisableRef)0x004FBC80;
const _EnableRef EnableRef = (_EnableRef)0x004FA5F0;
#elif OBLIVION_VERSION == OBLIVION_VERSION_1_2_416
const _DisableRef DisableRef = (_DisableRef)0x004FBB30;
const _EnableRef EnableRef = (_EnableRef)0x004FA540;
#else
#error unsupported version of oblivion
#endif

void TESObjectREFR::Disable()
{
	DisableRef(this);
}

void TESObjectREFR::Enable()
{
	EnableRef(this);
}