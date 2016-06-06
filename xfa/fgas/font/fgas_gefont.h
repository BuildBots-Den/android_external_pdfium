// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_FGAS_FONT_FGAS_GEFONT_H_
#define XFA_FGAS_FONT_FGAS_GEFONT_H_

#include <map>

#include "xfa/fgas/crt/fgas_utils.h"
#include "xfa/fgas/font/fgas_font.h"

#define FXFONT_SUBST_ITALIC 0x02

class CXFA_PDFFontMgr;

class CFGAS_GEFont : public IFGAS_Font {
 public:
  CFGAS_GEFont(const CFGAS_GEFont& src, uint32_t dwFontStyles);
  explicit CFGAS_GEFont(IFGAS_FontMgr* pFontMgr);
  ~CFGAS_GEFont();

  // IFGAS_Font:
  virtual void Release();
  virtual IFGAS_Font* Retain();
  FX_BOOL LoadFont(const FX_WCHAR* pszFontFamily,
                   uint32_t dwFontStyles,
                   uint16_t wCodePage);
  FX_BOOL LoadFont(const uint8_t* pBuffer, int32_t length);
  FX_BOOL LoadFont(const FX_WCHAR* pszFileName);
  FX_BOOL LoadFont(IFX_Stream* pFontStream, FX_BOOL bSaveStream);
  FX_BOOL LoadFont(CFX_Font* pExtFont, FX_BOOL bTakeOver = FALSE);
  virtual IFGAS_Font* Derive(uint32_t dwFontStyles, uint16_t wCodePage = 0);
  virtual void GetFamilyName(CFX_WideString& wsFamily) const;
  virtual uint32_t GetFontStyles() const;
  virtual uint8_t GetCharSet() const;
  virtual FX_BOOL GetCharWidth(FX_WCHAR wUnicode,
                               int32_t& iWidth,
                               FX_BOOL bCharCode = FALSE);
  virtual int32_t GetGlyphIndex(FX_WCHAR wUnicode, FX_BOOL bCharCode = FALSE);
  virtual int32_t GetAscent() const;
  virtual int32_t GetDescent() const;
  virtual FX_BOOL GetCharBBox(FX_WCHAR wUnicode,
                              CFX_Rect& bbox,
                              FX_BOOL bCharCode = FALSE);
  virtual FX_BOOL GetBBox(CFX_Rect& bbox);
  virtual int32_t GetItalicAngle() const;
  virtual void Reset();
  virtual IFGAS_Font* GetSubstFont(int32_t iGlyphIndex) const;
  virtual CFX_Font* GetDevFont() const { return m_pFont; }
  virtual void SetFontProvider(CXFA_PDFFontMgr* pProvider) {
    m_pProvider = pProvider;
  }
#if _FXM_PLATFORM_ != _FXM_PLATFORM_WINDOWS_
  virtual void SetLogicalFontStyle(uint32_t dwLogFontStyle) {
    m_bUseLogFontStyle = TRUE;
    m_dwLogFontStyle = dwLogFontStyle;
  }
#endif

 protected:
#if _FXM_PLATFORM_ != _FXM_PLATFORM_WINDOWS_
  FX_BOOL m_bUseLogFontStyle;
  uint32_t m_dwLogFontStyle;
#endif
  CFX_Font* m_pFont;
  IFGAS_FontMgr* m_pFontMgr;
  int32_t m_iRefCount;
  FX_BOOL m_bExtFont;
  IFX_Stream* m_pStream;
  IFX_FileRead* m_pFileRead;
  CFX_UnicodeEncoding* m_pFontEncoding;
  CFX_WordDiscreteArray* m_pCharWidthMap;
  CFX_MassArrayTemplate<CFX_Rect>* m_pRectArray;
  CFX_MapPtrToPtr* m_pBBoxMap;
  CXFA_PDFFontMgr* m_pProvider;
  uint16_t m_wCharSet;
  CFX_ArrayTemplate<IFGAS_Font*> m_SubstFonts;
  std::map<FX_WCHAR, IFGAS_Font*> m_FontMapper;
  FX_BOOL InitFont();
  FX_BOOL GetCharBBox(FX_WCHAR wUnicode,
                      CFX_Rect& bbox,
                      FX_BOOL bRecursive,
                      FX_BOOL bCharCode = FALSE);
  FX_BOOL GetCharWidth(FX_WCHAR wUnicode,
                       int32_t& iWidth,
                       FX_BOOL bRecursive,
                       FX_BOOL bCharCode = FALSE);
  int32_t GetGlyphIndex(FX_WCHAR wUnicode,
                        FX_BOOL bRecursive,
                        IFGAS_Font** ppFont,
                        FX_BOOL bCharCode = FALSE);
};

#endif  // XFA_FGAS_FONT_FGAS_GEFONT_H_
