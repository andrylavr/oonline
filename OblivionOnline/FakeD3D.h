#pragma once
/*

Copyright(c) 2007-2010   Julian Bangert 

This file is part of OblivionOnline.

    OblivionOnline is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    OblivionOnline is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Linking OblivionOnline statically or dynamically with other modules is making a combined work based
	on OblivionOnline. Thus, the terms and conditions of the GNU General Public License cover 
	the whole combination.

    In addition, as a special exception, the copyright holders of  OblivionOnline give you permission to 
	combine OblivionOnline program with free software programs or libraries that are released under
	the GNU LGPL and with code included in the standard release of Oblivion Script Extender by Ian Patterson (OBSE)
	under the OBSE license (or modified versions of such code, with unchanged license). You may copy and distribute such a system 
	following the terms of the GNU GPL for  OblivionOnline and the licenses of the other code concerned,
	provided that you include the source code of that other code when and as the GNU GPL
	requires distribution of source code.

	Note that people who make modified versions of  OblivionOnline are not obligated to grant this special exception
	for their modified versions; it is their choice whether to do so. 
	The GNU General Public License gives permission to release a modified version without this
	exception; this exception also makes it possible to release a modified version which carries 
	forward this exception.
*/
#ifndef _FAKED3D_H
#define _FAKED3D_H
#include <d3d9.h>
#include "main.h"
#include "UserInterface.h"
#include "D3DHook.h"
extern bool g_bRenderGUI; 
class MyDirect3DDevice9 : public IDirect3DDevice9
{
public:
	// We need d3d so that we'd use a pointer to MyDirect3D9 instead of the original IDirect3D9 implementor
	// in functions like GetDirect3D9
	MyDirect3DDevice9(IDirect3D9* d3d, IDirect3DDevice9* device)
	{
		m_d3d = d3d;
		m_device = device;
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj)
	{
		return m_device->QueryInterface(riid, ppvObj);
	}

	STDMETHOD_(ULONG,AddRef)(THIS)
	{
		return m_device->AddRef();
	}

	STDMETHOD_(ULONG,Release)(THIS)
	{
		ULONG count = m_device->Release();
		if(0 == count)
			delete this;

		return count;
	}

	/*** IDirect3DDevice9 methods ***/
	STDMETHOD(TestCooperativeLevel)(THIS)
	{
		return m_device->TestCooperativeLevel();
	}

	STDMETHOD_(UINT, GetAvailableTextureMem)(THIS)
	{
		return m_device->GetAvailableTextureMem();
	}

	STDMETHOD(EvictManagedResources)(THIS)
	{
		return m_device->EvictManagedResources();
	}

	STDMETHOD(GetDirect3D)(THIS_ IDirect3D9** ppD3D9)
	{
		// Let the device validate the incoming pointer for us
		HRESULT hr = m_device->GetDirect3D(ppD3D9);
		if(SUCCEEDED(hr))
			*ppD3D9 = m_d3d;

		return hr;	
	}

	STDMETHOD(GetDeviceCaps)(THIS_ D3DCAPS9* pCaps)
	{
		return m_device->GetDeviceCaps(pCaps);
	}

	STDMETHOD(GetDisplayMode)(THIS_ UINT iSwapChain,D3DDISPLAYMODE* pMode)
	{
		return m_device->GetDisplayMode(iSwapChain, pMode);

	}

	STDMETHOD(GetCreationParameters)(THIS_ D3DDEVICE_CREATION_PARAMETERS *pParameters)
	{
		return m_device->GetCreationParameters(pParameters);
	}

	STDMETHOD(SetCursorProperties)(THIS_ UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap)
	{
		return m_device->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
	}

	STDMETHOD_(void, SetCursorPosition)(THIS_ int X,int Y,DWORD Flags)
	{
		m_device->SetCursorPosition(X, Y, Flags);
	}

	STDMETHOD_(BOOL, ShowCursor)(THIS_ BOOL bShow)
	{
		return m_device->ShowCursor(bShow);
	}

	STDMETHOD(CreateAdditionalSwapChain)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain)
	{
		return m_device->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
	}

	STDMETHOD(GetSwapChain)(THIS_ UINT iSwapChain,IDirect3DSwapChain9** pSwapChain)
	{
		return m_device->GetSwapChain(iSwapChain, pSwapChain);
	}

	STDMETHOD_(UINT, GetNumberOfSwapChains)(THIS)
	{
		return m_device->GetNumberOfSwapChains();
	}

	STDMETHOD(Reset)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters)
	{
		return m_device->Reset(pPresentationParameters);
	}

	STDMETHOD(Present)(THIS_ CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
	{
		BeginScene();
		static IDirect3DStateBlock9 *state = NULL;
		if(bUIInitialized)
		{	
			if(g_bRenderGUI)
			{
				//save state 
				CreateStateBlock(D3DSBT_ALL,&state);
				//render
				CEGUI::System::getSingleton().renderGUI();
				//restore state
				state->Apply();
				state->Release();


			}
		}
		if(gClient)
			gClient->RunFrame();
		//gClient->GetServerStream()->Send();
		EndScene();
		return m_device->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
	}

	STDMETHOD(GetBackBuffer)(THIS_ UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer)
	{
		return m_device->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
	}

	STDMETHOD(GetRasterStatus)(THIS_ UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus)
	{
		return m_device->GetRasterStatus(iSwapChain, pRasterStatus);
	}

	STDMETHOD(SetDialogBoxMode)(THIS_ BOOL bEnableDialogs)
	{
		return m_device->SetDialogBoxMode(bEnableDialogs);
	}

	STDMETHOD_(void, SetGammaRamp)(THIS_ UINT iSwapChain,DWORD Flags,CONST D3DGAMMARAMP* pRamp)
	{
		return m_device->SetGammaRamp(iSwapChain, Flags, pRamp);
	}

	STDMETHOD_(void, GetGammaRamp)(THIS_ UINT iSwapChain,D3DGAMMARAMP* pRamp)
	{
		return m_device->GetGammaRamp(iSwapChain, pRamp);
	}

	STDMETHOD(CreateTexture)(THIS_ UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle)
	{
		return m_device->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
	}

	STDMETHOD(CreateVolumeTexture)(THIS_ UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle)
	{
		return m_device->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
	}

	STDMETHOD(CreateCubeTexture)(THIS_ UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle)
	{
		return m_device->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
	}

	STDMETHOD(CreateVertexBuffer)(THIS_ UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle)
	{
		return m_device->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
	}

	STDMETHOD(CreateIndexBuffer)(THIS_ UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle)
	{
		return m_device->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
	}

	STDMETHOD(CreateRenderTarget)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
	{
		return m_device->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
	}

	STDMETHOD(CreateDepthStencilSurface)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
	{
		return m_device->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
	}

	STDMETHOD(UpdateSurface)(THIS_ IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,CONST POINT* pDestPoint)
	{
		return m_device->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
	}

	STDMETHOD(UpdateTexture)(THIS_ IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture)
	{
		return m_device->UpdateTexture(pSourceTexture, pDestinationTexture);
	}

	STDMETHOD(GetRenderTargetData)(THIS_ IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface)
	{
		return m_device->GetRenderTargetData(pRenderTarget, pDestSurface);
	}

	STDMETHOD(GetFrontBufferData)(THIS_ UINT iSwapChain,IDirect3DSurface9* pDestSurface)
	{
		return m_device->GetFrontBufferData(iSwapChain, pDestSurface);
	}

	STDMETHOD(StretchRect)(THIS_ IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestSurface,CONST RECT* pDestRect,D3DTEXTUREFILTERTYPE Filter)
	{
		return m_device->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
	}

	STDMETHOD(ColorFill)(THIS_ IDirect3DSurface9* pSurface,CONST RECT* pRect,D3DCOLOR color)
	{
		return m_device->ColorFill(pSurface, pRect, color);
	}

	STDMETHOD(CreateOffscreenPlainSurface)(THIS_ UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
	{
		return m_device->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
	}

	STDMETHOD(SetRenderTarget)(THIS_ DWORD RenderTargetIndex,IDirect3DSurface9* pRenderTarget)
	{
		return m_device->SetRenderTarget(RenderTargetIndex, pRenderTarget);
	}

	STDMETHOD(GetRenderTarget)(THIS_ DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget)
	{
		return m_device->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
	}

	STDMETHOD(SetDepthStencilSurface)(THIS_ IDirect3DSurface9* pNewZStencil)
	{
		return m_device->SetDepthStencilSurface(pNewZStencil);
	}

	STDMETHOD(GetDepthStencilSurface)(THIS_ IDirect3DSurface9** ppZStencilSurface)
	{
		return m_device->GetDepthStencilSurface(ppZStencilSurface);
	}

	STDMETHOD(BeginScene)(THIS)
	{
		return m_device->BeginScene();
	}

	STDMETHOD(EndScene)(THIS)
	{
		return m_device->EndScene();
	}

	STDMETHOD(Clear)(THIS_ DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil)
	{
		return m_device->Clear(Count, pRects, Flags, Color, Z, Stencil);
	}

	STDMETHOD(SetTransform)(THIS_ D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix)
	{
		return m_device->SetTransform(State, pMatrix);
	}

	STDMETHOD(GetTransform)(THIS_ D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix)
	{
		return m_device->GetTransform(State, pMatrix);
	}

	STDMETHOD(MultiplyTransform)(THIS_ D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix)
	{
		return m_device->MultiplyTransform(State, pMatrix);
	}

	STDMETHOD(SetViewport)(THIS_ CONST D3DVIEWPORT9* pViewport)
	{
		return m_device->SetViewport(pViewport);
	}

	STDMETHOD(GetViewport)(THIS_ D3DVIEWPORT9* pViewport)
	{
		return m_device->GetViewport(pViewport);
	}

	STDMETHOD(SetMaterial)(THIS_ CONST D3DMATERIAL9* pMaterial)
	{
		return m_device->SetMaterial(pMaterial);
	}

	STDMETHOD(GetMaterial)(THIS_ D3DMATERIAL9* pMaterial)
	{
		return m_device->GetMaterial(pMaterial);
	}

	STDMETHOD(SetLight)(THIS_ DWORD Index,CONST D3DLIGHT9* pLight)
	{
		return m_device->SetLight(Index, pLight);
	}

	STDMETHOD(GetLight)(THIS_ DWORD Index,D3DLIGHT9* pLight)
	{
		return m_device->GetLight(Index, pLight);
	}

	STDMETHOD(LightEnable)(THIS_ DWORD Index,BOOL Enable)
	{
		return m_device->LightEnable(Index, Enable);
	}

	STDMETHOD(GetLightEnable)(THIS_ DWORD Index,BOOL* pEnable)
	{
		return m_device->GetLightEnable(Index, pEnable);
	}

	STDMETHOD(SetClipPlane)(THIS_ DWORD Index,CONST float* pPlane)
	{
		return m_device->SetClipPlane(Index, pPlane);
	}

	STDMETHOD(GetClipPlane)(THIS_ DWORD Index,float* pPlane)
	{
		return m_device->GetClipPlane(Index, pPlane);
	}

	STDMETHOD(SetRenderState)(THIS_ D3DRENDERSTATETYPE State,DWORD Value)
	{
		return m_device->SetRenderState(State, Value);
	}

	STDMETHOD(GetRenderState)(THIS_ D3DRENDERSTATETYPE State,DWORD* pValue)
	{
		return m_device->GetRenderState(State, pValue);
	}

	STDMETHOD(CreateStateBlock)(THIS_ D3DSTATEBLOCKTYPE Type,IDirect3DStateBlock9** ppSB)
	{
		return m_device->CreateStateBlock(Type, ppSB);
	}

	STDMETHOD(BeginStateBlock)(THIS)
	{
		return m_device->BeginStateBlock();
	}

	STDMETHOD(EndStateBlock)(THIS_ IDirect3DStateBlock9** ppSB)
	{
		return m_device->EndStateBlock(ppSB);
	}

	STDMETHOD(SetClipStatus)(THIS_ CONST D3DCLIPSTATUS9* pClipStatus)
	{
		return m_device->SetClipStatus(pClipStatus);
	}

	STDMETHOD(GetClipStatus)(THIS_ D3DCLIPSTATUS9* pClipStatus)
	{
		return m_device->GetClipStatus(pClipStatus);
	}

	STDMETHOD(GetTexture)(THIS_ DWORD Stage,IDirect3DBaseTexture9** ppTexture)
	{
		return m_device->GetTexture(Stage, ppTexture);
	}

	STDMETHOD(SetTexture)(THIS_ DWORD Stage,IDirect3DBaseTexture9* pTexture)
	{
		return m_device->SetTexture(Stage, pTexture);
	}

	STDMETHOD(GetTextureStageState)(THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue)
	{
		return m_device->GetTextureStageState(Stage, Type, pValue);
	}

	STDMETHOD(SetTextureStageState)(THIS_ DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value)
	{
		return m_device->SetTextureStageState(Stage, Type, Value);
	}

	STDMETHOD(GetSamplerState)(THIS_ DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD* pValue)
	{
		return m_device->GetSamplerState(Sampler, Type, pValue);
	}

	STDMETHOD(SetSamplerState)(THIS_ DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD Value)
	{
		return m_device->SetSamplerState(Sampler, Type, Value);
	}

	STDMETHOD(ValidateDevice)(THIS_ DWORD* pNumPasses)
	{
		return m_device->ValidateDevice(pNumPasses);
	}

	STDMETHOD(SetPaletteEntries)(THIS_ UINT PaletteNumber,CONST PALETTEENTRY* pEntries)
	{
		return m_device->SetPaletteEntries(PaletteNumber, pEntries);
	}

	STDMETHOD(GetPaletteEntries)(THIS_ UINT PaletteNumber,PALETTEENTRY* pEntries)
	{
		return m_device->GetPaletteEntries(PaletteNumber, pEntries);
	}

	STDMETHOD(SetCurrentTexturePalette)(THIS_ UINT PaletteNumber)
	{
		return m_device->SetCurrentTexturePalette(PaletteNumber);
	}

	STDMETHOD(GetCurrentTexturePalette)(THIS_ UINT *PaletteNumber)
	{
		return m_device->GetCurrentTexturePalette(PaletteNumber);
	}

	STDMETHOD(SetScissorRect)(THIS_ CONST RECT* pRect)
	{
		return m_device->SetScissorRect(pRect);
	}

	STDMETHOD(GetScissorRect)(THIS_ RECT* pRect)
	{
		return m_device->GetScissorRect(pRect);
	}

	STDMETHOD(SetSoftwareVertexProcessing)(THIS_ BOOL bSoftware)
	{
		return m_device->SetSoftwareVertexProcessing(bSoftware);
	}

	STDMETHOD_(BOOL, GetSoftwareVertexProcessing)(THIS)
	{
		return m_device->GetSoftwareVertexProcessing();
	}

	STDMETHOD(SetNPatchMode)(THIS_ float nSegments)
	{
		return m_device->SetNPatchMode(nSegments);
	}

	STDMETHOD_(float, GetNPatchMode)(THIS)
	{
		return m_device->GetNPatchMode();
	}

	STDMETHOD(DrawPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount)
	{
		return m_device->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
	}

	STDMETHOD(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
	{
		return m_device->DrawIndexedPrimitive(PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
	}

	STDMETHOD(DrawPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
	{
		return m_device->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
	}

	STDMETHOD(DrawIndexedPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
	{
		return m_device->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
	}

	STDMETHOD(ProcessVertices)(THIS_ UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags)
	{
		return m_device->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
	}

	STDMETHOD(CreateVertexDeclaration)(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl)
	{
		return m_device->CreateVertexDeclaration(pVertexElements, ppDecl);
	}

	STDMETHOD(SetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9* pDecl)
	{
		return m_device->SetVertexDeclaration(pDecl);
	}

	STDMETHOD(GetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9** ppDecl)
	{
		return m_device->GetVertexDeclaration(ppDecl);
	}

	STDMETHOD(SetFVF)(THIS_ DWORD FVF)
	{
		return m_device->SetFVF(FVF);
	}

	STDMETHOD(GetFVF)(THIS_ DWORD* pFVF)
	{
		return m_device->GetFVF(pFVF);
	}

	STDMETHOD(CreateVertexShader)(THIS_ CONST DWORD* pFunction,IDirect3DVertexShader9** ppShader)
	{
		return m_device->CreateVertexShader(pFunction, ppShader);
	}

	STDMETHOD(SetVertexShader)(THIS_ IDirect3DVertexShader9* pShader)
	{
		return m_device->SetVertexShader(pShader);
	}

	STDMETHOD(GetVertexShader)(THIS_ IDirect3DVertexShader9** ppShader)
	{
		return m_device->GetVertexShader(ppShader);
	}

	STDMETHOD(SetVertexShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount)
	{
		return m_device->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}

	STDMETHOD(GetVertexShaderConstantF)(THIS_ UINT StartRegister,float* pConstantData,UINT Vector4fCount)
	{
		return m_device->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}

	STDMETHOD(SetVertexShaderConstantI)(THIS_ UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
	{
		return m_device->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}

	STDMETHOD(GetVertexShaderConstantI)(THIS_ UINT StartRegister,int* pConstantData,UINT Vector4iCount)
	{
		return m_device->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}

	STDMETHOD(SetVertexShaderConstantB)(THIS_ UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount)
	{
		return m_device->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
	}

	STDMETHOD(GetVertexShaderConstantB)(THIS_ UINT StartRegister,BOOL* pConstantData,UINT BoolCount)
	{
		return m_device->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
	}

	STDMETHOD(SetStreamSource)(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride)
	{
		return m_device->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
	}

	STDMETHOD(GetStreamSource)(THIS_ UINT StreamNumber,IDirect3DVertexBuffer9** ppStreamData,UINT* pOffsetInBytes,UINT* pStride)
	{
		return m_device->GetStreamSource(StreamNumber, ppStreamData, pOffsetInBytes, pStride);
	}

	STDMETHOD(SetStreamSourceFreq)(THIS_ UINT StreamNumber,UINT Setting)
	{
		return m_device->SetStreamSourceFreq(StreamNumber, Setting);
	}

	STDMETHOD(GetStreamSourceFreq)(THIS_ UINT StreamNumber,UINT* pSetting)
	{
		return m_device->GetStreamSourceFreq(StreamNumber, pSetting);
	}

	STDMETHOD(SetIndices)(THIS_ IDirect3DIndexBuffer9* pIndexData)
	{
		return m_device->SetIndices(pIndexData);
	}

	STDMETHOD(GetIndices)(THIS_ IDirect3DIndexBuffer9** ppIndexData)
	{
		return m_device->GetIndices(ppIndexData);
	}

	STDMETHOD(CreatePixelShader)(THIS_ CONST DWORD* pFunction,IDirect3DPixelShader9** ppShader)
	{
		return m_device->CreatePixelShader(pFunction, ppShader);
	}

	STDMETHOD(SetPixelShader)(THIS_ IDirect3DPixelShader9* pShader)
	{
		return m_device->SetPixelShader(pShader);
	}

	STDMETHOD(GetPixelShader)(THIS_ IDirect3DPixelShader9** ppShader)
	{
		return m_device->GetPixelShader(ppShader);
	}

	STDMETHOD(SetPixelShaderConstantF)(THIS_ UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount)
	{
		return m_device->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}

	STDMETHOD(GetPixelShaderConstantF)(THIS_ UINT StartRegister,float* pConstantData,UINT Vector4fCount)
	{
		return m_device->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}

	STDMETHOD(SetPixelShaderConstantI)(THIS_ UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
	{
		return m_device->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}

	STDMETHOD(GetPixelShaderConstantI)(THIS_ UINT StartRegister,int* pConstantData,UINT Vector4iCount)
	{
		return m_device->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}

	STDMETHOD(SetPixelShaderConstantB)(THIS_ UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount)
	{
		return m_device->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
	}

	STDMETHOD(GetPixelShaderConstantB)(THIS_ UINT StartRegister,BOOL* pConstantData,UINT BoolCount)
	{
		return m_device->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
	}

	STDMETHOD(DrawRectPatch)(THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo)
	{
		return m_device->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
	}

	STDMETHOD(DrawTriPatch)(THIS_ UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo)
	{
		return m_device->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
	}

	STDMETHOD(DeletePatch)(THIS_ UINT Handle)
	{
		return m_device->DeletePatch(Handle);
	}

	STDMETHOD(CreateQuery)(THIS_ D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery)
	{
		return m_device->CreateQuery(Type, ppQuery);
	}

private:
	IDirect3DDevice9* m_device;	
	IDirect3D9* m_d3d;
};


class MyDirect3D9 : public IDirect3D9
{
public:
	MyDirect3D9(IDirect3D9* d3d) : m_d3d(d3d)
	{
	}

	/*** IUnknown methods ***/
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObj)
	{
		return m_d3d->QueryInterface(riid, ppvObj);
	}

    ULONG STDMETHODCALLTYPE AddRef()
	{
		return m_d3d->AddRef();
	}

    ULONG STDMETHODCALLTYPE Release()
	{
		ULONG count = m_d3d->Release();
		if(0 == count)
			delete this;

		return count;
	}

    /*** IDirect3D9 methods ***/
    HRESULT STDMETHODCALLTYPE RegisterSoftwareDevice(void* pInitializeFunction)
	{
		return m_d3d->RegisterSoftwareDevice(pInitializeFunction);
	}

    UINT STDMETHODCALLTYPE GetAdapterCount()
	{
		return m_d3d->GetAdapterCount();
	}

    HRESULT STDMETHODCALLTYPE GetAdapterIdentifier( UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER9* pIdentifier)
	{
		return m_d3d->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
	}

    UINT STDMETHODCALLTYPE GetAdapterModeCount( UINT Adapter,D3DFORMAT Format)
	{
		return m_d3d->GetAdapterModeCount(Adapter, Format);
	}

    HRESULT STDMETHODCALLTYPE EnumAdapterModes( UINT Adapter,D3DFORMAT Format,UINT Mode,D3DDISPLAYMODE* pMode)
	{
		return m_d3d->EnumAdapterModes(Adapter, Format, Mode, pMode);
	}

    HRESULT STDMETHODCALLTYPE GetAdapterDisplayMode( UINT Adapter,D3DDISPLAYMODE* pMode)
	{
		return m_d3d->GetAdapterDisplayMode(Adapter, pMode);
	}

    HRESULT STDMETHODCALLTYPE CheckDeviceType( UINT Adapter,D3DDEVTYPE DevType,D3DFORMAT AdapterFormat,D3DFORMAT BackBufferFormat,BOOL bWindowed)
	{
		return m_d3d->CheckDeviceType(Adapter, DevType, AdapterFormat, BackBufferFormat, bWindowed);
	}

    HRESULT STDMETHODCALLTYPE CheckDeviceFormat( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat)
	{
		return m_d3d->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
	}

    HRESULT STDMETHODCALLTYPE CheckDeviceMultiSampleType( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType,DWORD* pQualityLevels)
	{
		return m_d3d->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
	}

    HRESULT STDMETHODCALLTYPE CheckDepthStencilMatch( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat)
	{
		return m_d3d->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
	}

    HRESULT STDMETHODCALLTYPE CheckDeviceFormatConversion( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SourceFormat,D3DFORMAT TargetFormat)
	{
		return m_d3d->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
	}

    HRESULT STDMETHODCALLTYPE GetDeviceCaps( UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps)
	{
		return m_d3d->GetDeviceCaps(Adapter, DeviceType, pCaps);
	}

    HMONITOR STDMETHODCALLTYPE GetAdapterMonitor( UINT Adapter)
	{
		return m_d3d->GetAdapterMonitor(Adapter);
	}

    HRESULT STDMETHODCALLTYPE CreateDevice( UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface)
	{
		HRESULT hr = m_d3d->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags,
			pPresentationParameters, ppReturnedDeviceInterface);
		
		if(SUCCEEDED(hr))
		{
			// Return our device
			OblivionDirect3D9Device = *ppReturnedDeviceInterface;
			*ppReturnedDeviceInterface = new MyDirect3DDevice9(this, *ppReturnedDeviceInterface);
		}

		return hr;
	}

private:
	IDirect3D9* m_d3d;
};
#endif