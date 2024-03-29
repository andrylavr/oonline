#include "Commands_Creature.h"
#include "GameObjects.h"
#include "GameExtraData.h"
#include "GameAPI.h"
#include "GameForms.h"
#include "GameProcess.h"
#include "ParamInfos.h"

#if OBLIVION

class PrintAnimation
{
public:
	PrintAnimation() : index(0) {}
	UInt32 index;

	bool Accept(char* animName)
	{
		Console_Print("%d> %s", index, animName);
		_MESSAGE("%d> %s", index, animName);
		++index;
		return true;
	}
};

static bool Cmd_IsCreature_Execute(COMMAND_ARGS)
{
	*result = 0;
	TESActorBase* actorBase = NULL;
	ExtractArgs(paramInfo, arg1, opcodeOffsetPtr, thisObj, arg3, scriptObj, eventList, &actorBase);

	if (!actorBase) {
		if (!thisObj) return true;
		actorBase = (TESActorBase*)Oblivion_DynamicCast(thisObj->baseForm, 0, RTTI_TESForm, RTTI_TESActorBase, 0);
		if (!actorBase) return true;
	}

	TESCreature* creature = (TESCreature*)Oblivion_DynamicCast(actorBase, 0, RTTI_TESActorBase, RTTI_TESCreature, 0);
	if (creature) {
//		AnimationVisitor visitor(&creature->animation.data);
//		UInt32 animationCount = visitor.Count();
//		Console_Print("%s has %d animations", actorBase->GetEditorName(), animationCount);
//		PrintAnimation printer;
//		visitor.Visit(printer);
		*result = 1;
	}
	return true;
}

enum {
	kCreature_Type = 0,
	kCreature_CombatSkill,
	kCreature_MagicSkill,
	kCreature_StealthSkill,
	kCreature_Reach,
	kCreature_BaseScale,
	kCreature_SoulLevel,
	kCreature_Walks,
	kCreature_Swims,
	kCreature_Flies,
	kCreature_Biped,
	kCreature_WeaponAndShield,
	kCreature_NoHead,
	kCreature_NoLArm,
	kCreature_NoRArm,
	kCreature_NoCombatInWater,
	kCreature_NoMovement,
};

static bool GetCreatureValue(COMMAND_ARGS, UInt32 whichVal)
{
	*result = 0;
	TESActorBase* actorBase = NULL;
	ExtractArgs(paramInfo, arg1, opcodeOffsetPtr, thisObj, arg3, scriptObj, eventList, &actorBase);

	if (!actorBase) {
		if (!thisObj) return true;
		actorBase = (TESActorBase*)Oblivion_DynamicCast(thisObj->baseForm, 0, RTTI_TESForm, RTTI_TESActorBase, 0);
		if (!actorBase) return true;
	}

	TESCreature* creature = (TESCreature*)Oblivion_DynamicCast(actorBase, 0, RTTI_TESActorBase, RTTI_TESCreature, 0);
	switch(whichVal) {
		case kCreature_Type: 
			{
				*result = (creature) ? creature->type : -1;
				break;
			}

		case kCreature_CombatSkill:
			{
				*result = (creature) ? creature->stealthSkill : 0;
				break;
			}

		case kCreature_MagicSkill:
			{
				*result = (creature) ? creature->stealthSkill : 0;
				break;
			}

		case kCreature_StealthSkill:
			{
				*result = (creature) ? creature->stealthSkill : 0;
				break;
			}
		case kCreature_Reach:
			{
				*result = (creature) ? creature->attackReach : 0;
				break;
			}

		case kCreature_BaseScale:
			{
				*result = (creature) ? creature->baseScale : 1.0;
				break;
			}
		case kCreature_SoulLevel:
			{
				if (creature) {
					*result = creature->soulLevel;
				} else {
					TESNPC* npc = (TESNPC*)Oblivion_DynamicCast(actorBase, 0, RTTI_TESActorBase, RTTI_TESNPC, 0);
					if (npc) *result = 5;
				}
				break;
			}

		case kCreature_Walks:
			{
				*result = (creature && creature->actorBaseData.CreatureWalks()) ? 1 : 0;
				break;
			}

		case kCreature_Swims:
			{
				*result = (creature && creature->actorBaseData.CreatureSwims()) ? 1 : 0;
				break;
			}
		case kCreature_Flies:
			{
				*result = (creature && creature->actorBaseData.CreatureFlies()) ? 1 : 0;
				break;
			}
		case kCreature_Biped:
			{
				*result = (creature && creature->actorBaseData.IsCreatureBiped()) ? 1 : 0;
				break;
			}
		case kCreature_WeaponAndShield:
			{
				*result = (creature && creature->actorBaseData.CreatureHasWeaponAndShield()) ? 1 : 0;
				break;
			}
		case kCreature_NoHead:
			{
				*result = (creature && creature->actorBaseData.CreatureHasNoHead()) ? 1 : 0;
				break;
			}
		case kCreature_NoLArm:
			{
				*result = (creature && creature->actorBaseData.CreatureHasNoLeftArm()) ? 1 : 0;
				break;
			}
		case kCreature_NoRArm:
			{
				*result = (creature && creature->actorBaseData.CreatureHasNoRightArm()) ? 1 : 0;
				break;
			}
		case kCreature_NoCombatInWater:
			{
				*result = (creature && creature->actorBaseData.CreatureNoCombatInWater()) ? 1 : 0;
				break;
			}
		case kCreature_NoMovement:
			{
				*result = (creature && creature->actorBaseData.CreatureHasNoMovement()) ? 1 : 0;
				break;
			}

		default:
			*result = 0;
	}
	return true;
}

static bool Cmd_GetCreatureType_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_Type);
}

static bool Cmd_GetCreatureCombatSkill_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_CombatSkill);
}

static bool Cmd_GetCreatureMagicSkill_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_MagicSkill);
}

static bool Cmd_GetCreatureStealthSkill_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_StealthSkill);
}

static bool Cmd_GetCreatureReach_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_Reach);
}

static bool Cmd_GetCreatureBaseScale_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_BaseScale);
}

static bool Cmd_GetCreatureSoulLevel_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_SoulLevel);
}

static bool Cmd_GetCreatureWalks_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_Walks);
}

static bool Cmd_GetCreatureSwims_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_Swims);
}

static bool Cmd_GetCreatureFlies_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_Flies);
}

static bool Cmd_IsCreatureBiped_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_Biped);
}

static bool Cmd_CreatureUsesWeaponAndShield_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_WeaponAndShield);
}

static bool Cmd_CreatureHasNoHead_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_NoHead);
}

static bool Cmd_CreatureHasNoLeftArm_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_NoLArm);
}

static bool Cmd_CreatureHasNoRightArm_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_NoRArm);
}

static bool Cmd_CreatureNoCombatInWater_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_NoCombatInWater);
}

static bool Cmd_CreatureHasNoMovement_Execute(COMMAND_ARGS)
{
	return GetCreatureValue(PASS_COMMAND_ARGS, kCreature_NoMovement);
}


static bool Cmd_GetRider_Execute(COMMAND_ARGS)
{
	UInt32* refResult = (UInt32*)result;
	*refResult = 0;

	if (thisObj)
	{
		Creature* horse = (Creature*)Oblivion_DynamicCast(thisObj, 0, RTTI_TESObjectREFR, RTTI_Creature, 0);
		if (horse && horse->horseOrRider)
			*refResult = horse->horseOrRider->refID;
	}

	return true;
}


static bool Cmd_GetCreatureSoundBase_Execute(COMMAND_ARGS)
{
	TESActorBase* actorBase = 0;
	UInt32* refResult = (UInt32*)result;
	*refResult = 0;

	if (!ExtractArgs(paramInfo, arg1, opcodeOffsetPtr, thisObj, arg3, scriptObj, eventList, &actorBase))
		return true;

	if (!actorBase)
		if (thisObj)
			actorBase = (TESActorBase*)Oblivion_DynamicCast(thisObj->baseForm, 0, RTTI_TESForm, RTTI_TESActorBase, 0);

	TESCreature* crea = (TESCreature*)Oblivion_DynamicCast(actorBase, 0, RTTI_TESActorBase, RTTI_TESCreature, 0);
	if (crea)
	{
		TESCreature* base = crea->GetSoundBase();
		if (base)
			*refResult = base->refID;
	}

	return true;
}

static bool Cmd_HasModel_Execute(COMMAND_ARGS)
{
	char nifPath[512];
	TESActorBase* actorBase = 0;
	*result = 0;

	if (!ExtractArgs(paramInfo, arg1, opcodeOffsetPtr, thisObj, arg3, scriptObj, eventList, &nifPath, &actorBase))
		return true;

	if (!actorBase)
		if (thisObj)
			actorBase = (TESActorBase*)Oblivion_DynamicCast(thisObj->baseForm, 0, RTTI_TESForm, RTTI_TESActorBase, 0);

	TESCreature* crea = (TESCreature*)Oblivion_DynamicCast(actorBase, 0, RTTI_TESActorBase, RTTI_TESCreature, 0);
	if (crea && crea->modelList.FindNifPath(nifPath))
			*result = 1;


	return true;
}

class ModelListDumper
{
public:
	bool Accept(char* nifPath)
	{
		Console_Print("%s", nifPath);
		_MESSAGE("%s", nifPath);
		return true;
	}
};

static bool Cmd_ToggleCreatureModel_Execute(COMMAND_ARGS)
{
	TESActorBase* actorBase = NULL;
	UInt32 bEnable = 0;
	char nifPath[512];
	*result = 0;

	if (!ExtractArgs(paramInfo, arg1, opcodeOffsetPtr, thisObj, arg3, scriptObj, eventList, &nifPath, &bEnable, &actorBase))
		return false;

	if (!actorBase)
		if (thisObj)
			actorBase = (TESActorBase*)Oblivion_DynamicCast(thisObj->baseForm, 0, RTTI_TESForm, RTTI_TESActorBase, 0);	

	TESCreature* crea = (TESCreature*)Oblivion_DynamicCast(actorBase, 0, RTTI_TESActorBase, RTTI_TESCreature, 0);
	if (!crea)
		return true;
	if (bEnable)
	{
		if (crea->modelList.AddEntry(nifPath))
			*result = 1;
	}
	else
	{
		//ModelListVisitor(&(crea->modelList.modelList)).Visit(ModelListDumper());
		if (crea->modelList.RemoveEntry(nifPath))
			*result = 1;
		//ModelListVisitor(&crea->modelList.modelList).Visit(ModelListDumper());
	}
	return true;
}

static bool Cmd_GetCreatureSound_Execute(COMMAND_ARGS)
{
	TESActorBase* actorBase = 0;
	UInt32 whichSound = 0;
	UInt32* refResult = (UInt32*)result;
	*refResult = 0;

	if (!ExtractArgs(paramInfo, arg1, opcodeOffsetPtr, thisObj, arg3, scriptObj, eventList, &whichSound, &actorBase))
		return true;

	if (!actorBase)
		if (thisObj)
			actorBase = (TESActorBase*)Oblivion_DynamicCast(thisObj->baseForm, 0, RTTI_TESForm, RTTI_TESActorBase, 0);

	TESCreature* crea = (TESCreature*)Oblivion_DynamicCast(actorBase, 0, RTTI_TESActorBase, RTTI_TESCreature, 0);
	if (crea && crea->soundBase)
	{
		TESSound* sound = crea->GetSound(whichSound);
		if (sound)
			*refResult = sound->refID;
	}
	return true;
}

#endif

static ParamInfo kParams_OneOptionalActorBase[1] =
{
	{	"index", kParamType_ActorBase, 1 },
};

CommandInfo kCommandInfo_IsCreature =
{
	"IsCreature",
	"",
	0,
	"returns 1 if the passed actor base is a creature",
	0,
	1,
	kParams_OneOptionalActorBase,
	HANDLER(Cmd_IsCreature_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureType =
{
	"GetCreatureType",
	"",
	0,
	"returns the type of the calling creature or passed refID",
	0,
	1,
	kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureType_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureCombatSkill =
{
	"GetCreatureCombatSkill",
	"GetCreatureCombat",
	0,
	"returns the combat skill of the calling creature or passed refID",
	0,
	1,
	kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureCombatSkill_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureMagicSkill =
{
	"GetCreatureMagicSkill",
	"GetCreatureMagic",
	0,
	"returns the magic skill of the calling creature or passed refID",
	0,
	1,
	kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureMagicSkill_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureStealthSkill =
{
	"GetCreatureStealthSkill",
	"GetCreatureStealth",
	0,
	"returns the stealth skill of the calling creature or passed refID",
	0,
	1,
	kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureStealthSkill_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureBaseScale =
{
	"GetCreatureBaseScale",
	"GetCreatureScale",
	0,
	"returns the base scale of the calling creature or passed refID",
	0,
	1,
	kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureBaseScale_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureReach =
{
	"GetCreatureReach",
	"",
	0,
	"returns the reach of the calling creature or passed refID",
	0,
	1,
	kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureReach_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureSoulLevel =
{
	"GetCreatureSoulLevel", "GetActorSoulLevel",
	0,
	"returns the soul level of the calling actor or passed refID",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureSoulLevel_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureWalks =
{
	"GetCreatureWalks", "CreatureWalks",
	0,
	"returns 1 if the calling creature or creature refID has the Walk flag",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureWalks_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureFlies =
{
	"GetCreatureFlies", "CreatureFlies",
	0,
	"returns 1 if the calling creature or creature refID has the Flies flag",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureFlies_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureSwims =
{
	"GetCreatureSwims", "CreatureSwims",
	0,
	"returns 1 if the calling creature or creature refID has the Swims flag",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureSwims_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_IsCreatureBiped =
{
	"IsCreatureBiped", "IsBiped",
	0,
	"returns 1 if the calling creature or creature refID is marked as a biped",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_IsCreatureBiped_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_CreatureHasNoMovement =
{
	"CreatureHasNoMovement", "",
	0,
	"returns 1 if the calling creature or creature refID has the None movement flag",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_CreatureHasNoMovement_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_CreatureHasNoHead =
{
	"CreatureHasNoHead", "",
	0,
	"returns 1 if the calling creature or creature refID has the NoHead flag",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_CreatureHasNoHead_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_CreatureHasNoLeftArm =
{
	"CreatureHasNoLeftArm", "",
	0,
	"returns 1 if the calling creature or creature refID has the NoLeftArm flag",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_CreatureHasNoLeftArm_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_CreatureHasNoRightArm =
{
	"CreatureHasNoRightArm", "",
	0,
	"returns 1 if the calling creature or creature refID has the NoRightArm flag",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_CreatureHasNoRightArm_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_CreatureNoCombatInWater =
{
	"CreatureNoCombatInWater", "",
	0,
	"returns 1 if the calling creature or creature refID has the NoCombatInWater flag",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_CreatureNoCombatInWater_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_CreatureUsesWeaponAndShield =
{
	"CreatureUsesWeaponAndShield", "",
	0,
	"returns 1 if the calling creature or creature refID has the WeaponAndShield flag",
	0, 1, kParams_OneOptionalActorBase,
	HANDLER(Cmd_CreatureUsesWeaponAndShield_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetRider =
{
	"GetRider", "",
	0,
	"returns a reference to the actor currently riding the calling horse",
	1,
	0,
	NULL,
	HANDLER(Cmd_GetRider_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

CommandInfo kCommandInfo_GetCreatureSoundBase =
{
	"GetCreatureSoundBase", "",
	0,
	"returns the creature from which the specified creature's sounds are derived",
	0,
	1,
	kParams_OneOptionalActorBase,
	HANDLER(Cmd_GetCreatureSoundBase_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

static ParamInfo kParams_OneStringOneOptionalActorBase[2] =
{
	{	"model path",	kParamType_String,		0	},
	{	"creature",		kParamType_ActorBase,	1	},
};

CommandInfo kCommandInfo_HasModel =
{
	"HasModel",
	"",
	0,
	"returns 1 if the creature has the specified model path",
	0,
	2,
	kParams_OneStringOneOptionalActorBase,
	HANDLER(Cmd_HasModel_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

static ParamInfo kParams_ToggleCreatureModel[3] =
{
	{	"model path",	kParamType_String,		0	},
	{	"bool",			kParamType_Integer,		0	},
	{	"creature",		kParamType_ActorBase,	1	},
};

CommandInfo kCommandInfo_ToggleCreatureModel =
{
	"ToggleCreatureModel",
	"ToggleModel",
	0,
	"toggles a nifpath on or off in a creature's model list",
	0,
	3,
	kParams_ToggleCreatureModel,
	HANDLER(Cmd_ToggleCreatureModel_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};

static ParamInfo kParams_OneIntOneOptionalActorBase[2] =
{
	{	"int",	kParamType_Integer,		0 },
	{	"actor",kParamType_ActorBase,	1 },
};

CommandInfo kCommandInfo_GetCreatureSound =
{
	"GetCreatureSound",
	"",
	0,
	"returns the sound associated with a creature action",
	0,
	2,
	kParams_OneIntOneOptionalActorBase,
	HANDLER(Cmd_GetCreatureSound_Execute),
	Cmd_Default_Parse,
	NULL,
	0
};
