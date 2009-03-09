#pragma once

#include "GameRTTI.h"
#include "Utilities.h"

class TESForm;
class TESObjectREFR;
class Script;
struct ParamInfo;
class DataHandler;
class MemoryHeap;
class Tile;
class SceneGraph;
class NiNode;
class Tile;
class Menu;
class FormatStringArgs;

// only records individual objects if there's a block that matches it
// ### how can it tell?
struct ScriptEventList
{
	struct Event
	{
		TESForm	* object;
		UInt32	eventMask;
	};

	struct EventEntry
	{
		Event		* event;
		EventEntry	* next;
	};

	struct VarEntry;

	struct Var
	{
		UInt32		id;
		VarEntry	* nextEntry;
		double		data;
	};

	struct VarEntry
	{
		Var			* var;
		VarEntry	* next;
	};

	Script		* m_script;
	UInt32		m_unk1;
	EventEntry	* m_eventList;
	VarEntry	* m_vars;

	void	Dump(void);
	Var *	GetVariable(UInt32 id);
	UInt32	ResetAllVariables();
};

typedef void (* _Console_Print)(const char * buf, ...);
extern const _Console_Print Console_Print;

typedef bool (* _ExtractArgs)(ParamInfo * paramInfo, void * arg1, UInt32 * arg2, TESObjectREFR * arg3, UInt32 arg4, Script * script, ScriptEventList * eventList, ...);
extern const _ExtractArgs ExtractArgs;

// convenience macro for common arguments to ExtractArgs
#define PASS_EXTRACT_ARGS	paramInfo, arg1, opcodeOffsetPtr, thisObj, arg3, scriptObj, eventList

bool ExtractArgsEx(ParamInfo * paramInfo, void * scriptData, UInt32 * scriptDataOffset, Script * scriptObj, ScriptEventList * eventList, ...);
bool ExtractFormatStringArgs(UInt32 fmtStringPos, char* buffer, ParamInfo * paramInfo, void * scriptDataIn, UInt32 * scriptDataOffset, Script * scriptObj, ScriptEventList * eventList, UInt32 maxParams, ...);
bool ExtractSetStatementVar(Script* script, ScriptEventList* eventList, void* scriptDataIn, double* outVarData, UInt8* outModIndex = NULL);
bool ExtractFormattedString(FormatStringArgs& args, char* buffer);

// Problem: plugins may want to use %z specifier in format strings, but don't have access to StringVarMap
// Could change params to ExtractFormatStringArgs to include an OBSEStringVarInterface* but
//  this would break existing plugins
// Instead allow plugins to register their OBSEStringVarInterface for use
// I'm sure there is a better way to do this but I haven't found it
struct OBSEStringVarInterface;
void RegisterStringVarInterface(OBSEStringVarInterface* intfc);

typedef TESForm * (* _CreateFormInstance)(UInt8 type);
extern const _CreateFormInstance CreateFormInstance;

typedef TESForm * (* _LookupFormByID)(UInt32 id);
extern const _LookupFormByID LookupFormByID;

typedef void * (* _FormHeap_Allocate)(UInt32 size);
extern const _FormHeap_Allocate FormHeap_Allocate;

typedef void (* _FormHeap_Free)(void * ptr);
extern const _FormHeap_Free FormHeap_Free;

typedef void * (* _GetGlobalScriptStateObj)(void);
extern const _GetGlobalScriptStateObj GetGlobalScriptStateObj;

typedef void (* _ShowMessageBox_Callback)(void);
extern const _ShowMessageBox_Callback ShowMessageBox_Callback;

// message is messageBox string, unk2 is 0, var args are char* for buttons
// pass at least one button string or the messagebox can't be closed
typedef bool (* _ShowMessageBox)(const char * message, _ShowMessageBox_Callback callback, UInt32 unk2, ...);
extern const _ShowMessageBox ShowMessageBox;

// set to scriptObj->refID after calling ShowMessageBox()
// GetButtonPressed checks this before returning a value, if it doesn't match it returns -1
typedef UInt32* _ShowMessageBox_pScriptRefID;
extern const _ShowMessageBox_pScriptRefID ShowMessageBox_pScriptRefID;
typedef UInt8* _ShowMessageBox_button;
extern const _ShowMessageBox_button ShowMessageBox_button;

// unk1 = 0, unk2 = 1
typedef bool (* _QueueUIMessage)(const char * string, UInt32 unk1, UInt32 unk2, float duration);
extern const _QueueUIMessage QueueUIMessage;
const UInt32 kMaxMessageLength = 0x4000;

//displays icon and plays sound (used by Additem, Addspell, etc...)
//ddsPath relative to Textures\Menus\...  soundID as defined in the CS
typedef bool (* _QueueUIMessage_2)(const char * string, float duration, const char * ddsPath, const char * soundID);
extern const _QueueUIMessage_2 QueueUIMessage_2;

typedef bool (* _IsGodMode)(void);
extern const _IsGodMode IsGodMode;

typedef char (__stdcall * _ScancodeToChar)(UInt32 scanCode, UInt32 bUppercase);
extern const _ScancodeToChar ScancodeToChar;

extern MemoryHeap	* g_formHeap;

UInt32 __cdecl ThisCall(UInt32 function, void * _this, ...);
UInt32 __cdecl ThisStdCall(UInt32 function, void * _this, ...);

UInt32 AddFormToDataHandler(DataHandler * dataHandler, TESForm * form);
extern DataHandler ** g_dataHandler;

// 1C8 (different between 1.1, 1.2)
class TESSaveLoadGame
{
public:
	TESSaveLoadGame();
	~TESSaveLoadGame();

#if OBLIVION_VERSION >= OBLIVION_VERSION_1_2
	UInt32	unk000[0x28 >> 2];	// 000 (1.2)
#else
	UInt32	unk000[0x2C >> 2];	// 000 (1.1)
#endif

	struct CreatedObject
	{
		UInt32			formID;
		CreatedObject	* next;

		UInt32			Info() const	{ return formID; }
		CreatedObject *	Next() const	{ return next; }
	};

	typedef Visitor <CreatedObject, UInt32>	CreatedObjectVisitor;

	CreatedObject	createdObjectList;				// 028 (1.2) 02C (1.1)
	UInt32			unk030[(0x048 - 0x030) >> 2];	// 030 (1.2) 034 (1.1)

	UInt8	numMods;			// 048 (1.2) 04C (1.1)
	UInt8	pad049[3];			// 049 (1.2) 04D (1.1)
	UInt8	* modRefIDTable;	// 04C (1.2) 050 (1.1)
								// table mapping stored mod indices to loaded mod indices

	void	LoadCreatedObjectsHook(UInt32 unk0);
	bool	LoadGame(const char* filename);
};

#ifdef OBLIVION_VERSION
STATIC_ASSERT(offsetof(TESSaveLoadGame, numMods) == ((OBLIVION_VERSION >= OBLIVION_VERSION_1_2) ? 0x48 : 0x4C));
#endif

void AddFormToCreatedBaseObjectsList(TESSaveLoadGame * objList, TESForm * form);
extern TESSaveLoadGame ** g_createdBaseObjList;	// a TESSaveLoadGame
// TESSaveLoadGame + 0x14 is a void * to the current save/load buffer
// TESSaveLoadGame + 0x80 stores a UInt8 containing the version of the save?

UInt32 NiTPointerMap_Lookup(void * map, void * key, void ** data);
extern void * g_gameSettingsTable;

extern const bool * g_bConsoleMode;
bool IsConsoleMode();

extern const bool * g_bIsConsoleOpen;
bool IsConsoleOpen();

const char * GetObjectClassName(void * obj);

const char * GetFullName(TESForm * baseForm);

enum {
	kActorVal_Strength = 0,		// 0x00
	kActorVal_Intelligence,
	kActorVal_Willpower,
	kActorVal_Agility,
	kActorVal_Speed,
	kActorVal_Endurance,		//0x05
	kActorVal_Personality,
	kActorVal_Luck,
	kActorVal_Health,
	kActorVal_Magicka,
	kActorVal_Fatigue,			// 0x0a
	kActorVal_Encumbrance,
	kActorVal_Armorer,
	kActorVal_Athletics,
	kActorVal_Blade,
	kActorVal_Block,			// 0x0f
	kActorVal_Blunt,			// 0x10
	kActorVal_HandToHand,
	kActorVal_HeavyArmor,
	kActorVal_Alchemy,			
	kActorVal_Alteration,
	kActorVal_Conjuration,		// 0x15
	kActorVal_Destruction,
	kActorVal_Illusion,
	kActorVal_Mysticism,
	kActorVal_Restoration,
	kActorVal_Acrobatics,		// 0x1a
	kActorVal_LightArmor,
	kActorVal_Marksman,
	kActorVal_Mercantile,
	kActorVal_Security,
	kActorVal_Sneak,			// 0x1f
	kActorVal_Speechcraft,		// 0x20
	kActorVal_Aggression,
	kActorVal_Confidence,
	kActorVal_Energy,
	kActorVal_Responsibility,
	kActorVal_Bounty,			// 0x25
	kActorVal_Fame,
	kActorVal_Infamy,
	kActorVal_MagickaMultiplier,
	kActorVal_NightEyeBonus,
	kActorVal_AttackBonus,		// 0x2a
	kActorVal_DefendBonus,
	kActorVal_CastingPenalty,
	kActorVal_Blindness,
	kActorVal_Chameleon,
	kActorVal_Invisibility,		// 0x2f
	kActorVal_Paralysis,		// 0x30
	kActorVal_Silence,
	kActorVal_Confusion,
	kActorVal_DetectItemRange,
	kActorVal_SpellAbsorbChance,
	kActorVal_SpellReflectChance,// 0x35
	kActorVal_SwimSpeedMultiplier,
	kActorVal_WaterBreathing,
	kActorVal_WaterWalking,
	kActorVal_StuntedMagicka,
	kActorVal_DetectLifeRange,	// 0x3a
	kActorVal_ReflectDamage,
	kActorVal_Telekinesis,
	kActorVal_ResistFire,
	kActorVal_ResistFrost,
	kActorVal_ResistDisease,	// 0x3f
	kActorVal_ResistMagic,		// 0x40
	kActorVal_ResistNormalWeapons,
	kActorVal_ResistParalysis,
	kActorVal_ResistPoison,
	kActorVal_ResistShock,
	kActorVal_Vampirism,		// 0x45
	kActorVal_Darkness,
	kActorVal_ResistWaterDamage,
	///
	kActorVal_OblivionMax,
};

extern char*** g_baseActorValueNames;		//those with an associated game setting string
extern char** g_extraActorValueNames;		//MagickaMultiplier .. ResistWaterDamage (unchangeable)
const char* GetActorValueString(UInt32 actorValue);
bool IsValidActorValue(UInt32 actorValue);

UInt32 SafeModUInt32(UInt32 originalVal, float modBy);
float SafeChangeFloat(float originalVal, float changeVal, bool bMod, bool bNegativeAllowed);

extern CRITICAL_SECTION * g_extraListMutex;
extern CRITICAL_SECTION * g_pathingMutex;

struct SettingInfo
{
	union
	{
		int		i;
		UInt32	u;
		float	f;
		char	* s;
	};
	
	char	* name;
	
	enum EType {
		kSetting_Bool = 0,
		kSetting_c,
		kSetting_h,
		kSetting_Integer,
		kSetting_Unsigned,
		kSetting_Float,
		kSetting_String,
		kSetting_r,
		kSetting_a,
		kSetting_Other
	};

	EType Type() const;
};

bool GetGameSetting(char *settingName, SettingInfo** setting);

// 134
class InterfaceManager
{
public:
	InterfaceManager();
	~InterfaceManager();

	static InterfaceManager *	GetSingleton(void);

	enum {				// special values for IsActiveMenuMode()
		kMenuMode_GameMode = 0,
		kMenuMode_BigFour,
		kMenuMode_Any,
		kMenuMode_Console,
	};

	SceneGraph*		unk000;							// 000
	SceneGraph*		unk004;							// 004
	UInt32			unk008[(0x018 - 0x008) >> 2];	// 008
	void*			unk018;							// 018 NiDirectionalLight *
	Tile			* cursor;						// 01C
	UInt32			unk020[(0x054 - 0x020) >> 2];	// 020
	NiNode*			unk054[(0x064 - 0x054) >> 2];	// 054 
	NiNode*			unk064;							// 064 ShadowSceneNode *
	Tile			* menuRoot;						// 068
	Tile			* strings;						// 06C
	NiNode*			unk070;							// 070
	UInt32			unk074;							// 074
	void*			unk078;							// 078 NiAlphaProperty*
	UInt32			unk07C;							// 07C
	Tile			* hudReticule;					// 080
	UInt32			unk084;							// 084
	Tile			* unk088;						// 088
	UInt32			unk08C;							// 08C
	UInt32			unk090;							// 090
	UInt32			unk094;							// 094
	Tile			* activeTile;					// 098 - moused-over tile
	Menu			* activeMenu;					// 09C - menu over which the mouse cursor is placed
	UInt32			unk0A0;							// 0A0
	UInt32			unk0A4;							// 0A4
	UInt32			unk0A8;							// 0A8
	UInt32			unk0AC;							// 0AC
	UInt8			msgBoxButtonPressed;			// 0B0
	UInt8			unk0B1[3];						// 0B1
	void			* unk0B4;						// 0B4 - stores callback for ShowMessageBox() (anything else?)
	UInt32			unk0B8;							// 0B8	
	TESObjectREFR	* debugSelection;				// 0BC
	UInt32			unk0C0[(0x134 - 0x0C0) >> 2];	// 0C0

	bool CreateTextEditMenu(const char* promptText, const char* defaultText);
	float GetDepth();
	bool MenuModeHasFocus(UInt32 menuType);		// returns true if menuType is on top (has focus)
	bool IsGameMode();

};

STATIC_ASSERT(offsetof(InterfaceManager, activeMenu) == 0x09C);
STATIC_ASSERT(sizeof(InterfaceManager) == 0x134);

bool SCRIPT_ASSERT(bool expr, Script* script, const char * errorMsg, ...);

//A4
class ScriptRunner
{
public:
	static ScriptRunner *	GetSingleton;

	UInt32					unk00;						//00
	UInt32					unk04;						//04
	ScriptEventList			* eventList;				//08
	UInt32					unk0C;						//0C
	UInt32					unk10;						//10
	Script					* script;					//14
	UInt32					unk18[ (0xA0 - 0x18) >> 2];	//18..9F
	UInt8					unkA0;						//A0
	UInt8					unkA1;						//A1
	UInt8					unkA2;						//A2
	UInt8					unkA3;						//A3

	//unk4 = offset or length
	bool ExecuteLine(Script* scriptObj, UInt16 opcode, UInt32 unk2, UInt16* unk3, UInt16 unk4, UInt16* unk5, 
					 UInt32 currentLine, UInt32 unk7, UInt32 unk8);
	bool Run(Script* scriptObj, UInt32 unk1, ScriptEventList* eventList, UInt32 unk3, UInt32 unkt4, UInt32 unk5,
		UInt32 unk6, float unk7);
};

STATIC_ASSERT(sizeof(ScriptRunner) == 0xA4);

// A plugin author requested the ability to use OBSE format specifiers to format strings with the args
// coming from a source other than script.
// So changed ExtractFormattedString to take an object derived from following class, containing the args
// Probably doesn't belong in GameAPI.h but utilizes a bunch of stuff defined here and can't think of a better place for it
class FormatStringArgs
{
public:
	enum argType {
		kArgType_Float,
		kArgType_Form		// TESForm*
	};

	virtual bool Arg(argType asType, void * outResult) = 0;	// retrieve next arg
	virtual bool SkipArgs(UInt32 numToSkip) = 0;			// skip specified # of args
	virtual bool HasMoreArgs() = 0;
	virtual std::string GetFormatString() = 0;						// return format string
};

// concrete class used for extracting script args
class ScriptFormatStringArgs : public FormatStringArgs
{
public:
	virtual bool Arg(argType asType, void* outResult);
	virtual bool SkipArgs(UInt32 numToSkip);
	virtual bool HasMoreArgs();
	virtual std::string GetFormatString();

	ScriptFormatStringArgs(UInt32 _numArgs, UInt8* _scriptData, Script* _scriptObj, ScriptEventList* _eventList);
	UInt32 GetNumArgs();
	UInt8* GetScriptData();

private:
	UInt32			numArgs;
	UInt8			* scriptData;
	Script			* scriptObj;
	ScriptEventList	* eventList;
	std::string fmtString;
};


