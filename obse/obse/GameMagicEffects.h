#pragma once

class MagicItem;
class EffectItem;
class MagicTarget;
class MagicCaster;
class TESForm;
class TESObject;

// 38?
class ActiveEffect
{
public:
	ActiveEffect();	// args are caster, magicItem, effectItem
	virtual ~ActiveEffect();

	virtual ActiveEffect *	Clone(void);
	virtual void			Unk_02(UInt32 arg);
	virtual void			Unk_03(UInt32 arg);
	virtual void			SaveGame(UInt32 arg);
	virtual void			LoadGame(UInt32 arg);
	virtual void			Unk_06(UInt32 arg);
	virtual void			Unk_07(UInt32 arg);
	virtual void			Unk_08(UInt32 arg);
	virtual bool			UnregisterCaster(MagicCaster * _caster);	// returns 1 and clears caster if it matches the parameter, else returns 0
	virtual bool			Unk_0A(void);
	virtual void			CopyTo(ActiveEffect * target);
	virtual bool			Unk_0C(UInt32 arg);
	virtual bool			Unk_0D(UInt32 arg);
	virtual void			Unk_0E(void);	// update/add effect?
	virtual void			Unk_0F(void);	// update/add effect?

//	void		** _vtbl;			// 00
	float		timeElapsed;		// 04
	MagicItem	* item;				// 08
	EffectItem	* effectItem;		// 0C
	UInt8		flags10;			// 10
	UInt8		flags11;			// 11
	UInt8		flags12;			// 12
	UInt8		pad13;				// 13
	UInt32		unk14;				// 14
	float		magnitude;			// 18 - adjusted based on target?
	float		duration;			// 1C - adjusted based on target?
	MagicTarget	* target;			// 20
	MagicCaster	* caster;			// 24
	UInt32		unk28;				// 28
	UInt32		unk2C;				// 2C
	UInt32		unk30;				// 30 - on Enchantment on Armor this is TESARMO
	TESForm		* data;				// 34 - in ScriptEffect this is a Script *
};

// 40
class ScriptEffect : public ActiveEffect
{
public:
	ScriptEffect();
	virtual ~ScriptEffect();

	UInt32	unk38;	// 38
	UInt32	unk3C;	// 3C
};

// 40
class CureEffect : public ActiveEffect
{
public:
	CureEffect();
	virtual ~CureEffect();

	UInt32	unk38;			// 38
								// 0 - CUPA
								// 1 - CUDI
								// 5 - CUPO
	UInt32	effectToCure;	// 3C
								// 'PARA' for CUPA (cure paralysis)
								// 0xFFFFFFFF for CUDA, CUPO
};

// 3C
class ValueModifierEffect : public ActiveEffect
{
	// initializes magnitude to 1 if kEffect_NoMagnitude is set in effectFlags

public:
	ValueModifierEffect();
	virtual ~ValueModifierEffect();

	UInt32	actorVal;	// 38
};

// 3C
class CalmEffect : public ValueModifierEffect
{
public:
	CalmEffect();
	virtual ~CalmEffect();
};

// 3C
class ChameleonEffect : public ValueModifierEffect
{
public:
	ChameleonEffect();
	virtual ~ChameleonEffect();
};

// 3C
class DarknessEffect : public ValueModifierEffect
{
public:
	DarknessEffect();
	virtual ~DarknessEffect();
};

// 3C
class DetectLifeEffect : public ValueModifierEffect
{
public:
	DetectLifeEffect();
	virtual ~DetectLifeEffect();
};

// 3C
class InvisibilityEffect : public ValueModifierEffect
{
public:
	InvisibilityEffect();
	virtual ~InvisibilityEffect();
};

// 3C
class NightEyeEffect : public ValueModifierEffect
{
public:
	NightEyeEffect();
	virtual ~NightEyeEffect();
};

// 3C
class ParalysisEffect : public ValueModifierEffect
{
public:
	ParalysisEffect();
	virtual ~ParalysisEffect();
};

// 40
class ShieldEffect : public ValueModifierEffect
{
public:
	ShieldEffect();
	virtual ~ShieldEffect();

	UInt32	unk3C;	// 3C - type? kActorVal_*?
						// 0x48 - SHLD
						// 0x2B - FRSH, FISH, LISH
};

// 40
class FrenzyEffect : public ValueModifierEffect
{
public:
	FrenzyEffect();
	virtual ~FrenzyEffect();

	UInt8	unk3C;		// 3C
	UInt8	pad3D[3];	// 3D
};

// 3C+
class AssociatedItemEffect : public ActiveEffect
{
public:
	AssociatedItemEffect();
	virtual ~AssociatedItemEffect();

	TESObject	* item;	// 38 - creature, armor, weapon
};

// 64
class SummonCreatureEffect : public AssociatedItemEffect
{
public:
	SummonCreatureEffect();
	virtual ~SummonCreatureEffect();

	// C
	struct Unk48	// memory-related, seen elsewhere
	{
		UInt32	unk0;
		UInt32	unk4;
		UInt32	unk8;
	};

	UInt32	unk3C;		// 3C
	UInt8	unk40;		// 40
	UInt8	pad41[3];	// 41
	UInt32	unk44;		// 44
	Unk48	unk48;		// 48
	Unk48	unk54;		// 54
	UInt8	unk60;		// 60
	UInt8	unk61;		// 61
	UInt8	pad62[2];	// 62
};

// 8C
class BoundItemEffect : public AssociatedItemEffect
{
public:
	BoundItemEffect();
	virtual ~BoundItemEffect();

	UInt32	unk3C;		// 3C
	UInt32	unk40;		// 40
	UInt32	unk44;		// 44
	UInt32	unk48;		// 48
	UInt32	unk4C;		// 4C
	UInt32	unk50;		// 50
	UInt32	unk54;		// 54
	UInt32	unk58;		// 58
	UInt32	unk5C;		// 5C
	UInt32	unk60;		// 60
	UInt32	unk64;		// 64
	UInt32	unk68;		// 68
	UInt32	unk6C;		// 6C
	UInt32	unk70;		// 70
	UInt32	unk74;		// 74
	UInt32	unk78;		// 78
	UInt32	unk7C;		// 7C
	UInt32	unk80;		// 80
	UInt8	unk84;		// 84
	UInt8	unk85;		// 85
	UInt8	unk86;		// 86
	UInt8	unk87;		// 87
	UInt8	unk88;		// 88
	UInt8	pad89[3];	// 89
};

// 4C
class AbsorbEffect : public ValueModifierEffect
{
public:
	AbsorbEffect();
	virtual ~AbsorbEffect();

	UInt32	unk3C;		// 3C - NiNode *?
	UInt32	unk40;		// 40 - NiNode *?
	UInt32	unk44;		// 44 - NiNode *?
	UInt32	unk48;		// 48 - NiNode *?
};

// 38
class CommandEffect : public ActiveEffect
{
public:
	CommandEffect();
	virtual ~CommandEffect();
};

// 38
class CommandCreatureEffect : public CommandEffect
{
public:
	CommandCreatureEffect();
	virtual ~CommandCreatureEffect();
};

// 38
class CommandHumanoidEffect : public CommandEffect
{
public:
	CommandHumanoidEffect();
	virtual ~CommandHumanoidEffect();
};

// 3C
class DemoralizeEffect : public ActiveEffect
{
public:
	DemoralizeEffect();
	virtual ~DemoralizeEffect();

	UInt8	unk38;		// 38
	UInt8	pad39[3];	// 39
};

// 3C
class DisintegrateArmorEffect : public ActiveEffect
{
public:
	DisintegrateArmorEffect();
	virtual ~DisintegrateArmorEffect();

	UInt32	unk38;	// 38
};

// 38
class DisintegrateWeaponEffect : public ActiveEffect
{
public:
	DisintegrateWeaponEffect();
	virtual ~DisintegrateWeaponEffect();
};

// 38
class DispelEffect : public ActiveEffect
{
public:
	DispelEffect();
	virtual ~DispelEffect();
};

// 3C
class LightEffect : public ActiveEffect
{
public:
	LightEffect();
	virtual ~LightEffect();

	UInt32	unk3C;	// 3C - NiNode *?
};

// 38
class LockEffect : public ActiveEffect
{
public:
	LockEffect();
	virtual ~LockEffect();
};

// 38
class OpenEffect : public ActiveEffect
{
public:
	OpenEffect();
	virtual ~OpenEffect();
};

// 60
class ReanimateEffect : public ActiveEffect
{
public:
	ReanimateEffect();
	virtual ~ReanimateEffect();

	// C
	struct Unk44
	{
		UInt32	unk0;	// 0
		UInt32	unk4;	// 4
		UInt32	unk8;	// 8
	};

	// 10
	struct Unk50
	{
		UInt32	unk0;	// 0
		UInt32	unk4;	// 4
		UInt32	unk8;	// 8
		UInt32	unkC;	// C
	};

	UInt32	unk38;		// 38
	UInt32	unk3C;		// 3C
	UInt32	unk40;		// 40
	Unk44	unk44;		// 44
	Unk50	unk50;		// 50
};

// 38
class SoulTrapEffect : public ActiveEffect
{
public:
	SoulTrapEffect();
	virtual ~SoulTrapEffect();
};

// 38
class SunDamageEffect : public ActiveEffect
{
public:
	SunDamageEffect();
	virtual ~SunDamageEffect();

	UInt32	unk38;		// 38
	UInt8	unk3C;		// 3C
	UInt8	unk3D;		// 3D
	UInt8	pad3E[2];	// 3E
};

// 50
class TelekinesisEffect : public ValueModifierEffect
{
public:
	TelekinesisEffect();
	virtual ~TelekinesisEffect();

	UInt32	unk3C;		// 3C - NiNode *?
	UInt32	unk40;		// 40
	UInt32	unk44;		// 44
	UInt32	unk48;		// 48
	UInt8	unk4C;		// 4C
	UInt8	unk4D;		// 4D
	UInt8	pad4E[2];	// 4E
};

// 3C
class TurnUndeadEffect : public ActiveEffect
{
public:
	TurnUndeadEffect();
	virtual ~TurnUndeadEffect();

	UInt8	unk38;		// 38
	UInt8	pad39[3];	// 39
};

// 38
class VampirismEffect : public ActiveEffect
{
public:
	VampirismEffect();
	virtual ~VampirismEffect();
};
