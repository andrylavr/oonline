#ifndef GameCommand_h__
#define GameCommand_h__
/*
Copyright 2009   Julian Bangert aka masterfreek64 
This file is part of OblivionOnline.

OblivionOnline is free software; you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

OblivionOnline is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//for version 2.416
#include "CommandTable.h"
static const _Cmd_Execute Cmd_Show_Execute = (_Cmd_Execute) 0x00502210;
static const _Cmd_Execute Cmd_ShowVars_Execute = (_Cmd_Execute) 0x005097A0;
static const _Cmd_Execute Cmd_ShowQuestVars_Execute = (_Cmd_Execute) 0x00509B30;
static const _Cmd_Execute Cmd_ShowQuests_Execute = (_Cmd_Execute) 0x00509D10;
static const _Cmd_Execute Cmd_ToggleCombatStats_Execute = (_Cmd_Execute) 0x00500770;
static const _Cmd_Execute Cmd_ToggleSafeZone_Execute = (_Cmd_Execute) 0x00500F60;
static const _Cmd_Execute Cmd_ToggleAI_Execute = (_Cmd_Execute) 0x005011F0;
static const _Cmd_Execute Cmd_ToggleCollisionGeometry_Execute = (_Cmd_Execute) 0x00500E30;
static const _Cmd_Execute Cmd_ToggleMaterialGeometry_Execute = (_Cmd_Execute) 0x00500E40;
static const _Cmd_Execute Cmd_ToggleBorders_Execute = (_Cmd_Execute) 0x00507C60;
static const _Cmd_Execute Cmd_ToggleSky_Execute = (_Cmd_Execute) 0x00507CB0;
static const _Cmd_Execute Cmd_ToggleLeaves_Execute = (_Cmd_Execute) 0x00507DC0;
static const _Cmd_Execute Cmd_ToggleWireframe_Execute = (_Cmd_Execute) 0x0050FCA0;
static const _Cmd_Execute Cmd_ToggleCollision_Execute = (_Cmd_Execute) 0x00507D30;
static const _Cmd_Execute Cmd_ToggleDebugText_Execute = (_Cmd_Execute) 0x00501000;
static const _Cmd_Execute Cmd_ToggleMenus_Execute = (_Cmd_Execute) 0x00500F10;
static const _Cmd_Execute Cmd_ShowScenegraph_Execute = (_Cmd_Execute) 0x0050FD10;
static const _Cmd_Execute Cmd_ToggleMagicStats_Execute = (_Cmd_Execute) 0x00507BD0;
static const _Cmd_Execute Cmd_ShowAnim_Execute = (_Cmd_Execute) 0x00509D70;
static const _Cmd_Execute Cmd_Show1stPerson_Execute = (_Cmd_Execute) 0x0050A050;
static const _Cmd_Execute Cmd_Help_Execute = (_Cmd_Execute) 0x00501540;
static const _Cmd_Execute Cmd_TogglePathGrid_Execute = (_Cmd_Execute) 0x00501650;
static const _Cmd_Execute Cmd_TogglePathLine_Execute = (_Cmd_Execute) 0x00501660;
static const _Cmd_Execute Cmd_PickRefByID_Execute = (_Cmd_Execute) 0x00513E90;
static const _Cmd_Execute Cmd_SetLightingPasses_Execute = (_Cmd_Execute) 0x005101E0;
static const _Cmd_Execute Cmd_ToggleLODLand_Execute = (_Cmd_Execute) 0x00508240;
static const _Cmd_Execute Cmd_ToggleGrassUpdate_Execute = (_Cmd_Execute) 0x00501A60;
static const _Cmd_Execute Cmd_CenterOnCell_Execute = (_Cmd_Execute) 0x005083C0;
static const _Cmd_Execute Cmd_SetGameSetting_Execute = (_Cmd_Execute) 0x00514100;
static const _Cmd_Execute Cmd_SetINISetting_Execute = (_Cmd_Execute) 0x005143C0;
static const _Cmd_Execute Cmd_GetINISetting_Execute = (_Cmd_Execute) 0x00514230;
static const _Cmd_Execute Cmd_CenterOnExterior_Execute = (_Cmd_Execute) 0x005084A0;
static const _Cmd_Execute Cmd_CalcPathToPoint_Execute = (_Cmd_Execute) 0x00510C70;
static const _Cmd_Execute Cmd_CalcLowPathToPoint_Execute = (_Cmd_Execute) 0x00510E60;
static const _Cmd_Execute Cmd_SetFog_Execute = (_Cmd_Execute) 0x005087C0;
static const _Cmd_Execute Cmd_SetClipDist_Execute = (_Cmd_Execute) 0x00510480;
static const _Cmd_Execute Cmd_ToggleShadowVolumes_Execute = (_Cmd_Execute) 0x005087A0;
static const _Cmd_Execute Cmd_SetImageSpaceGlow_Execute = (_Cmd_Execute) 0x00508860;
static const _Cmd_Execute Cmd_ToggleDetection_Execute = (_Cmd_Execute) 0x005010E0;
static const _Cmd_Execute Cmd_ToggleHighProcess_Execute = (_Cmd_Execute) 0x005013F0;
static const _Cmd_Execute Cmd_ToggleLowProcess_Execute = (_Cmd_Execute) 0x00501440;
static const _Cmd_Execute Cmd_ToggleMiddleLowProcess_Execute = (_Cmd_Execute) 0x00501480;
static const _Cmd_Execute Cmd_ToggleMiddleHighProcess_Execute = (_Cmd_Execute) 0x005014C0;
static const _Cmd_Execute Cmd_ToggleAiSchedules_Execute = (_Cmd_Execute) 0x00501500;
static const _Cmd_Execute Cmd_SpeakSound_Execute = (_Cmd_Execute) 0x00513C90;
static const _Cmd_Execute Cmd_BetaComment_Execute = (_Cmd_Execute) 0x0050A400;
static const _Cmd_Execute Cmd_ToggleCellNode_Execute = (_Cmd_Execute) 0x0050A8A0;
static const _Cmd_Execute Cmd_ToggleTrees_Execute = (_Cmd_Execute) 0x0050A9A0;
static const _Cmd_Execute Cmd_SetCameraFOV_Execute = (_Cmd_Execute) 0x00511720;
static const _Cmd_Execute Cmd_Verbose_Execute = (_Cmd_Execute) 0x00507930;
static const _Cmd_Execute Cmd_ToggleGodMode_Execute = (_Cmd_Execute) 0x00500D10;
static const _Cmd_Execute Cmd_RefreshShaders_Execute = (_Cmd_Execute) 0x0050AA20;
static const _Cmd_Execute Cmd_ToggleScripts_Execute = (_Cmd_Execute) 0x00500D50;
static const _Cmd_Execute Cmd_SexChange_Execute = (_Cmd_Execute) 0x00515920;
static const _Cmd_Execute Cmd_ToggleConversations_Execute = (_Cmd_Execute) 0x00507BA0;
static const _Cmd_Execute Cmd_ToggleFullHelp_Execute = (_Cmd_Execute) 0x00500E00;
static const _Cmd_Execute Cmd_ShowQuestLog_Execute = (_Cmd_Execute) 0x005120A0;
static const _Cmd_Execute Cmd_ShowFullQuestLog_Execute = (_Cmd_Execute) 0x00512220;
static const _Cmd_Execute Cmd_DumpTexturePalette_Execute = (_Cmd_Execute) 0x00515330;
static const _Cmd_Execute Cmd_CenterOnWorld_Execute = (_Cmd_Execute) 0x005085D0;
static const _Cmd_Execute Cmd_ToggleGrass_Execute = (_Cmd_Execute) 0x0050EC90;
static const _Cmd_Execute Cmd_AddFaceAnimNote_Execute = (_Cmd_Execute) 0x00505120;
static const _Cmd_Execute Cmd_RefreshINI_Execute = (_Cmd_Execute) 0x00513BB0;
static const _Cmd_Execute Cmd_ToggleEmotions_Execute = (_Cmd_Execute) 0x00507A00;
static const _Cmd_Execute Cmd_AddDecal_Execute = (_Cmd_Execute) 0x00510580;
static const _Cmd_Execute Cmd_TestCode_Execute = (_Cmd_Execute) 0x00977C50;
static const _Cmd_Execute Cmd_ToggleMapMarkers_Execute = (_Cmd_Execute) 0x00507800;
static const _Cmd_Execute Cmd_PlayerSpellBook_Execute = (_Cmd_Execute) 0x00507740;
static const _Cmd_Execute Cmd_PrintAiList_Execute = (_Cmd_Execute) 0x005007A0;
static const _Cmd_Execute Cmd_ShowQuestTargets_Execute = (_Cmd_Execute) 0x00515AF0;
static const _Cmd_Execute Cmd_HairTint_Execute = (_Cmd_Execute) 0x00508B80;
static const _Cmd_Execute Cmd_SaveGame_Execute = (_Cmd_Execute) 0x005023D0;
static const _Cmd_Execute Cmd_LoadGame_Execute = (_Cmd_Execute) 0x00502500;
static const _Cmd_Execute Cmd_TestAllCells_Execute = (_Cmd_Execute) 0x00507960;
static const _Cmd_Execute Cmd_SaveWorld_Execute = (_Cmd_Execute) 0x00500E60;
static const _Cmd_Execute Cmd_ReloadCurrentClimate_Execute = (_Cmd_Execute) 0x00507A30;
static const _Cmd_Execute Cmd_ReloadCurrentWeather_Execute = (_Cmd_Execute) 0x00507A90;
static const _Cmd_Execute Cmd_TestSeenData_Execute = (_Cmd_Execute) 0x0050ED50;
static const _Cmd_Execute Cmd_TestLocalMap_Execute = (_Cmd_Execute) 0x0050EF90;
static const _Cmd_Execute Cmd_MoveToQuestTarget_Execute = (_Cmd_Execute) 0x00512910;
static const _Cmd_Execute Cmd_PrintNPCDialog_Execute = (_Cmd_Execute) 0x005007C0;
static const _Cmd_Execute Cmd_ShowSubtitle_Execute = (_Cmd_Execute) 0x005007D0;
static const _Cmd_Execute Cmd_ShowRenderPasses_Execute = (_Cmd_Execute) 0x00500820;
static const _Cmd_Execute Cmd_FreezeRenderAccumulation_Execute = (_Cmd_Execute) 0x00500830;
static const _Cmd_Execute Cmd_ToggleOcclusion_Execute = (_Cmd_Execute) 0x00500860;
static const _Cmd_Execute Cmd_OutputMemContexts_Execute = (_Cmd_Execute) 0x00500890;
static const _Cmd_Execute Cmd_OutputMemStats_Execute = (_Cmd_Execute) 0x005009E0;
static const _Cmd_Execute Cmd_ToggleDetectionStats_Execute = (_Cmd_Execute) 0x00500F70;
static const _Cmd_Execute Cmd_SetTargetRefraction_Execute = (_Cmd_Execute) 0x00507E60;
static const _Cmd_Execute Cmd_SetTargetRefractionFire_Execute = (_Cmd_Execute) 0x00507FF0;
static const _Cmd_Execute Cmd_ToggleRefractionDebug_Execute = (_Cmd_Execute) 0x00508180;
static const _Cmd_Execute Cmd_ToggleCharControllerShape_Execute = (_Cmd_Execute) 0x00507C00;
static const _Cmd_Execute Cmd_ShowHeadTrackTarget_Execute = (_Cmd_Execute) 0x00508340;
static const _Cmd_Execute Cmd_SetSkyParam_Execute = (_Cmd_Execute) 0x00503C60;
static const _Cmd_Execute Cmd_SetHDRParam_Execute = (_Cmd_Execute) 0x0050B0C0;
static const _Cmd_Execute Cmd_ShowPivot_Execute = (_Cmd_Execute) 0x00511C10;
static const _Cmd_Execute Cmd_PrintHDRParam_Execute = (_Cmd_Execute) 0x0050B210;
static const _Cmd_Execute Cmd_ToggleHDRDebug_Execute = (_Cmd_Execute) 0x00503CE0;
static const _Cmd_Execute Cmd_RevertWorld_Execute = (_Cmd_Execute) 0x00500C90;
static const _Cmd_Execute Cmd_OutputArchiveProfile_Execute = (_Cmd_Execute) 0x00500AE0;
static const _Cmd_Execute Cmd_QuitGame_Execute = (_Cmd_Execute) 0x005077E0;
static const _Cmd_Execute Cmd_SaveIniFiles_Execute = (_Cmd_Execute) 0x00513B60;
static const _Cmd_Execute Cmd_SetDebugText_Execute = (_Cmd_Execute) 0x005081F0;
static const _Cmd_Execute Cmd_ToggleLiteBrite_Execute = (_Cmd_Execute) 0x005081B0;
static const _Cmd_Execute Cmd_RunMemoryPass_Execute = (_Cmd_Execute) 0x00501040;
static const _Cmd_Execute Cmd_ResetMemContexts_Execute = (_Cmd_Execute) 0x00500890;
static const _Cmd_Execute Cmd_ToggleWaterSystem_Execute = (_Cmd_Execute) 0x0050D860;
static const _Cmd_Execute Cmd_ToggleWaterRadius_Execute = (_Cmd_Execute) 0x0050D8C0;
static const _Cmd_Execute Cmd_ShowWhoDetectsPlayer_Execute = (_Cmd_Execute) 0x00500780;
static const _Cmd_Execute Cmd_ToggleCombatAI_Execute = (_Cmd_Execute) 0x00508300;
static const _Cmd_Execute Cmd_ToggleFlyCam_Execute = (_Cmd_Execute) 0x005013E0;
static const _Cmd_Execute Cmd_ModWaterShader_Execute = (_Cmd_Execute) 0x0050D8E0;
static const _Cmd_Execute Cmd_WaterShallowColor_Execute = (_Cmd_Execute) 0x0050E250;
static const _Cmd_Execute Cmd_WaterDeepColor_Execute = (_Cmd_Execute) 0x005065B0;
static const _Cmd_Execute Cmd_WaterReflectionColor_Execute = (_Cmd_Execute) 0x00506680;
static const _Cmd_Execute Cmd_BeginTrace_Execute = (_Cmd_Execute) 0x00977C50;
static const _Cmd_Execute Cmd_RunCellTest_Execute = (_Cmd_Execute) 0x005068C0;
static const _Cmd_Execute Cmd_StartAllQuests_Execute = (_Cmd_Execute) 0x0050E5A0;
static const _Cmd_Execute Cmd_CompleteAllQuestStages_Execute = (_Cmd_Execute) 0x0050E600;
static const _Cmd_Execute Cmd_FlushNonPersistActors_Execute = (_Cmd_Execute) 0x00506920;
static const _Cmd_Execute Cmd_ToggleFogOfWar_Execute = (_Cmd_Execute) 0x00506990;
static const _Cmd_Execute Cmd_OutputLocalMapPictures_Execute = (_Cmd_Execute) 0x0050E6A0;
static const _Cmd_Execute Cmd_SetGamma_Execute = (_Cmd_Execute) 0x0050E950;
static const _Cmd_Execute Cmd_WasteMemory_Execute = (_Cmd_Execute) 0x005069D0;
static const _Cmd_Execute Cmd_ClearAdaptedLight_Execute = (_Cmd_Execute) 0x00506AD0;
static const _Cmd_Execute Cmd_ToggleCastShadows_Execute = (_Cmd_Execute) 0x00506B80;
static const _Cmd_Execute Cmd_ShowSubSpaces_Execute = (_Cmd_Execute) 0x00506C80;
static const _Cmd_Execute Cmd_SetSTBBColorConstants_Execute = (_Cmd_Execute) 0x00508980;
static const _Cmd_Execute Cmd_CloseFile_Execute = (_Cmd_Execute) 0x00508A20;
static const _Cmd_Execute Cmd_SetTreeMipmapBias_Execute = (_Cmd_Execute) 0x00514500;
static const _Cmd_Execute Cmd_ClearFaceGenModelData_Execute = (_Cmd_Execute) 0x00506E90;

static const _Cmd_Execute Cmd_MessageBox_Execute = (_Cmd_Execute) 0x00513280;
static const _Cmd_Execute Cmd_GetDistance_Execute = (_Cmd_Execute) 0x005003F0;
static const _Cmd_Execute Cmd_AddItem_Execute = (_Cmd_Execute) 0x00507320;
static const _Cmd_Execute Cmd_SetEssential_Execute = (_Cmd_Execute) 0x0050B780;
static const _Cmd_Execute Cmd_Rotate_Execute = (_Cmd_Execute) 0x00510620;
static const _Cmd_Execute Cmd_GetLocked_Execute = (_Cmd_Execute) 0x00502390;
static const _Cmd_Execute Cmd_GetPos_Execute = (_Cmd_Execute) 0x00501A80;
static const _Cmd_Execute Cmd_SetPos_Execute = (_Cmd_Execute) 0x00508FC0;
static const _Cmd_Execute Cmd_GetAngle_Execute = (_Cmd_Execute) 0x00501B40;
static const _Cmd_Execute Cmd_SetAngle_Execute = (_Cmd_Execute) 0x00509110;
static const _Cmd_Execute Cmd_GetStartingPos_Execute = (_Cmd_Execute) 0x00501AE0;
static const _Cmd_Execute Cmd_GetStartingAngle_Execute = (_Cmd_Execute) 0x00501BA0;
static const _Cmd_Execute Cmd_GetSecondsPassed_Execute = (_Cmd_Execute) 0x00501C20;
static const _Cmd_Execute Cmd_Activate_Execute = (_Cmd_Execute) 0x00507650;
static const _Cmd_Execute Cmd_GetActorValue_Execute = (_Cmd_Execute) 0x00501670;
static const _Cmd_Execute Cmd_SetActorValue_Execute = (_Cmd_Execute) 0x005016D0;
static const _Cmd_Execute Cmd_ModActorValue_Execute = (_Cmd_Execute) 0x005017E0;
static const _Cmd_Execute Cmd_SetAtStart_Execute = (_Cmd_Execute) 0x00509220;
static const _Cmd_Execute Cmd_GetCurrentTime_Execute = (_Cmd_Execute) 0x00501C00;
static const _Cmd_Execute Cmd_PlayGroup_Execute = (_Cmd_Execute) 0x005107A0;
static const _Cmd_Execute Cmd_LoopGroup_Execute = (_Cmd_Execute) 0x00501C40;
static const _Cmd_Execute Cmd_SkipAnim_Execute = (_Cmd_Execute) 0x00501CF0;
static const _Cmd_Execute Cmd_StartCombat_Execute = (_Cmd_Execute) 0x00514660;
static const _Cmd_Execute Cmd_StopCombat_Execute = (_Cmd_Execute) 0x00501D30;
static const _Cmd_Execute Cmd_GetScale_Execute = (_Cmd_Execute) 0x00501E20;
static const _Cmd_Execute Cmd_UnusedFunction1_Execute = (_Cmd_Execute) 0x00000000;
static const _Cmd_Execute Cmd_UnusedFunction2_Execute = (_Cmd_Execute) 0x00000000;
static const _Cmd_Execute Cmd_GetLineOfSight_Execute = (_Cmd_Execute) 0x00501EF0;
static const _Cmd_Execute Cmd_AddSpell_Execute = (_Cmd_Execute) 0x00514950;
static const _Cmd_Execute Cmd_RemoveSpell_Execute = (_Cmd_Execute) 0x00510B90;
static const _Cmd_Execute Cmd_Cast_Execute = (_Cmd_Execute) 0x00501F50;
static const _Cmd_Execute Cmd_GetButtonPressed_Execute = (_Cmd_Execute) 0x005072B0;
static const _Cmd_Execute Cmd_GetInSameCell_Execute = (_Cmd_Execute) 0x00503210;
static const _Cmd_Execute Cmd_Enable_Execute = (_Cmd_Execute) 0x0050A150;
static const _Cmd_Execute Cmd_Disable_Execute = (_Cmd_Execute) 0x0050A240;
static const _Cmd_Execute Cmd_GetDisabled_Execute = (_Cmd_Execute) 0x00502370;
static const _Cmd_Execute Cmd_MenuMode_Execute = (_Cmd_Execute) 0x00502270;
static const _Cmd_Execute Cmd_PlaceAtMe_Execute = (_Cmd_Execute) 0x00514B50;
static const _Cmd_Execute Cmd_PlaySound_Execute = (_Cmd_Execute) 0x00509490;
static const _Cmd_Execute Cmd_GetDisease_Execute = (_Cmd_Execute) 0x00502630;
static const _Cmd_Execute Cmd_GetVampire_Execute = (_Cmd_Execute) 0x00502650;
static const _Cmd_Execute Cmd_GetClothingValue_Execute = (_Cmd_Execute) 0x00502670;
static const _Cmd_Execute Cmd_SameFaction_Execute = (_Cmd_Execute) 0x00502690;
static const _Cmd_Execute Cmd_SameRace_Execute = (_Cmd_Execute) 0x005026F0;
static const _Cmd_Execute Cmd_SameSex_Execute = (_Cmd_Execute) 0x00502750;
static const _Cmd_Execute Cmd_GetDetected_Execute = (_Cmd_Execute) 0x00502810;
static const _Cmd_Execute Cmd_GetDead_Execute = (_Cmd_Execute) 0x00502870;
static const _Cmd_Execute Cmd_GetItemCount_Execute = (_Cmd_Execute) 0x00502890;
static const _Cmd_Execute Cmd_GetGold_Execute = (_Cmd_Execute) 0x005029C0;
static const _Cmd_Execute Cmd_GetSleeping_Execute = (_Cmd_Execute) 0x005029E0;
static const _Cmd_Execute Cmd_GetTalkedToPC_Execute = (_Cmd_Execute) 0x00502B00;
static const _Cmd_Execute Cmd_Say_Execute = (_Cmd_Execute) 0x005118D0;
static const _Cmd_Execute Cmd_SayTo_Execute = (_Cmd_Execute) 0x00511AB0;
static const _Cmd_Execute Cmd_GetScriptVariable_Execute = (_Cmd_Execute) 0x00000000;
static const _Cmd_Execute Cmd_StartQuest_Execute = (_Cmd_Execute) 0x00502D30;
static const _Cmd_Execute Cmd_StopQuest_Execute = (_Cmd_Execute) 0x00502D80;
static const _Cmd_Execute Cmd_GetQuestRunning_Execute = (_Cmd_Execute) 0x00502B80;
static const _Cmd_Execute Cmd_SetStage_Execute = (_Cmd_Execute) 0x00502CB0;
static const _Cmd_Execute Cmd_GetStage_Execute = (_Cmd_Execute) 0x00502BE0;
static const _Cmd_Execute Cmd_GetStageDone_Execute = (_Cmd_Execute) 0x00502C40;
static const _Cmd_Execute Cmd_GetFactionRankDifference_Execute = (_Cmd_Execute) 0x00502E20;
static const _Cmd_Execute Cmd_GetAlarmed_Execute = (_Cmd_Execute) 0x00502E90;
static const _Cmd_Execute Cmd_IsRaining_Execute = (_Cmd_Execute) 0x00502EF0;
static const _Cmd_Execute Cmd_GetAttacked_Execute = (_Cmd_Execute) 0x00502FD0;
static const _Cmd_Execute Cmd_GetIsCreature_Execute = (_Cmd_Execute) 0x00502FF0;
static const _Cmd_Execute Cmd_GetLockLevel_Execute = (_Cmd_Execute) 0x005023B0;
static const _Cmd_Execute Cmd_GetShouldAttack_Execute = (_Cmd_Execute) 0x00503010;
static const _Cmd_Execute Cmd_GetInCell_Execute = (_Cmd_Execute) 0x00503070;
static const _Cmd_Execute Cmd_GetIsClass_Execute = (_Cmd_Execute) 0x00503270;
static const _Cmd_Execute Cmd_GetIsRace_Execute = (_Cmd_Execute) 0x00503330;
static const _Cmd_Execute Cmd_GetIsSex_Execute = (_Cmd_Execute) 0x00503390;
static const _Cmd_Execute Cmd_GetInFaction_Execute = (_Cmd_Execute) 0x00503410;
static const _Cmd_Execute Cmd_GetIsID_Execute = (_Cmd_Execute) 0x005035F0;
static const _Cmd_Execute Cmd_GetFactionRank_Execute = (_Cmd_Execute) 0x005037B0;
static const _Cmd_Execute Cmd_GetGlobalValue_Execute = (_Cmd_Execute) 0x00503930;
static const _Cmd_Execute Cmd_IsSnowing_Execute = (_Cmd_Execute) 0x00502F10;
static const _Cmd_Execute Cmd_GetDisposition_Execute = (_Cmd_Execute) 0x00503990;
static const _Cmd_Execute Cmd_GetRandomPercent_Execute = (_Cmd_Execute) 0x005039F0;
static const _Cmd_Execute Cmd_StreamMusic_Execute = (_Cmd_Execute) 0x00509610;
static const _Cmd_Execute Cmd_GetQuestVariable_Execute = (_Cmd_Execute) 0x00000000;
static const _Cmd_Execute Cmd_GetLevel_Execute = (_Cmd_Execute) 0x00503A10;
static const _Cmd_Execute Cmd_GetArmorRating_Execute = (_Cmd_Execute) 0x00503A30;
static const _Cmd_Execute Cmd_RemoveItem_Execute = (_Cmd_Execute) 0x00513810;
static const _Cmd_Execute Cmd_ModDisposition_Execute = (_Cmd_Execute) 0x00503A50;
static const _Cmd_Execute Cmd_GetDeadCount_Execute = (_Cmd_Execute) 0x00503B00;
static const _Cmd_Execute Cmd_ShowMap_Execute = (_Cmd_Execute) 0x0050AD00;
static const _Cmd_Execute Cmd_StartConversation_Execute = (_Cmd_Execute) 0x0050AE10;
static const _Cmd_Execute Cmd_Drop_Execute = (_Cmd_Execute) 0x00500650;
static const _Cmd_Execute Cmd_AddTopic_Execute = (_Cmd_Execute) 0x00503B60;
static const _Cmd_Execute Cmd_Message_Execute = (_Cmd_Execute) 0x00513600;
static const _Cmd_Execute Cmd_SetAlert_Execute = (_Cmd_Execute) 0x00503BC0;
static const _Cmd_Execute Cmd_GetIsAlerted_Execute = (_Cmd_Execute) 0x00503C40;
static const _Cmd_Execute Cmd_Look_Execute = (_Cmd_Execute) 0x0050AFD0;
static const _Cmd_Execute Cmd_StopLook_Execute = (_Cmd_Execute) 0x0050B070;
static const _Cmd_Execute Cmd_EvaluatePackage_Execute = (_Cmd_Execute) 0x0050AF90;
static const _Cmd_Execute Cmd_Yield_Execute = (_Cmd_Execute) 0x00501DD0;
static const _Cmd_Execute Cmd_EnablePlayerControls_Execute = (_Cmd_Execute) 0x005047E0;
static const _Cmd_Execute Cmd_DisablePlayerControls_Execute = (_Cmd_Execute) 0x005047F0;
static const _Cmd_Execute Cmd_GetPlayerControlsDisabled_Execute = (_Cmd_Execute) 0x00504800;
static const _Cmd_Execute Cmd_GetHeadingAngle_Execute = (_Cmd_Execute) 0x00504820;
static const _Cmd_Execute Cmd_PickIdle_Execute = (_Cmd_Execute) 0x00511FA0;
static const _Cmd_Execute Cmd_IsWeaponOut_Execute = (_Cmd_Execute) 0x00504890;
static const _Cmd_Execute Cmd_IsTorchOut_Execute = (_Cmd_Execute) 0x005048B0;
static const _Cmd_Execute Cmd_IsShieldOut_Execute = (_Cmd_Execute) 0x005048D0;
static const _Cmd_Execute Cmd_IsYielding_Execute = (_Cmd_Execute) 0x005048F0;
static const _Cmd_Execute Cmd_IsActionRef_Execute = (_Cmd_Execute) 0x005006E0;
static const _Cmd_Execute Cmd_IsFacingUp_Execute = (_Cmd_Execute) 0x00504910;
static const _Cmd_Execute Cmd_GetKnockedState_Execute = (_Cmd_Execute) 0x00504950;
static const _Cmd_Execute Cmd_GetWeaponAnimType_Execute = (_Cmd_Execute) 0x00504970;
static const _Cmd_Execute Cmd_GetWeaponSkillType_Execute = (_Cmd_Execute) 0x00504990;
static const _Cmd_Execute Cmd_GetCurrentAIPackage_Execute = (_Cmd_Execute) 0x005049B0;
static const _Cmd_Execute Cmd_IsWaiting_Execute = (_Cmd_Execute) 0x005049D0;
static const _Cmd_Execute Cmd_IsIdlePlaying_Execute = (_Cmd_Execute) 0x005049F0;
static const _Cmd_Execute Cmd_CompleteQuest_Execute = (_Cmd_Execute) 0x00502DD0;
static const _Cmd_Execute Cmd_Lock_Execute = (_Cmd_Execute) 0x00504A10;
static const _Cmd_Execute Cmd_UnLock_Execute = (_Cmd_Execute) 0x00504B00;
static const _Cmd_Execute Cmd_GetCrimeGold_Execute = (_Cmd_Execute) 0x00504CE0;
static const _Cmd_Execute Cmd_SetCrimeGold_Execute = (_Cmd_Execute) 0x0050B4A0;
static const _Cmd_Execute Cmd_ModCrimeGold_Execute = (_Cmd_Execute) 0x00504D00;
static const _Cmd_Execute Cmd_GetCrimeKnown_Execute = (_Cmd_Execute) 0x00504BB0;
static const _Cmd_Execute Cmd_PositionWorld_Execute = (_Cmd_Execute) 0x00508C30;
static const _Cmd_Execute Cmd_PositionCell_Execute = (_Cmd_Execute) 0x00508E20;
static const _Cmd_Execute Cmd_GetCrime_Execute = (_Cmd_Execute) 0x00504C60;
static const _Cmd_Execute Cmd_PayFine_Execute = (_Cmd_Execute) 0x0050B590;
static const _Cmd_Execute Cmd_PayFineThief_Execute = (_Cmd_Execute) 0x00504DB0;
static const _Cmd_Execute Cmd_IsGuard_Execute = (_Cmd_Execute) 0x00504E10;
static const _Cmd_Execute Cmd_GoToJail_Execute = (_Cmd_Execute) 0x0050B620;
static const _Cmd_Execute Cmd_CanPayCrimeGold_Execute = (_Cmd_Execute) 0x00504E30;
static const _Cmd_Execute Cmd_GetFatiguePercentage_Execute = (_Cmd_Execute) 0x005019E0;
static const _Cmd_Execute Cmd_GetPCIsClass_Execute = (_Cmd_Execute) 0x00503470;
static const _Cmd_Execute Cmd_GetPCIsRace_Execute = (_Cmd_Execute) 0x005034D0;
static const _Cmd_Execute Cmd_GetPCIsSex_Execute = (_Cmd_Execute) 0x00503530;
static const _Cmd_Execute Cmd_GetPCInFaction_Execute = (_Cmd_Execute) 0x00503590;
static const _Cmd_Execute Cmd_SameFactionAsPC_Execute = (_Cmd_Execute) 0x005027B0;
static const _Cmd_Execute Cmd_SameRaceAsPC_Execute = (_Cmd_Execute) 0x005027D0;
static const _Cmd_Execute Cmd_SameSexAsPC_Execute = (_Cmd_Execute) 0x005027F0;
static const _Cmd_Execute Cmd_GetIsReference_Execute = (_Cmd_Execute) 0x00503750;
static const _Cmd_Execute Cmd_SetFactionRank_Execute = (_Cmd_Execute) 0x0050AB80;
static const _Cmd_Execute Cmd_ModFactionRank_Execute = (_Cmd_Execute) 0x0050AC40;
static const _Cmd_Execute Cmd_KillActor_Execute = (_Cmd_Execute) 0x00501960;
static const _Cmd_Execute Cmd_ResurrectActor_Execute = (_Cmd_Execute) 0x00510150;
static const _Cmd_Execute Cmd_IsTalking_Execute = (_Cmd_Execute) 0x00504E50;
static const _Cmd_Execute Cmd_GetWalkSpeed_Execute = (_Cmd_Execute) 0x00504E70;
static const _Cmd_Execute Cmd_GetCurrentAIProcedure_Execute = (_Cmd_Execute) 0x00504E90;
static const _Cmd_Execute Cmd_GetTrespassWarningLevel_Execute = (_Cmd_Execute) 0x00504EB0;
static const _Cmd_Execute Cmd_IsTrespassing_Execute = (_Cmd_Execute) 0x00504ED0;
static const _Cmd_Execute Cmd_IsInMyOwnedCell_Execute = (_Cmd_Execute) 0x00504EF0;
static const _Cmd_Execute Cmd_GetWindSpeed_Execute = (_Cmd_Execute) 0x00502F30;
static const _Cmd_Execute Cmd_GetCurrentWeatherPercent_Execute = (_Cmd_Execute) 0x00502F50;
static const _Cmd_Execute Cmd_GetIsCurrentWeather_Execute = (_Cmd_Execute) 0x00502F70;
static const _Cmd_Execute Cmd_IsContinuingPackagePCNear_Execute = (_Cmd_Execute) 0x00504F10;
static const _Cmd_Execute Cmd_AddScriptPackage_Execute = (_Cmd_Execute) 0x005123A0;
static const _Cmd_Execute Cmd_RemoveScriptPackage_Execute = (_Cmd_Execute) 0x0050B6A0;
static const _Cmd_Execute Cmd_CanHaveFlames_Execute = (_Cmd_Execute) 0x00504F30;
static const _Cmd_Execute Cmd_HasFlames_Execute = (_Cmd_Execute) 0x00504F50;
static const _Cmd_Execute Cmd_AddFlames_Execute = (_Cmd_Execute) 0x00504F70;
static const _Cmd_Execute Cmd_RemoveFlames_Execute = (_Cmd_Execute) 0x00505020;
static const _Cmd_Execute Cmd_GetOpenState_Execute = (_Cmd_Execute) 0x00505090;
static const _Cmd_Execute Cmd_MoveToMarker_Execute = (_Cmd_Execute) 0x00512870;
static const _Cmd_Execute Cmd_GetSitting_Execute = (_Cmd_Execute) 0x00502A00;
static const _Cmd_Execute Cmd_GetFurnitureMarkerID_Execute = (_Cmd_Execute) 0x00502A20;
static const _Cmd_Execute Cmd_GetIsCurrentPackage_Execute = (_Cmd_Execute) 0x005050B0;
static const _Cmd_Execute Cmd_IsCurrentFurnitureRef_Execute = (_Cmd_Execute) 0x00502A40;
static const _Cmd_Execute Cmd_IsCurrentFurnitureObj_Execute = (_Cmd_Execute) 0x00502AA0;
static const _Cmd_Execute Cmd_SetSize_Execute = (_Cmd_Execute) 0x00501760;
static const _Cmd_Execute Cmd_RemoveMe_Execute = (_Cmd_Execute) 0x00500450;
static const _Cmd_Execute Cmd_DropMe_Execute = (_Cmd_Execute) 0x005005F0;
static const _Cmd_Execute Cmd_GetFactionReaction_Execute = (_Cmd_Execute) 0x00511800;
static const _Cmd_Execute Cmd_SetFactionReaction_Execute = (_Cmd_Execute) 0x00503810;
static const _Cmd_Execute Cmd_ModFactionReaction_Execute = (_Cmd_Execute) 0x005038A0;
static const _Cmd_Execute Cmd_GetDayOfWeek_Execute = (_Cmd_Execute) 0x005051D0;
static const _Cmd_Execute Cmd_IsPlayerInJail_Execute = (_Cmd_Execute) 0x005051F0;
static const _Cmd_Execute Cmd_GetTalkedToPCParam_Execute = (_Cmd_Execute) 0x00502B20;
static const _Cmd_Execute Cmd_RemoveAllItems_Execute = (_Cmd_Execute) 0x005074F0;
static const _Cmd_Execute Cmd_WakeUpPC_Execute = (_Cmd_Execute) 0x0050B700;
static const _Cmd_Execute Cmd_IsPCSleeping_Execute = (_Cmd_Execute) 0x00505210;
static const _Cmd_Execute Cmd_IsPCAMurderer_Execute = (_Cmd_Execute) 0x00505230;
static const _Cmd_Execute Cmd_SetCombatStyle_Execute = (_Cmd_Execute) 0x00505250;
static const _Cmd_Execute Cmd_PlaySound3D_Execute = (_Cmd_Execute) 0x00509520;
static const _Cmd_Execute Cmd_SelectPlayerSpell_Execute = (_Cmd_Execute) 0x005129E0;
static const _Cmd_Execute Cmd_GetDetectionLevel_Execute = (_Cmd_Execute) 0x00505350;
static const _Cmd_Execute Cmd_IsActorDetected_Execute = (_Cmd_Execute) 0x005053D0;
static const _Cmd_Execute Cmd_GetEquipped_Execute = (_Cmd_Execute) 0x00502960;
static const _Cmd_Execute Cmd_Wait_Execute = (_Cmd_Execute) 0x0050B810;
static const _Cmd_Execute Cmd_StopWaiting_Execute = (_Cmd_Execute) 0x0050B920;
static const _Cmd_Execute Cmd_IsSwimming_Execute = (_Cmd_Execute) 0x005053B0;
static const _Cmd_Execute Cmd_ScriptEffectElapsedSeconds_Execute = (_Cmd_Execute) 0x00502350;
static const _Cmd_Execute Cmd_SetCellPublicFlag_Execute = (_Cmd_Execute) 0x005031A0;
static const _Cmd_Execute Cmd_GetPCSleepHours_Execute = (_Cmd_Execute) 0x0050BAA0;
static const _Cmd_Execute Cmd_SetPCSleepHours_Execute = (_Cmd_Execute) 0x0050BAC0;
static const _Cmd_Execute Cmd_GetAmountSoldStolen_Execute = (_Cmd_Execute) 0x00505460;
static const _Cmd_Execute Cmd_ModAmountSoldStolen_Execute = (_Cmd_Execute) 0x0050BB20;
static const _Cmd_Execute Cmd_CloseCurrentOblivionGate_Execute = (_Cmd_Execute) 0x00515D20;
static const _Cmd_Execute Cmd_GetPCExpelled_Execute = (_Cmd_Execute) 0x00505480;
static const _Cmd_Execute Cmd_SetPCExpelled_Execute = (_Cmd_Execute) 0x0050BB70;
static const _Cmd_Execute Cmd_GetPCFactionMurder_Execute = (_Cmd_Execute) 0x005054E0;
static const _Cmd_Execute Cmd_SetPCFactionMurder_Execute = (_Cmd_Execute) 0x0050BD80;
static const _Cmd_Execute Cmd_GetPCFactionSteal_Execute = (_Cmd_Execute) 0x00505540;
static const _Cmd_Execute Cmd_SetPCFactionSteal_Execute = (_Cmd_Execute) 0x0050BE00;
static const _Cmd_Execute Cmd_GetPCFactionAttack_Execute = (_Cmd_Execute) 0x005055A0;
static const _Cmd_Execute Cmd_SetPCFactionAttack_Execute = (_Cmd_Execute) 0x0050BE80;
static const _Cmd_Execute Cmd_GetPCFactionSubmitAuthority_Execute = (_Cmd_Execute) 0x00505600;
static const _Cmd_Execute Cmd_SetPCFactionSubmitAuthority_Execute = (_Cmd_Execute) 0x0050BF00;
static const _Cmd_Execute Cmd_GetDestroyed_Execute = (_Cmd_Execute) 0x00505660;
static const _Cmd_Execute Cmd_SetDestroyed_Execute = (_Cmd_Execute) 0x00505680;
static const _Cmd_Execute Cmd_GetActionRef_Execute = (_Cmd_Execute) 0x0050BF80;
static const _Cmd_Execute Cmd_GetSelf_Execute = (_Cmd_Execute) 0x0050BFF0;
static const _Cmd_Execute Cmd_GetContainer_Execute = (_Cmd_Execute) 0x0050C160;
static const _Cmd_Execute Cmd_GetForceRun_Execute = (_Cmd_Execute) 0x0050C230;
static const _Cmd_Execute Cmd_SetForceRun_Execute = (_Cmd_Execute) 0x0050C290;
static const _Cmd_Execute Cmd_GetForceSneak_Execute = (_Cmd_Execute) 0x0050C330;
static const _Cmd_Execute Cmd_SetForceSneak_Execute = (_Cmd_Execute) 0x0050C390;
static const _Cmd_Execute Cmd_AdvancePCSkill_Execute = (_Cmd_Execute) 0x0050D020;
static const _Cmd_Execute Cmd_AdvancePCLevel_Execute = (_Cmd_Execute) 0x005056F0;
static const _Cmd_Execute Cmd_HasMagicEffect_Execute = (_Cmd_Execute) 0x00505710;
static const _Cmd_Execute Cmd_GetDoorDefaultOpen_Execute = (_Cmd_Execute) 0x005057D0;
static const _Cmd_Execute Cmd_SetDoorDefaultOpen_Execute = (_Cmd_Execute) 0x0050C430;
static const _Cmd_Execute Cmd_ShowClassMenu_Execute = (_Cmd_Execute) 0x00505810;
static const _Cmd_Execute Cmd_ShowRaceMenu_Execute = (_Cmd_Execute) 0x00505850;
static const _Cmd_Execute Cmd_ShowBirthSignMenu_Execute = (_Cmd_Execute) 0x00505870;
static const _Cmd_Execute Cmd_ShowNameMenu_Execute = (_Cmd_Execute) 0x00977C50;
static const _Cmd_Execute Cmd_SetOpenState_Execute = (_Cmd_Execute) 0x0050C560;
static const _Cmd_Execute Cmd_CloseOblivionGate_Execute = (_Cmd_Execute) 0x00515EF0;
static const _Cmd_Execute Cmd_IsSpellTarget_Execute = (_Cmd_Execute) 0x00505770;
static const _Cmd_Execute Cmd_GetIsPlayerBirthsign_Execute = (_Cmd_Execute) 0x005058D0;
static const _Cmd_Execute Cmd_GetPersuasionNumber_Execute = (_Cmd_Execute) 0x00505930;
static const _Cmd_Execute Cmd_VampireFeed_Execute = (_Cmd_Execute) 0x0050C620;
static const _Cmd_Execute Cmd_HasVampireFed_Execute = (_Cmd_Execute) 0x00505970;
static const _Cmd_Execute Cmd_GetIsClassDefault_Execute = (_Cmd_Execute) 0x00505990;
static const _Cmd_Execute Cmd_GetClassDefaultMatch_Execute = (_Cmd_Execute) 0x005059F0;
static const _Cmd_Execute Cmd_GetInCellParam_Execute = (_Cmd_Execute) 0x005030D0;
static const _Cmd_Execute Cmd_SetInChargen_Execute = (_Cmd_Execute) 0x005032D0;
static const _Cmd_Execute Cmd_GetCombatTarget_Execute = (_Cmd_Execute) 0x0050C070;
static const _Cmd_Execute Cmd_GetPackageTarget_Execute = (_Cmd_Execute) 0x0050C0F0;
static const _Cmd_Execute Cmd_ShowSpellMaking_Execute = (_Cmd_Execute) 0x00505890;
static const _Cmd_Execute Cmd_ShowEnchantment_Execute = (_Cmd_Execute) 0x005058B0;
static const _Cmd_Execute Cmd_SetGhost_Execute = (_Cmd_Execute) 0x00505A30;
static const _Cmd_Execute Cmd_GetIsGhost_Execute = (_Cmd_Execute) 0x00505A10;
static const _Cmd_Execute Cmd_EquipItem_Execute = (_Cmd_Execute) 0x005162B0;
static const _Cmd_Execute Cmd_UnequipItem_Execute = (_Cmd_Execute) 0x005164C0;
static const _Cmd_Execute Cmd_SetClass_Execute = (_Cmd_Execute) 0x0050C6E0;
static const _Cmd_Execute Cmd_SetUnconscious_Execute = (_Cmd_Execute) 0x00505AC0;
static const _Cmd_Execute Cmd_GetUnconscious_Execute = (_Cmd_Execute) 0x00505B50;
static const _Cmd_Execute Cmd_SetRestrained_Execute = (_Cmd_Execute) 0x00505B70;
static const _Cmd_Execute Cmd_GetRestrained_Execute = (_Cmd_Execute) 0x00505C00;
static const _Cmd_Execute Cmd_ForceFlee_Execute = (_Cmd_Execute) 0x0050C790;
static const _Cmd_Execute Cmd_GetIsUsedItem_Execute = (_Cmd_Execute) 0x00503650;
static const _Cmd_Execute Cmd_GetIsUsedItemType_Execute = (_Cmd_Execute) 0x005036B0;
static const _Cmd_Execute Cmd_ModPCFame_Execute = (_Cmd_Execute) 0x0050C980;
static const _Cmd_Execute Cmd_GetPCFame_Execute = (_Cmd_Execute) 0x00505C20;
static const _Cmd_Execute Cmd_ModPCInfamy_Execute = (_Cmd_Execute) 0x0050CA90;
static const _Cmd_Execute Cmd_GetPCInfamy_Execute = (_Cmd_Execute) 0x00505C40;
static const _Cmd_Execute Cmd_SetPCFame_Execute = (_Cmd_Execute) 0x0050CA10;
static const _Cmd_Execute Cmd_SetPCInfamy_Execute = (_Cmd_Execute) 0x0050CB20;
static const _Cmd_Execute Cmd_GetIsPlayableRace_Execute = (_Cmd_Execute) 0x005033F0;
static const _Cmd_Execute Cmd_GetOffersServicesNow_Execute = (_Cmd_Execute) 0x00505C60;
static const _Cmd_Execute Cmd_GetGameSetting_Execute = (_Cmd_Execute) 0x00513FC0;
static const _Cmd_Execute Cmd_StopCombatAlarmOnActor_Execute = (_Cmd_Execute) 0x00501D80;
static const _Cmd_Execute Cmd_GetUsedItemLevel_Execute = (_Cmd_Execute) 0x00503710;
static const _Cmd_Execute Cmd_GetUsedItemActivate_Execute = (_Cmd_Execute) 0x00503730;
static const _Cmd_Execute Cmd_SetWeather_Execute = (_Cmd_Execute) 0x00507AE0;
static const _Cmd_Execute Cmd_ForceTakeCover_Execute = (_Cmd_Execute) 0x0050C8D0;
static const _Cmd_Execute Cmd_ModBarterGold_Execute = (_Cmd_Execute) 0x00505C80;
static const _Cmd_Execute Cmd_SetBarterGold_Execute = (_Cmd_Execute) 0x0050CBC0;
static const _Cmd_Execute Cmd_GetBarterGold_Execute = (_Cmd_Execute) 0x00505D10;
static const _Cmd_Execute Cmd_IsTimePassing_Execute = (_Cmd_Execute) 0x00505D90;
static const _Cmd_Execute Cmd_IsPleasant_Execute = (_Cmd_Execute) 0x00502EB0;
static const _Cmd_Execute Cmd_IsCloudy_Execute = (_Cmd_Execute) 0x00502ED0;
static const _Cmd_Execute Cmd_TrapUpdate_Execute = (_Cmd_Execute) 0x00977C50;
static const _Cmd_Execute Cmd_SetQuestObject_Execute = (_Cmd_Execute) 0x005052D0;
static const _Cmd_Execute Cmd_ForceActorValue_Execute = (_Cmd_Execute) 0x00501890;
static const _Cmd_Execute Cmd_ModPCSkill_Execute = (_Cmd_Execute) 0x0050D020;
static const _Cmd_Execute Cmd_ModPCAttribute_Execute = (_Cmd_Execute) 0x0050D3E0;
static const _Cmd_Execute Cmd_EnableFastTravel_Execute = (_Cmd_Execute) 0x0050D460;
static const _Cmd_Execute Cmd_GetArmorRatingUpperBody_Execute = (_Cmd_Execute) 0x00505DB0;
static const _Cmd_Execute Cmd_GetParentRef_Execute = (_Cmd_Execute) 0x0050C1C0;
static const _Cmd_Execute Cmd_PlayBink_Execute = (_Cmd_Execute) 0x0050D4C0;
static const _Cmd_Execute Cmd_GetBaseActorValue_Execute = (_Cmd_Execute) 0x00501A00;
static const _Cmd_Execute Cmd_IsOwner_Execute = (_Cmd_Execute) 0x00500570;
static const _Cmd_Execute Cmd_SetOwnership_Execute = (_Cmd_Execute) 0x005075A0;
static const _Cmd_Execute Cmd_IsCellOwner_Execute = (_Cmd_Execute) 0x00505DD0;
static const _Cmd_Execute Cmd_SetCellOwnership_Execute = (_Cmd_Execute) 0x00505E60;
static const _Cmd_Execute Cmd_IsHorseStolen_Execute = (_Cmd_Execute) 0x00505EE0;
static const _Cmd_Execute Cmd_SetCellFullName_Execute = (_Cmd_Execute) 0x00512AE0;
static const _Cmd_Execute Cmd_SetActorFullName_Execute = (_Cmd_Execute) 0x00512BB0;
static const _Cmd_Execute Cmd_IsLeftUp_Execute = (_Cmd_Execute) 0x00504930;
static const _Cmd_Execute Cmd_IsSneaking_Execute = (_Cmd_Execute) 0x00505F20;
static const _Cmd_Execute Cmd_IsRunning_Execute = (_Cmd_Execute) 0x00505F40;
static const _Cmd_Execute Cmd_GetFriendHit_Execute = (_Cmd_Execute) 0x00505F60;
static const _Cmd_Execute Cmd_IsInCombat_Execute = (_Cmd_Execute) 0x00505FC0;
static const _Cmd_Execute Cmd_SetPackDuration_Execute = (_Cmd_Execute) 0x0050D5E0;
static const _Cmd_Execute Cmd_PlayMagicShaderVisuals_Execute = (_Cmd_Execute) 0x00505FE0;
static const _Cmd_Execute Cmd_PlayMagicEffectVisuals_Execute = (_Cmd_Execute) 0x00512CA0;
static const _Cmd_Execute Cmd_StopMagicShaderVisuals_Execute = (_Cmd_Execute) 0x005061B0;
static const _Cmd_Execute Cmd_StopMagicEffectVisuals_Execute = (_Cmd_Execute) 0x00512FA0;
static const _Cmd_Execute Cmd_ResetInterior_Execute = (_Cmd_Execute) 0x00506260;
static const _Cmd_Execute Cmd_IsAnimPlaying_Execute = (_Cmd_Execute) 0x00510A90;
static const _Cmd_Execute Cmd_SetActorAlpha_Execute = (_Cmd_Execute) 0x0050D680;
static const _Cmd_Execute Cmd_EnableLinkedPathPoints_Execute = (_Cmd_Execute) 0x005062B0;
static const _Cmd_Execute Cmd_DisableLinkedPathPoints_Execute = (_Cmd_Execute) 0x005062D0;
static const _Cmd_Execute Cmd_IsInInterior_Execute = (_Cmd_Execute) 0x005062F0;
static const _Cmd_Execute Cmd_ForceWeather_Execute = (_Cmd_Execute) 0x00500D90;
static const _Cmd_Execute Cmd_ToggleActorsAI_Execute = (_Cmd_Execute) 0x00501120;
static const _Cmd_Execute Cmd_IsActorsAIOff_Execute = (_Cmd_Execute) 0x00501180;
static const _Cmd_Execute Cmd_SetInvestmentGold_Execute = (_Cmd_Execute) 0x0050CC80;
static const _Cmd_Execute Cmd_GetInvestmentGold_Execute = (_Cmd_Execute) 0x00505D50;
static const _Cmd_Execute Cmd_IsActorUsingATorch_Execute = (_Cmd_Execute) 0x00505D70;
static const _Cmd_Execute Cmd_SetLevel_Execute = (_Cmd_Execute) 0x0050CD30;
static const _Cmd_Execute Cmd_ResetFallDamageTimer_Execute = (_Cmd_Execute) 0x0050CFB0;
static const _Cmd_Execute Cmd_IsXBox_Execute = (_Cmd_Execute) 0x00505D30;
static const _Cmd_Execute Cmd_GetInWorldspace_Execute = (_Cmd_Execute) 0x00503140;
static const _Cmd_Execute Cmd_ModPCMiscStat_Execute = (_Cmd_Execute) 0x0050D740;
static const _Cmd_Execute Cmd_GetPCMiscStat_Execute = (_Cmd_Execute) 0x00506310;
static const _Cmd_Execute Cmd_IsActorEvil_Execute = (_Cmd_Execute) 0x00506370;
static const _Cmd_Execute Cmd_IsActorAVictim_Execute = (_Cmd_Execute) 0x00506390;
static const _Cmd_Execute Cmd_GetTotalPersuasionNumber_Execute = (_Cmd_Execute) 0x00505950;
static const _Cmd_Execute Cmd_SetScale_Execute = (_Cmd_Execute) 0x005093B0;
static const _Cmd_Execute Cmd_ModScale_Execute = (_Cmd_Execute) 0x00501E40;
static const _Cmd_Execute Cmd_GetIdleDoneOnce_Execute = (_Cmd_Execute) 0x005063B0;
static const _Cmd_Execute Cmd_KillAllActors_Execute = (_Cmd_Execute) 0x00508700;
static const _Cmd_Execute Cmd_GetNoRumors_Execute = (_Cmd_Execute) 0x005063D0;
static const _Cmd_Execute Cmd_SetNoRumors_Execute = (_Cmd_Execute) 0x0050D7B0;
static const _Cmd_Execute Cmd_Dispel_Execute = (_Cmd_Execute) 0x00502140;
static const _Cmd_Execute Cmd_WhichServiceMenu_Execute = (_Cmd_Execute) 0x00506410;
static const _Cmd_Execute Cmd_TriggerHitShader_Execute = (_Cmd_Execute) 0x00506450;
static const _Cmd_Execute Cmd_RefreshTopicList_Execute = (_Cmd_Execute) 0x005064A0;
static const _Cmd_Execute Cmd_Reset3DState_Execute = (_Cmd_Execute) 0x0050E320;
static const _Cmd_Execute Cmd_IsRidingHorse_Execute = (_Cmd_Execute) 0x005064B0;
static const _Cmd_Execute Cmd_DispelAllSpells_Execute = (_Cmd_Execute) 0x005021E0;
static const _Cmd_Execute Cmd_IsTurnArrest_Execute = (_Cmd_Execute) 0x00506570;
static const _Cmd_Execute Cmd_AddAchievement_Execute = (_Cmd_Execute) 0x00977C50;
static const _Cmd_Execute Cmd_DuplicateAllItems_Execute = (_Cmd_Execute) 0x00507470;
static const _Cmd_Execute Cmd_IsInDangerousWater_Execute = (_Cmd_Execute) 0x00506530;
static const _Cmd_Execute Cmd_EssentialDeathReload_Execute = (_Cmd_Execute) 0x005071D0;
static const _Cmd_Execute Cmd_SetShowQuestItems_Execute = (_Cmd_Execute) 0x0050AA40;
static const _Cmd_Execute Cmd_DuplicateNPCStats_Execute = (_Cmd_Execute) 0x0050AAA0;
static const _Cmd_Execute Cmd_ResetHealth_Execute = (_Cmd_Execute) 0x005028F0;
static const _Cmd_Execute Cmd_SetIgnoreFriendlyHits_Execute = (_Cmd_Execute) 0x00506750;
static const _Cmd_Execute Cmd_GetIgnoreFriendlyHits_Execute = (_Cmd_Execute) 0x005067C0;
static const _Cmd_Execute Cmd_IsPlayersLastRiddenHorse_Execute = (_Cmd_Execute) 0x005064F0;
static const _Cmd_Execute Cmd_SetActorRefraction_Execute = (_Cmd_Execute) 0x0050E340;
static const _Cmd_Execute Cmd_SetItemValue_Execute = (_Cmd_Execute) 0x00506810;
static const _Cmd_Execute Cmd_SetRigidBodyMass_Execute = (_Cmd_Execute) 0x005131F0;
static const _Cmd_Execute Cmd_ShowViewerStrings_Execute = (_Cmd_Execute) 0x0050FF70;
static const _Cmd_Execute Cmd_ReleaseWeatherOverride_Execute = (_Cmd_Execute) 0x00507B90;
static const _Cmd_Execute Cmd_SetAllReachable_Execute = (_Cmd_Execute) 0x005012F0;
static const _Cmd_Execute Cmd_SetAllVisible_Execute = (_Cmd_Execute) 0x00501340;
static const _Cmd_Execute Cmd_SetNoAvoidance_Execute = (_Cmd_Execute) 0x00501390;
static const _Cmd_Execute Cmd_SendTrespassAlarm_Execute = (_Cmd_Execute) 0x00506AF0;
static const _Cmd_Execute Cmd_SetSceneIsComplex_Execute = (_Cmd_Execute) 0x0050E9D0;
static const _Cmd_Execute Cmd_Autosave_Execute = (_Cmd_Execute) 0x0050A3E0;
static const _Cmd_Execute Cmd_StartMasterFileSeekData_Execute = (_Cmd_Execute) 0x00977C50;
static const _Cmd_Execute Cmd_DumpMasterFileSeekData_Execute = (_Cmd_Execute) 0x00977C50;
static const _Cmd_Execute Cmd_IsActor_Execute = (_Cmd_Execute) 0x00506D00;
static const _Cmd_Execute Cmd_IsEssential_Execute = (_Cmd_Execute) 0x00506CC0;
static const _Cmd_Execute Cmd_PreloadMagicEffect_Execute = (_Cmd_Execute) 0x00513090;
static const _Cmd_Execute Cmd_ShowDialogSubtitles_Execute = (_Cmd_Execute) 0x005007D0;
static const _Cmd_Execute Cmd_ForceCloseOblivionGate_Execute = (_Cmd_Execute) 0x005160D0;
static const _Cmd_Execute Cmd_IsPlayerMovingIntoNewSpace_Execute = (_Cmd_Execute) 0x00506D40;
static const _Cmd_Execute Cmd_CreateFullActorCopy_Execute = (_Cmd_Execute) 0x00511570;
static const _Cmd_Execute Cmd_DeleteFullActorCopy_Execute = (_Cmd_Execute) 0x0050A340;
static const _Cmd_Execute Cmd_GetTimeDead_Execute = (_Cmd_Execute) 0x00506D80;
static const _Cmd_Execute Cmd_GetPlayerHasLastRiddenHorse_Execute = (_Cmd_Execute) 0x00505F00;
static const _Cmd_Execute Cmd_PurgeCellBuffers_Execute = (_Cmd_Execute) 0x00500C60;
static const _Cmd_Execute Cmd_SetPlayerInSEWorld_Execute = (_Cmd_Execute) 0x0050EA30;
static const _Cmd_Execute Cmd_GetPlayerInSEWorld_Execute = (_Cmd_Execute) 0x00506DC0;
static const _Cmd_Execute Cmd_PushActorAway_Execute = (_Cmd_Execute) 0x0050EAB0;
static const _Cmd_Execute Cmd_SetActorsAI_Execute = (_Cmd_Execute) 0x00506DE0;
static const _Cmd_Execute Cmd_ClearOwnership_Execute = (_Cmd_Execute) 0x00507620;
static ParamInfo kParams_CmdShow[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdShowQuestVars[1] = {
	{ "Quest", kParamType_Quest, 0 }
};
static ParamInfo kParams_CmdToggleAI[1] = {
	{ "Actor (optional)", kParamType_Actor, 1 }
};
static ParamInfo kParams_CmdPickRefByID[1] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdSetLightingPasses[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdCenterOnCell[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdSetGameSetting[2] = {
	{ "String", kParamType_String, 0 },
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdSetINISetting[2] = {
	{ "String", kParamType_String, 0 },
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetINISetting[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdCenterOnExterior[2] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdCalcLowPathToPoint[3] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetFog[2] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetClipDist[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdSetImageSpaceGlow[4] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdSpeakSound[3] = {
	{ "Filename", kParamType_String, 0 },
	{ "Emotion", kParamType_Integer, 1 },
	{ "EmotionValue", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdBetaComment[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdToggleCellNode[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetCameraFOV[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdShowQuestLog[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdShowFullQuestLog[1] = {
	{ "Quest", kParamType_Quest, 0 }
};
static ParamInfo kParams_CmdDumpTexturePalette[1] = {
	{ "String", kParamType_String, 1 }
};
static ParamInfo kParams_CmdCenterOnWorld[3] = {
	{ "WorldSpace", kParamType_WorldSpace, 0 },
	{ "Cell X", kParamType_Integer, 0 },
	{ "Cell Y", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdAddFaceAnimNote[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdToggleMapMarkers[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdHairTint[3] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSaveGame[2] = {
	{ "String", kParamType_String, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdLoadGame[2] = {
	{ "String", kParamType_String, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdTestAllCells[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSaveWorld[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdTestLocalMap[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMoveToQuestTarget[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdShowSubtitle[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdOutputMemContexts[1] = {
	{ "String", kParamType_String, 1 }
};
static ParamInfo kParams_CmdOutputMemStats[1] = {
	{ "String", kParamType_String, 1 }
};
static ParamInfo kParams_CmdToggleDetectionStats[1] = {
	{ "Actor (optional)", kParamType_Actor, 1 }
};
static ParamInfo kParams_CmdSetTargetRefraction[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdSetTargetRefractionFire[2] = {
	{ "Float", kParamType_Float, 0 },
	{ "Int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetSkyParam[2] = {
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdSetHDRParam[6] = {
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdOutputArchiveProfile[1] = {
	{ "String", kParamType_String, 1 }
};
static ParamInfo kParams_CmdSetDebugText[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdRunMemoryPass[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModWaterShader[2] = {
	{ "String", kParamType_String, 0 },
	{ "Float(optional)", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdWaterShallowColor[3] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdWaterDeepColor[3] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdWaterReflectionColor[3] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdRunCellTest[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdFlushNonPersistActors[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetGamma[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdWasteMemory[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdToggleCastShadows[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetSTBBColorConstants[4] = {
	{ "Float (Optional)", kParamType_Float, 1 },
	{ "Float (Optional)", kParamType_Float, 1 },
	{ "Float (Optional)", kParamType_Float, 1 },
	{ "Float (Optional)", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdCloseFile[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdSetTreeMipmapBias[2] = {
	{ "Float (Optional)", kParamType_Float, 1 },
	{ "Float (Optional)", kParamType_Float, 1 }
};

static ParamInfo kParams_CmdMessageBox[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetDistance[1] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdAddItem[2] = {
	{ "ObjectID", kParamType_InventoryObject, 0 },
	{ "Count", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetEssential[2] = {
	{ "Actor Base", kParamType_ActorBase, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdRotate[2] = {
	{ "Axis", kParamType_Axis, 0 },
	{ "Speed", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetPos[1] = {
	{ "Axis", kParamType_Axis, 0 }
};
static ParamInfo kParams_CmdSetPos[2] = {
	{ "Axis", kParamType_Axis, 0 },
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdGetAngle[1] = {
	{ "Axis", kParamType_Axis, 0 }
};
static ParamInfo kParams_CmdSetAngle[2] = {
	{ "Axis", kParamType_Axis, 0 },
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdGetStartingPos[1] = {
	{ "Axis", kParamType_Axis, 0 }
};
static ParamInfo kParams_CmdGetStartingAngle[1] = {
	{ "Axis", kParamType_Axis, 0 }
};
static ParamInfo kParams_CmdActivate[2] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 1 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetActorValue[1] = {
	{ "Actor Value", kParamType_ActorValue, 0 }
};
static ParamInfo kParams_CmdSetActorValue[2] = {
	{ "Actor Value", kParamType_ActorValue, 0 },
	{ "Amount", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModActorValue[2] = {
	{ "Actor Value", kParamType_ActorValue, 0 },
	{ "Amount", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdPlayGroup[2] = {
	{ "Animation Group", kParamType_AnimationGroup, 0 },
	{ "Flags", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdLoopGroup[3] = {
	{ "Animation Group", kParamType_AnimationGroup, 0 },
	{ "Integer", kParamType_Integer, 0 },
	{ "Flags", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdStartCombat[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdGetLineOfSight[1] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdAddSpell[1] = {
	{ "Spell Item", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdRemoveSpell[1] = {
	{ "Spell Item", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdCast[2] = {
	{ "Magic Item", kParamType_MagicItem, 0 },
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdGetInSameCell[1] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdMenuMode[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdPlaceAtMe[4] = {
	{ "ObjectID", kParamType_TESObject, 0 },
	{ "Count", kParamType_Integer, 1 },
	{ "Distance", kParamType_Integer, 1 },
	{ "Direction", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdPlaySound[1] = {
	{ "Sound", kParamType_Sound, 0 }
};
static ParamInfo kParams_CmdSameFaction[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdSameRace[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdSameSex[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdGetDetected[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdGetItemCount[1] = {
	{ "ObjectID", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdSay[5] = {
	{ "Topic", kParamType_Topic, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 },
	{ "NPC (Optional)", kParamType_NPC, 1 },
	{ "Integer (Optional)", kParamType_Integer, 1 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSayTo[3] = {
	{ "Actor", kParamType_Actor, 0 },
	{ "Topic", kParamType_Topic, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetScriptVariable[2] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 },
	{ "Variable Name", kParamType_VariableName, 0 }
};
static ParamInfo kParams_CmdStartQuest[1] = {
	{ "Quest", kParamType_Quest, 0 }
};
static ParamInfo kParams_CmdStopQuest[1] = {
	{ "Quest", kParamType_Quest, 0 }
};
static ParamInfo kParams_CmdGetQuestRunning[1] = {
	{ "Quest", kParamType_Quest, 0 }
};
static ParamInfo kParams_CmdSetStage[2] = {
	{ "Quest", kParamType_Quest, 0 },
	{ "Stage", kParamType_QuestStage, 0 }
};
static ParamInfo kParams_CmdGetStage[1] = {
	{ "Quest", kParamType_Quest, 0 }
};
static ParamInfo kParams_CmdGetStageDone[2] = {
	{ "Quest", kParamType_Quest, 0 },
	{ "Stage", kParamType_QuestStage, 0 }
};
static ParamInfo kParams_CmdGetFactionRankDifference[2] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdGetShouldAttack[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdGetInCell[1] = {
	{ "Cell", kParamType_Cell, 0 }
};
static ParamInfo kParams_CmdGetIsClass[1] = {
	{ "Class", kParamType_Class, 0 }
};
static ParamInfo kParams_CmdGetIsRace[1] = {
	{ "Race", kParamType_Race, 0 }
};
static ParamInfo kParams_CmdGetIsSex[1] = {
	{ "Sex", kParamType_Sex, 0 }
};
static ParamInfo kParams_CmdGetInFaction[1] = {
	{ "Faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdGetIsID[1] = {
	{ "ObjectID", kParamType_TESObject, 0 }
};
static ParamInfo kParams_CmdGetFactionRank[1] = {
	{ "Faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdGetGlobalValue[1] = {
	{ "Global", kParamType_Global, 0 }
};
static ParamInfo kParams_CmdGetDisposition[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdStreamMusic[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetQuestVariable[2] = {
	{ "Quest", kParamType_Quest, 0 },
	{ "Variable Name", kParamType_VariableName, 0 }
};
static ParamInfo kParams_CmdRemoveItem[2] = {
	{ "ObjectID", kParamType_InventoryObject, 0 },
	{ "Count", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModDisposition[2] = {
	{ "Actor", kParamType_Actor, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetDeadCount[1] = {
	{ "Actor Base", kParamType_ActorBase, 0 }
};
static ParamInfo kParams_CmdShowMap[2] = {
	{ "Map Marker", kParamType_MapMarker, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdStartConversation[2] = {
	{ "Actor", kParamType_Actor, 0 },
	{ "Topic", kParamType_Topic, 1 }
};
static ParamInfo kParams_CmdDrop[2] = {
	{ "ObjectID", kParamType_InventoryObject, 0 },
	{ "Count", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdAddTopic[1] = {
	{ "Topic", kParamType_Topic, 0 }
};
static ParamInfo kParams_CmdMessage[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdSetAlert[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdLook[1] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdGetHeadingAngle[1] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdIsActionRef[1] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdCompleteQuest[1] = {
	{ "Quest", kParamType_Quest, 0 }
};
static ParamInfo kParams_CmdLock[2] = {
	{ "Integer (Optional)", kParamType_Integer, 1 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdUnLock[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetCrimeGold[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModCrimeGold[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetCrimeKnown[3] = {
	{ "Crime Type", kParamType_CrimeType, 0 },
	{ "Criminal", kParamType_Actor, 0 },
	{ "Victim", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdPositionWorld[5] = {
	{ "X", kParamType_Float, 0 },
	{ "Y", kParamType_Float, 0 },
	{ "Z", kParamType_Float, 0 },
	{ "Rotation", kParamType_Float, 0 },
	{ "Worldspace", kParamType_WorldSpace, 0 }
};
static ParamInfo kParams_CmdPositionCell[5] = {
	{ "X", kParamType_Float, 0 },
	{ "Y", kParamType_Float, 0 },
	{ "Z", kParamType_Float, 0 },
	{ "Rotation", kParamType_Float, 0 },
	{ "Interior Cell", kParamType_Cell, 0 }
};
static ParamInfo kParams_CmdGetCrime[2] = {
	{ "Actor", kParamType_Actor, 0 },
	{ "Crime Type (optional)", kParamType_CrimeType, 1 }
};
static ParamInfo kParams_CmdGetPCIsClass[1] = {
	{ "Class", kParamType_Class, 0 }
};
static ParamInfo kParams_CmdGetPCIsRace[1] = {
	{ "Race", kParamType_Race, 0 }
};
static ParamInfo kParams_CmdGetPCIsSex[1] = {
	{ "Sex", kParamType_Sex, 0 }
};
static ParamInfo kParams_CmdGetPCInFaction[1] = {
	{ "Faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdGetIsReference[1] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdSetFactionRank[2] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModFactionRank[2] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdKillActor[1] = {
	{ "Actor (optional)", kParamType_Actor, 1 }
};
static ParamInfo kParams_CmdResurrectActor[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetIsCurrentWeather[1] = {
	{ "Weather ID", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdAddScriptPackage[1] = {
	{ "Package", kParamType_AIPackage, 0 }
};
static ParamInfo kParams_CmdMoveToMarker[4] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 },
	{ "Float (Optional)", kParamType_Float, 1 },
	{ "Float (Optional)", kParamType_Float, 1 },
	{ "Float (Optional)", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdGetIsCurrentPackage[1] = {
	{ "Package", kParamType_AIPackage, 0 }
};
static ParamInfo kParams_CmdIsCurrentFurnitureRef[1] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdIsCurrentFurnitureObj[1] = {
	{ "Furniture", kParamType_Furniture, 0 }
};
static ParamInfo kParams_CmdSetSize[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdRemoveMe[1] = {
	{ "Container (optional)", kParamType_Container, 1 }
};
static ParamInfo kParams_CmdGetFactionReaction[2] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdSetFactionReaction[3] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Faction", kParamType_Faction, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModFactionReaction[3] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Faction", kParamType_Faction, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetTalkedToPCParam[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdRemoveAllItems[2] = {
	{ "Container (optional)", kParamType_Container, 1 },
	{ "Ownership Added (optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdWakeUpPC[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetCombatStyle[1] = {
	{ "Combat Style (optional)", kParamType_CombatStyle, 1 }
};
static ParamInfo kParams_CmdPlaySound3D[1] = {
	{ "Sound", kParamType_Sound, 0 }
};
static ParamInfo kParams_CmdSelectPlayerSpell[1] = {
	{ "Spell Item", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdGetDetectionLevel[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdGetEquipped[1] = {
	{ "ObjectID", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdWait[1] = {
	{ "Package", kParamType_AIPackage, 0 }
};
static ParamInfo kParams_CmdStopWaiting[1] = {
	{ "Package", kParamType_AIPackage, 0 }
};
static ParamInfo kParams_CmdSetCellPublicFlag[2] = {
	{ "Cell", kParamType_Cell, 0 },
	{ "Flag", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetPCSleepHours[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModAmountSoldStolen[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdCloseCurrentOblivionGate[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetPCExpelled[1] = {
	{ "Faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdSetPCExpelled[2] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetPCFactionMurder[1] = {
	{ "Faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdSetPCFactionMurder[2] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetPCFactionSteal[1] = {
	{ "Faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdSetPCFactionSteal[2] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetPCFactionAttack[1] = {
	{ "Faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdSetPCFactionAttack[2] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetPCFactionSubmitAuthority[1] = {
	{ "Faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdSetPCFactionSubmitAuthority[2] = {
	{ "Faction", kParamType_Faction, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetDestroyed[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetForceRun[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetForceSneak[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdAdvancePCSkill[2] = {
	{ "Actor Value", kParamType_ActorValue, 0 },
	{ "Amount", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdHasMagicEffect[1] = {
	{ "Magic Effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdSetDoorDefaultOpen[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetOpenState[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdCloseOblivionGate[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdIsSpellTarget[1] = {
	{ "Magic Item", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdGetIsPlayerBirthsign[1] = {
	{ "Birthsign", kParamType_Birthsign, 0 }
};
static ParamInfo kParams_CmdVampireFeed[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdGetIsClassDefault[1] = {
	{ "Class", kParamType_Class, 0 }
};
static ParamInfo kParams_CmdGetInCellParam[2] = {
	{ "Cell", kParamType_Cell, 0 },
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdSetInChargen[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetGhost[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdEquipItem[2] = {
	{ "ObjectID", kParamType_InventoryObject, 0 },
	{ "Flag", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdUnequipItem[2] = {
	{ "ObjectID", kParamType_InventoryObject, 0 },
	{ "Flag", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetClass[1] = {
	{ "Class", kParamType_Class, 0 }
};
static ParamInfo kParams_CmdSetUnconscious[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetRestrained[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdForceFlee[2] = {
	{ "Cell (optional)", kParamType_Cell, 1 },
	{ "ObjectReferenceID (optional)", kParamType_ObjectRef, 1 }
};
static ParamInfo kParams_CmdGetIsUsedItem[1] = {
	{ "ObjectID", kParamType_TESObject, 0 }
};
static ParamInfo kParams_CmdGetIsUsedItemType[1] = {
	{ "Form Type", kParamType_FormType, 0 }
};
static ParamInfo kParams_CmdModPCFame[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModPCInfamy[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetPCFame[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetPCInfamy[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetGameSetting[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdSetWeather[2] = {
	{ "Weather ID", kParamType_WeatherID, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdForceTakeCover[2] = {
	{ "Actor", kParamType_Actor, 0 },
	{ "Value", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModBarterGold[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetBarterGold[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetQuestObject[2] = {
	{ "Object", kParamType_TESObject, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdForceActorValue[2] = {
	{ "Actor Value", kParamType_ActorValue, 0 },
	{ "Amount", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModPCSkill[2] = {
	{ "Actor Value", kParamType_ActorValue, 0 },
	{ "Amount", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModPCAttribute[2] = {
	{ "Actor Value", kParamType_ActorValue, 0 },
	{ "Amount", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdEnableFastTravel[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdPlayBink[2] = {
	{ "String", kParamType_String, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetBaseActorValue[1] = {
	{ "Actor Value", kParamType_ActorValue, 0 }
};
static ParamInfo kParams_CmdIsOwner[1] = {
	{ "Owner(optional)", kParamType_Owner, 1 }
};
static ParamInfo kParams_CmdSetOwnership[1] = {
	{ "Owner(optional)", kParamType_Owner, 1 }
};
static ParamInfo kParams_CmdIsCellOwner[2] = {
	{ "Cell", kParamType_Cell, 0 },
	{ "Owner(optional)", kParamType_Owner, 1 }
};
static ParamInfo kParams_CmdSetCellOwnership[2] = {
	{ "Cell", kParamType_Cell, 0 },
	{ "Owner(optional)", kParamType_Owner, 1 }
};
static ParamInfo kParams_CmdSetCellFullName[2] = {
	{ "Cell", kParamType_Cell, 0 },
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdSetActorFullName[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetFriendHit[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdSetPackDuration[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdPlayMagicShaderVisuals[2] = {
	{ "Effect Shader ID", kParamType_EffectShader, 0 },
	{ "Time(optional)", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdPlayMagicEffectVisuals[2] = {
	{ "Magic Effect", kParamType_MagicEffect, 0 },
	{ "Time(optional)", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdStopMagicShaderVisuals[1] = {
	{ "Effect Shader ID", kParamType_EffectShader, 0 }
};
static ParamInfo kParams_CmdStopMagicEffectVisuals[1] = {
	{ "Magic Effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdResetInterior[1] = {
	{ "Cell", kParamType_Cell, 0 }
};
static ParamInfo kParams_CmdSetActorAlpha[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdForceWeather[2] = {
	{ "Weather ID", kParamType_WeatherID, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetInvestmentGold[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetLevel[4] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 },
	{ "Integer (Optional)", kParamType_Integer, 1 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetInWorldspace[1] = {
	{ "WorldSpace", kParamType_WorldSpace, 0 }
};
static ParamInfo kParams_CmdModPCMiscStat[2] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetPCMiscStat[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetScale[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdModScale[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdKillAllActors[1] = {
	{ "Actor (optional)", kParamType_Actor, 1 }
};
static ParamInfo kParams_CmdSetNoRumors[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdDispel[1] = {
	{ "Magic Item", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdTriggerHitShader[1] = {
	{ "Float (Optional)", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdAddAchievement[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdDuplicateAllItems[2] = {
	{ "Container (optional)", kParamType_Container, 1 },
	{ "Ownership Added (optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdEssentialDeathReload[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_CmdSetShowQuestItems[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdDuplicateNPCStats[1] = {
	{ "Actor (optional)", kParamType_Actor, 1 }
};
static ParamInfo kParams_CmdSetIgnoreFriendlyHits[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetActorRefraction[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdSetItemValue[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetRigidBodyMass[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdSetAllReachable[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetAllVisible[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetNoAvoidance[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSendTrespassAlarm[1] = {
	{ "Actor", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdSetSceneIsComplex[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdPreloadMagicEffect[1] = {
	{ "Magic Effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdShowDialogSubtitles[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdForceCloseOblivionGate[1] = {
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetPlayerInSEWorld[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdPushActorAway[2] = {
	{ "ObjectReferenceID", kParamType_ObjectRef, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetActorsAI[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdtestargcommand[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetInventoryItemType[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsKeyPressed[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetEquipmentSlotType[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdPrintToConsole[21] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdSetActiveSpell[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdSquareRoot[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdrSin[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdrCos[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdrTan[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdrASin[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdrACos[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdrATan[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdLog[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdExp[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdLog10[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdFloor[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdCeil[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdAbs[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdRand[2] = {
	{ "float", kParamType_Float, 0 },
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdPow[2] = {
	{ "float", kParamType_Float, 0 },
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdrATan2[2] = {
	{ "float", kParamType_Float, 0 },
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdrSinh[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdrCosh[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdrTanh[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdSin[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdCos[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdTan[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdASin[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdACos[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdATan[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdATan2[2] = {
	{ "float", kParamType_Float, 0 },
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdSinh[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdCosh[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdTanh[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdGetInventoryObject[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetEquippedObject[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsKeyPressed2[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdTapKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdHoldKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdReleaseKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdHammerKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdAHammerKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdUnhammerKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdDisableKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdEnableKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMoveMouseX[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMoveMouseY[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetMouseSpeedX[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdSetMouseSpeedY[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_Cmdcon_SetGameSetting[2] = {
	{ "String", kParamType_String, 0 },
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_Cmdcon_SetINISetting[2] = {
	{ "String", kParamType_String, 0 },
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_Cmdcon_GetINISetting[1] = {
	{ "String", kParamType_String, 0 }
};
static ParamInfo kParams_Cmdcon_SetFog[2] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdcon_SetClipDist[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_Cmdcon_SetImageSpaceGlow[4] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_Cmdcon_SetCameraFOV[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdcon_HairTint[3] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdcon_SetTargetRefraction[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_Cmdcon_SetTargetRefractionFire[2] = {
	{ "Float", kParamType_Float, 0 },
	{ "Int", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdcon_SetSkyParam[2] = {
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_Cmdcon_RunMemoryPass[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdcon_ModWaterShader[2] = {
	{ "String", kParamType_String, 0 },
	{ "Float(optional)", kParamType_Float, 1 }
};
static ParamInfo kParams_Cmdcon_WaterShallowColor[3] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdcon_WaterDeepColor[3] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdcon_WaterReflectionColor[3] = {
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 },
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdcon_SetGamma[1] = {
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_Cmdcon_SetHDRParam[6] = {
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 },
	{ "Float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdGetCurrentValue[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetObjectValue[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetObjectType[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsWeapon[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsAmmo[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsArmor[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsClothing[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsBook[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsIngredient[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsContainer[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsKey[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsAlchemyItem[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsApparatus[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsSoulGem[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsSigilStone[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsDoor[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsActivator[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsLight[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsFurniture[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdHasSpell[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdIsClassSkill[2] = {
	{ "skill", kParamType_ActorValue, 0 },
	{ "class", kParamType_Class, 1 }
};
static ParamInfo kParams_CmdGetClassAttribute[2] = {
	{ "index", kParamType_Integer, 0 },
	{ "class", kParamType_Class, 1 }
};
static ParamInfo kParams_CmdGetClassSkill[2] = {
	{ "index", kParamType_Integer, 0 },
	{ "class", kParamType_Class, 1 }
};
static ParamInfo kParams_CmdGetClassSpecialization[1] = {
	{ "class", kParamType_Class, 1 }
};
static ParamInfo kParams_CmdModActorValue2[2] = {
	{ "actor value", kParamType_ActorValue, 0 },
	{ "amount", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetNumericGameSetting[2] = {
	{ "string", kParamType_String, 0 },
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdGetControl[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetAltControl[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetKeyPress[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetEquippedCurrentValue[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "slot", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetEquippedObjectValue[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "slot", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetMagicItemValue[3] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetMagicEffectValue[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectCodeValue[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "effect code", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicItemHasEffect[3] = {
	{ "effect code", kParamType_MagicEffect, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdMagicItemHasEffectCode[3] = {
	{ "effect code", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "actor value", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetMouseButtonPress[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetRefEssential[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetWeight[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetWeight[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModWeight[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetGoldValue[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetGoldValue[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModGoldValue[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetObjectHealth[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetObjectHealth[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModObjectHealth[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetEquipmentSlot[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetEquipmentSlot[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetObjectCharge[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetObjectCharge[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModObjectCharge[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsQuestItem[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetQuestItem[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetEnchantment[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetEnchantment[2] = {
	{ "value", kParamType_MagicItem, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdRemoveEnchantment[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetAttackDamage[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetAttackDamage[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModAttackDamage[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetWeaponReach[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetWeaponReach[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModWeaponReach[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetWeaponSpeed[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetWeaponSpeed[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModWeaponSpeed[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetWeaponType[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetWeaponType[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetIgnoresResistance[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetIgnoresResistance[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetArmorAR[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetArmorAR[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModArmorAR[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetArmorType[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetArmorType[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetSoulLevel[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetSoulGemCapacity[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsFood[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetIsFood[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsPoison[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetName[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetModelPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetIconPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetMaleBipedPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetFemaleBipedPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetMaleGroundPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetFemaleGroundPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetMaleIconPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetFemaleIconPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetEquippedCurrentHealth[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetEquippedCurrentHealth[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "slot", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModEquippedCurrentHealth[2] = {
	{ "value", kParamType_Float, 0 },
	{ "slot", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetEquippedCurrentCharge[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetEquippedCurrentCharge[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "slot", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModEquippedCurrentCharge[2] = {
	{ "value", kParamType_Float, 0 },
	{ "slot", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetEquippedWeaponPoison[1] = {
	{ "poison", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdCloneForm[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsClonedForm[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetNumericINISetting[2] = {
	{ "string", kParamType_String, 0 },
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdGetMagicItemType[1] = {
	{ "spell", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdGetMagicItemEffectCount[1] = {
	{ "spell", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdGetNthEffectItemCode[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNthEffectItemMagnitude[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNthEffectItemArea[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNthEffectItemDuration[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNthEffectItemRange[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNthEffectItemActorValue[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetSpellType[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdGetSpellMagickaCost[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdGetSpellMasteryLevel[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdGetEnchantmentType[1] = {
	{ "spell", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdGetEnchantmentCharge[1] = {
	{ "spell", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdGetEnchantmentCost[1] = {
	{ "spell", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectCode[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectBaseCost[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectSchool[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectProjectileSpeed[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectEnchantFactor[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectBarterFactor[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectBaseCostC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectSchoolC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectProjectileSpeedC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectEnchantFactorC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectBarterFactorC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetNthEffectItemMagnitude[3] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdModNthEffectItemMagnitude[3] = {
	{ "value", kParamType_Float, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemArea[3] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdModNthEffectItemArea[3] = {
	{ "value", kParamType_Float, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemDuration[3] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdModNthEffectItemDuration[3] = {
	{ "value", kParamType_Float, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemRange[3] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemActorValue[3] = {
	{ "value", kParamType_ActorValue, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemActorValueC[3] = {
	{ "actor value code", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdRemoveNthEffectItem[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetSpellType[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdSetSpellMagickaCost[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdModSpellMagickaCost[2] = {
	{ "value", kParamType_Float, 0 },
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdSetSpellMasteryLevel[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdSetEnchantmentCharge[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdModEnchantmentCharge[2] = {
	{ "value", kParamType_Float, 0 },
	{ "magic item", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdSetEnchantmentCost[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdModEnchantmentCost[2] = {
	{ "value", kParamType_Float, 0 },
	{ "magic item", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdSetEnchantmentType[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 }
};
/*static ParamInfo kParams_CmdSetNumericINISetting[2] = {
	{ "string", kParamType_String, 0 },
	{ "float", kParamType_Float, 0 }
};*/
static ParamInfo kParams_CmdGetNumericINISetting[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectHostile[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectHostileC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSaveIP[1] = {
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdRestoreIP[1] = {
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdCopyNthEffectItem[3] = {
	{ "from Magic Item", kParamType_MagicItem, 0 },
	{ "toMagicItem", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdCopyAllEffectItems[2] = {
	{ "from Magic Item", kParamType_MagicItem, 0 },
	{ "toMagicItem", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdAddEffectItem[2] = {
	{ "effect", kParamType_MagicEffect, 0 },
	{ "toMagicItem", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdAddEffectItemC[2] = {
	{ "effect code", kParamType_Integer, 0 },
	{ "toMagicItem", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdIsMagicItemAutoCalc[1] = {
	{ "spell", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdSetMagicItemAutoCalc[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectForSpellmaking[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectForSpellmakingC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectForEnchanting[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectForEnchantingC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectDetrmimental[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectDetrimentalC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectCanRecover[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectCanRecoverC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectMagnitudePercent[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectMagnitudePercentC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectFXPersists[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectFXPersistsC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectOnSelfAllowed[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectOnSelfAllowedC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectOnTouchAllowed[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectOnTouchAllowedC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectOnTargetAllowed[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdIsMagicEffectOnTargetAllowedC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectHasNoDuration[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectHasNoDurationC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectHasNoMagnitude[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectHasNoMagnitudeC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectHasNoArea[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectHasNoAreaC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectHasNoIngredient[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectHasNoIngredientC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectHasNoHitEffect[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectHasNoHitEffectC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesWeapon[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesWeaponC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesArmor[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesArmorC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesCreature[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesCreatureC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesSkill[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesSkillC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesAttribute[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesAttributeC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesOtherActorValue[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdMagicEffectUsesOtherActorValueC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectOtherActorValue[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectOtherActorValueC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectUsedObject[1] = {
	{ "magic effect", kParamType_MagicEffect, 0 }
};
static ParamInfo kParams_CmdGetMagicEffectUsedObjectC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsCreature[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetCreatureType[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetCreatureCombatSkill[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetCreatureMagicSkill[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetCreatureStealthSkill[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetBookCantBeTaken[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetBookIsScroll[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetBookSkillTaught[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetBookCantBeTaken[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetBookIsScroll[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetBookSkillTaught[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetApparatusType[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetApparatusType[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetQuality[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetQuality[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModQuality[2] = {
	{ "value", kParamType_Float, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetSoulLevel[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetSoulGemCapacity[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModModelPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModIconPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModMaleBipedPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModFemaleBipedPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModMaleGroundPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModFemaleGroundPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModMaleIconPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdModFemaleIconPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCompareModelPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCompareIconPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCompareMaleBipedPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCompareFemaleBipedPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCompareMaleGroundPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCompareFemaleGroundPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCompareMaleIconPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCompareFemaleIconPath[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetNthPlayerSpell[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdCopyModelPath[2] = {
	{ "src", kParamType_InventoryObject, 0 },
	{ "dest", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCopyIconPath[2] = {
	{ "src", kParamType_InventoryObject, 0 },
	{ "dest", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCopyMaleBipedPath[2] = {
	{ "src", kParamType_InventoryObject, 0 },
	{ "dest", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCopyFemaleBipedPath[2] = {
	{ "src", kParamType_InventoryObject, 0 },
	{ "dest", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCopyMaleGroundPath[2] = {
	{ "src", kParamType_InventoryObject, 0 },
	{ "dest", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCopyFemaleGroundPath[2] = {
	{ "src", kParamType_InventoryObject, 0 },
	{ "dest", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCopyMaleIconPath[2] = {
	{ "src", kParamType_InventoryObject, 0 },
	{ "dest", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCopyFemaleIconPath[2] = {
	{ "src", kParamType_InventoryObject, 0 },
	{ "dest", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_Cmdcon_Save[2] = {
	{ "String", kParamType_String, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_Cmdcon_ToggleAI[1] = {
	{ "Actor (optional)", kParamType_Actor, 1 }
};
static ParamInfo kParams_CmdIsScripted[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdCompareName[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdMenuTapKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMenuHoldKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMenuReleaseKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetEquipmentSlotMask[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int (optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdLeftShift[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdRightShift[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdLogicalAnd[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdLogicalOr[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdLogicalXor[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdLogicalNot[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetSpellSchool[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdIsNthEffectItemScripted[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNthEffectItemScript[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNthEffectItemScriptVisualEffect[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNthEffectItemScriptSchool[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdIsNthEffectItemScriptHostile[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemScriptVisualEffect[3] = {
	{ "effect", kParamType_MagicEffect, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemScriptVisualEffectC[3] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemScriptSchool[3] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemScriptHostile[3] = {
	{ "value", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_Cmdfmod[3] = {
	{ "x", kParamType_Float, 0 },
	{ "n", kParamType_Float, 0 },
	{ "offset", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdCopyName[2] = {
	{ "src", kParamType_InventoryObject, 0 },
	{ "dest", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetDisableGlobalCollision[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdAddFullEffectItem[6] = {
	{ "effect", kParamType_MagicEffect, 0 },
	{ "magnitude", kParamType_Integer, 0 },
	{ "area", kParamType_Integer, 0 },
	{ "duration", kParamType_Integer, 0 },
	{ "range", kParamType_Integer, 0 },
	{ "toMagicItem", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdAddFullEffectItemC[6] = {
	{ "effect code", kParamType_Integer, 0 },
	{ "magnitude", kParamType_Integer, 0 },
	{ "area", kParamType_Integer, 0 },
	{ "duration", kParamType_Integer, 0 },
	{ "range", kParamType_Integer, 0 },
	{ "toMagicItem", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdGetPlayerSkillUse[1] = {
	{ "actor value", kParamType_ActorValue, 0 }
};
static ParamInfo kParams_CmdRunBatchScript[1] = {
	{ "filename", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetSkillUseIncrement[2] = {
	{ "skill", kParamType_ActorValue, 0 },
	{ "index", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetSkillUseIncrement[3] = {
	{ "nuVal", kParamType_Float, 0 },
	{ "skill", kParamType_ActorValue, 0 },
	{ "index", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdIncrementPlayerSkillUse[3] = {
	{ "skill", kParamType_ActorValue, 0 },
	{ "index", kParamType_Integer, 1 },
	{ "howManyTimes", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdIsClassAttribute[2] = {
	{ "skill", kParamType_ActorValue, 0 },
	{ "class", kParamType_Class, 1 }
};
static ParamInfo kParams_CmdModName[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdAppendToName[2] = {
	{ "value", kParamType_String, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetRaceAttribute[2] = {
	{ "attribute", kParamType_ActorValue, 0 },
	{ "race", kParamType_Race, 1 }
};
static ParamInfo kParams_CmdGetRaceAttributeC[2] = {
	{ "which", kParamType_Integer, 0 },
	{ "race", kParamType_Race, 1 }
};
static ParamInfo kParams_CmdGetRaceSkillBonus[2] = {
	{ "attribute", kParamType_ActorValue, 0 },
	{ "race", kParamType_Race, 1 }
};
static ParamInfo kParams_CmdIsRaceBonusSkillC[2] = {
	{ "attribute", kParamType_Integer, 0 },
	{ "race", kParamType_Race, 1 }
};
static ParamInfo kParams_CmdIsRaceBonusSkill[2] = {
	{ "attribute", kParamType_ActorValue, 0 },
	{ "race", kParamType_Race, 1 }
};
static ParamInfo kParams_CmdGetRaceSkillBonusC[2] = {
	{ "attribute", kParamType_Integer, 0 },
	{ "race", kParamType_Race, 1 }
};
static ParamInfo kParams_CmdGetNthRaceBonusSkill[2] = {
	{ "attribute", kParamType_ActorValue, 0 },
	{ "race", kParamType_Race, 1 }
};
static ParamInfo kParams_CmdGetClimateSunriseBegin[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetClimateSunriseEnd[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetClimateSunsetBegin[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetClimateSunsetEnd[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetSpellExplodesWithNoTarget[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdSetSpellExplodesWithNoTarget[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdRemoveAllEffectItems[1] = {
	{ "spell", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdSetNthEffectItemScript[3] = {
	{ "script", kParamType_MagicItem, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemScriptName[3] = {
	{ "name", kParamType_String, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetMerchantContainer[1] = {
	{ "container", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdMagicItemHasEffectCount[3] = {
	{ "effect code", kParamType_MagicEffect, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdMagicItemHasEffectCountCode[3] = {
	{ "effect code", kParamType_Integer, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "actor value", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetScript[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdRemoveScript[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetScript[2] = {
	{ "script", kParamType_MagicItem, 0 },
	{ "object", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsPlayable[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetIsPlayable[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetPCAMurderer[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetClimateMoonPhaseLength[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetClimateHasMasser[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetClimateHasSecunda[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetClimateSunriseBegin[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetClimateSunriseEnd[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetClimateSunsetBegin[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetClimateSunsetEnd[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetClimateMoonPhaseLength[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetClimateHasMasser[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetClimateHasSecunda[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetClimateVolatility[2] = {
	{ "weather", kParamType_WeatherID, 0 },
	{ "GetWeatherInfo", 57047257, 0 } //strange parameter type
};
static ParamInfo kParams_CmdSetClimateVolatility[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdIsKeyPressed3[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsControlPressed[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdDisableControl[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdEnableControl[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdOnKeyDown[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdOnControlDown[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetNthActiveEffectCode[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetNthActiveEffectMagnitude[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetNthActiveEffectDuration[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetNthActiveEffectTimeElapsed[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetNthActiveEffectMagicItem[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetNthActiveEffectCaster[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetNthActiveEffectMagicItemIndex[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetTotalActiveEffectMagnitude[2] = {
	{ "magic effect", kParamType_MagicEffect, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdGetTotalAENonAbilityMagnitude[2] = {
	{ "magic effect", kParamType_MagicEffect, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdGetTotalAEAbilityMagnitude[2] = {
	{ "magic effect", kParamType_MagicEffect, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdGetTotalAESpellMagnitude[2] = {
	{ "magic effect", kParamType_MagicEffect, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdGetTotalAEDiseaseMagnitude[2] = {
	{ "magic effect", kParamType_MagicEffect, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdGetTotalAELesserPowerMagnitude[2] = {
	{ "magic effect", kParamType_MagicEffect, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdGetTotalAEPowerMagnitude[2] = {
	{ "magic effect", kParamType_MagicEffect, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdGetTotalAEAllSpellsMagnitude[2] = {
	{ "magic effect", kParamType_MagicEffect, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdGetTotalAEEnchantmentMagnitude[2] = {
	{ "magic effect", kParamType_MagicEffect, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_CmdGetTotalAEAlchemyMagnitude[2] = {
	{ "magic effect", kParamType_MagicEffect, 0 },
	{ "actor value", kParamType_ActorValue, 1 }
};
static ParamInfo kParams_Cmdcon_LoadGame[2] = {
	{ "String", kParamType_String, 0 },
	{ "Integer (Optional)", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdIsPluginInstalled[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetPluginVersion[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetNthActiveEffectData[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetTotalActiveEffectMagnitudeC[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetTotalAENonAbilityMagnitudeC[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetTotalAEAbilityMagnitudeC[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetTotalAESpellMagnitudeC[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetTotalAEDiseaseMagnitudeC[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetTotalAELesserPowerMagnitudeC[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetTotalAEPowerMagnitudeC[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetTotalAEAllSpellsMagnitudeC[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetTotalAEEnchantmentMagnitudeC[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetTotalAEAlchemyMagnitudeC[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdAddToLeveledList[4] = {
	{ "leveled list", kParamType_InventoryObject, 0 },
	{ "item to add", kParamType_InventoryObject, 0 },
	{ "level", kParamType_Integer, 1 },
	{ "count", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdRemoveFromLeveledList[2] = {
	{ "leveled list", kParamType_InventoryObject, 0 },
	{ "item to remove", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdSetTravelHorse[1] = {
	{ "container", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdCompareNames[2] = {
	{ "compare to", kParamType_InventoryObject, 0 },
	{ "base object", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdTapControl[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetWeatherWindSpeed[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherCloudSpeedLower[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherCloudSpeedUpper[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherTransDelta[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherSunGlare[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherSunDamage[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherFogDayNear[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherFogDayFar[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherFogNightNear[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherFogNightFar[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherHDRValue[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherHDRValue[3] = {
	{ "nuVal", kParamType_Float, 0 },
	{ "which", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdGetWeatherColor[4] = {
	{ "rgb", kParamType_Integer, 0 },
	{ "whichColor", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 },
	{ "time", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetWeatherColor[6] = {
	{ "red", kParamType_Integer, 0 },
	{ "green", kParamType_Integer, 0 },
	{ "blue", kParamType_Integer, 0 },
	{ "whichColor", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 },
	{ "time", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetWeatherLightningFrequency[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherWindSpeed[2] = {
	{ "value", kParamType_Float, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherCloudSpeedLower[2] = {
	{ "value", kParamType_Float, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherCloudSpeedUpper[2] = {
	{ "value", kParamType_Float, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherTransDelta[2] = {
	{ "value", kParamType_Float, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherSunGlare[2] = {
	{ "value", kParamType_Float, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherSunDamage[2] = {
	{ "value", kParamType_Float, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherFogDayNear[2] = {
	{ "value", kParamType_Float, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherFogDayFar[2] = {
	{ "value", kParamType_Float, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherFogNightNear[2] = {
	{ "value", kParamType_Float, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetWeatherFogNightFar[2] = {
	{ "value", kParamType_Float, 0 },
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdCalcLeveledItem[4] = {
	{ "leveled list", kParamType_InventoryObject, 0 },
	{ "level", kParamType_Integer, 0 },
	{ "chance none flag", kParamType_Integer, 1 },
	{ "min level difference", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetOpenKey[1] = {
	{ "int", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdGetWeatherLightningFrequency[1] = {
	{ "weather", kParamType_WeatherID, 0 }
};
static ParamInfo kParams_CmdSetNthActiveEffectMagnitude[2] = {
	{ "value", kParamType_Float, 0 },
	{ "which", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModNthActiveEffectMagnitude[2] = {
	{ "value", kParamType_Float, 0 },
	{ "which", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetHair[2] = {
	{ "body data", kParamType_InventoryObject, 0 },
	{ "base NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdCopyHair[2] = {
	{ "copy from", kParamType_NPC, 0 },
	{ "copy to", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetEyes[2] = {
	{ "body data", kParamType_InventoryObject, 0 },
	{ "base NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdCopyEyes[2] = {
	{ "copy from", kParamType_NPC, 0 },
	{ "copy to", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdGetContainerRespawns[1] = {
	{ "container", kParamType_Container, 1 }
};
static ParamInfo kParams_CmdSetContainerRespawns[2] = {
	{ "respawns", kParamType_Integer, 0 },
	{ "container", kParamType_Container, 1 }
};
static ParamInfo kParams_CmdGetCreatureReach[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetCreatureBaseScale[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetCreatureSoulLevel[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetFirstRef[3] = {
	{ "form type", kParamType_Integer, 1 },
	{ "cell depth", kParamType_Integer, 1 },
	{ "include taken refs", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNumRefs[3] = {
	{ "form type", kParamType_Integer, 1 },
	{ "cell depth", kParamType_Integer, 1 },
	{ "include taken refs", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdIsOffLimits[1] = {
	{ "NPC", kParamType_NPC, 0 }
};
static ParamInfo kParams_CmdMessageEX[21] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdMessageBoxEX[21] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 }
};
static ParamInfo kParams_Cmdcon_ToggleMapMarkers[1] = {
	{ "Integer", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetNthChildRef[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetScaleEX[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdGetNthFollower[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsActorRespawning[1] = {
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdIsPCLevelOffset[1] = {
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdHasLowLevelProcessing[1] = {
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdIsSummonable[1] = {
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdHasNoPersuasion[1] = {
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdCanCorpseCheck[1] = {
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetActorMinLevel[1] = {
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetActorMaxLevel[1] = {
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdSetFemale[2] = {
	{ "bool", kParamType_Integer, 0 },
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdSetActorRespawns[2] = {
	{ "bool", kParamType_Integer, 0 },
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdSetPCLevelOffset[4] = {
	{ "bool", kParamType_Integer, 0 },
	{ "min level", kParamType_Integer, 1 },
	{ "max level", kParamType_Integer, 1 },
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdSetLowLevelProcessing[2] = {
	{ "bool", kParamType_Integer, 0 },
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdSetSummonable[2] = {
	{ "bool", kParamType_Integer, 0 },
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdSetNoPersuasion[2] = {
	{ "bool", kParamType_Integer, 0 },
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdSetCanCorpseCheck[2] = {
	{ "bool", kParamType_Integer, 0 },
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetNumFactions[1] = {
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetNthFaction[2] = {
	{ "bool", kParamType_Integer, 0 },
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdIsFactionEvil[1] = {
	{ "faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdIsFactionHidden[1] = {
	{ "faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdFactionHasSpecialCombat[1] = {
	{ "faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdSetFactionEvil[2] = {
	{ "faction", kParamType_Faction, 0 },
	{ "bool", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetFactionHidden[2] = {
	{ "faction", kParamType_Faction, 0 },
	{ "bool", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetFactionSpecialCombat[2] = {
	{ "faction", kParamType_Faction, 0 },
	{ "bool", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsLightCarriable[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetLightRadius[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetLightRadius[2] = {
	{ "value", kParamType_Integer, 0 },
	{ "type", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetRaceSpellCount[1] = {
	{ "race", kParamType_Race, 1 }
};
static ParamInfo kParams_CmdGetNthRaceSpell[2] = {
	{ "attribute", kParamType_Integer, 0 },
	{ "race", kParamType_Race, 1 }
};
static ParamInfo kParams_CmdMagicItemHasEffectItemScript[2] = {
	{ "script", kParamType_MagicItem, 0 },
	{ "magic item", kParamType_MagicItem, 0 }
};
static ParamInfo kParams_CmdSetCurrentSoulLevel[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetCreatureWalks[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetCreatureSwims[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetCreatureFlies[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdIsCreatureBiped[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdCreatureHasNoMovement[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdCreatureHasNoHead[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdCreatureHasNoLeftArm[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdCreatureHasNoRightArm[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdCreatureNoCombatInWater[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdCreatureUsesWeaponAndShield[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdIsFemale[1] = {
	{ "base actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdSetHarvested[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetActorValueC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetActorValueC[2] = {
	{ "actor value", kParamType_Integer, 0 },
	{ "amount", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModActorValueC[2] = {
	{ "actor value", kParamType_Integer, 0 },
	{ "amount", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdModNthEffectItemScriptName[3] = {
	{ "name", kParamType_String, 0 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetBaseActorValueC[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetCreatureSoundBase[1] = {
	{ "index", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetNumRanks[1] = {
	{ "faction", kParamType_Faction, 0 }
};
static ParamInfo kParams_CmdHasModel[2] = {
	{ "model path", kParamType_String, 0 },
	{ "creature", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdIsModLoaded[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetRace[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdHasName[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetRefCount[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetMagicProjectileSpell[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdGetModIndex[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetSourceModIndex[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetCalcAllLevels[1] = {
	{ "int", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdGetCalcEachInCount[1] = {
	{ "int", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdGetChanceNone[1] = {
	{ "int", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdCalcLeveledItemNR[4] = {
	{ "leveled list", kParamType_InventoryObject, 0 },
	{ "level", kParamType_Integer, 0 },
	{ "chance none flag", kParamType_Integer, 1 },
	{ "min level difference", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNumLevItems[1] = {
	{ "int", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdGetNthLevItem[2] = {
	{ "index", kParamType_Integer, 0 },
	{ "leveled list", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdAddItemNS[2] = {
	{ "item", kParamType_InventoryObject, 0 },
	{ "quantity", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdRemoveItemNS[2] = {
	{ "item", kParamType_InventoryObject, 0 },
	{ "quantity", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdEquipItemNS[2] = {
	{ "item", kParamType_InventoryObject, 0 },
	{ "lockEquip", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdUnequipItemNS[2] = {
	{ "item", kParamType_InventoryObject, 0 },
	{ "lockEquip", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdAddSpellNS[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdRemoveSpellNS[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdGetHair[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdGetEyes[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdGetHairColor[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdGetOpenSound[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetCloseSound[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetLoopSound[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetOpenSound[2] = {
	{ "sound", kParamType_Sound, 0 },
	{ "object", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetCloseSound[2] = {
	{ "sound", kParamType_Sound, 0 },
	{ "object", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetLoopSound[2] = {
	{ "sound", kParamType_Sound, 0 },
	{ "object", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetCreatureSound[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdIsPlayable2[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsFormValid[1] = {
	{ "int", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdIsReference[1] = {
	{ "ref", kParamType_ObjectRef, 0 }
};
static ParamInfo kParams_CmdToggleCreatureModel[3] = {
	{ "model path", kParamType_String, 0 },
	{ "bool", kParamType_Integer, 0 },
	{ "creature", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdSetMessageSound[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdSetMessageIcon[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetVariable[2] = {
	{ "variable name", kParamType_String, 0 },
	{ "quest", kParamType_Quest, 1 }
};
static ParamInfo kParams_CmdGetRefVariable[2] = {
	{ "variable name", kParamType_String, 0 },
	{ "quest", kParamType_Quest, 1 }
};
static ParamInfo kParams_CmdHasVariable[2] = {
	{ "variable name", kParamType_String, 0 },
	{ "quest", kParamType_Quest, 1 }
};
static ParamInfo kParams_CmdGetFullGoldValue[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetNthDetectedActor[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetDetectionState[2] = {
	{ "actor", kParamType_Actor, 0 },
	{ "level", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetHotKeyItem[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdClearHotKey[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetHotKeyItem[2] = {
	{ "hotkey", kParamType_Integer, 0 },
	{ "item", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdOffersWeapons[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersArmor[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersClothing[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersBooks[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersLights[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersIngredients[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersApparatus[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersMiscItems[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersMagicItems[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersSpells[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersPotions[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersTraining[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersRecharging[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersRepair[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdOffersServicesC[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdGetTrainerSkill[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdGetTrainerLevel[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersWeapons[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersArmor[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersClothing[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersBooks[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersIngredients[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersSpells[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersLights[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersMiscItems[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersMagicItems[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersApparatus[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersPotions[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersTraining[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersRecharging[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetOffersRepair[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetServicesMask[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdGetServicesMask[1] = {
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetTrainerSkill[2] = {
	{ "skill", kParamType_ActorValue, 0 },
	{ "npc", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdSetTrainerLevel[2] = {
	{ "RGB value", kParamType_Integer, 0 },
	{ "NPC", kParamType_NPC, 1 }
};
static ParamInfo kParams_CmdGetNumPackages[1] = {
	{ "actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdGetNthPackage[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "actor", kParamType_ActorBase, 1 }
};
static ParamInfo kParams_CmdCompareScripts[2] = {
	{ "script", kParamType_InventoryObject, 0 },
	{ "script", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdIsAnimGroupPlaying[1] = {
	{ "anim group", kParamType_AnimationGroup, 0 }
};
static ParamInfo kParams_CmdAnimPathIncludes[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdClearLeveledList[1] = {
	{ "int", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdGetNthLevItemCount[2] = {
	{ "index", kParamType_Integer, 0 },
	{ "leveled list", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdGetNthLevItemLevel[2] = {
	{ "index", kParamType_Integer, 0 },
	{ "leveled list", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdIsSpellHostile[1] = {
	{ "spell", kParamType_SpellItem, 0 }
};
static ParamInfo kParams_CmdSetSpellHostile[2] = {
	{ "spell", kParamType_SpellItem, 0 },
	{ "bool", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdRemoveLevItemByLevel[2] = {
	{ "index", kParamType_Integer, 0 },
	{ "leveled list", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdIsModelPathValid[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsIconPathValid[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsBipedModelPathValid[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdIsBipedIconPathValid[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdFileExists[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetPCAttributeBonus[1] = {
	{ "actor value", kParamType_ActorValue, 0 }
};
static ParamInfo kParams_CmdSetNameEx[22] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "inventory object", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetHasBeenPickedUp[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetActiveMenuFilter[1] = {
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetActiveMenuSelection[1] = {
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetActiveMenuObject[1] = {
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetActiveMenuRef[1] = {
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetSoundPlaying[2] = {
	{ "string", kParamType_String, 1 },
	{ "float", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdGetAlchMenuIngredient[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetAlchMenuIngredientCount[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetAlchMenuApparatus[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetAltControl2[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetLevItemByLevel[2] = {
	{ "index", kParamType_Integer, 0 },
	{ "leveled list", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdSetControl[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetAltControl[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdsv_Construct[21] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 }
};
static ParamInfo kParams_Cmdsv_Compare[23] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "stringVar", kParamType_Integer, 0 },
	{ "bCaseSensitive", kParamType_Integer, 1 }
};
static ParamInfo kParams_Cmdsv_Erase[3] = {
	{ "stringVar", kParamType_Integer, 0 },
	{ "startPos", kParamType_Integer, 1 },
	{ "howMany", kParamType_Integer, 1 }
};
static ParamInfo kParams_Cmdsv_Length[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdsv_SubString[3] = {
	{ "stringVar", kParamType_Integer, 0 },
	{ "startPos", kParamType_Integer, 1 },
	{ "howMany", kParamType_Integer, 1 }
};
static ParamInfo kParams_Cmdsv_Count[25] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "stringVar", kParamType_Integer, 0 },
	{ "startPos", kParamType_Integer, 1 },
	{ "endPos", kParamType_Integer, 1 },
	{ "bCaseSensitive", kParamType_Integer, 1 }
};
static ParamInfo kParams_Cmdsv_Find[25] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "stringVar", kParamType_Integer, 0 },
	{ "startPos", kParamType_Integer, 1 },
	{ "endPos", kParamType_Integer, 1 },
	{ "bCaseSensitive", kParamType_Integer, 1 }
};
static ParamInfo kParams_Cmdsv_Replace[26] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "stringVar", kParamType_Integer, 0 },
	{ "startPos", kParamType_Integer, 1 },
	{ "endPos", kParamType_Integer, 1 },
	{ "bCaseSensitive", kParamType_Integer, 1 },
	{ "howMany", kParamType_Integer, 1 }
};
static ParamInfo kParams_Cmdsv_ToNumeric[2] = {
	{ "stringVar", kParamType_Integer, 0 },
	{ "startPos", kParamType_Integer, 1 }
};
static ParamInfo kParams_Cmdsv_Insert[23] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "stringVar", kParamType_Integer, 0 },
	{ "bCaseSensitive", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdIsDigit[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsLetter[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsPrintable[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsPunctuation[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdIsUpperCase[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_Cmdsv_GetChar[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetDebugMode[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdDebugPrint[21] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdRunScriptLine[22] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "run on ref", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdCharToAscii[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetFirstRefInCell[4] = {
	{ "cell", kParamType_Cell, 0 },
	{ "form type", kParamType_Integer, 1 },
	{ "cell depth", kParamType_Integer, 1 },
	{ "include taken refs", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNumRefsInCell[4] = {
	{ "cell", kParamType_Cell, 0 },
	{ "form type", kParamType_Integer, 1 },
	{ "cell depth", kParamType_Integer, 1 },
	{ "include taken refs", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdOpenTextInput[23] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "type", kParamType_Integer, 1 },
	{ "maxlength", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdInsertInInputText[21] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdSetRaceAlias[3] = {
	{ "race", kParamType_Race, 0 },
	{ "alias", kParamType_Race, 0 },
	{ "bEnableAlias", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetRaceVoice[3] = {
	{ "race", kParamType_Race, 0 },
	{ "alias", kParamType_Race, 0 },
	{ "bEnableAlias", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetRacePlayable[2] = {
	{ "race", kParamType_Race, 0 },
	{ "bool", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetIngredient[1] = {
	{ "Flora", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetIngredientChance[2] = {
	{ "Season", kParamType_Integer, 0 },
	{ "Flora", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetIngredient[2] = {
	{ "Ingredient", kParamType_InventoryObject, 1 },
	{ "Flora", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetIngredientChance[3] = {
	{ "Season", kParamType_Integer, 0 },
	{ "New Chance", kParamType_Integer, 0 },
	{ "Flora", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetProjectileSource[1] = {
	{ "actor reference", kParamType_Actor, 0 }
};
static ParamInfo kParams_CmdSetArrowProjectileEnchantment[1] = {
	{ "enchantment", kParamType_MagicItem, 1 }
};
static ParamInfo kParams_CmdSetArrowProjectileBowEnchantment[1] = {
	{ "enchantment", kParamType_MagicItem, 1 }
};
static ParamInfo kParams_CmdSetArrowProjectilePoison[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetProjectileSpeed[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdModPCSpellEffectiveness[1] = {
	{ "float", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdGetNthModName[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetName[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetStringGameSetting[1] = {
	{ "string", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetModelPath[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetIconPath[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetBipedModelPath[2] = {
	{ "path type", kParamType_Integer, 0 },
	{ "item", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetBipedIconPath[2] = {
	{ "path type", kParamType_Integer, 0 },
	{ "item", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetNthFactionRankName[3] = {
	{ "faction", kParamType_Faction, 0 },
	{ "rank", kParamType_Integer, 0 },
	{ "bFemale", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetNthEffectItemScriptName[2] = {
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetModelPathEX[22] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "object", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetIconPathEX[22] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "object", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetNthFactionRankNameEX[24] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "faction", kParamType_Faction, 0 },
	{ "rank", kParamType_Integer, 0 },
	{ "bFemale", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetStringGameSettingEX[21] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdSetBipedModelPathEX[23] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "whichPath", kParamType_Integer, 0 },
	{ "item", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetBipedIconPathEX[23] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "whichPath", kParamType_Integer, 0 },
	{ "item", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetNthEffectItemScriptNameEX[23] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "magic item", kParamType_MagicItem, 0 },
	{ "which effect", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdToggleFirstPerson[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetFormFromMod[2] = {
	{ "modName", kParamType_String, 0 },
	{ "formID", kParamType_String, 0 }
};
static ParamInfo kParams_CmdGetHidesRings[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetHidesRings[2] = {
	{ "path type", kParamType_Integer, 0 },
	{ "item", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetHidesAmulet[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetHidesAmulet[2] = {
	{ "path type", kParamType_Integer, 0 },
	{ "item", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetMapMarkerVisible[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetCanTravelToMapMarker[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetMapMarkerType[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetCursorPos[1] = {
	{ "axis", kParamType_Axis, 0 }
};
static ParamInfo kParams_CmdIsFlora[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetPCMajorSkillUps[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetPCAttributeBonus[2] = {
	{ "actor value", kParamType_ActorValue, 0 },
	{ "amount", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetMenuFloatValue[22] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "menuType", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetMenuStringValue[22] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "menuType", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetMenuFloatValue[23] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "menuType", kParamType_Integer, 0 },
	{ "new value", kParamType_Float, 0 }
};
static ParamInfo kParams_CmdSetMenuStringValue[22] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "menuType", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdToUpper[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdToLower[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetButtonPressed[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetBaseForm[1] = {
	{ "int", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdGetBipedSlotMask[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdSetBipedSlotMask[2] = {
	{ "path type", kParamType_Integer, 0 },
	{ "item", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetNumExplicitRefs[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetNthExplicitRef[2] = {
	{ "path type", kParamType_Integer, 0 },
	{ "item", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdClickMenuButton[22] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "menuType", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdGetProjectile[3] = {
	{ "type", kParamType_Integer, 1 },
	{ "maxLifetime", kParamType_Float, 1 },
	{ "formToMatch", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdRemoveNthLevItem[2] = {
	{ "index", kParamType_Integer, 0 },
	{ "leveled list", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdGetLevItemIndexByLevel[2] = {
	{ "index", kParamType_Integer, 0 },
	{ "leveled list", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdGetLevItemIndexByForm[2] = {
	{ "leveled list", kParamType_InventoryObject, 0 },
	{ "item to remove", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdGetBookText[1] = {
	{ "int", kParamType_InventoryObject, 1 }
};
static ParamInfo kParams_CmdGetMenuHasTrait[22] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "menuType", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetChanceNone[2] = {
	{ "index", kParamType_Integer, 0 },
	{ "leveled list", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_Cmdsv_Set[22] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "stringVar", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdIsControl[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdSetIsControl[2] = {
	{ "int", kParamType_Integer, 0 },
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdLoadGameEx[21] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdDeleteFromInputText[3] = {
	{ "numToDelete", kParamType_Integer, 0 },
	{ "bBackwards", kParamType_Integer, 1 },
	{ "bWholeWords", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdSetPCTrainingSessionsUsed[1] = {
	{ "int", kParamType_Integer, 0 }
};
static ParamInfo kParams_CmdMoveTextInputCursor[2] = {
	{ "numToMove", kParamType_Integer, 0 },
	{ "bBackwards", kParamType_Integer, 1 }
};
static ParamInfo kParams_CmdGetStringIniSetting[21] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdSetStringIniSetting[21] = {
	{ "format string", kParamType_String, 0 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 },
	{ "variable", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdTestExtractArgs[1] = {
	{ "TESForm", kParamType_InventoryObject, 0 }
};
static ParamInfo kParams_CmdPrintToFile[11] = {
	{ "string", kParamType_String, 0 },
	{ "string", kParamType_String, 0 },
	{ "float", kParamType_Float, 1 },
	{ "float", kParamType_Float, 1 },
	{ "float", kParamType_Float, 1 },
	{ "float", kParamType_Float, 1 },
	{ "float", kParamType_Float, 1 },
	{ "float", kParamType_Float, 1 },
	{ "float", kParamType_Float, 1 },
	{ "float", kParamType_Float, 1 },
	{ "float", kParamType_Float, 1 }
};
static ParamInfo kParams_CmdDumpLevList[1] = {
	{ "int", kParamType_InventoryObject, 0 }
};
#endif