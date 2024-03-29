#pragma once

#include "GameBSExtraData.h"
#include "GameForms.h"

/****
 *	id	size	type					Decoded
 *	00	?		
 *	01	?		
 *	02	?		ExtraHavok
 *	03	?		ExtraCell3D
 *	04	?		ExtraWaterHeight			*
 *	05	?		ExtraCellWaterType
 *	06	?		
 *	07	?		
 *	08	?		ExtraRegionList				*
 *	09	10		ExtraSeenData				*
 *	0A	?		ExtraEditorID
 *	0B	?		ExtraCellMusicType			*
 *	0C	?		ExtraCellClimate			*
 *	0D	?		ExtraProcessMiddleLow
 *	0E	?		
 *	0F	?		ExtraCellCanopyShadowMask
 *	10	10		ExtraDetachTime
 *	11	?		ExtraPersistentCell			*
 *	12	14		ExtraScript					*
 *	13	14		ExtraAction					
 *	14	24		ExtraStartingPosition
 *	15	?		ExtraAnim
 *	16	?		
 *	17	?		ExtraUsedMarkers
 *	18	?		ExtraDistantData
 *	19	?		ExtraRagDollData
 *	1A	10		ExtraContainerChanges		*
 *	1B	C		ExtraWorn					*
 *	1C	?		ExtraWornLeft				*
 *	1D	?		
 *	1E	20		ExtraPackageStartLocation	*
 *	1F	1C		ExtraPackage				*
 *	20	10		ExtraTresPassPackage		*
 *	21	10		ExtraRunOncePacks
 *	22	?		ExtraReferencePointer
 *	23	10		ExtraFollower				*
 *	24	10		ExtraLevCreaModifier
 *	25	C		ExtraGhost
 *	26	?		ExtraOriginalReference
 *	27	?		ExtraOwnership				*
 *	28	?		ExtraGlobal					*
 *	29	?		ExtraRank					*
 *	2A	?		ExtraCount					*
 *	2B	10		ExtraHealth					*
 *	2C	10		ExtraUses					*
 *	2D	10		ExtraTimeLeft			
 *	2E	10		ExtraCharge					*
 *	2F	10		ExtraSoul					*
 *	30	10		ExtraLight					*
 *	31	10		ExtraLock					*
 *	32	?		ExtraTeleport				*
 *	33	?		ExtraMapMarker
 *	34	?										animation-related?
 *	35	C		ExtraLeveledCreature
 *	36	14		ExtraLeveledItem
 *	37	?		ExtraScale					*
 *	38	?		ExtraSeed
 *	39	?		
 *	3A	?		NonActorMagicTarget
 *	3B	?		
 *	3C	?		
 *	3D	?		ExtraCrimeGold				*
 *	3E	?		ExtraOblivionEntry
 *	3F	?		ExtraEnableStateParent		*
 *	40	?		ExtraEnableStateChildren	*
 *	41	?		ExtraItemDropper
 *	42	14		ExtraDroppedItemList
 *	43	?		ExtraRandomTeleportMarker	*
 *	44	10		ExtraMerchantContainer		*
 *	45	?		
 *	46	1C		ExtraPersuasionPercent
 *	47	C		ExtraCannotWear
 *	48	10		ExtraPoison					*
 *	49	?		
 *	4A	?		ExtraLastFinishedSequence
 *	4B	?		ExtraSavedMovementData
 *	4C	10		ExtraNorthRotation			*
 *	4D	10		ExtraXTarget
 *	4E	10		ExtraFriendHitList
 *	4F	10		ExtraHeadingTarget
 *	50	C		ExtraBoundArmor
 *	51	?		ExtraRefractionProperty
 *	52	?		ExtraInvestmentGold
 *	53	?		ExtraStartingWorldOrCell
 *	54	?		
 *	55	10		ExtraQuickKey				*
 *	56	?		
 *	57	?		ExtraEditorRefMoveData
 *	58	10		ExtraTravelHorse			*
 *	59	10		ExtraInfoGeneralTopic
 *	5A	10		ExtraHasNoRumors
 *	5B	?		ExtraSound
 *	5C	10		ExtraHaggleAmount
 *	more?
 *	
 *	bits - seems to be linear bitfield
 *	+08	0000000x	00	?
 *	+09	0000000x	08	region list?
 *	+0A	0000000x	10	detach time?
 *	+0B	0000000x	18	distant data?
 *	+0C	0000000x	20	tresspass package?
 *	+0D	0000000x	28	global?
 *	+0E	0000000x	30	light?
 *	+0E	00x00000	35	leveled creature
 *	+0F	0000000x	38	seed?
 *	+10	0000000x	40	enable state children?
 *	+10	x0000000	47	cannot wear
 *	+12	0000000x	50	bound armor
 *	+13	0000000x	58	travel horse
 *	+13	x0000000	5F	?
 **/

// ### incomplete

#include "Utilities.h"

class AlchemyItem;
class TESForm;
class TESObjectREFR;
class TESObjectCELL;
class TESPackage;
class Character;
class NiAVObject;
class TESKey;
class TESFaction;
class TESNPC;
class TESGlobal;
class TESClimate;
class TrespassPackage;
class TESRegionList;
class Script;
struct ScriptEventList;

enum ExtraDataType
{
	kExtraData_Havok =					0x02,
	kExtraData_Cell3D =					0x03,
	kExtraData_WaterHeight =			0x04,
	kExtraData_CellWaterType =			0x05,
	kExtraData_RegionList =				0x08,
	kExtraData_SeenData =				0x09,
	kExtraData_EditorID =				0x0A,
	kExtraData_CellMusicType =			0x0B,
	kExtraData_CellClimate =			0x0C,
	kExtraData_ProcessMiddleLow =		0x0D,
	kExtraData_CellCanopyShadowMask =	0x0F,
	kExtraData_DetachTime =				0x10,
	kExtraData_PersistentCell =			0x11,
	kExtraData_Script =					0x12,
	kExtraData_Action =					0x13,
	kExtraData_StartingPosition =		0x14,
	kExtraData_Anim =					0x15,

	kExtraData_UsedMarkers =			0x17,
	kExtraData_DistantData =			0x18,
	kExtraData_RagDollData =			0x19,
	kExtraData_ContainerChanges =		0x1A,
	kExtraData_Worn =					0x1B,
	kExtraData_WornLeft =				0x1C,

	kExtraData_StartLocation =			0x1E,
	kExtraData_Package =				0x1F,
	kExtraData_TresPassPackage =		0x20,
	kExtraData_RunOncePacks =			0x21,
	kExtraData_ReferencePointer =		0x22,
	kExtraData_Follower =				0x23,
	kExtraData_LevCreaModifier =		0x24,
	kExtraData_Ghost =					0x25,
	kExtraData_OriginalReference =		0x26,
	kExtraData_Ownership =				0x27,
	kExtraData_Global =					0x28,
	kExtraData_Rank =					0x29,
	kExtraData_Count =					0x2A,
	kExtraData_Health =					0x2B,
	kExtraData_Uses =					0x2C,
	kExtraData_TimeLeft =				0x2D,
	kExtraData_Charge =					0x2E,
	kExtraData_Soul =					0x2F,
	kExtraData_Light =					0x30,
	kExtraData_Lock =					0x31,
	kExtraData_Teleport =				0x32,
	kExtraData_MapMarker =				0x33,

	kExtraData_LeveledCreature =		0x35,
	kExtraData_LeveledItem =			0x36,
	kExtraData_Scale =					0x37,
	kExtraData_Seed =					0x38,
	kExtraData_NonActorMagicCaster =	0x39,

	kExtraData_CrimeGold =				0x3D,
	kExtraData_OblivionEntry =			0x3E,
	kExtraData_EnableStateParent =		0x3F,
	kExtraData_EnableStateChildren =	0x40,
	kExtraData_ItemDropper =			0x41,
	kExtraData_DroppedItemList =		0x42,
	kExtraData_RandomTeleportMarker =	0x43,
	kExtraData_MerchantContainer =		0x44,

	kExtraData_PersuasionPercent =		0x46,
	kExtraData_CannotWear =				0x47,
	kExtraData_Poison =					0x48,

	kExtraData_LastFinishedSequence =	0x4A,
	kExtraData_SavedMovementData =		0x4B,
	kExtraData_NorthRotation =			0x4C,
	kExtraData_XTarget =				0x4D,
	kExtraData_FriendHitList =			0x4E,
	kExtraData_HeadingTarget =			0x4F,
	kExtraData_BoundArmor =				0x50,
	kExtraData_RefractionProperty =		0x51,
	kExtraData_InvestmentGold =			0x52,
	kExtraData_StartingWorldOrCell =	0x53,

	kExtraData_QuickKey =				0x55,

	kExtraData_EditorRefMoveData =		0x57,
	kExtraData_TravelHorse =			0x58,
	kExtraData_InfoGeneralTopic =		0x59,
	kExtraData_HasNoRumors =			0x5A,
	kExtraData_ExtraSound =				0x5B,
	kExtraData_HaggleAmount =			0x5C,
};


class ExtraContainerChanges : public BSExtraData
{
public:
	ExtraContainerChanges();
	virtual ~ExtraContainerChanges();

	struct EntryExtendData
	{
		ExtraDataList	* data;
		EntryExtendData	* next;

		ExtraDataList* Info() const { return data; }
		EntryExtendData* Next() const { return next; }
	};

	struct EntryData
	{
		EntryExtendData	* extendData;
		SInt32			countDelta;
		TESForm			* type;
	};

	struct Entry
	{
		EntryData	* data;
		Entry		* next;

		EntryData* Info() const { return data; }
		Entry* Next() const { return next; }
	};

	struct Data
	{
		Entry			* objList;
		TESObjectREFR	* owner;
		float			unk2;
		float			unk3;
	};

	Data	* data;

	EntryData *	GetByType(TESForm * type);
};

typedef Visitor<ExtraContainerChanges::Entry, ExtraContainerChanges::EntryData> ExtraEntryVisitor;
typedef Visitor<ExtraContainerChanges::EntryExtendData, ExtraDataList> ExtendDataVisitor;

// cell and position where the current package was started?
class ExtraPackageStartLocation : public BSExtraData
{
public:
	ExtraPackageStartLocation();
	virtual ~ExtraPackageStartLocation();

	TESForm			* cell;		// 0C can be worldspace or cell
	float			x, y, z;	// 10
	UInt32			pad1C;		// 1C
};

// current package
class ExtraPackage : public BSExtraData
{
public:
	ExtraPackage();
	virtual ~ExtraPackage();

	TESPackage	* package;	// 0C
	UInt32		unk10;		// 10
	UInt32		unk14;		// 14
	UInt32		unk18;		// 18
};

// list of all characters following the owner via a package
class ExtraFollower : public BSExtraData
{
public:
	ExtraFollower();
	virtual ~ExtraFollower();

	struct ListNode
	{
		Character	* character;
		ListNode	* next;

		Character* Info() const { return character; }
        ListNode* Next() const { return next; }
	};

	ListNode	* followers;
};

typedef Visitor<ExtraFollower::ListNode, Character> ExtraFollowerVisitor;

class ExtraHealth : public BSExtraData
{
public:
	ExtraHealth();
	virtual ~ExtraHealth();
	float health;

	static ExtraHealth* Create();
};

class ExtraUses : public BSExtraData
{
public:
	ExtraUses();
	~ExtraUses();
	UInt32 unk0;
	static ExtraUses* Create();
};

class ExtraCharge : public BSExtraData
{
public:
	ExtraCharge();
	~ExtraCharge();
	float charge;
	static ExtraCharge* Create();
};

class ExtraSoul: public BSExtraData
{
public:
	ExtraSoul();
	~ExtraSoul();
	UInt8 soul;
	UInt8 padding[3];
	static ExtraSoul* Create();
};

// used by torches, etc (implies one light per object?)
class ExtraLight : public BSExtraData
{
public:
	ExtraLight();
	virtual ~ExtraLight();

	struct Data
	{
		NiAVObject	* light;	// probably NiLight
		float		unk4;		// intensity? only seen 1.0f
	};

	Data	* data;	// C
};

class ExtraPoison : public BSExtraData
{
public:
	ExtraPoison();
	~ExtraPoison();

	AlchemyItem* poison;
	static ExtraPoison* Create();
};

class ExtraMerchantContainer : public BSExtraData
{
public:
	ExtraMerchantContainer();
	~ExtraMerchantContainer();
	TESObjectREFR* containerRef;
};

class ExtraWaterHeight : public BSExtraData
{
public:
	ExtraWaterHeight();
	~ExtraWaterHeight();
	float waterHeight;
};

class ExtraTravelHorse : public BSExtraData
{
public:
	ExtraTravelHorse();
	~ExtraTravelHorse();

	TESObjectREFR*	horseRef;	// Horse
	static ExtraTravelHorse* Create();
};

class ExtraLock : public BSExtraData
{
public:
	ExtraLock();
	~ExtraLock();

	enum
	{
		kLock_isLocked =	1 << 0,
		//..?
		kLock_Leveled =		1 << 2,
	};

	struct Data
	{
		UInt32	lockLevel;
		TESKey	* key;
		UInt8	flags;
		UInt8	pad[3];
	};

	Data	* data;
	static ExtraLock* Create();
};

class ExtraOwnership : public BSExtraData
{
public:
	ExtraOwnership();
	~ExtraOwnership();

	TESForm*	owner;	//maybe this should be a union {TESFaction*; TESNPC*} but it would be more unwieldy to access and modify
};

class ExtraRank	: public BSExtraData
{								//ownership data, stored separately from ExtraOwnership
public:
	ExtraRank();
	~ExtraRank();

	UInt32	rank;
};

class ExtraGlobal : public BSExtraData
{								//ownership data, stored separately from ExtraOwnership
public:
	ExtraGlobal();
	~ExtraGlobal();

	TESGlobal*	globalVar;
};

class ExtraTeleport : public BSExtraData
{
public:
	ExtraTeleport();
	~ExtraTeleport();

	struct Data
	{
		TESObjectREFR*	linkedDoor;
		float			x; //x, y, z, zRot refer to teleport marker's position and rotation
		float			y; 
		float			z;
		float			zRot;
		UInt32			unk1;	//looks like flags (have only seen 0x80000000)
		UInt32			unk2;
	};

	Data *	data;
};

class ExtraRandomTeleportMarker : public BSExtraData
{
public:
	ExtraRandomTeleportMarker();
	~ExtraRandomTeleportMarker();

	TESObjectREFR *	teleportRef;
};

class ExtraCellClimate : public BSExtraData
{
public:
	ExtraCellClimate();
	~ExtraCellClimate();

	TESClimate* climate;
};

class ExtraQuickKey : public BSExtraData		//turns up in ExtraContainerChanges::EntryExtendData
{												//need to find for spells
public:
	ExtraQuickKey();
	~ExtraQuickKey();

	UInt8 keyID;		//0 thru 7
	UInt8 pad[3];

	static ExtraQuickKey * Create();
};

class ExtraScale : public BSExtraData
{
public:
	ExtraScale();
	~ExtraScale();

	float scale;
};

class ExtraNorthRotation : public BSExtraData
{
public:
	ExtraNorthRotation();
	~ExtraNorthRotation();

	float rotation;		//in radians, not degrees
};

class ExtraTrespassPackage : public BSExtraData
{
public:
	ExtraTrespassPackage();
	~ExtraTrespassPackage();

	TrespassPackage* package;
};

class ExtraRegionList : public BSExtraData
{
public:
	ExtraRegionList();
	~ExtraRegionList();

	TESRegionList* regionList;
};

class ExtraSeenData : public BSExtraData
{
public:
	ExtraSeenData();
	~ExtraSeenData();

	void* unk1;			//pointer to SeenData or IntSeenData, neither exposed yet
};

class ExtraPersistentCell : public BSExtraData
{
public:
	ExtraPersistentCell();
	~ExtraPersistentCell();

	TESObjectCELL* cell;
};

class ExtraCellMusicType : public BSExtraData
{
public:
	ExtraCellMusicType();
	~ExtraCellMusicType();

	enum
	{
		kMusicType_Public = 1,
		kMusicType_Dungeon = 2
	};

	UInt8 musicType;
	UInt8 pad[3];
};

class ExtraCrimeGold : public BSExtraData
{
public:
	ExtraCrimeGold();
	~ExtraCrimeGold();

	float crimeGold;
};

class ExtraEnableStateParent : public BSExtraData
{
public:
	ExtraEnableStateParent();
	~ExtraEnableStateParent();

	TESObjectREFR	* parent;
	UInt32			oppositeState;		//is 1 if enable state set to opposite of parent's
};

class ExtraEnableStateChildren : public BSExtraData
{
public:
	ExtraEnableStateChildren();
	~ExtraEnableStateChildren();

	struct Entry
	{
		TESObjectREFR	* child;
		Entry			* next;

		TESObjectREFR* Info() const { return child; }
        Entry* Next() const { return next; }
	};

	Entry childList;
};

typedef Visitor<ExtraEnableStateChildren::Entry, TESObjectREFR> EnableStateChildrenVisitor;

class ExtraScript : public BSExtraData
{
public:
	ExtraScript();
	~ExtraScript();

	Script			* script;
	ScriptEventList	* eventList;
};

class ExtraCount : public BSExtraData
{
public:
	ExtraCount();
	~ExtraCount();

	UInt16	count;
	UInt8	pad[2];

	static ExtraCount* Create();
};

class ExtraMapMarker : public BSExtraData
{
public:
	ExtraMapMarker();
	~ExtraMapMarker();

	enum {
		kFlag_Visible	= 1 << 0,
		kFlag_CanTravel	= 1 << 1
	};

	enum {
		kType_Unk0 = 0,
		kType_Camp,
		kType_Unk2,
		kType_City,
		//...

		kType_Max
	};

	struct Data {
		TESFullName	fullName;
		UInt16		flags;
		UInt16		type;	// possibly only 8 bits, haven't checked yet
	};

	Data	* data;

	TESFullName* GetFullName();
	const char* GetName();
	bool IsVisible()	{	return (data->flags & kFlag_Visible) == kFlag_Visible;	}
	bool CanTravelTo()	{	return (data->flags & kFlag_CanTravel) == kFlag_CanTravel;	}
	void SetVisible(bool bVisible)	{
		data->flags = (bVisible) ? (data->flags | kFlag_Visible) : (data->flags & ~kFlag_Visible);	}
	void SetCanTravelTo(bool bCanTravel) {
		data->flags = (bCanTravel) ? (data->flags | kFlag_CanTravel) : (data->flags & ~kFlag_CanTravel);	}
};

class ExtraSound : public BSExtraData
{
public:
	ExtraSound();
	~ExtraSound();

	UInt32	* unk01;
};

class ExtraAction : public BSExtraData
{
public:
	ExtraAction();
	~ExtraAction();

	TESObjectREFR	* actionRef;
	UInt32			unk10;
};