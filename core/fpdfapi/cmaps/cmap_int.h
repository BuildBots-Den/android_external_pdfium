// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef CORE_FPDFAPI_CMAPS_CMAP_INT_H_
#define CORE_FPDFAPI_CMAPS_CMAP_INT_H_

#include "core/fxcrt/fx_string.h"
#include "core/fxcrt/fx_system.h"

struct FXCMAP_CMap {
  enum MapType : uint8_t { None, Single, Range };

  const char* m_Name;
  const uint16_t* m_pWordMap;
  const uint16_t* m_pDWordMap;
  uint16_t m_WordCount;
  uint16_t m_DWordCount;
  MapType m_WordMapType;
  MapType m_DWordMapType;
  int8_t m_UseOffset;
};

const FXCMAP_CMap* FPDFAPI_FindEmbeddedCMap(const ByteString& name,
                                            int charset,
                                            int coding);
uint16_t FPDFAPI_CIDFromCharCode(const FXCMAP_CMap* pMap, uint32_t charcode);
uint32_t FPDFAPI_CharCodeFromCID(const FXCMAP_CMap* pMap, uint16_t cid);

#endif  // CORE_FPDFAPI_CMAPS_CMAP_INT_H_
