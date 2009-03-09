#pragma once

#include "CommandTable.h"

static ParamInfo kParams_OneInt[1] =
{
	{	"int", kParamType_Integer, 0 }, 
};

static ParamInfo kParams_TwoInts[2] =
{
	{	"int", kParamType_Integer, 0 },
	{	"int", kParamType_Integer, 0 },
};

static ParamInfo kParams_OneOptionalInt[1] =
{
	{	"int", kParamType_Integer, 1 }, 
};

static ParamInfo kParams_OneInt_OneOptionalInt[2] =
{
	{	"int", kParamType_Integer, 0 },
	{	"int", kParamType_Integer, 1 },
};

static ParamInfo kParams_OneFloat[1] =
{
	{	"float", kParamType_Float,	0 },
};

static ParamInfo kParams_OneString[1] =
{
	{	"string",	kParamType_String,	0 },
};

static ParamInfo kParams_TwoFloats[2] =
{
	{	"float",	kParamType_Float,	0 },
	{	"float",	kParamType_Float,	0 },
};

static ParamInfo kParams_OneSpellItem[1] =
{
	{	"spell", kParamType_SpellItem, 0 }, 
};

static ParamInfo kParams_OneMagicItem[1] =
{
	{	"spell", kParamType_MagicItem, 0 }, 
};

static ParamInfo kParams_OneMagicEffect[1] =
{
	{	"magic effect", kParamType_MagicEffect, 0 }, 
};

static ParamInfo kParams_OneInventoryObject[1] =
{
	{	"int", kParamType_InventoryObject, 0},
};

static ParamInfo kParams_OneOptionalInventoryObject[1] =
{
	{	"int", kParamType_InventoryObject, 1},
};

static ParamInfo kParams_OneInt_OneOptionalInventoryObject[2] =
{
	{	"path type",	kParamType_Integer,			0	},
	{	"item",			kParamType_InventoryObject,	1	},
};

static ParamInfo kParams_OneActorValue[1] =
{
	{	"actor value", kParamType_ActorValue, 0},
};

#define FORMAT_STRING_PARAMS 	\
	{"format string",	kParamType_String, 0}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1}, \
	{"variable",		kParamType_Float, 1} 

static ParamInfo kParams_FormatString[21] =
{
	FORMAT_STRING_PARAMS
};

#define SIZEOF_FMT_STRING_PARAMS 21
#define NUM_PARAMS(paramInfoName) SIZEOF_ARRAY(paramInfoName, ParamInfo)

static ParamInfo kParams_OneActorRef[1] =
{
	{	"actor reference",	kParamType_Actor,	0	},
};

static ParamInfo kParams_OneOptionalActorRef[1] =
{
	{	"actor reference",	kParamType_Actor,	1	},
};

static ParamInfo kParams_Axis[1] = 
{
	{	"axis",	kParamType_Axis,	0	},
};
