#include "obse/GameExtraData.h"
#include "obse/GameAPI.h"

ExtraContainerChanges::EntryData * ExtraContainerChanges::GetByType(TESForm * type)
{
	ExtraContainerChanges::EntryData	* result = NULL;

	if(data)
	{
		for(Entry * entry = data->objList; entry; entry = entry->next)
		{
			if(entry->data && (entry->data->type == type))
			{
				result = entry->data;
				break;
			}
		}
	}

	return result;
}

#if OBLIVION_VERSION == OBLIVION_VERSION_1_1

static const UInt32 s_ExtraHealthSize = 0x10;
static const UInt32 s_ExtraHealthVtbl = 0x00A02294;
static const UInt32 s_ExtraChargeSize = 0x10;
static const UInt32 s_ExtraChargeVtbl = 0x00A022B8;
static const UInt32 s_ExtraUsesSize = 0x10;
static const UInt32 s_ExtraUsesVtbl = 0x00A022A0;
static const UInt32 s_ExtraPoisonSize = 0x10;
static const UInt32 s_ExtraPoisonVtbl = 0x00A02420;
static const UInt32 s_ExtraTravelHorseSize = 0x10;
static const UInt32 s_ExtraTravelHorseVtbl = 0x00A023FC;
static const UInt32 s_ExtraLockSize = 0x10;
static const UInt32 s_ExtraLockVtbl = 0x00A02210;
static const UInt32 s_ExtraSoulSize = 0x10;
static const UInt32 s_ExtraSoulVtbl = 0x00A022C4;
static const UInt32 s_ExtraCountSize = 0x10;
static const UInt32 s_ExtraCountVtbl = 0xA02288;
static const UInt32 s_ExtraQuickKeySize = 0x10;
static const UInt32 s_ExtraQuickKeyVtbl = 0x00A02330;
static const UInt32 s_ExtraDataListVtbl = 0x00A01A98;

#elif OBLIVION_VERSION == OBLIVION_VERSION_1_2

static const UInt32 s_ExtraHealthSize = 0x10;
static const UInt32 s_ExtraHealthVtbl = 0x00A358B0;
static const UInt32 s_ExtraChargeSize = 0x10;
static const UInt32 s_ExtraChargeVtbl = 0x00A358D4;
static const UInt32 s_ExtraUsesSize = 0x10;
static const UInt32 s_ExtraUsesVtbl = 0x00A358BC;
static const UInt32 s_ExtraPoisonSize = 0x10;
static const UInt32 s_ExtraPoisonVtbl = 0x00A35A48;
static const UInt32 s_ExtraTravelHorseSize = 0x10;
static const UInt32 s_ExtraTravelHorseVtbl = 0x00A35A24;
static const UInt32 s_ExtraLockSize = 0x10;
static const UInt32 s_ExtraLockVtbl = 0x00A35820;
static const UInt32 s_ExtraSoulSize = 0x10;
static const UInt32 s_ExtraSoulVtbl = 0x00A358E0;
static const UInt32 s_ExtraCountSize = 0x10;
static const UInt32 s_ExtraCountVtbl = 0x00A358A4;
static const UInt32 s_ExtraQuickKeySize = 0x10;
static const UInt32 s_ExtraQuickKeyVtbl = 0x00A3594C;
static const UInt32 s_ExtraDataListVtbl = 0x00A35160;

#elif OBLIVION_VERSION == OBLIVION_VERSION_1_2_416

static const UInt32 s_ExtraHealthSize = 0x10;
static const UInt32 s_ExtraHealthVtbl = 0x00A35848;
static const UInt32 s_ExtraChargeSize = 0x10;
static const UInt32 s_ExtraChargeVtbl = 0x00A3586C;
static const UInt32 s_ExtraUsesSize = 0x10;
static const UInt32 s_ExtraUsesVtbl = 0x00A35854;
static const UInt32 s_ExtraPoisonSize = 0x10;
static const UInt32 s_ExtraPoisonVtbl = 0x00A359E0;
static const UInt32 s_ExtraTravelHorseSize = 0x10;
static const UInt32 s_ExtraTravelHorseVtbl = 0x00A359BC;
static const UInt32 s_ExtraLockSize = 0x10;
static const UInt32 s_ExtraLockVtbl = 0x00A357B8;
static const UInt32 s_ExtraSoulSize = 0x10;
static const UInt32 s_ExtraSoulVtbl = 0x00A35878;
static const UInt32 s_ExtraCountSize = 0x10;
static const UInt32 s_ExtraCountVtbl = 0x00A3583C;
static const UInt32 s_ExtraQuickKeySize = 0x10;
static const UInt32 s_ExtraQuickKeyVtbl = 0x00A358E4;
static const UInt32 s_ExtraDataListVtbl = 0x00A350F8;

#else
#error unsupported oblivion version
#endif

// static
BSExtraData* BSExtraData::Create(UInt8 xType, UInt32 size, UInt32 vtbl)
{
	void* memory = FormHeap_Allocate(size);
	memset(memory, 0, size);
	((UInt32*)memory)[0] = vtbl;
	BSExtraData* xData = (BSExtraData*)memory;
	xData->type = xType;
	return xData;
}

// static
ExtraHealth* ExtraHealth::Create()
{
	ExtraHealth* xHealth = (ExtraHealth*)BSExtraData::Create(kExtraData_Health, s_ExtraHealthSize, s_ExtraHealthVtbl);
	return xHealth;
}

// static
ExtraCharge* ExtraCharge::Create()
{
	ExtraCharge* xCharge = (ExtraCharge*)BSExtraData::Create(kExtraData_Charge, s_ExtraChargeSize, s_ExtraChargeVtbl);
	return xCharge;
}

// static
ExtraUses* ExtraUses::Create()
{
	ExtraUses* xUses = (ExtraUses*)BSExtraData::Create(kExtraData_Uses, s_ExtraUsesSize, s_ExtraUsesVtbl);
	return xUses;
}

// static
ExtraPoison* ExtraPoison::Create()
{
	ExtraPoison* xPoison = (ExtraPoison*)BSExtraData::Create(kExtraData_Poison, s_ExtraPoisonSize, s_ExtraPoisonVtbl);
	return xPoison;
}

ExtraTravelHorse* ExtraTravelHorse::Create()
{
	ExtraTravelHorse* xHorse = (ExtraTravelHorse*)BSExtraData::Create(kExtraData_TravelHorse, s_ExtraTravelHorseSize,
																	  s_ExtraTravelHorseVtbl);
	return xHorse;
}

ExtraLock* ExtraLock::Create()
{
	ExtraLock* xLock = (ExtraLock*)BSExtraData::Create(kExtraData_Lock, s_ExtraLockSize, s_ExtraLockVtbl);
	ExtraLock::Data* lockData = (ExtraLock::Data*)FormHeap_Allocate(sizeof(ExtraLock::Data));
	memset(lockData, 0, sizeof(ExtraLock::Data));
	xLock->data = lockData;
	return xLock;
}

ExtraSoul* ExtraSoul::Create()
{
	ExtraSoul* xSoul = (ExtraSoul*)BSExtraData::Create(kExtraData_Soul, s_ExtraSoulSize, s_ExtraSoulVtbl);
	memset(xSoul->padding, 0, 3);
	return xSoul;
}

ExtraCount* ExtraCount::Create()
{
	ExtraCount* xCount = (ExtraCount*)BSExtraData::Create(kExtraData_Count, s_ExtraCountSize, s_ExtraCountVtbl);
	return xCount;
}

ExtraQuickKey* ExtraQuickKey::Create()
{
	ExtraQuickKey* xQuickKey = (ExtraQuickKey*)BSExtraData::Create(kExtraData_QuickKey, s_ExtraQuickKeySize, s_ExtraQuickKeyVtbl);
	memset(xQuickKey->pad, 0, 3);
	return xQuickKey;
}

ExtraDataList* ExtraDataList::Create()
{
	ExtraDataList* xData = (ExtraDataList*)FormHeap_Allocate(sizeof(ExtraDataList));
	memset(xData, 0, sizeof(ExtraDataList));
	((UInt32*)xData)[0] = s_ExtraDataListVtbl;
	return xData;
}
